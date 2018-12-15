#include<stdio.h>
#define MAX 2000
#define MOD 1000000
#define ll long long int
ll arr[MAX][MAX],a[MAX*MAX];
ll max(ll a,ll b) {
	return a>b?a:b;
}
void generate()
{
	ll num,i;
	for(i=1;i<56;i++)
	{
		num=100003 - 200003*i + 300007*i*i*i;
		num%=MOD;
		num-=500000;
		arr[i/MAX][(i-1)%MAX]=num;
		a[i]=num;
	}
	for(;i<=MAX*MAX;i++)
	{
		a[i]=a[i-24]+a[i-55]+MOD;
		a[i]%=MOD;
		a[i]-=500000;
		arr[i/MAX][(i-1)%MAX]=a[i];
	}
	return;
}
ll kadane(ll a[], ll size)
{
    ll max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main()
{
	generate();
	//printf("%lld %lld\n",a[10],a[100]);
	ll v[MAX],sz=0,i,j,m=0;
	for(i=0;i<MAX;i++)
	{
		sz=0;
		for(j=0;j<MAX;j++)
		v[sz++]=arr[i][j];
		m=max(m,kadane(v,sz));
		sz=0;
		for(j=0;i-j>=0;j++)
		v[sz++]=arr[i-j][j];
		m=max(m,kadane(v,sz));
	}
	for(j=0;j<MAX;j++)
	{
		sz=0;
		for(i=0;i<MAX;i++)
		v[sz++]=arr[i][j];
		m=max(m,kadane(v,sz));
		sz=0;
		for(i=0;i+j<MAX;i++)
		v[sz++]=arr[i][i+j];
		m=max(m,kadane(v,sz));
	}
	for(i=0;i<MAX;i++)
	{
		sz=0;
		for(j=MAX-1;i+sz<MAX;j--)
		v[sz++]=arr[i+sz][j];
		m=max(m,kadane(v,sz));
	}
	for(j=0;j<MAX;j++)
	{
		sz=0;
		for(i=MAX-1;j-sz>=0;i--)
		v[sz++]=arr[i][j-sz];
		m=max(m,kadane(v,sz));
	}
	printf("%lld",m);
}











