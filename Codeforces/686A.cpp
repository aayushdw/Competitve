#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>
#include<bitset>
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
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
int main()
{
	ll n,x,i,c1=0,c2=0,p;
	char c;
	scll(n); scll(x);
	for(i=0;i<n;i++)
	{
		getchar();
		c=getchar();
		scll(p);
		if(c=='+')
		x+=p;
		else
		{
			if(p>x)
			c2++;
			else
			x-=p;
		}
	}
	printf("%lld %lld",x,c2);
	return 0;
}
