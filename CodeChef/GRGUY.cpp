#include<stdio.h>
#include<strings.h>
#include<limits.h>
char a[2][200005];
int solve(int l,int curr)
{
	int i=0;
	if(a[curr][0]=='#')
	return -1;
	int count=0;
	for(i=1;i<l;i++)
	{
		if(a[0][i]=='#'&&a[1][i]=='#')
		return -1;
		if(a[curr][i]=='.')
		continue;
		curr=!curr;
		count++;
	}
	return count;
}
int main()
{
	int t,l,k,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a[0]);
		scanf("%s",a[1]);
		l=strlen(a[0]);
		x=solve(l,0);
		y=solve(l,1);
		if(x<0&&y<0)
		k=-1;
		else if(x<0)
		k=y;
		else if(y<0)
		k=x;
		else
		k=x<y?x:y;
		if(k<0)
		printf("No\n");
		else
		printf("Yes\n%d\n",k);
	}
	return 0;
}
