#include<stdio.h>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define ll long long int
ll C[801][10];
ll min(ll a,ll b)
{	return a<b?a:b;	}
void pre()
{
	ll i,j,k;
	for (i = 0; i <= 800; i++)
    {
        for (j = 0; j <= min(i, 8); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
int main()
{
	pre();
	ll n,p;
	sc(n);
	p=C[n][5]+C[n][6]+C[n][7];
	pr(p);
	return 0;
}
