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
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

string c;
vl v;

pll poo(ll l)
{
	ll x=l/2+1,y=(l+1)/2;
	pll ret;
	ret.F=x*(x-1)/2+y*(y-1)/2;
	ret.S=x*y;
	return ret;
}

pll foo()
{
	pll ret;
	vl x[2];
	x[0].resize(v.size());
	x[1].resize(v.size());
	ll a[2]={0},b[2]={0},curr=0;
	rep(i,0,v.size())
	{
		if(i%2==0)
		{
			x[0^curr][i]=v[i]/2;
			x[1^curr][i]=(v[i]+1)/2;
			b[0^curr]+=v[i]/2;
			b[1^curr]+=(v[i]+1)/2;
		}
		curr^=(v[i]%2);
	}

	rep(i,0,v.size())
	{
		b[0]-=x[0][i];
		b[1]-=x[1][i];
		a[1]+=x[0][i]*b[0]+x[1][i]*b[1];
		a[0]+=x[0][i]*b[1]+x[1][i]*b[0];
		i++;
	}

	ret.F=a[0]; ret.S=a[1];
	return ret;
}

int main()
{
	ll l=1,even=0,odd=0,ans[2]={0};
	cin>>c;
	rep(i,1,c.length())
	if(c[i]!=c[i-1])
	{
		v.pb(l);
		l=1;
	}
	else
		l++;
	v.pb(l);

	pll x,y,z;

	rep(i,0,v.size())
	{
		x=poo(v[i]);
		z.F+=x.F;
		z.S+=x.S;
	}

	x=foo();
	v.erase(v.begin());
	y=foo();


	printf("%lld %lld",x.F+y.F+z.F,x.S+y.S+z.S);
	return 0;
}