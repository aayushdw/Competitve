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
#define MAX 100000+5
using namespace std;

class DSU
{
  public:
  	vi par,rank,sum;
  	void init(int n)
  	{
  		par.assign(n,0);
  		rank.assign(n,0);
  		sum.assign(n,0);
  		rep(i,0,n)
  		par[i]=i;
  	}
  	int find(int u)
  	{	return (par[u]==u)?u:find(par[u]);	}
  	int getSum(int u)
  	{	return (par[u]==u)?0:sum[u]^getSum(par[u]);	}
  	void unite(int x,int v,int val)
  	{
  		x=find(x); v=find(v);
  		if(x==v) return;
  		if(rank[x]>rank[v]) swap(x,v);
  		par[x]=v;
  		rank[v]+=rank[x];
  		sum[x]=val;
  	}
};

int main()
{
	int n,q,u,v,c,uu,vv;
	string s;
    si(n);
    DSU p;
    p.init(n);
    si(q);
    int ans=q;
    rep(i,1,q+1)
    {
		si(u); si(v); cin>>s;
		if(s=="even") c=0;
		else c=1;
		uu=p.find(u); vv=p.find(v);
		if(uu!=vv) p.unite(u,v,c);
		else
		{
			uu=p.getSum(u); vv=p.getSum(v);
			printf("%d %d %d %d\n",u,v,uu,vv);
			if(uu^vv!=c)
			{
				ans=q;
				break;
			}
		}
    }
    pr(ans);
    return 0;
}