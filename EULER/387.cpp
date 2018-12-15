#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
using namespace std;
typedef long long int ll;
vector<pair<ll,ll> > vold,vnew;
int T;
ll mod;
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll a[]={1996011519951206ll,1995120619960115ll,1995100319960115ll,195100319951206ll,1996011519951003ll};
 
 
ll multi(ll x,ll y)
{
	ll w=x*y-mod*(ll(double(x)*y/mod+1e-3));
	while(w<0)
		w+=mod;
	while(w>=mod)
		w-=mod;
	return w;
}
 
ll pow(ll x,ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
			t=multi(t,x);
		x=multi(x,x);
		y>>=1;
	}
	return t;
}
 
bool judge(ll n)
{
	if(n==2) return true;
	if(n<2||!(n&1)) return false;
	for(int i=0;i<25;i++)
		if(n%b[i]==0&&n!=b[i])
			return false;
	mod=n;
	int t=0;
	ll u=n-1;
	while(!(u&1)) t++,u>>=1;
	for(int i=0;i<5;i++)
	{
		ll x=a[i]%(n-1)+1;
		x=pow(x,u);
		ll y=x;
		for(int j=1;j<=t;j++)
		{
			x=multi(x,x);
			if(x==1&&y!=1&&y!=n-1)
				return false;
			y=x;
		}
		if(x!=1) return false;
	}
	return true;
}

int main()
{
	ll i,j,sum=0,k;
	for(i=1;i<=9;i++)
	vold.pb(mp(i,i));
	for(i=1;i<17;i++)
	{
		for(j=0;j<vold.size();j++)
		{
			if(!judge(vold[j].first/vold[j].second))
			continue;
			if(judge(vold[j].first*10+1))
			{
				sum+=vold[j].first*10+1;
				//printf("%lld\n",vold[j].first*10+1);
			}
			if(judge(vold[j].first*10+3))
			{
				sum+=vold[j].first*10+3;
				//printf("%lld\n",vold[j].first*10+3);
			}
			if(judge(vold[j].first*10+7))
			{
				sum+=vold[j].first*10+7;
				//printf("%lld\n",vold[j].first*10+7);
			}
			if(judge(vold[j].first*10+9))
			{
				sum+=vold[j].first*10+9;
				//printf("%lld\n",vold[j].first*10+9);
			}
		}
		/*for(j=0;j<vold.size();j++)
		printf("%lld ",vold[j].first);
		printf("\n");*/
		vnew.clear();
		vnew.insert(vnew.end(),vold.begin(),vold.end());
		vold.clear();
		for(j=0;j<vnew.size();j++)
		for(k=0;k<=9;k++)
		if((vnew[j].first*10+k)%(vnew[j].second+k)==0)
		vold.pb(mp(vnew[j].first*10+k,vnew[j].second+k));
	}
	printf("%lld\n",sum);
	return 0;
}
