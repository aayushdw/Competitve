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
// #define ii pair<int,int> 
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
#define lb lower_bound
#define ub upper_bound
 
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
#define INF 8000000000000000000
#define MAX 30+5
using namespace std;

ll c[MAX],w[MAX];

ll getNum(ll p)
{
	ll x = 1;
	while(x<=p)
		x *= 2;
	return x/2;
}

int main()
{
	ll n,l;
	sl(n); sl(l);
	rep(i,0,n)
		sl(c[i]);
	w[0] = 1;
	rep(i,1,n)
		w[i] = 2*w[i-1];
	ll ans = 0;
	ll ANS = INF;
	// rep(i,0,n)
	// 	printf("%lld ",w[i]);
	// printf("\n");
	while(l>0)
	{
		ll temp = INF;
		ll v = getNum(l);
		ll sub = v;
		// printf("Buy %lld\n",v);
		rep(i,0,n)
		{
			if(w[i]<=v)
				temp = min(temp,(v/w[i])*c[i]);
			else
			{
				// printf("%lld %lld\n",v,w[i]);
				ANS = min(ANS,ans + c[i]);
				// if(c[i]<temp)
				// {
				// 	temp = c[i];
				// 	sub = w[i];
				// }
			}
			// printf("temp = %lld\n",temp);
		}
		ans += temp;
		l -= sub;
		// printf("Bought = %lld\nLeft = %lld\n",temp,l);
		// printf("Cur = %lld\n\n",ans);
	}
	prll(min(ans,ANS));
	return 0;
}