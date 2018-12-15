#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
int x,arr[11],a[11][11];
void permute(int l,int r,int val)
{
	if(l==r)
	{
		if(a[l][arr[l]]<=0)
		return;
		x=max(x,val+a[l][arr[l]]);
		return;
	}
	rep(i,l,r+1)
	{
		if(a[l][arr[i]]<=0)
			continue;
		swap(arr[l],arr[i]);
		permute(l+1,r,val+a[l][arr[l]]);
		swap(arr[l],arr[i]);
	}
}
int solve()
{
	x=0;
	permute(0,10,0);
	return x;
}
int main()
{
	int t,ans,p;
	bool f;
	sc(t);
	while(t--)
	{
		rep(i,0,11)
		rep(j,0,11)
		sc(a[i][j]);
		rep(i,0,11)
		arr[i]=i;
		ans=solve();
		pr(ans);
	}
	return 0;
}