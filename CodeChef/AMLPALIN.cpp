#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
int main()
{
	int t,n,i,x;
	char s[5];
	sc(t);
	while(t--)
	{
		int a[4]={0};
		sc(n); getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(s[0]=='a'&&s[1]=='a')
			a[0]++;
			if(s[0]=='a'&&s[1]=='b')
			a[1]++;
			if(s[0]=='b'&&s[1]=='a')
			a[2]++;
			if(s[0]=='b'&&s[1]=='b')
			a[3]++;
		}
		x=a[1]<a[2]?a[1]:a[2];
		if(a[3]==0&&x==0)
		{
			for(i=0;i<a[0];i++)
			printf("aa");
			printf("\n");
			continue;
		}
		if(a[0]%2==0)
		{
			for(i=0;i<a[0]/2;i++)
			printf("aa");
			for(i=0;i<x;i++)
			printf("ab");
			for(i=0;i<a[3];i++)
			printf("bb");
			for(i=0;i<x;i++)
			printf("ba");
			for(i=0;i<a[0]/2;i++)
			printf("aa");
		}
		else
		{
			if(a[3]%2==0)
			{
				for(i=0;i<a[0]/2;i++)
				printf("aa");
				for(i=0;i<x;i++)
				printf("ab");
				for(i=0;i<a[3]/2;i++)
				printf("bb");
				printf("aa");
				for(i=0;i<a[3]/2;i++)
				printf("bb");
				for(i=0;i<x;i++)
				printf("ba");
				for(i=0;i<a[0]/2;i++)
				printf("aa");
			}
			else
			{
				for(i=0;i<a[0]/2;i++)
				printf("aa");
				for(i=0;i<x;i++)
				printf("ab");
				for(i=0;i<a[3]/2;i++)
				printf("bb");
				printf("aa");
				for(i=0;i<a[3]/2;i++)
				printf("bb");
				for(i=0;i<x;i++)
				printf("ba");
				for(i=0;i<a[0]/2;i++)
				printf("aa");
			}
		}
		printf("\n");
	}
	return 0;
}
