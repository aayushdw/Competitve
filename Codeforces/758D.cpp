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
#define INF 10000000000000000
#define MAX 100
using namespace std;
char s[MAX];
ll a[MAX];
ll check(ll x,ll y, ll n)
{
	if(a[x]==0)
		return 0;
	ll ret=0;
	rep(i,x,y+1)
	{
		ret*=10;
		ret+=a[i];

	}
	if(ret>=n)
		return INF;
	return ret;
}

ll power(ll a,ll b)
{
	ll ret=1;
	while(b--)
		ret*=a;
	return ret;
}

int main()
{
	ll n;
	sl(n);
	scanf("%s",s);
	ll len=strlen(s);
	rep(i,0,len)
	a[i]=s[i]-'0';
	ll curr=len-1;
	ll p=0,ans=0,ri;
	while(curr>=0)
	{
		//printf("FOR : %lld\n",p);
		ll i=0;
		ll num=-1;
		while(check(curr-i,curr,n)<INF && curr-i>=0)
		{
			if(num<check(curr-i,curr,n))
			{
				ri=i;
				num=check(curr-i,curr,n);
			}
			i++;
			//printf("Candidate: %lld\n",num);
		}
		i--;
		//printf("num = %lld\n",num);
		ans+=num*power(n,p);
		p++;
		i=ri;
		curr=curr-i-1;
		//prll(curr);
	}
	printf("%lld",ans);
	return 0;
}