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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 300000+5
using namespace std;

ll a[MAX],b[MAX],c[MAX];
map<ll,ll> smax;
map<ll,ll> smin;
typeof(smax.begin()) it;

int main()
{
	clr(a); clr(b); clr(c);
	ll n;
	sl(n);
	rep(i,0,3*n)
	sl(a[i]);
	ll sum=0;
	rep(i,0,n)
	{
		it=smax.find(a[i]);
		sum+=a[i];
		if(it==smax.end())
			smax.insert(mp(a[i],1ll));
		else
			it->S++;
	}
	b[n-1]=sum;
	rep(i,n,2*n)
	{
		it=smax.begin();
		if(it->F > a[i])
		{
			b[i]=sum;
			continue;
		}

		sum -= it->F;
		if(it->S==1)
			smax.erase(it);
		else
			it->S--;

		it=smax.find(a[i]);
		sum+=a[i];
		if(it==smax.end())
			smax.insert(mp(a[i],1ll));
		else
			it->S++;

		b[i]=sum;
	}

	reverse(a,a+3*n);
	sum=0;

	rep(i,0,n)
	{
		it=smin.find(a[i]);
		if(it==smin.end())
			smin.insert(mp(a[i],1ll));
		else
			it->S++;
		sum+=a[i];
	}

	c[n-1]=sum;
	rep(i,n,2*n)
	{
		it=smin.end();
		it--;
		if(it->F < a[i])
		{
			c[i]=sum;
			continue;
		}


		sum -= it->F;
		if(it->S==1)
			smin.erase(it);
		else
			it->S--;


		it=smin.find(a[i]);
		sum+=a[i];
		if(it==smin.end())
			smin.insert(mp(a[i],1ll));
		else
			it->S++;

		c[i]=sum;
	}

	//return 0;

	reverse(c,c+3*n);
	ll ans=-INF;
	rep(i,n-1,2*n)
		ans=max(ans,b[i]-c[i+1]);
	
	prll(ans);

	/*rep(i,0,3*n)
	printf("%3lld",b[i]);
	printf("\n");
	rep(i,0,3*n)
	printf("%3lld",c[i]);*/
	return 0;
}