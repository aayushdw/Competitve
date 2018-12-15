#include<bits/stdc++.h>
#define scll(x) scanf("%lld",&x)
typedef long long int ll;
using namespace std;
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        ll res = (x%m + m) % m;
        return res;
    }
}



int main()
{
	ll x,y;
	while(1)
	{
		scll(x); scll(y);
		printf("%lld\n",modInverse(x,y));
	}
}
