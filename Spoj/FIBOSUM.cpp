#include<stdio.h>
#define LL long long
#define MOD 1000000007
#define sc(x) scanf("%lld",&x)
void multiply(LL F[2][2],LL M[2][2],LL m)
{
  LL x=(F[0][0]*M[0][0] + F[0][1]*M[1][0])%m;
  LL y=(F[0][0]*M[0][1] + F[0][1]*M[1][1])%m;
  LL z=(F[1][0]*M[0][0] + F[1][1]*M[1][0])%m;
  LL w=(F[1][0]*M[0][1] + F[1][1]*M[1][1])%m;
  F[0][0]=x;
  F[0][1]=y;
  F[1][0]=z;
  F[1][1]=w;
}
 
void power(LL F[2][2],LL n,LL m)
{
  if(n==0 || n==1)
  return;
  LL M[2][2] = {{1,1},{1,0}};
  power(F,n/2,m);
  multiply(F,F,m);
  if(n%2!=0)
  multiply(F,M,m);
}
 
LL cal_fib(LL n,LL m)
{
  LL F[2][2] = {{1,1},{1,0}};
  if(n==0)
  return 0;
  power(F,n-1,m);
  return F[0][0];
}
int main()
{
	LL t,m,n,k;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		k=cal_fib(m+2,MOD)-cal_fib(n+1,MOD);
		k+=MOD;
		k%=MOD;
		printf("%lld\n",k);
	}
	return 0;
}
