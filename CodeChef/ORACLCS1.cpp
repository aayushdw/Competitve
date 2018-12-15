#include<stdio.h>
#include<strings.h>
#include<limits.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int t,n,m,count_a=0,count_b=0,i,j;
	sc(t);
	char s[101];
	while(t--)
	{
		sc(n);
		int a=INT_MAX,b=INT_MAX;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			count_a=0; count_b=0;
			while(s[count_a+count_b]!=0)
			{
				if(s[count_a+count_b]=='a')
				count_a++;
				else
				count_b++;
			}
			if(a>count_a)
			a=count_a;
			if(b>count_b)
			b=count_b;
		}
		printf("%d\n",a<b?a:b);
	}
	return 0;
}
