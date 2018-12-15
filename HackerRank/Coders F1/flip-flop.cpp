#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define MAX 100000+5
int main()
{
	int t,i,count;
	char s[MAX],p;
	sc(t);
	while(t--)
	{
		getchar();
		scanf("%s",s); count=0;
		p=s[0]; i=1;
		while(s[i]!='\0')
		{
			while(s[i]==p)
			{
				count++;
				i++;
			}
			if(s[i]=='\0')
			break;
			p=s[i];
			i++;
		}
		printf("%d\n",count);
	}
	return 0;
}
