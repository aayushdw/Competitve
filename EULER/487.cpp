// References : 
// 	http://129.81.170.14/~vhm/sum-powers.pdf
// 	http://dc.lib.unc.edu/cgi-bin/showfile.exe?CISOROOT=/jncas&CISOPTR=3514
// 	https://upload.wikimedia.org/wikipedia/commons/2/22/Sums_of_powers_of_positive_integers_and_their_recurrence_relations.pdf
//	https://gowers.wordpress.com/2014/11/04/sums-of-kth-powers/

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
 
#define MOD 1000000007ll
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

// PARAMETERS:
#define NUM 1000000000000ll
#define POW 10000ll

// #define NUM 5ll
// #define POW 3ll

ll s[POW+1];

template <typename T>
T powmod(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

ll invMod(ll num,ll mod)
{
	return powmod(num,mod-2,mod);
}

ll _solve(ll mod)
{
	s[0] = NUM % mod;
	rep(i,1,POW+1)
	{
		ll mul = 1;
		s[i] = (powmod(NUM+1,i+1,mod)-1+mod)%mod;
		// printf("s[%lld] = %lld\n" , i,s[i]);
		rep(j,0,i)
		{
			// printf("mul = %lld\n",mul);
			s[i] -= (mul * s[j]) % mod;
			s[i] %= mod;
			mul = (mul * (i+1-j)) % mod;
			mul = (mul * invMod(j+1,mod)) % mod;
		}
		// printf("s[%lld] = %lld\n" , i,s[i]);
		s[i] = (s[i] + mod) % mod;
		s[i] *= invMod(i+1,mod);
		s[i] %= mod;
		// printf("%lld %lld\n" ,i,s[i]);
	}
	// rep(i,0,POW+1)
	// {
	// 	printf("%lld %lld\n" ,i,s[i]);
	// }
	return s[POW];
}

void solve()
{
	ll numPrimes;
	sl(numPrimes);
	ll ans = 0;
	while(numPrimes--)
	{
		ll prime;
		sl(prime);
		ans += _solve(prime);
		prll(numPrimes);
	}
	prll(ans);
	return;
}

int main()
{
	solve();
	return 0;
}