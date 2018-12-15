#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define ll long long int
int main(){
	ll n,p;
	sc(n);
	p=n*(n-1)*(n-2)*(n-3)*(n-4);
	p/=120;
	p*=n*(n-1)*(n-2)*(n-3)*(n-4);
	pr(p);
	return 0;
}
