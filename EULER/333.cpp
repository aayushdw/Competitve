#include <bits/stdc++.h>
 
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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 1000000ll
using namespace std;

ll p2[25],p3[25];
ll c[MAX]={0};
bool t[MAX]={1,1,0};

void pre()
{
	p2[0] = 1; p3[0] = 1;
	rep(i,1,25)
	p2[i] = p2[i-1]*2, p3[i] = p3[i-1]*3;
}

void seive()
{
	ll i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}

void foo(ll i,ll j,ll s)
{
	ll x = p2[i]*p3[j];
	if(s+x>=MAX)
		return;
	c[s+x]++;
	rep(_i,0,i)
		rep(_j,j+1,15)
			foo(_i,_j,s+x);
}

int main()
{
	pre();
	rep(i,0,24)
	rep(j,0,15)
		foo(i,j,0);
	seive();
	ll ans=0;
	rep(i,0,MAX)
		if(!t[i] && c[i]==1)
		{
			ans += i;
			// printf("%lld %lld\n",i,c[i]);
		}
	prll(ans);
	return 0;
}