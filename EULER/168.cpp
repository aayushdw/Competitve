#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
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
using boost::multiprecision::cpp_int;

cpp_int power(cpp_int base,int exp)
{
	cpp_int ret = 1;
	while(exp--)
		ret *= base;
	return ret;
}

int main()
{
	cpp_int f = 10;
	cpp_int ans = 0;
	rep(n,1,100)
	{
		rep(p,1,10)
		rep(y,1,10)
		{
			cpp_int x = (power(10,n) - p)*y;
			if(!(x%(10*p-1)))
			{
				x /= (10*p-1);
				if(x<power(10,n-1))
					continue;
				cpp_int num = (10*x + y);
				ans += num%100000;
			}
		}
	}
	cout<<ans%100000<<endl;
	return 0;
}