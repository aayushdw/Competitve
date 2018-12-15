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
#define lb lower_bound
#define ub upper_bound
 
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
#define MAX 100000+5
using namespace std;

vl L,R,Lcum,Rcum,Lsum,Rsum;
ll tot;

ll bin(ll key, vl &v)
{
	if(v[0] > key)
	return -1;
	ll low = 0, high = v.size()-1;
	while(low+1<high)
	{
		ll mid = (low+high)>>1;
		if(v[mid]>key)
			high = mid-1;
		else
			low = mid;
	}
	if(v[high]<=key)
		return high;
	else
		return low;
}

ll foo(ll key, vl &V, vl &Vsum)
{
	ll idx = bin(key,V);
	return Vsum[idx] + idx*(key-V[idx]);
}

ll query(ll k)
{
	if(k>tot) return 0;
	k = tot-k;
	ll low = 0, high = MOD;
	while(low+1<high)
	{
		ll mid = (low+high)>>1;
		if(foo(mid,L,Lsum)-foo(mid,R,Rsum)>k)
			high = mid;
		else
			low = mid;
	}
	if(foo(high,L,Lsum)-foo(high,R,Rsum)<k)
		return high;
	else
		return low;
}

void pre( vl &l, vl &r )
{
	L = l, R = r;
	tot = 0;
	sort(all(L)); sort(all(R));
	rep(i,1,R.size())
		R[i]++;
	Lcum = L, Rcum = R;
	Lsum = L, Rsum = R;
	rep(i,1,Lcum.size())
	{
		Lcum[i] = Lcum[i-1] + Lcum[i];
		Rcum[i] = Rcum[i-1] + Rcum[i];
		Lsum[i] = (i-1)*(L[i]-L[i-1]) + Lsum[i-1];
		Rsum[i] = (i-1)*(R[i]-R[i-1]) + Rsum[i-1];
		tot += R[i]-L[i];
	}
}

void print(vl &v)
{
	rep(i,0,v.size())
		printf("%lld ",v[i]);
	printf("\n");
}

void solve()
{
	ll n,q;
	sl(n); sl(q);
	vl x(n+1), y(n+1), z(q+1), a(4), b(4), c(4), m(4), l(n+1), r(n+1), k(q+1);
	
	cin >> x[1] >> x[2] >> a[1] >> b[1] >> c[1] >> m[1];
	cin >> y[1] >> y[2] >> a[2] >> b[2] >> c[2] >> m[2];
	cin >> z[1] >> z[2] >> a[3] >> b[3] >> c[3] >> m[3];

	rep(i,3,n+1)
	{
		x[i] = ( a[1]*x[i-1] + b[1]*x[i-2] + c[1] ) % m[1];
		y[i] = ( a[2]*y[i-1] + b[2]*y[i-2] + c[2] ) % m[2];
		
	}
	rep(i,3,q+1)
		z[i] = ( a[3]*z[i-1] + b[3]*z[i-2] + c[3] ) % m[3];
	rep(i,1,n+1)
	{
		l[i] = min(x[i],y[i]) + 1;
		r[i] = max(x[i],y[i]) + 1;
	}

	pre(l,r);
	
	ll ans = 0;

	rep(i,1,q+1)
	{
		k[i] = z[i] + 1;
		ans += i*query(k[i]);
	}
	prll(ans);
}

int main()
{
	ll t;
	sl(t);
	rep(i,1,t+1)
	{
		printf("Case #%lld: ",i);
		solve();
	}
	return 0;
}