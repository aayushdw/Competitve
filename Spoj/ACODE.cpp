#include<stdio.h>
#define ll long long int
int main()
{
	char s[5005];
	ll a[5005],i;
	while(1)
	{
		scanf("%s",s+1);
		if(s[1]=='0')
		break;
		a[0]=1; a[1]=1;
		i=2;
		while(s[i]!='\0')
		{
			if(s[i]=='0')
			{
				a[i]=a[i-2];
				i++;
				continue;
			}
			if(s[i]-'0'+10*(s[i-1]-'0')<=26&&s[i]-'0'+10*(s[i-1]-'0')>9)
			a[i]=a[i-1]+a[i-2];
			else
			a[i]=a[i-1];
			i++;
		}
		printf("%lld\n",a[i-1]);
	}
	return 0;
}
