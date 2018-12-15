#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
int main()
{
	ll n,p,i;
	scll(n);
	p=n;
	ll arr[n];
	arr[0]=0;
	for(i=1;i<n;i++)
	arr[i]=!arr[i-1];
	for(i=0;i<n-1;i++)
	{
		p=arr[i];
		if(!p%2)
		printf("I hate that ");
		else
		printf("I love that ");
	}
	if(arr[n-1])
	printf("I love it");
	else
	printf("I hate it");
	return 0;
}
