#include<stdio.h>
#define MAX 338400
#define ll long long int
ll a[MAX][101]={0}, arr[101]={0};
int main(){
	ll i,j,k,sum=0;
	a[0][0]=1;
	for(i=1;i<=100;i++)
	arr[i]=i*i;
	for(i=1;i<=100;i++)
	for(j=MAX-arr[i]-1;j>=0;j--)
	for(k=0;k<100;k++)
	a[j+arr[i]][k+1]+=a[j][k];
	for(i=1;i<MAX;i++)
	if(a[i][50]==1)
	sum+=i;
	printf("%lld",sum);
}
