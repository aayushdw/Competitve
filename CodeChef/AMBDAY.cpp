#include<set>
#include<stdio.h>
#include<vector>
#include<bitset>
#include<limits.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define MOD 1000000007
#define MAX 1000000
using namespace std;
int main()
{
	int t,F,H,W,i,p,n,m;
	sc(t);
	while(t--)
	{
		sc(F); sc(H); sc(W);
		set<int> v;
		for(i=0;i<F;i++)
		{
			sc(p);
			v.insert(p);
		}
		n=0; m=INT_MAX;
		set<int>::const_iterator it;
		for(it = v.begin(); it != v.end(); it++)
		{
			m=min(m,*it-n);
			n=*it;
		}
		it=--v.end();
		m=min(W-*it,m);
		printf("%d\n",H*m);
	}
	return 0;
}
