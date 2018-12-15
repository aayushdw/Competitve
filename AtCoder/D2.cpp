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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define MAX 100000+5
using namespace std;

bitset<MAX> t;
vl G[MAX];
bitset<MAX> vis;
ll c[MAX],k;
ll nec[MAX],T[MAX];
int isfound = 0 ; 
int root ; 

ll dfs(ll u)
{
	vis[u]=true;
	rep(i,0,G[u].size())
	if(!vis[G[u][i]])
		c[u]+=dfs(G[u][i]);
	c[u]+=t[u];
	return c[u];
}

void dfs1(ll u)
{
	vis[u] = 1 ; 
	if(!isfound){
		int cnt = 0 ; 
		for(int i=0;i<G[u].size();i++){
			if((c[G[u][i]] > 0)&&(!vis[G[u][i]]))
				cnt++ ; 
		}
		if(cnt >= 2){
			isfound = 1 ;
			root = u ;  
			nec[u] = 1 ; 
		}

	}
	else{
		if(c[u]!=0){
			nec[u] = 1 ; 
		}
	}
	for(int i=0;i<G[u].size();i++){
		if(!vis[G[u][i]]){
			dfs1(G[u][i]) ; 
		}
	}
}

ll dfs2(ll u)
{
	vis[u]=true;
	T[u]=1;
	rep(i,0,G[u].size())
		if(!nec[G[u][i]] && !vis[G[u][i]])
		{
			T[u]*=(dfs2(G[u][i])+1);
			T[u]%=MOD;
		}
	return T[u];
}

int main()
{
	ll tt;
	sl(tt);
	while(tt--)
	{
		ll n;
		sl(n);
		t.reset();
		rep(i,0,MAX)
		G[i].clear();
		clr(nec);
		
		rep(i,0,n-1)
		{
			ll u,v,p;
			sl(u); sl(v); sl(p);
			G[u].pb(v);
			G[v].pb(u);
			if(p)
			{
				t[u]=true;
				t[v]=true;
			}
		}
		k=0;
		rep(i,1,n+1)
			k+=t[i];

		/*rep(i,1,n+1)
			printf("%d ",t[i]==1);
		printf("\n");*/


		vis.reset();
		clr(c);
		dfs(1);

		/*cout<<endl;
		prll(k);
		rep(i,1,n+1)
			printf("%lld ",c[i]);*/

		vis.reset();
		dfs1(1);

		/*cout<<endl;
		rep(i,1,n+1)
			printf("%lld ",nec[i]);
		cout<<endl;*/

		clr(T);
		vis.reset();
		rep(i,1,n+1)
		if(nec[i])
			dfs2(i);

		ll ans=1;
		rep(i,1,n+1)
		if(nec[i] && T[i])
		{
			ans*=T[i];
			ans%+MOD;
		}
		prll(ans);
	}
	return 0;
}