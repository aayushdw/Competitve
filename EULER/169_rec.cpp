#include<stdio.h>
#include<vector>
using namespace std;
int count=0;
void solve(vector<int> v,int index,int sz,int level)
{
	int r=0;
	for(int i=index;i<sz;i++)
	{
		v[i]+=r;
		if(v[i]>1)
		{
			r=2*(v[i]-2);
			v[i]=2;
		}
	}
	if(r)
	return;
	printf("level->%d\t",level);
	for(int i=0;i<sz;i++)
	printf("%d ",v[i]);
	printf("\n");
	count++;
	vector<int> a(v);
	for(int i=index;i<sz-1;i++)
	{
		if(v[i]&&i!=sz-1)
		{
			a[i]--;
			a[i+1]+=2;
			solve(a,i+1,sz,level+1);
			a[i]=v[i];
			a[i+1]=v[i+1];
		}
	}
}
int main()
{
	char arr[]="101010";
	vector<int> v;
	int sz=sizeof(arr)/sizeof(char);
	for(int i=0;i<sz;i++)
	v.push_back(arr[i]-'0');
	/*for(int i=0;i<sz-1;i++)
	printf("%d",v[i]);*/
	solve(v,0,sz-1,0);
	printf("%d",count);
}
