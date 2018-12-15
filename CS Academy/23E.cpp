#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 1<<28
#define MAX 200000+5
#define NIL 0
using namespace std;

// This is the famous "Yarin sieve", for use when memory is tight.
#define MAXSIEVE 1000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 500 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void seive()
{
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
	if (a[i>>3]&(1<<(i&7)))
	for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
	a[j>>3]&=~(1<<(j&7));
}

vector< int > G[MAX],adj[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

int arr[MAX];
int ans[MAX];

int main()
{
	seive();
	int num;
	si(num);
	rep(i,0,num)
	si(arr[i]);

	n=100000; m=n;

	rep(i,0,num)
	rep(j,0,i)
	if((arr[i]+arr[j])%2 && isprime(arr[i]+arr[j]))
	{
		//printf("%d %d\n",i,j);
		if(arr[i]%2)
		{
			G[arr[i]].pb(n+arr[j]);
			G[n+arr[j]].pb(arr[i]);
		}
		else
		{
			G[arr[j]].pb(n+arr[i]);
			G[n+arr[i]].pb(arr[j]);
		}
	}

	pr(hopcroft_karp());

	clr(ans);

	rep(i,0,MAX)
	if(!match[i])
		rep(j,0,G[i].size())
			if(match[G[i][j]])
				ans[G[i][j]]=1;

	rep(i,0,MAX)
	{
		if(match[i])
		{
			//printf("%d %d\n",i,match[i]);

			if(ans[match[i]]==1)
				ans[i]=-1;
			else
			{
				ans[i]=1;
				ans[match[i]]=-1;
			}

			if(ans[i]==1)
			{
				ans[match[i]]=-1;
				//printf("%d -1\n",match[i]);
			}
			else if(ans[i]==-1)
			{
				rep(j,0,G[i].size())
				if(match[G[i][j]])
				{
					//printf("%d %d 1\n",G[i][j],i);
					ans[G[i][j]]=1;
				}
			}
		}
	}

	vi v;

	rep(i,0,MAX)
	if(ans[i]==1 && i<=100000)
		//printf("%d ",i);
		v.pb(i);
	else if(ans[i]==1)
		//printf("%d ",i-100000);
		v.pb(i-100000);
	sort(all(v));
	rep(i,0,v.size())
	printf("%d ",v[i]);
	return 0;
}