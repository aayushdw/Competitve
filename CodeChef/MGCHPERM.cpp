#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
#define MAX 1000005
ll MOD=1000000007;
 
ll arr[MAX][8]={0},C[MAX][8]={0},arr1[MAX][8]={0};
 
ll min(ll a,ll b)
{
	return a<b?a:b;
}
 
void pre()
{
	ll i,p,j;
	for(i=0;i<MAX;i++)
	arr[i][1]=i;
	for(i=2;i<8;i++)
	{
		p=i*(i+1)/2;
		for(j=p;j<p+i;j++)
		{
			arr[j][i]=arr[j-i][i-1];
			arr1[j][i]=(arr1[j-1][i]+arr[j][i])%MOD;
		}
		for(j=p+i;j<MAX;j++)
		{
			arr[j][i]=arr[j-i][i]+arr[j-i][i-1];
			arr[j][i]%=MOD;
			arr1[j][i]=(arr1[j-1][i]+arr[j][i])%MOD;
		}
	}
	return;
}
 
void binomialCoeff()
{
    ll i, j,k=8;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j]%=MOD;
        }
    }
 
}
 
int main()
{
	ll t,n,k,i,res,p,count,j;
	pre();
	binomialCoeff();
	for(i=1;i<7;i++)
	{
		for(j=1;j<25;j++)
		printf("%2lld ",arr[j][i]);
		printf("\n");
	}
	return 0;
	sc(t);
	while(t--)
	{
		sc(n); sc(k); count=0;
		/*printf("%lld\n",C[n][k]);
		continue;*/
		count=arr1[n][k-1];
		p=C[n+1][k];
		res=p-count;
		if(res<0)
		res+=MOD;
		printf("%lld\n",res);
	}
	return 0;
} 
