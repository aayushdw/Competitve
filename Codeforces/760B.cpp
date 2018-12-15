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

ll goo(ll num, ll val)
{
	if(num==0)
		return 0;
	ll ret=val*(val+1)/2;
	if(val>num)
		ret-=(val-num)*(val-num+1)/2;
	else
		ret+=num-val;
	return ret;
}

ll foo(ll n,ll k,ll v)
{
	ll prev=k-1,next=n-k;
	return goo(prev,v-1)+goo(next,v-1)+v;
}

ll solve(ll n,ll m,ll k)
{
	ll low=1, high=m, mid,vmid;
	while(low<high)
	{
		if(low+1==high)
		{
			if(foo(n,k,high)<=m)
				return high;
			else
				return low;
		}
		//printf("%lld %lld\n",low,high);
		mid=(high+low)/2;
		//prll(mid);
		vmid=foo(n,k,mid);
		if(vmid>m)
			high=mid-1;
		else
			low=mid;
	}
	return low;
}

int main()
{
	ll n,m,k;
	sl(n); sl(m); sl(k);
	if(n==m)
	{
		printf("1");
		return 0;
	}
	printf("%lld",solve(n,m,k));
	return 0;
}