#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
ll bin_search(ll key, ll a[], ll x, ll y)
{
	if(x==y)
	return x;
	ll mid=(x+y)/2;
	if(a[mid]>key)
	return bin_search(key,a,x,mid);
	else
	return bin_search(key,a,mid+1,y);
}
int main()
{
	ll n,q,x;
	scll(n);
	ll a[n];
	rep(i,0,n)
	scll(a[i]);
	sort(a,a+n);
	scll(q);
	while(q--)
	{
		scll(x);
		if(a[n-1]<=x)
		printf("%lld\n",n);
		else
		printf("%lld\n",bin_search(x,a,0,n-1));
	}
	return 0;
}
