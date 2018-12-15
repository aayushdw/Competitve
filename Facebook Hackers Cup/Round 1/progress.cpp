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
#define INF 10000000000000
#define MAX 305
using namespace std;

ll num[MAX];
vl v[MAX];

ll solve(ll n,ll m)
{
	ll ret=0,cost,idx;
	clr(num);
	rep(i,0,n)
	{
		cost=INF;
		rep(j,0,i+1)
		rep(k,num[j],m)
		if(cost>v[j][k]+(num[j]+1)*(num[j]+1)-num[j]*num[j])
		{
			cost=v[j][k]+(num[j]+1)*(num[j]+1)-num[j]*num[j];
			idx=j;
		}
		ret+=cost;
		num[idx]++;
	}
	return ret;
}

int main()
{
	ll t,n,m,p;
	sl(t);
	rep(tt,1,t+1)
	{
		rep(i,0,MAX)
		v[i].clear();
		sl(n); sl(m);
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				sl(p);
				v[i].pb(p);
			}
			sort(all(v[i]));
		}
		printf("Case #%lld: %lld\n",tt,solve(n,m));
	}
	return 0;
}