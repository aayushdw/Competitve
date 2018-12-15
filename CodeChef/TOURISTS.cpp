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
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

vi cycle;
vii edge;
map<int,int> adj[MAX];
bitset<MAX> vis;
int degree[MAX]={0};

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=true;
	tr(it,adj[u])
	dfs(it->F);
}

int main()
{
	int n,m,u,v;
	si(n); si(m);

	if(n==1)
	{
		printf("YES");
		return 0;
	}

	typeof(adj[0].begin()) it;

	rep(i,0,m)
	{
		si(u); si(v);
		edge.pb(mp(u,v));

		degree[u]++; degree[v]++;

		it=adj[u].find(v);
		if(it==adj[u].end())
			adj[u].insert(mp(v,1));
		else
			it->S++;

		it=adj[v].find(u);
		if(it==adj[v].end())
			adj[v].insert(mp(u,1));
		else
			it->S++;
	}

	bool f=false;
	vis.reset();
	dfs(1);
	rep(i,1,n+1)
	if(!vis[i])
		f=true;

	rep(i,1,n+1)
	if(!degree[i] || degree[i]%2 || f)
	{
		printf("NO");
		return 0;
	}

	printf("YES\n");

	stack<int> s;
	u=1;
	//s.push(u);
	while(!s.empty() || !adj[u].empty())
	{
		if(adj[u].empty())
		{
			cycle.pb(u);
			u=s.top();
			s.pop();
		}
		else
		{
			v=adj[u].begin()->F;

			it=adj[u].find(v);
			if(it->S==1)
				adj[u].erase(it);
			else
				it->S--;

			it=adj[v].find(u);
			if(it->S==1)
				adj[v].erase(it);
			else
				it->S--;


			//if(adj[v].size())
			s.push(u);
			u=v;
		}
		//printf("Curr : %d\n",u);
	}


	rep(i,0,MAX)
	adj[i].clear();

	rep(i,0,cycle.size())
	printf("%d ",cycle[i]);
	printf("\n");

	rep(i,0,cycle.size()-1)
	{
		u=cycle[i];
		v=cycle[i+1];
		it=adj[u].find(v);
		if(it==adj[u].end())
			adj[u].insert(mp(v,1));
		else
			it->S++;
	}

		u=cycle[cycle.size()-1];
		v=cycle[0];
		it=adj[u].find(v);
		if(it==adj[u].end())
			adj[u].insert(mp(v,1));
		else
			it->S++;


	rep(i,0,edge.size())
	{
		u=edge[i].F, v=edge[i].S;

		bool flag=true;

		it=adj[u].find(v);
		if(it!=adj[u].end())
		{
			printf("%d %d\n",u,v);
			flag=false;
			if(it->S==1)
				adj[u].erase(it);
			else
				it->S--;
		}

		it=adj[v].find(u);
		if(flag && it!=adj[v].end())
		{
			printf("%d %d\n",v,u);
			flag=false;
			if(it->S==1)
				adj[v].erase(it);
			else
				it->S--;
		}

		if(flag)
			printf("asfdasf\n");
	}
	
	return 0;
}