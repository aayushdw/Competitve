#include<stdio.h>
void sort(int a[])
{
	int i,j,t;
	for(i=0;i<6;i++)
	for(j=0;j<6;j++)
	if(a[i]<a[j])
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	return;
}
int check(int a[])
{
	int f[6],b[6],i;
	for(i=0;i<6;i++)
	{
		f[i]=a[i]/100;
		b[i]=a[i]%100;
	}
	sort(f);
	sort(b);
	for(i=0;i<6;i++)
	{
		if(f[i]!=b[i])
		return 0;
	}
	return 1;
}
int main()
{
	int a[6],b[6],i,j;
	for(b[0]=1225;;a[0]++)
	{
		
		printf("%d b[0]\n",b[0]);
		for(a[1]=1;;a[1]++)
		{
			b[1]=(a[1])*a[1];
			if(b[1]<1000)
			continue;
			if(b[1]>9999)
			break;
			printf("%d b[1]\n",b[1]);
			for(a[2]=1;;a[2]++)
			{
				b[2]=(3*a[2]-1)*a[2]/2;
				if(b[2]<1000)
				continue;
				if(b[2]>9999)
				break;
				for(a[3]=1;;a[3]++)
				{
					b[3]=(2*a[3]-1)*a[3];
					if(b[3]<1000)
					continue;
					if(b[3]>9999)
					break;
					for(a[4]=1;;a[4]++)
					{
						b[4]=(5*a[4]-3)*a[4]/2;
						if(b[4]<1000)
						continue;
						if(b[4]>9999)
						break;
						for(a[5]=1;;a[5]++)
						{
							b[5]=(3*a[5]-2)*a[5];
							if(b[5]<1000)
							continue;
							if(b[5]>9999)
							break;
							if(check(b))
							{
								for(i=0;i<6;i++)
								printf("%d %d\n",b[i],a[i]);
							}
						}
					}
				}
			}
		}
	}
}
