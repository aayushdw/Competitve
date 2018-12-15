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



int main()
{
	ll n,k,c=0,i;
	sl(n); sl(k);
	for(i=1;i*i<=n;i++)
		if(n%i==0)
		{
			c++;
			if(c==k)
			{
				printf("%lld",i);
				return 0;
			}
		}
	i--;
	if(i*i==n)
		c=2*c-1;
	else
		c*=2;
	if(c==k)
	{
		printf("%lld\n",n);
		return 0;
	}
	ll d=0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
			d++;
		if(c-d==k)
		{
			printf("%lld",n/i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}