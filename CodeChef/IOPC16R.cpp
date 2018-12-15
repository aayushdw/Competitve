#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 1000000+5
using namespace std;
int arr[10]={0};
int main()
{
	int i,j,k,l,a[10][10],f,t;
	sc(t);
	while(t--)
	{
		for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		sc(a[i][j]);
		f=0;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			arr[a[i][j]]++;
			for(j=1;j<10;j++)
			{
				if(arr[j]!=1)
				f=1;
				arr[j]=0;
			}
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			arr[a[j][i]]++;
			for(j=1;j<10;j++)
			{
				if(arr[j]!=1)
				f=1;
				arr[j]=0;
			}
		}
		for(i=0;i<9;i+=3)
		{
			for(j=0;j<9;j+=3)
			{
				for(k=0;k<3;k++)
				for(l=0;l<3;l++)
				arr[a[i+k][j+l]]++;
				for(k=1;k<10;k++)
				{
					if(arr[k]!=1)
					f=1;
					arr[k]=0;
				}
			}
		}
		if(f)
		printf("Not A Sudoku\n");
		else
		printf("Its A Sudoku\n");
	}
	return 0;
}
