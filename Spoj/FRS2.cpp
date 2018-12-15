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
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
void multiply(ll F[2][2],ll M[2][2],ll m)
{
  ll x=(F[0][0]*M[0][0] + F[0][1]*M[1][0])%m;
  ll y=(F[0][0]*M[0][1] + F[0][1]*M[1][1])%m;
  ll z=(F[1][0]*M[0][0] + F[1][1]*M[1][0])%m;
  ll w=(F[1][0]*M[0][1] + F[1][1]*M[1][1])%m;
  F[0][0]=x;
  F[0][1]=y;
  F[1][0]=z;
  F[1][1]=w;
}

void power(ll F[2][2],ll n,ll m)
{
  if(n==0 || n==1)
  return;
  ll M[2][2] = {{1,1},{1,0}};
  power(F,n/2,m);
  multiply(F,F,m);
  if(n%2!=0)
  multiply(F,M,m);
}

ll cal_fib(ll n,ll m)
{
  ll F[2][2] = {{1,1},{1,0}};
  if(n==0)
  return 0;
  power(F,n-1,m);
  return F[0][0];
}

ll getMod(char s[], ll mod)
{
	ll l=strlen(s),num=0,p;
	rep(i,0,l)
	{
		p=s[i]-'0';
		num*=10;
		num+=p;
		num%=mod;
	}
	return num;
}

int main()
{
	ll t,n;
	char s[105];
	scll(t);
	while(t--)
	{
		scanf("%s",s);
		n=getMod(s,329616);
		n=cal_fib(n,2000000016);
		n=cal_fib(n,1000000007);
		printf("%lld\n",n);
	}
	return 0;
}