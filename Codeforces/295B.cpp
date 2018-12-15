#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define INF 10000000ll
#define MAX 500+5
using namespace std;

ll g[MAX][MAX]={0},dist[MAX][MAX]={0},v[MAX],ans[MAX];
bitset<MAX> t;

int main()
{
	ll n,p;
	sl(n);
	rep(i,0,n)
	rep(j,0,n)
	sl(g[i][j]);
	rep(i,0,n)
	sl(v[i]);
	reverse(v,v+n);
	rep(i,0,n)
	rep(j,0,n)
	dist[i][j]=g[i][j];
	t.reset();
	rep(i,0,n)
	{
		p=v[i]-1;
		t[p]=true;
		rep(j,0,n)
		{
			rep(k,0,n)
			{
				dist[j][k]=min(dist[j][k],dist[j][p]+dist[p][k]);
				if(dist[j][k]!=INF&&t[j]&&t[k])
				ans[i]+=dist[j][k];
				//printf("%lld ",dist[j][k]);
			}
			//printf("\n");
		}
	}
	reverse(ans,ans+n);
	rep(i,0,n)
	printf("%lld ",ans[i]);
	return 0;
}






