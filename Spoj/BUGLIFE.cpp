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
#define ison(x,i) (((x) >> (i)) & 1)  //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))   //set ith bit in x to be zero
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
      rank.assign(n,1);
      sum.assign(n,0);
      rep(i,0,n)
      par[i]=i;
    }
    int find(int u)
    { return (par[u]==u)?u:find(par[u]);  }
    int getSum(int u)
    { return (par[u]==u)?0:sum[u]^getSum(par[u]); }
    void unite(int u,int v,int val)
    {
    	int uu,vv,su,sv;
    	uu=find(u); vv=find(v);
    	su=getSum(u); sv=getSum(v);
    	if(uu==vv) return;
    	if(rank[uu]>rank[vv]) swap(uu,vv),swap(u,v);
    	par[uu]=vv;
    	rank[vv]+=rank[uu];
    	sum[uu]=!(su^sv);
    }
};

int main()
{
	int n,q,t,u,v,uu,vv;
	bool f;
	si(t);
	rep(tt,1,t+1)
	{
		DSU p; f=true;
		si(n); si(q);
		p.init(n+1);
		while(q--)
		{
			si(u); si(v);
			uu=p.find(u); vv=p.find(v);
			if(uu!=vv) p.unite(u,v,1);
			else if(!(p.getSum(u)^p.getSum(v))) f=false;
		}
		printf("Scenario #%d:\n",tt);
		if(f)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
}