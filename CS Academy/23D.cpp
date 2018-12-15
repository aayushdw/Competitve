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
 
#define rep(i,x,y) for(int i=x;i<y;i++)
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

int a[MAX],x[MAX][2];
vi v;

ii foo(ii x,ii y)
{
	ii ret;
	ret.F=max(x.F,y.F);
	ret.S=min(x.S,y.S);
	return ret;
}

int main()
{
	int n;
	si(n);
	rep(i,0,n)
	si(a[i]);
	rep(i,1,n)
	v.pb(a[i]-a[i-1]);
	rep(i,0,n)
	{
		si(x[i][0]);
		si(x[i][1]);
	}
	ii lim=mp(x[0][0],x[0][1]);

	int p=1,cur_sum=0;
	rep(i,0,n-1)
	{
		cur_sum+=p*v[i];
		//pr(cur_sum);
		if(p==1)
		{
			ii y=mp(cur_sum-x[i+1][1],cur_sum-x[i+1][0]);
			lim=foo(lim,y);
		}
		else
		{
			ii y=mp(x[i+1][0]+cur_sum,x[i+1][1]+cur_sum);
			lim=foo(lim,y);
		}
		p*=-1;
	}
	pr(max(0,lim.S-lim.F+1));
	return 0;
}