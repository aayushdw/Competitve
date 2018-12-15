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
#define MAX 10000000
using namespace std;

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

vector< pair< ii,int > > E;

int main()
{
	sieve();
	int n,m;
	si(n); si(m);

	if(n==2)
	{
		printf("2 2\n1 2 2\n");
		return 0;
	}

	int curSum = 0;
	if(n%2==0)	//CHECK
	{
		// g[1].pb(mp(n,2))
		curSum = 2;
		E.pb(mp(mp(1,n),2));
		printf("2 ");
	}
	else
	{
		// g[1].pb(mp(n,3));
		curSum = 3;
		E.pb(mp(mp(1,n),3));
		printf("3 ");
	}
	
	rep(i,3,n)
	{
		// g[1].pb(mp(i,5));
		// g[i].pb(mp(1,5));
		E.pb(mp(mp(1,i),5));
		curSum += 5;
	}

	for(int i=3;;i++)
		if(!t[curSum+i])
		{
			E.pb(mp(mp(1,2),i));
			curSum += i;
			break;
		}
	printf("%d\n",curSum);

	m -= n-1;
	rep(i,2,n+1)
	{
		if(m==0)
			break;
		rep(j,i+1,n+1)
		{
			E.pb(mp(mp(i,j),100000000));
			m--;
			if(m==0)
				break;
		}
		if(m==0)
			break;
	}
	rep(i,0,E.size())
		printf("%d %d %d\n",E[i].F.F,E[i].F.S,E[i].S);
	return 0;
}