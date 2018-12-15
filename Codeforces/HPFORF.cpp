#include<bits/stdc++.h>
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
ll b[505][505];
bool vis[505][505],a[505][505];
ll dfs(ll i,ll j,ll p,ll n,ll m)
{
	//printf("%lld %lld %lld\n",i,j,p);
	vis[i][j]=true;
	if(i>0 && !a[i-1][j])
	p++;
	if(j>0 && !a[i][j-1])
	p++;
	if(i<n-1 && !a[i+1][j])
	p++;
	if(j<m-1 && !a[i][j+1])
	p++;
	
	if(i>0 && a[i-1][j] && !vis[i-1][j])
	p+=dfs(i-1,j,0,n,m);
	if(j>0 && a[i][j-1] && !vis[i][j-1])
	p+=dfs(i,j-1,0,n,m);
	if(i<n-1 && a[i+1][j] && !vis[i+1][j])
	p+=dfs(i+1,j,0,n,m);
	if(j<m-1 && a[i][j+1] && !vis[i][j+1])
	p+=dfs(i,j+1,0,n,m);
	
	b[i][j]=p;
	return b[i][j];
}


void dfs2(ll i,ll j,ll p,ll n,ll m)
{
	//printf("%lld %lld %lld\n",i,j,p);
	vis[i][j]=true;
	b[i][j]=p;
	
	if(i>0 && a[i-1][j] && !vis[i-1][j])
	dfs2(i-1,j,p,n,m);
	if(j>0 && a[i][j-1] && !vis[i][j-1])
	dfs2(i,j-1,p,n,m);
	if(i<n-1 && a[i+1][j] && !vis[i+1][j])
	dfs2(i+1,j,p,n,m);
	if(j<m-1 && a[i][j+1] && !vis[i][j+1])
	dfs2(i,j+1,p,n,m);
	
}


int main()
{
	ll t,n,m,i,j,k;
	char c;
	scll(t);
	while(t--)
	{
		scll(n); scll(m); scll(k);
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				c=getchar();
				if(c=='*')
				a[i][j]=false;
				else
				a[i][j]=true;
			}
		}
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			printf("%d",a[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			vis[i][j]=false;
			b[i][j]=0;
		}
		
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(a[i][j] && !vis[i][j])
			dfs(i,j,0,n,m);
		}
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			printf("%lld ",b[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		vis[i][j]=false;
		
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(a[i][j] && !vis[i][j])
			dfs2(i,j,b[i][j],n,m);
		}
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			printf("%lld ",b[i][j]);
			printf("\n");
		}
		*/
		for(i=0;i<k;i++)
		{
			scll(n); scll(m);
			n--; m--;
			printf("%lld\n",b[n][m]);
		}
	}
	return 0;
}
