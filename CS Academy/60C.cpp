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

int a[42],b[42];

map< ll , vi > m[2];

void getsum(int st,int end,int half)
{
	int n = end-st+1;
	rep(i,0,1<<n)
	{
		ll x = 0;
		rep(j,0,n)
		{
			if(ison(i,j))
			{
				x += a[st+j];
				// c++;
			}
			else
			{
				x -= b[st+j];
				// c--;
			}
		}
		auto it = m[half].find(x);
		if(it==m[half].end())
		{
			vi v;
			v.pb(i);
			m[half].insert(mp(x,v));
		}
		else
			(it->S).push_back(i);
	}
	return;
}

int main()
{
	ll n;
	sl(n);
	rep(i,0,n)
	{
		si(a[i]);
		si(b[i]);
	}
	int p = n/2;
	// Handle n = 1 case

	if(n==1)
	{
		if(a[0]==0)
			pr(0);
		else if(b[0]==0)
			pr(1);
		else
			pr(-1);
		return 0;
	}

	getsum(0,p-1,0);
	getsum(p,n-1,1);


	int h1,h2,diff = INT_MAX;

	tr(it,m[0])
	{
		ll val = it->F;
		vi v1 = it->S;
		auto iter = m[1].find(-val);
		if(iter==m[1].end())
			continue;
		vi v2 = iter->S;
		vii x,y;
		rep(i,0,v1.size())
			x.pb(mp(__builtin_popcount(v1[i]),v1[i]));
		rep(i,0,v2.size())
			y.pb(mp(__builtin_popcount(v2[i]),v2[i]));
		sort(all(x));
		sort(all(y));
		int i = 0 , j = 0;
		return 0;
		while(i<x.size() || j<y.size())
		{
			if( abs(n-2*(x[i].F+y[j].F)) < diff)
				h1 = x[i].S , h2 = y[j].S;
			if(i+1==x.size())
				j++;
			else if(j+1==y.size())
				i++;
			else
			{
				if( abs( n - 2*(x[i+1].F+y[j].F)) < abs( n - 2*(x[i].F+y[j+1].F)) )
					i++;
				else
					j++;
			}
			if(i+1==x.size() && j+1 == y.size())
				break;
		}
		return 0;
		
	}

	
	if(diff==INT_MAX)
		pr(-1);
	else
	{
		rep(i,0,p)
			if(ison(h1,i))
				printf("1 ");
			else
				printf("0 ");
		rep(i,p,n)
			if(ison(h2,i))
				printf("1 ");
			else
				printf("0 ");
	}

	return 0;
}