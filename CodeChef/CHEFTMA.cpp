#include<stdio.h>
#include<limits.h>
#include<set>
#include<vector>
#include<algorithm>
#define sc(x) scanf("%d",&x)
#define MAX 100005
#define ll long long int
using namespace std;
vector<int> work,magic;
int main()
{
	int t,n,k,m,i,j,p,f;
	sc(t);
	while(t--)
	{
		work.resize(0);
		magic.resize(0);
		sc(n); sc(k); sc(m);
		for(i=0;i<n;i++)
		{
			sc(p);
			work.push_back(p);
		}
		for(i=0;i<n;i++)
		{
			sc(p);
			work[i]-=p;
		}
		k+=m;
		for(i=0;i<k;i++)
		{
			sc(p);
			magic.push_back(p);
		}
		sort(work.begin(),work.end());
		sort(magic.begin(),magic.end());
		/*
		for(i=0;i<n;i++)
		printf("%d ",work[i]);
		printf("\n");
		for(i=0;i<k;i++)
		printf("%d ",magic[i]);
		*/
		i=k-1; j=n-1; f=0;
		while(i>=0)
		{
			while(work[j]<magic[i])
			{
				i--;
				if(i<0)
				{
					f=1;
					break;
				}
			}
			if(f)
			break;
			work[j]-=magic[i];
			j--;
			i--;
		}
		ll sum=0;
		for(i=0;i<n;i++)
		sum+=work[i];
		printf("%lld\n",sum);
	}
	return 0;
}
