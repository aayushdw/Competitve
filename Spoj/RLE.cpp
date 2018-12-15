#include<stdio.h>
int main()
{
	char s[100005],ch;
	int i=0,count;
	ch=getchar();
	while(ch!='\n')
	{
		s[i++]=ch;
		ch=getchar();
	}
	i=1;
	while(1)
	{
		count=1;
		while(s[i]==s[i-1])
		{
			count++;
			i++;
		}
		if(count>3)
		printf("%d!%c",count,s[i-1]);
		else
		{
			while(count--)
			printf("%c",s[i-1]);
		}
		i++;
		if(s[i-1]=='\n')
		return 0;
	}
	return 0;
}
