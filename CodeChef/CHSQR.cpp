#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
int main()
{
	int t,n;
	sc(t);
	while(t--)
	{
		sc(n);
		int a[n][n];
		rep(i,1,n+1)
		for(int j=((n/2)+i-1)%n,k=0;k<n;k++,j=(j+1)%n)
			a[k][j]=i;
		rep(i,0,n)
		{
			rep(j,0,n)
			printf("%d ",a[i][j]);
			printf("\n");
		}

	}
	return 0;
}