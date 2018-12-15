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
int main()
{
	ll t,n,f,i;
	scll(t);
	while(t--)
	{
		scll(n);
		ll arr[n];
		for(i=0;i<n;i++)
		scll(arr[i]);
		f=0;
		for(i=1;i<n-1;i++)
		if(arr[i-1]==arr[i]&&arr[i+1]==arr[i])
		f=1;
		if(f)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
