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
#define MAX 1000+5
using namespace std;

int ans=0,c[MAX],r[MAX],par[MAX],m;
vi edge[MAX];
vi dfs(int u)
{
	if(edge[u].empty())
	{
		vi ret(101,0);
		rep(i,r[u],c[u]+1)
			ret[i]=1;
		return ret;
	}

	vi ret(101,0);
	if(u!=0)
	{
		rep(i,r[u],c[u]+1)
			ret[i]=1;
	}

	rep(x,0,edge[u].size())
	{
		vi v=dfs(edge[u][x]);
		if(!u)
		{
			m=0;
			rep(j,0,101)
				m=max(m,v[j]);
			ans+=m;
			continue;
		}
		vi temp=ret;

		rep(j,0,c[u]+1)
		{
			rep(k,0,j+1)
			{
				temp[j]=max(temp[j],ret[j-k]+v[k]);
			}
		}

		ret=temp;

	}

	return ret;
}

int main()
{
	int n;
	si(n);
	rep(i,1,n+1)
	{
		si(par[i]); si(r[i]); si(c[i]);
		edge[par[i]].pb(i);
	}
	vi v=dfs(0);
	pr(ans);
	return 0;
}
