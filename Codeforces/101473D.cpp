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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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

int n,a[20],b[20];

bool solve(int len)
{
	/*rep(i,0,len)
		printf("%d ",a[i]);
		printf("\n");*/
		

	if(len<n)
		return false;
	if(len==n)
	{

		int num=0;
		rep(i,0,n)
		num+=(a[i]==b[i]);
		//pr(num);
		if(num==n)
		{
			//printf("adfasf");
			return true;
		}

		reverse(a,a+n);
		num=0;
		rep(i,0,n)
		num+=(a[i]==b[i]);
		reverse(a,a+n);
		//pr(num);
		if(num==n)
		{
			//printf("adfasfa");
			return true;
		}
		else
			return false;
	}
	int temp[len];
	rep(i,0,len)
	temp[i]=a[i];
	rep(i,1,len)
	{
		int newlen = max(i,len-i);
		int filled = 0,k=0;
		clr(a);
		while(filled < len)
		{
			if(i-k-1>=0)
			{
				filled++;
				a[k]+=temp[i-k-1];
			}
			if(i+k<len)
			{
				filled++;
				a[k]+=temp[i+k];
			}
			k++;
		}
		if(solve(newlen))
			return true;
	}
	return false;
}

int main()
{
	/*ll n=15;
	ll ans[20];
	ans[1]=1; ans[0]=0; ans[2]=1;
	rep(i,3,n+1)
	{
		ans[i]=0;
		rep(j,i/2+i%2,i)
		ans[i]+=2*ans[j];
		printf("%lld %lld\n",i,ans[i]);
	}*/

	int m;
	si(m);
	rep(i,0,m)
	si(a[i]);
	si(n);
	rep(i,0,n)
	si(b[i]);

	if(solve(m))
		printf("S");
	else
		printf("N");
	return 0;
}