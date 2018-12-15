#include<stdio.h>
#include<math.h>
int main()
{
	int l=1,line,a,b;
	char ch='a';
	double num,max=0;
	FILE *fp;
	fp= fopen("99.txt","r");
	while(ch!=EOF)
	{
		fscanf(fp,"%d",&a);
		getc(fp);
		fscanf(fp,"%d",&b);
		printf("%d %d\n",a,b);
		num=b*log10(a);
		if(num>max)
		{
			max=num;
			line=l;
		}
		ch=getc(fp);
	}
	printf("%d",line);
	return 0;
}
