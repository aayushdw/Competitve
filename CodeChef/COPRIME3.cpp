#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1000000 + 5

int n, maxai, i, ai, a[maxn], p[maxn], dp[maxn], j;
long long ret=0, kol, ret1=0;

int main () {
	
	// Input reading
	
	scanf("%d", &n);
	maxai = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d", &ai);
		++a[ai];
		maxai = max(maxai, ai);
	}
	
	// Mobius function calculation
	
	for(i = 2; i <= maxai; i++) if (!p[i]) { 
		j = i;
		while (j <= maxai) {
			if (!p[j]) p[j] = i;
			j += i;			
		}
	}
	
	// Calculation M(X) * C(D(X), 3), for all X where this expression is nonzero
	
	for(i = 1; i <= maxai; i++) {
		
		// Mobuis function
		
		if (i == 1) dp[i] = 1; else {
			if (p[i / p[i]] == p[i]) dp[i] = 0; else // Checking for non square-free
			dp[i] = -1 * dp[i / p[i]];
		}
		if (!dp[i]) continue;
		
		// Calculating D(X). Can be done naively, because [N/1] + [N/2] + [N/3] + ... + [N/N] -> N log N
		
		j = i; kol = 0;
		while (j <= maxai) {
			kol += a[j];
			j += i;			
		}
		
		// Adding the number of the combinations to the final answer
		
		ret += kol * (kol - 1) * (kol - 2) * dp[i];
		ret1 += kol *(kol-1) *dp[i];
	}
	cout << ret << endl;
	cout << ret1;
    return 0;
}