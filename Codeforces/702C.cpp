#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define INF 1e12
#define MAX 100000+5
using namespace std;

vi v,vec;

ll getmin(ll p)
{
	ll low=0,high=vec.size()-1,mid;
	if(vec[0]>p)
		return -INF;
	while(low<high)
	{
		if(low+1==high)
		{
			if(vec[high]<=p)
				return vec[high];
			else
				return vec[low];
		}
		mid=(low+high)/2;
		if(vec[mid]==p)
			return p;
		if(vec[mid]>p)
			high=mid-1;
		else
			low=mid;
	}
	return vec[low];
}

ll getmax(ll p)
{
	ll low=0,high=vec.size()-1,mid;
	if(vec[high]<p)
		return INF;
	while(low<high)
	{
		if(low+1==high)
		{
			if(vec[low]>=p)
				return vec[low];
			else
				return vec[high];
		}
		mid=(low+high)/2;
		if(vec[mid]==p)
			return p;
		if(vec[mid]<p)
			low=mid+1;
		else
			high=mid;
	}
	return vec[low];
}

int main()
{
	ll n,m,p,x,y,z;
	sl(n); sl(m);
	rep(i,0,n)
	{
		sl(p);
		v.pb(p);
	}
	rep(i,0,m)
	{
		sl(p);
		vec.pb(p);
	}
	ll ans=0;
	rep(i,0,n)
	{
		p=v[i];
		y=getmin(p);
		z=getmax(p);
		//printf("%d %d %d\n",p,y,z);
		x=min(z-p,p-y);
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}