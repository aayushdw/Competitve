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
#define MAX 300000+5
#define MAXN 1000000+5
using namespace std;

int n,isPresent[MAXN],arr[MAX],pre[MAX],suf[MAX];
vi ans;

bool check(int val)
{
	ans.clear();
	clr(isPresent);
	
	for(int i=0;i<n;i+=val)
	{
		int l=i,r=min(n-1,i+val-1);
		pre[l]=arr[l];
		rep(j,l+1,r+1)
			pre[j]=__gcd(pre[j-1],arr[j]);
		suf[r]=arr[r];
		for(int j=r-1;j>=l;j--)
			suf[j]=__gcd(suf[j+1],arr[j]);	
	}
	rep(i,0,val)
		isPresent[arr[i]]++;
	bool f=false;
	rep(i,0,n-val+1)
	{
		int p=__gcd(suf[i],pre[i+val-1]);
		if(isPresent[p])
		{
			//pr(i);
			f=true;
			ans.pb(i);
		}
		isPresent[arr[i]]--;
		isPresent[arr[i+val]]++;
	}
	return f;
}

int main()
{
	si(n);
	rep(i,0,n)
		si(arr[i]);
	int low=1,high=n,mid;
	while(low<high)
	{
		mid=(low+high+1)>>1;
		if(check(mid))
			low=mid;
		else
			high=mid-1;
	}
	check(low);
	cout<<ans.size()<<' '<<low-1<<endl;
	rep(i,0,ans.size())
		printf("%d ",ans[i]+1);
	return 0;
}