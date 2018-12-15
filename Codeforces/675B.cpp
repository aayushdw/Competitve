#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld\n",x)
#define ll long long int
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	ll a,b,c,d,n,p,q,r,s,mi,ma,diff,m;
	sc(n); sc(a); sc(b); sc(c); sc(d);
	p=a>b?a-b:b-a;
	q=a>c?a-c:c-a;
	r=c>d?c-d:d-c;
	s=b>d?b-d:d-b;
	mi=min(p,min(q,min(r,s)));
	ma=max(p,max(q,max(r,s)));
	diff=ma-mi;
	pr(ma); pr(mi);
	pr(diff);
	m=n-diff;
	//pr(diff);
	if(m<0)
	pr(0);
	else
	pr(m*n);
}
