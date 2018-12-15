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
ll arr[200][3]={0};
int main()
{
	ll n;
	scll(n);
	ll a[n];
	rep(i,0,n)
	scll(a[i]);
	
	if(a[0]==1)
	arr[0][0]=1;
	else if(a[0]==2)
	arr[0][1]=1;
	else if(a[0]==3)
	arr[0][0]=1, arr[0][1]=1;
	
	rep(i,1,n)
	{
		if(a[i]==3)
		{
			arr[i][0]=max(arr[i-1][1],arr[i-1][2])+1;
			arr[i][1]=max(arr[i-1][0],arr[i-1][2])+1;
			arr[i][2]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
		}
		else if(a[i]==0)
		{
			arr[i][0]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
			arr[i][1]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
			arr[i][2]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
		}
		else if(a[i]==1)
		{
			arr[i][0]=max(arr[i-1][1],arr[i-1][2])+1;
			arr[i][1]=-1;
			arr[i][2]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
		}
		else
		{
			arr[i][0]=-1;
			arr[i][1]=max(arr[i-1][0],arr[i-1][2])+1;;
			arr[i][2]=max(arr[i-1][2],max(arr[i-1][1],arr[i-1][0]));
		}
		
	}
	
	/*rep(i,0,n)
	printf("%lld %lld %lld\n",arr[i][0],arr[i][1],arr[i][2]);*/
	
	ll ans=max(arr[n-1][0],max(arr[n-1][1],arr[n-1][2]));
	ans=n-ans;
	prll(ans);
	return 0;
}
