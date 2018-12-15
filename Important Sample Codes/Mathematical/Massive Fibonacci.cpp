#include <map>
#include <iostream>
using namespace std;

typedef long long ll;
const long M = 1000000007; // modulo
map<long, long> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main(){
	ll n;
	F[0]=F[1]=1;
	while (cin >> n)
	cout << (n==0 ? 0 : f(n-1)) << endl;
}
