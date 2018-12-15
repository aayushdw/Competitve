#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
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
#define priority_queue pq;
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
#define MAX 1000+5
using namespace std;

int vis[2][MAX][MAX],a[MAX][MAX],n,m;

int dfs(int flag,int i,int j,int x)
{
	if(i<0 || j<0 || i>=n || j>=m || vis[flag][i][j] || !a[i][j])
		return 0;
	vis[flag][i][j]=x;
	int ret=1;
	ret+=dfs(flag,i+1,j,x);
	ret+=dfs(flag,i-1,j,x);
	ret+=dfs(flag,i,j+1,x);
	ret+=dfs(flag,i,j-1,x);
	return ret;
}

int main()
{
	clr(vis);
	si(n); si(m);
	rep(i,0,n)
	rep(j,0,m)
	si(a[i][j]);
	int x=1,y;
	rep(i,0,n)
	rep(j,0,m)
	if(a[i][j])
	{
		y=dfs(0,i,j,x);
		dfs(1,i,j,y);
		x=(y>0)?(x+1):x;
	}
	/*rep(i,0,n)
	{
		rep(j,0,m)
		printf("%d ",vis[0][i][j]);
		printf("\n");
	}*/
	int ans=0;
	set<int> s;
	rep(i,0,n)
	rep(j,0,m)
	if(!a[i][j])
	{
		s.clear();
		x=0;
		if(i>0)
		{
			s.insert(vis[0][i-1][j]);
			x+=vis[1][i-1][j];
		}
		if(i<n && s.find(vis[0][i+1][j])==s.end())
		{
			s.insert(vis[0][i+1][j]);
			x+=vis[1][i+1][j];
		}
		if(j>0 && s.find(vis[0][i][j-1])==s.end())
		{
			s.insert(vis[0][i][j-1]);
			x+=vis[1][i][j-1];
		}
		if(i<n && s.find(vis[0][i][j+1])==s.end())
		{
			s.insert(vis[0][i][j+1]);
			x+=vis[1][i][j+1];
		}
		ans=max(ans,x+1);
	}
	pr(ans);
	return 0;
}