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
#define MAX 100000+5
using namespace std;

// This is the famous "Yarin sieve", for use when memory is tight.
#define MAXSIEVE 1000000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 15813 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void sieve()
{
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
	if (a[i>>3]&(1<<(i&7)))
	for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
	a[j>>3]&=~(1<<(j&7));
}

int main()
{
	sieve();
	return 0;
}