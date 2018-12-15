#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 180000000
#define scll(t) scanf("%lld",&t)
#define sc(t) scanf("%d",&t)
#define plld(t) printf("%lld\n",t)
int store[MAX]={0};
int sievephi[MAX];
 
void precalc(){
	for(int i=1;i<=MAX;i++)
		sievephi[i]=i;
		
	for(int i=2;i<=MAX;i+=2)
		sievephi[i]-=sievephi[i]/2;
 
	for(int i=3;i<=MAX;i+=2)
		if(sievephi[i]==i)
			for(int j=i;j<=MAX;j+=i)
				sievephi[j]-=sievephi[j]/i;
				
}

int main()
{
	precalc();
	//return 0;
	int k;
	for(int i=1;i<MAX;i++)
	{
		k=sievephi[i];
		if(!store[k])
			store[k]=i;
	}
	int t,n;
	sc(t);
	while(t--)
	{
		sc(n);
		if(store[n])
			printf("%d\n",store[n]);
		else
			printf("-1\n");
	}
	return 0;
} 