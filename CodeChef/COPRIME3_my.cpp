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

#define MOD 359999
#define INF 10000000000000000
#define MAX 1000000+5
#define MAXN 1000000+5
#define M 1000000007
using namespace std;

ll p[MAXN],arr[1005],a[MAXN],dp[MAXN];

void mobius()
{
	ll j;
	rep(i,2,MAXN)
	{
		j=i;
		while(j<MAXN)
		{
			if(!p[j])
				p[j]=i;
			j+=i;
		}
	}

	dp[1]=1;
	rep(i,2,MAXN)
	if(p[i/p[i]]==p[i])
		dp[i]=0;
	else
		dp[i]=-1*dp[i/p[i]];
}

int main()
{
	mobius();
	ll p,n,k,three=0;
	sl(n);
	memset(a,0,sizeof(a));
	rep(i,0,n)
	{
		sl(p);
		a[p]++;
	}

	rep(i,1,MAXN)
		{
			if(!dp[i])
				continue;

			k=i;
			p=0;
			while(k<MAXN)
			{
				p+=a[k];
				k+=i;
			}
			three+=p*(p-1)*(p-2)*dp[i]/6;
		}

	prll(three);
}