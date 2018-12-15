#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define LEN 1000000000
#define MOD 1000000000+7;
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
ll a[10],b[10];
int main()
{
	rep(i,0,10)
	a[i]=1;
	rep(i,2,LEN+1)
	{
		/*printf("Length = %lld\n",i-1);
		rep(j,0,10)
		{
			//a[j]=b[j];
			printf("%lld = %lld\n",j,a[j]);
		}*/
		b[9]=(a[8]+a[6]);
		b[8]=(a[9]+a[5]+a[7]);
		b[7]=(a[8]+a[4]);
		b[6]=(a[3]+a[5]+a[9]);
		b[5]=(a[2]+a[4]+a[6]+a[8]);
		b[4]=(a[1]+a[5]+a[7]);
		b[3]=(a[0]+a[2]+a[6]);
		b[2]=(a[1]+a[3]+a[5]);
		b[1]=(a[2]+a[4]);
		b[0]=a[3];
		//printf("Length = %lld\n",i);
		rep(j,0,10)
		{
			b[j]%=MOD;
			a[j]=b[j];
			//printf("%lld = %lld\n",j,a[j]);
		}
	}
	
	ll ans=0;
	rep(i,0,10)
	{
		//printf("%lld %lld\n",i,a[i]);
		ans+=a[i]; ans%=MOD;
		//printf("%lld\n",ans);
	}
	prll(ans);
	return 0;
}