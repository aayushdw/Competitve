#include<stdio.h>
#include<vector>
#define ll long long int
using namespace std;
int main()
{
	char arr[]="101010";
	vector<ll> v,f,ans;
	ll sz=sizeof(arr)/sizeof(char),i,j;
	sz--;
	for(i=0;i<sz;i++)
	v.push_back(arr[i]-'0');
	/*for(int i=0;i<sz;i++)
	printf("%d",v[i]);*/
	for(i=sz-1,j=0;i>=0;i--,j++)
	{
		if(v[i])
		f.push_back(j);
	}
	for(int i=0;i<f.size();i++)
	printf("%d ",f[i]);
	printf("\n");
	for(i=0;i<f.size();i++)
	{
		if(i)
		{
			ans.push_back((f[i]-f[i-1]+1)*ans[i-1]-1);
		}
		else
		ans.push_back(f[i]+1);
	}
	printf("%lld",ans[ans.size()-1]);
}
