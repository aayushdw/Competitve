#include<stdio.h>
#include<strings.h>
#define sc(x) scanf("%d",&x)
char arr[26][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char str[25],string[10005],s[10005];
int main()
{
	int t,count,i,j,n,l;
	sc(t);
	while(t--)
	{
		count=0;
		scanf("%s",s);
		sc(n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			l=strlen(str);
			string[0]='\0';
			for(j=0;j<l;j++)
			strcat(string,arr[str[j]-'A']);
			if(!strcmp(string,s))
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
