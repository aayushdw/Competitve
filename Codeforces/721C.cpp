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
#define MAX 5000+5
using namespace std;

vii par[MAX];
vi vec;
map< int,int > M[MAX];
typeof(M[0].begin()) it;

int foo(int u,int t)
{
	if(t<0)
		return INT_MIN;
	else if(t==1)
		return 1;
	int p=0,q,ret=-1;
	rep(i,0,par[u].size())
	{
		int v=par[u][i].F;
		int w=par[u][i].S;
		q=foo(v,t-w);
		if(q>p)
			p=q, ret=i;
	}
	//printf("foo(%d,%d) = %d\n",u,t,p+1);
	M[u].insert(mp(t,ret));
	return p+1;
}

int main()
{
	int n,m,t,u,v,w;
	si(n); si(m); si(t);
	while(m--)
	{
		si(u); si(v); si(w);
		par[v].pb(mp(u,w));
	}
	int x=foo(n,t);
	pr(x);

	//printf("\n");
	int p=n;
	//tr(i,M)
	/*printf("%d %d\n",p,t);
	it=M.find(mp(5,6));
	printf("%d %d %d\n",it->F.F,it->F.S,it->S);*/

	
	rep(i,0,x)
	{
		vec.pb(p);
		it=M[p].find(t);
		if(it!=M[p].end())
		{
			int j=it->S;
			//pr(j);
			if(j==-1)
				break;
			t-=par[p][j].S;
			p=par[p][j].F;
		}
	}
	reverse(all(vec));
	rep(i,0,x)
	printf("%d ",vec[i]);
	
	return 0;
}