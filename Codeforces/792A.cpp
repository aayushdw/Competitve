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
#define MAX 200000+5
using namespace std;

int a[MAX];

int main()
{
	int n;
	si(n);
	rep(i,0,n)
	si(a[i]);
	sort(a,a+n);
	int ans=INT_MAX;
	rep(i,1,n)
	ans=min(ans,a[i]-a[i-1]);
	printf("%d ",ans);
	if(ans==0)
	{
		ll prev=a[0],p=1,c=0;
		rep(i,1,n)
		if(a[i]==prev)
			p++;
		else
		{
			prev=a[i];
			c+=p*(p-1)/2;
			p=1;
		}
		c+=p*(p-1)/2;
		prll(c);
		return 0;
	}
	int c=0;
	rep(i,1,n)
	if(a[i]-a[i-1]==ans)
		c++;
	pr(c);
	return 0;
}