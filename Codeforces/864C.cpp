#include<bits/stdc++.h>
 
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

ll d[MAX];

int main()
{
	ll a,b,f,k;
	sl(a); sl(b); sl(f); sl(k);
	ll tot = a*k;
	ll cur = 0,num = 0,fuel = b;

	d[0] = f;
	rep(i,1,k)
	{
		d[i] = d[i-1];
		if(i%2)
			d[i]+=2*(a-f);
		else
			d[i]+=2*f;
	}
	d[k] = tot;

	rep(i,0,k)
	{
		//printf("%lld %lld %lld %lld\n",cur,d[i],fuel,num);

		if(cur+fuel<d[i])
		{
			pr(-1);
			return 0;
		}

		fuel-=(d[i]-cur);
		if(d[i]+fuel<d[i+1])
		{
			num++;
			fuel=b;
		}

		cur = d[i];
	}

	if(cur+fuel<d[k])
	{
		pr(-1);
		return 0;
	}

	printf("%lld\n",num);

	return 0;
}