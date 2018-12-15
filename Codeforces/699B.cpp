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
ll row[10000]={0},col[10000]={0};
int main()
{
	ll n,m,ro=-1,co=-1;
	bool f=true;
	char ch;
	scll(n); scll(m);
	ll a[n][m];
	rep(i,0,n)
	{
		getchar();
		rep(j,0,m)
		{
			ch=getchar();
			if(ch=='*')
			{
				row[i]++; col[j]++;
				a[i][j]=1;
			}
			else
			a[i][j]=0;
		}
	}
	ll c=0;
	rep(i,0,n)
	if(row[i]>1)
	c++, ro=i;
	
	if(c>1)
	f=false;
	c=0;
	rep(i,0,m)
	if(col[i]>1)
	c++, co=i;

	if(c>1)
	f=false;
	
	//printf("%lld %lld\n",ro,co);
	
	rep(i,0,n)
	rep(j,0,m)
	if(a[i][j])
	{
	    if(i==ro||j==co)
	    continue;
	    else
	    f=false;
	}
	
	if(!f)
	printf("NO");
	else
	{
		if(ro<0)
		ro=0;
		if(co<0)
		co=0;
		printf("YES\n%lld %lld",ro+1,co+1);
	}
	return 0;
}
