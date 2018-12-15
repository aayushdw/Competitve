#include<stdio.h>
int main()
{
	int t,a[7],i;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=1;i<7;i++)
		{
			scanf("%s",s);
			if(s[0]=='b')
			{
				if(s[2]=='a')
				a[i]=1;
				else if(s[2]=='u')
				a[i]=2;
			}
			else if(s[0]=='r')
			a[i]=3;
			else if(s[0]=='g')
			a[i]=4;
			else if(s[0]=='y')
			a[i]=5;
			else if(s[0]=='o')
			a[i]=6;
		}
		if((a[1]==a[5]&&a[1]==a[3])||(a[1]==a[6]&&a[1]==a[4])||(a[1]==a[4]&&a[1]==a[5])||(a[1]==a[3]&&a[1]==a[6]))
		{
			printf("YES\n");
			continue;
		}
		if((a[2]==a[5]&&a[2]==a[3])||(a[2]==a[6]&&a[2]==a[4])||(a[2]==a[4]&&a[2]==a[5])||(a[2]==a[3]&&a[2]==a[6]))
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
