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
#define MAX 100000+5
#define SQMAX 400+5
using namespace std;

int n;
int ans[SQMAX][MAX]={0};
bitset<MAX> vis;
int a[MAX];

int dfs(int u,int k)
{
	if(u>n)
		return 0;
	if(vis[u])
		return ans[k][u];
	vis[u]=true;
	return ans[k][u]=dfs(u+a[u]+k,k)+1;
}

void pre()
{
	for(int i=1;i<400;i++)
	{
		vis.reset();
		rep(j,1,n+1)
		if(!vis[j])
		dfs(j,i);
	}
}

int solve(int p,int k)
{
	if(k<400)
	{
		return ans[k][p];
	}
	else
	{
		int c=0;
		while(p<=n)
		{
			p=p+a[p]+k;
			c++;
		}
		return  c;
	}
}

int main()
{
	int q,p,k;
	si(n);
	rep(i,1,n+1)
	si(a[i]);
	pre();
	si(q);
	while(q--)
	{
		si(p); si(k);
		pr(solve(p,k));
	}
	return 0;
}