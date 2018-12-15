#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

int ans=INT_MAX;

bitset<4> a[4];

void foo(int x,int num)
{
	
	bool f=false;
	rep(i,0,4)
	rep(j,0,4)
	f|=a[i][j];
	if(!f)
	{
		ans=min(ans,num);
	}
	
	f=true;
	rep(i,0,4)
	rep(j,0,4)
	f&=a[i][j];
	if(f)
	{
		ans=min(ans,num);
	}
	
	if(x==16)
	return;
	
	foo(x+1,num);
	int i=x/4, j=x%4;
	a[i][j]=!a[i][j];
	if(i+1<4)
	a[i+1][j]=!a[i+1][j];
	if(j+1<4)
	a[i][j+1]=!a[i][j+1];
	if(i>0)
	a[i-1][j]=!a[i-1][j];
	if(j>0)
	a[i][j-1]=!a[i][j-1];
	
	foo(x+1,num+1);
	
	a[i][j]=!a[i][j];
	if(i+1<4)
	a[i+1][j]=!a[i+1][j];
	if(j+1<4)
	a[i][j+1]=!a[i][j+1];
	if(i>0)
	a[i-1][j]=!a[i-1][j];
	if(j>0)
	a[i][j-1]=!a[i][j-1];
	
}

int main()
{
	char c;
	rep(i,0,4)
	{
		rep(j,0,4)
		{
			c=getchar();
			if(c=='b')
			a[i][j]=false;
			else
			a[i][j]=true;
		}
		getchar();
	}
	
	
	foo(0,0);
	if(ans==INT_MAX)
	printf("Impossible");
	else
	cout<<ans;
	return 0;
}
