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
	ll t,n,c,a,b;
	scll(t);
	while(t--)
	{
		n,c;
		scll(n);
		scll(c);
		
		bool f=false;
		
		if(n==1)
		f=true;
		else if((2*c)%n!=0)
		f=false;
		else
		{
			c=(2*c)/n;
			a=2;
			b=n-1;
			if(c%__gcd(a,b)!=0)
			f=false;
			else
			{
				if(b%2==0)
				{
					if(c>=b+2&&c%2==0)
					f=true;
					else
					f=false; 
				}
				else
				{
					if(c>a*b)
					f=true;
					else if(c>=b+2&&c%2!=0)
					f=true;
					else
					f=false;
				}
			}
		}
		if(f)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
