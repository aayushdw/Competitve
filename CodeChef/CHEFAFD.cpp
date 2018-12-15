#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define NIL 0
#define MAX 50000+5
 
using namespace std;
 

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 200000;

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bitset<MAXN1> used,vis;

void init(int _n1, int _n2) {
	n1 = _n1;
	n2 = _n2;
	edges = 0;
	fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
	head[edges] = v;
	prev[edges] = last[u];
	last[u] = edges++;
}

void bfs() {
	fill(dist, dist + n1, -1);
	int sizeQ = 0;
	for (int u = 0; u < n1; ++u) {
		if (!used[u]) {
			Q[sizeQ++] = u;
			dist[u] = 0;
		}
	}
	for (int i = 0; i < sizeQ; i++) {
		int u1 = Q[i];
		for (int e = last[u1]; e >= 0; e = prev[e]) {
			int u2 = matching[head[e]];
			if (u2 >= 0 && dist[u2] < 0) {
				dist[u2] = dist[u1] + 1;
				Q[sizeQ++] = u2;
			}
		}
	}
}

bool dfs(int u1) {
	vis[u1] = true;
	for (int e = last[u1]; e >= 0; e = prev[e]) {
		int v = head[e];
		int u2 = matching[v];
		if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
			matching[v] = u1;
			used[u1] = true;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	used.reset();
	fill(matching, matching + n2, -1);
	for (int res = 0;;) {
		bfs();
		vis.reset();
		int f = 0;
		for (int u = 0; u < n1; ++u)
			if (!used[u] && dfs(u))
				++f;
		if (!f)
			return res;
		res += f;
	}
}


int main()
{
	int t,num,u,v,l,n,m;
	char s[5];
	si(t);
	while(t--)
	{
		//RESET
		clr(last);
		clr(prev);
		clr(head);
		clr(matching);
		clr(dist);
		clr(Q);
 
		si(num);
		n=num*num;
		m=num*num;

		init(n,m);

		rep(i,0,num)
		rep(j,0,num)
		{
			u=i*num+j;
			//printf("For %d - ",u);
			scanf("%s",s);
			l=strlen(s);
			rep(k,0,l)
			{
				//Make Adjacency
				if(s[k]=='U')
					v = i>0 ? (i-1)*num+j : -1;
				if(s[k]=='D')
					v = (i<num-1) ? (i+1)*num+j: -1;
				if(s[k]=='L')
					v = (j>0) ? i*num+j-1 : -1;
				if(s[k]=='R')
					v =  (j<num-1) ? i*num+j+1 : -1;
				if(v>=0)
				{
					//printf("%d ",v);
					addEdge(u,v);
				}
			}
			//printf("\n");
		}
		
		l=maxMatching();

		if(l==n)
		{
			printf("YES\n");
			rep(i,0,num)
			{
				rep(j,0,num)
				{
					u=i*num+j;
					//printf("%d ",match[u]);
					if(matching[u]==(i-1)*num+j)
						printf("U ");
					if(matching[u]==(i+1)*num+j)
						printf("D ");
					if(matching[u]==i*num+j-1)
						printf("L ");
					if(matching[u]==i*num+j+1)
						printf("R ");
				}
				printf("\n");
			}
		}
		else
			printf("NO\n");
	}
	return 0;
} 