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
#define MAX 100000+5
using namespace std;



int main()
{
	int n,l,k;
	cin>>n>>l>>k;
	double a[n+1][n+1];
	double temp[n+1][n+1];
	clr(a);
	a[0][min(k,n)] = 1.0;
	vii v(n,mp(0,0));
	rep(i,0,n)
		si(v[i].S);
	rep(i,0,n)
		si(v[i].F);
	sort(all(v));
	reverse(all(v));
	rep(i,0,n)
	{
		double p = v[i].S*1.0/100.0;
		int diff = v[i].F;
		clr(temp);
		rep(j,0,i+1)
		{
			rep(k,0,n+1)
			{
				if(k+diff<0)
					temp[j][k] += a[j][k]*(1-p);
				else
				{
					if(k+diff>n)
						temp[j+1][n] += a[j][k]*p;
					else
						temp[j+1][k+diff] += a[j][k]*p;
					temp[j][k] += a[j][k]*(1.0-p);
				}
			}
		}
		rep(j,0,n+1)
			rep(k,0,n+1)
				a[j][k] = temp[j][k];
	}

	double ans = 0;
	rep(j,l,n+1)
	rep(k,0,n+1)
	ans += a[j][k];
	printf("%0.15lf\n",ans);
	return 0;
}