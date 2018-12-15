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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 33554500
// #define MAX 100
using namespace std;

ll mu[MAX];

void mobius()
{
	rep(i,1,MAX)
		mu[i] = 1;
	for(int i=2;i*i<MAX;i++)
		if(mu[i]==1)
		{
			for(int j=i;j<MAX;j+=i)
				mu[j] *= -i;
			for(int j=i*i;j<MAX;j+=i*i)
				mu[j] = 0;
		}
	rep(i,2,MAX)
	{
		if(abs(mu[i])==i)
			mu[i] /= i;
		else if(mu[i]<0)
			mu[i] = 1;
		else if(mu[i]>0)
			mu[i] = -1;
	}
}

int main()
{
	mobius();
	ll ans = 0;
	rep(i,2,MAX)
		ans -= mu[i]*((1ll<<50)/(i*i));
	prll((1ll<<50)-ans);
	rep(i,0,100)
		printf("%lld %lld\n",i,mu[i]);
	return 0;
}