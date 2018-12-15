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
#define ii pair<int,in>t 
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



int main()
{
	vector<ll> n = {17,78,19,23,29,77,95,77,1,11,13,15,1,55};
	vector<ll> d = {91,85,51,38,33,29,23,19,17,13,11,2,7,1};
	ll num = 2 , j = 0 , iter = 0;
	while(iter<1000000000)
	{
		j = 0;
		while(num%d[j])
		{
			j++;
			j%=14;
		}
		iter++;
		// {
		// 	printf("%d * %d / %d\n",num,n[j],d[j]);
		// }

		num /= d[j];
		num *= n[j];
		if(num<0)
		{
			prll(iter);
			return 0;
		}
		if(num && (!(num&(num-1))))
		{
			printf("%10lld %10lld\n",num,iter);
		}
	}
	return 0;
}