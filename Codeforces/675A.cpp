#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
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
	ll a,b,c;
	sc(a); sc(b); sc(c);
	if((b-a)*c<0)
	{
		printf("NO");
		return 0;
	}
	if(c==0&&b==a)
	{
		printf("YES");
		return 0;
	}
	if(c==0&&b!=a)
	{
		printf("NO");
		return 0;
	}
	if((b-a)%c==0)
	{
		printf("YES");
		return 0;
	}
	if((b-a)%c!=0)
	{
		printf("NO");
		return 0;
	}
	return 0;
}
