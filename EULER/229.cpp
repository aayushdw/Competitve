#include<stdio.h>
#include<set>
#include<bitset>
#define ll long long int
#define MAX 2000000000+1
#define mp make_pair
using namespace std;
set<ll> v[4];
bitset<MAX> t[4];
int main()
{
	ll i,j;
	for(i=1;i*i<=MAX;i++)
	for(j=1;j<=i&&j*j+i*i<=MAX;j++)
	//v[0].insert(i*i+j*j);
	t[0][i*i+j*j]=true;
	printf("1 done\n");
	for(i=1;i*i<=MAX;i++)
	for(j=1;2*j*j+i*i<=MAX;j++)
	//v[1].insert(i*i+2*j*j);
	t[1][i*i+2*j*j]=true;
	printf("2 done\n");
	for(i=1;i*i<=MAX;i++)
	for(j=1;3*j*j+i*i<=MAX;j++)
	//v[2].insert(i*i+3*j*j);
	t[2][i*i+3*j*j]=true;
	printf("3 done\n");
	for(i=1;i*i<=MAX;i++)
	for(j=1;7*j*j+i*i<=MAX;j++)
	//v[3].insert(i*i+7*j*j);
	t[3][i*i+7*j*j]=true;
	printf("7 done\n");
	/*typeof(v[3].begin()) it;
	bool f;
	ll count=0;
	for(it=v[3].begin();it!=v[3].end();it++)
	{
		f=true;
		for(i=0;i<3;i++)
		if(v[i].find(*it)==v[i].end())
		f=false;
		if(f)
		count++;
	}*/
	
	ll count=0;
	for(i=0;i<=MAX;i++)
	if(t[0][i]&&t[1][i]&&t[2][i]&&t[3][i])
	count++;
	printf("%lld",count);
}
