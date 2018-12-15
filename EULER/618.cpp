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
#define MAX 10
using namespace std;

bitset<MAX> t;
vi primes;
int S[MAX]={0};

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
	rep(i,2,MAX)
		if(!t[i])
			primes.pb(i);
}

int main()
{
	sieve();
	clr(S);
	rep(i,2,MAX)
	{
		if(!t[i])
			S[i] = i;
		for(int j=0;primes[j]<=i;j++)
			S[i] += S[i-primes[j]]*primes[j];
	}
	rep(i,0,MAX)
		printf("%3d : %d\n",i,S[i]);
	return 0;
}