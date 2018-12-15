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

vl x,y;

int main()
{
	int t;
	ll n,m,sum,p,xsum,ysum,xp,yp,ans;
	bool f;
	si(t);
	while(t--)
	{
		x.clear(); y.clear();
		x.pb(0); y.pb(0);
		xsum=0; ysum=0; xp=0; yp=0;
		f=true;

		sl(n); sl(m); sl(sum);

		rep(i,0,n)
		{
			sl(p);
			x.pb(p);
		}
		rep(i,0,m)
		{
			sl(p);
			y.pb(p);
			if(ysum+p<=sum && f)
			{
				ysum+=p;
				yp++;
			}
			else
				f=false;
		}
		ans=yp; xp=1; xsum=x[1];
		//printf("\n%lld %lld %lld %lld\n",xp,xsum,yp,ysum);
		while(xp<x.size() && xsum<=sum)
		{
			while(xsum+ysum>sum && yp>=0)
			{
				ysum-=y[yp];
				yp--;
			}
			//printf("%lld %lld %lld %lld\n",xp,xsum,yp,ysum);
			if(xp+yp>ans)
				ans=xp+yp;
			if(xp==x.size()-1)
				break;
			else
			{
				xp++;
				xsum+=x[xp];
			}
		}
		prll(ans);
	}
	return 0;
}