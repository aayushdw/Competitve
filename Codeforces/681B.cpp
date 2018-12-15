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
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
 
ll gcd ( ll a, ll b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
int main()
{
	//ll n,p=gcd(1234567,gcd(123456,1234));
	ll n,a=1234567,b=123456,c=1234,i,j,k;
	scll(n);
	for(i=n/a;i>=0;i--)
	for(j=(n-a*i)/b;j>=0;j--)
	for(k=(n-a*i-b*j)/c;k>=0;k--)
	{
		if(a*i+b*j+c*k==n)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
