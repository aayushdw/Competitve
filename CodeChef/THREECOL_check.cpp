#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

int main()
{
	srand(time(NULL));
	int n,p,a,b,c,d,e;
	//sc(n);
	n=20;
	int arr[n+1][n+1];
	rep(i,1,n+1)
	rep(j,1,n+1)
	arr[i][j]=rand()%3;

	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		printf("%d ",arr[i][j]);
		printf("\n");
	}
	printf("\n");

	sc(p);
	while(p--)
	{
		sc(a); sc(b); sc(c); sc(d);
		e=arr[a][b];
		if(arr[a][b]==1)
		{
			if(arr[c][d]==2)
				e=0;
			if(arr[c][d]==0)
				e=2;
		}
		if(arr[a][b]==2)
		{
			if(arr[c][d]==1)
				e=0;
			if(arr[c][d]==0)
				e=1;
		}
		if(arr[a][b]==0)
		{
			if(arr[c][d]==2)
				e=1;
			if(arr[c][d]==1)
				e=2;
		}
		arr[a][b]=e;
		arr[c][d]=e;

	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}