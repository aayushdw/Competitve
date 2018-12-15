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
#define MAX 20000000
using namespace std;

vi a[10];
int d[10][10];
int p[10];

bitset<MAX> t;

void sieve()
{
	t.reset();
	t[0] = t[1] = true;
	t[2] = false;
	for(int i=4;i<MAX;i+=2)
		t[i] = true;
	for(int i=3;i*i<MAX;i+=2)
	{
		if(t[i])	continue;
		for(int j=i+i+i;j<MAX;j+=i+i)
			t[j] = true;
	}
}

void initialize()
{
	a[0] = {1,1,1,0,1,1,1};
	a[1] = {0,0,1,0,0,0,1};
	a[2] = {0,1,1,1,1,1,0};
	a[3] = {0,1,1,1,0,1,1};
	a[4] = {1,0,1,1,0,0,1};
	a[5] = {1,1,0,1,0,1,1};
	a[6] = {1,1,0,1,1,1,1};
	a[7] = {1,1,1,0,0,0,1};
	a[8] = {1,1,1,1,1,1,1};
	a[9] = {1,1,1,1,0,1,1};

	rep(i,0,10)
		rep(j,0,7)
			p[i] += a[i][j];

	rep(i,0,10)
		rep(j,0,10)
			rep(k,0,10)
				d[i][j] += a[i][k] != a[j][k];

	return;

}

int foo(int a,int b)
{
	int ret = 0;
	while(a||b)
	{
		if(a&&b)
			ret += d[a%10][b%10];
		else if(a)
			ret += p[a%10];
		else
			ret += p[b%10];
		a/=10;
		b/=10;
		// pr(ret);
	}
	return ret;
}

int _start(int a)
{
	int ret = 0;
	while(a)
	{
		ret += p[a%10];
		a /= 10;
	}
	return ret;
}

ll solve(vi v)
{
	ll x = _start(v[0]), y = 2*_start(v[0]);
	// prll(x); prll(y);
	rep(i,1,v.size())
	{
		x += foo(v[i],v[i-1]);
		y += 2*_start(v[i]);
		// prll(x); prll(y);
	}
	x += _start(v.back());
	// prll(x); prll(y);
	// // prll(y-x);
	// rep(i,0,v.size())
	// 	pr(v[i]);
	// if(y-x<0)
		// cout<<"ERROR"<<endl;
	return y-x;
}

int digitSum(int n)
{
	int ret = 0;
	while(n)
	{
		ret += n%10;
		n /= 10;
	}
	return ret;
}

int main()
{
	initialize();
	sieve();
	vi v;
	ll ans = 0;
	rep(i,10000000,20000000)
		if(!t[i])
		{
			int temp = i;
			v.clear();
			v.pb(temp);
			while(digitSum(temp)!=temp)
			{
				temp = digitSum(temp);
				v.pb(temp);
			}
			ans += solve(v);
		}
	prll(ans);
	// pr(foo(5,131));
	return 0;
}