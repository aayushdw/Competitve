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
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

map<ll, pll > m;
typeof(m.begin()) it;

void pre(ll n)
{
	if(n==1 || n==0)
	{
		m.insert(mp(1ll,mp(1ll,1ll)));
		return;
	}
	pre(n/2);
	it=m.find(n/2);
	m.insert(mp(n,mp(2*(it->S.F)+1 , 2*(it->S.S)+n%2)));
}

ll foo(ll n,ll x)
{
	if(x<=0 || n==0)
	{
		return 0;
	}
	else if(n==1)
		return 1;
	it=m.find(n/2);
	ll len=it->S.F;
	if(x<=len)
		return foo(n/2,x);
	else if(x==len+1)
		return it->S.S+n%2;
	else
		return it->S.S+n%2+foo(n/2,x-len-1);
}

int main()
{
	ll n,r,l;
	sl(n); sl(l); sl(r);
	pre(n);
	ll ans=foo(n,r)-foo(n,l-1);
	prll(ans);
	return 0;
}