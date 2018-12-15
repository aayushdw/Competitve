#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
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
	ll n;
	scll(n);
	ll a[n+5],odd=0,i,price=0;
	for(i=0;i<n;i++)
	{
		scll(a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			price++;
			odd++;
			continue;
		}
		if(a[i]%2==0)
		price+=a[i]/2;
		else
		{
			if(odd>0)
			{
				price++;
				a[i]-=3;
				odd--;
				while(a[i]>1&&odd>1)
				{
					odd-=2;
					a[i]-=2;
				}
				price+=a[i]/2;
			}
			else
			{
				odd++;
				price+=(a[i]+1)/2;
			}
		}
	}
	printf("%lld",price);
	return 0;
} 
