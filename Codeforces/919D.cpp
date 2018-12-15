#include <bits/stdc++.h>
 
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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 300000+5
using namespace std;

vi G[MAX];
// int a[MAX][26];
string s;
bitset<MAX> vis,foo;
vi topo;
int ans = 0;

bool dfs(int u)
{
	if(!vis[u])
	{
		vis[u] = true;
		foo[u] = true;
		rep(i,0,G[u].size())
			if(!vis[G[u][i]] && dfs(G[u][i]))
				return true;
			else if(foo[G[u][i]])
				return true;
		topo.pb(u);
	}
	foo[u] = false;
	return false;
}

void DFS(int u,vi &temp)
{
	vis[u] = true;
	temp[s[u]-'a']++;
	ans = max(ans,temp[s[u]-'a']);	
	rep(i,0,G[u].size())
		DFS(G[u][i],temp);
	temp[s[u]-'a']--;
}

int main()
{
	int n,m;
	si(n); si(m);
	cin>>s;
	set< ii > edges;
	while(m--)
	{
		int u,v;
		si(u); si(v);
		if(edges.find(mp(u,v))!=edges.end())
			continue;
		edges.insert(mp(u,v));
		if(u==v)
		{
			pr(-1);
			return 0;
		}
		u--;
		v--;
		G[u].pb(v);
	}

	vis.reset();
	foo.reset();
	rep(i,0,n)
		if(dfs(i))
		{
			pr(-1);
			return 0;
		}
	reverse(all(topo));
	// rep(i,0,topo.size())
	// 	printf("%d ",topo[i]+1);
	// printf("\n");

	vis.reset();
	rep(i,0,topo.size())
	{
		vi temp(26,0);
		if(!vis[topo[i]])
			DFS(topo[i],temp);
	}
	pr(ans);
	return 0;
}