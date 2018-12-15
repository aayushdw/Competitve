#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string.h>
#define MOD 1000000007
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%I64d",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%I64d",x)
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
	ll arr[64]={0},i,j;
	for(i=0;i<64;i++)
	for(j=0;j<64;j++)
	arr[i & j]++;
	char s[100000+5];
	scanf("%s",s);
	ll l=strlen(s);
	ll m=1;
	for(i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			m*=arr[s[i]-'0'];
			m%=MOD;
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			m*=arr[10+s[i]-'A'];
			m%=MOD;
		}
		else if(s[i]>='a' && s[i]<='z')
		{
			m*=arr[36+s[i]-'a'];
			m%=MOD;
		}
		else if(s[i]=='-')
		{
			m*=arr[62];
			m%=MOD;
		}
		else if(s[i]=='_')
		{
			m*=arr[63];
			m%=MOD;
		}
	}
	printf("%lld",m);
	return 0;
}
