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
#define INF 4000000000000000000
#define MAX 200000+5
using namespace std;

int a[MAX],par[MAX],ans[MAX],L[MAX];
vi q2[MAX],G[MAX];
vii q1[MAX];

struct BIT {
    int data[MAX]={0};
    void update(int idx, int val) {
        while (idx < MAX) {
            data[idx] += val;
            idx += idx & -idx;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += data[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l);
    }
};

BIT bit;

void DFS(int u)
{
	rep(i,0,q1[u].size())
	{
		int time = q1[u][i].F;
		int val = q1[u][i].S;
		bit.update(time,val);
		//printf("Q: %d %d\n",time,val);
	}

	rep(i,0,q2[u].size())
	{
		ans[q2[u][i]] = a[u] + L[u]*bit.query(q2[u][i]);
		//pr(bit.query(q2[u][i]));
	}
	
	rep(i,0,G[u].size())
	if(G[u][i]!=par[u])
		DFS(G[u][i]);

	rep(i,0,q1[u].size())
	{
		int time = q1[u][i].F;
		int val = q1[u][i].S;
		bit.update(time,-val);
	}
}

void dfs(int u)
{
	rep(i,0,G[u].size())
	if(G[u][i]!=par[u])
	{
		par[G[u][i]]=u;
		L[G[u][i]]=-L[u];
		dfs(G[u][i]);
	}
}

int main()
{
	int n,m,u,v,type,x,val;
	si(n); si(m);
	rep(i,1,n+1)
	si(a[i]);
	rep(i,0,n-1)
	{
		si(u); si(v);
		G[u].pb(v);
		G[v].pb(u);
	}
	par[1]=1;
	L[1]=1;
	dfs(1);
	rep(i,1,m+1)
	{
		si(type);
		//pr(type);
		if(type==1)
		{
			si(x); si(val);
			val*=L[x];
			q1[x].pb(mp(i,val));
		}
		else
		{
			si(x);
			q2[x].pb(i);
		}
	}

	//return 0;

	rep(i,0,MAX)
		ans[i]=INT_MAX;

	DFS(1);

	rep(i,1,m+1)
	if(ans[i]!=INT_MAX)
		pr(ans[i]);

	return 0;
}