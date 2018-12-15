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

bool between(int a,int b, int x, int y)
{
	if(a<b)
		swap(a,b);
	if(x<y)
		swap(x,y);
	return ( a>=x && b<=y );
}

bool same_dir(int a,int b,int x,int y)
{
	ll _a = a;
	ll _b = b;
	ll _x = x;
	ll _y = y;
	return (_a-_b)*(_x-_y)>=0;
}

vi calc(int start,int end, vi &a, vi &b)
{
	vi ret;
	rep(i,0,a.size())
	{
		if( between(start,end,a[i],b[i]) && same_dir(start,end,a[i],b[i]) )
			ret.pb(i);
	}
	return ret;
}

int _merge(vi &a,vi &b)
{
	set<int> s;
	rep(i,0,a.size())
		s.insert(a[i]);
	rep(i,0,b.size())
		s.insert(b[i]);
	return (int)s.size();
}

int main()
{
	int n,e1,e2;
	si(n); si(e1); si(e2);
	vi a(n,0), b(n,0);
	rep(i,0,n)
	{
		si(a[i]); si(b[i]);
	}

	int ans = 0;

	{
		int st1 = e1, en1 = n;
		int st2 = e2, en2 = n;
		vi v1 = calc(st1,en1,a,b);
		vi v2 = calc(st2,en2,a,b);
		int v = _merge(v1,v2);
		//return 0;
		// pr(v);

		// printf("State: %d %d %d %d\n",st1,en1,st2,en2);
		// rep(i,0,v1.size())
		// 	printf("%d ",v1[i]);
		// printf("\n");
		// rep(i,0,v2.size())
		// 	printf("%d ",v2[i]);
		// printf("\n");

		ans = max(ans,v);
	}
	// return 0;
	{
		int st1 = e1, en1 = 1;
		int st2 = e2, en2 = n;
		vi v1 = calc(st1,en1,a,b);
		vi v2 = calc(st2,en2,a,b);
		int v = _merge(v1,v2);
		// pr(v);
		ans = max(ans,v);
	}

	{
		int st1 = e1, en1 = n;
		int st2 = e2, en2 = 1;
		vi v1 = calc(st1,en1,a,b);
		vi v2 = calc(st2,en2,a,b);
		int v = _merge(v1,v2);
		// pr(v);
		ans = max(ans,v);
	}

	{
		int st1 = e1, en1 = 1;
		int st2 = e2, en2 = 1;
		vi v1 = calc(st1,en1,a,b);
		vi v2 = calc(st2,en2,a,b);
		int v = _merge(v1,v2);
		// pr(v);
		ans = max(ans,v);
	}

	pr(ans);

	return 0;
}