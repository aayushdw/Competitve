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
#define MAX 10000001
// #define MAX 10001
using namespace std;

vi primeFactors[MAX];
int cur[MAX];
int ans[MAX];

void factorize()
{
	rep(i,0,MAX)
		cur[i] = i;
	for(int i=2;i*i<MAX;i++)
	{
		if(!primeFactors[i].empty())
			continue;
		for(int j=i;j<MAX;j+=i)
		{
			ll temp = 1;
			while(cur[j]%i==0)
			{
				cur[j] /= i;
				temp *= i;
			}
			primeFactors[j].pb(temp);
		}
	}
	rep(i,2,MAX)
		if(cur[i]!=1)
			primeFactors[i].pb(cur[i]);

	// rep(i,2,MAX)
	// {
	// 	printf("%d: ",i);
	// 	rep(j,0,primeFactors[i].size())
	// 		printf("%d ",primeFactors[i][j]);
	// 	printf("\n");
	// }

}

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive caint
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // caint
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
    }
}


int foo(int mask,int bits,int n)
{
	int u = 1,v = 1;
	rep(i,0,bits)
		if(ison(mask,i))
			u *= primeFactors[n][i];
		else
			v *= primeFactors[n][i];
	// printf("%d = %d * %d , gcd = %d\n",n,u,v,__gcd(u,v));
	if(v-2<0)	return 0;
	int w = modInverse(u,v);
	// printf("u=%d , v=%d , n=%d , w=%d\n",u,v,n,w);
	return u*w;
}

void solve()
{
	rep(i,2,MAX)
	{
		ans[i] = 1;
		int n = primeFactors[i].size();
		if(n==1) continue;
		rep(j,0,1<<n)
			ans[i] = max(ans[i],foo(j,n,i));
	}

	ll ret = 0;

	rep(i,2,MAX)
	{
		ret += ans[i];
		// printf("M(%d) = %d\n",i,ans[i]);
	}
	prll(ret);
	return;
}

int main()
{
	factorize();
	solve();
	return 0;
}