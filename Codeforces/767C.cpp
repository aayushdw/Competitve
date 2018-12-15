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
#define INF 4000000000000000000
#define MAX 1000000+5
using namespace std;

int par[MAX],sum[MAX],num[MAX],val[MAX]={0},tot=0,n;
vi ans;
vi edge[MAX];
bitset<MAX> vis;
ii xyz;

int getsum(int u)
{
	vis[u]=true;
	ll ret=val[u];
	rep(i,0,edge[u].size())
	{
		int v=edge[u][i];
		if(!vis[v])
			ret+=getsum(v);
	}
	sum[u]=ret;
	//printf("SUM: %d %d\n",u,sum[u]);
	return ret;
}

int getnum(int u)
{
	vis[u]=true;
	num[u]=1;
	rep(i,0,edge[u].size())
	{
		int v=edge[u][i];
		if(!vis[v])
			num[u]+=getnum(v);
	}
	return num[u];
}

ii foo(int u)
{
	vis[u]=true;
	ll ret=val[u];
	ii x,y;
	y.S=0;
	rep(i,0,edge[u].size())
	{
		int v=edge[u][i];
		if(!vis[v])
		{
			x=foo(v);
			ret+=x.F;
			y.S = max(x.S,y.S);
		}
	}
	if(u && ret==2*tot/3 && y.S && n-num[u])
	{
		xyz.F=u;
		xyz.S=y.S;
		//printf("asfa %d %d\n",u,num[u]);
	}
	if(u && ret==tot/3 && !y.S)
	{
		ans.pb(u);
		y.S=u;
	}
	y.F=ret;
	return y;
}

/*int dfs(int u, bool f)
{
	vis[u]=true;
	int p=0,q;
	rep(i,0,edge[u].size())
	{
		int v=edge[u][i];
		if(!vis[v])
		{
			if(sum[v]==tot/3)
			{
				if(f)
				{
					ans.pb(v);
				}
				
				dfs(v,false);
				p=v;
			}
			else
			{
				q=dfs(v,f);
				p=max(p,q);
			}
		}
	}
	if(u && sum[u]==2*tot/3 && p)
	{
		xyz=mp(u,p);
	}
	return p;
}*/

int main()
{
	si(n);
	rep(i,1,n+1)
	{
		si(par[i]);
		edge[par[i]].pb(i);
		si(val[i]);
		tot+=val[i];
	}
	xyz.F=0; xyz.S=0;
	vis.reset();
	if(tot%3==0)
	{
		getnum(0);
		vis.reset();
		getsum(0);
		vis.reset();
		foo(0);
	}
	/*rep(i,0,n+1)
	printf("%d ",sum[i]);
	printf("\n");
	rep(i,0,ans.size())
	printf("%d ",ans[i]);
	printf("\n");
	printf("XYZ: %d %d\n",xyz.F,xyz.S);*/
	if(ans.size()>1)
		printf("%d %d",ans[0],ans[1]);
	else if(xyz.F!=0)
	{
		printf("%d %d",xyz.F,xyz.S);
	}
	else
		printf("-1");
	return 0;
}