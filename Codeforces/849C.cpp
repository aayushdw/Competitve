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

ll getTri(ll k)
{
	ll low=0,high=1000,mid;
	while(low!=high)
	{
		if(low+1==high)
		{
			if((high*(high+1))/2<=k)
				return high;
			else
				return low;
		}
		mid = (low+high)/2;
		if((mid*(mid+1))/2>k)
			high = mid-1;
		else
			low=mid;
	}
	return low;
}

int main()
{
	ll k;
	sl(k);
	int curr=0;
	if(k==0)
		printf("%c",'a');
	while(k)
	{
		ll p = getTri(k);
		prll(p+1);
		/*rep(i,0,p+1)
			printf("%c",'a'+curr);*/
		k-=(p*(p+1))/2;
		curr++;
	}
	return 0;
}