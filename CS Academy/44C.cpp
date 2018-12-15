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
using namespace std;

//bitset<MAX> vis;
set<int> G[MAX];
int c[MAX]={0};
vi p;
int n;
bool ans = true;
int idx;

void dfs(int u)
{
	if(idx>=n)
		return;

	int x = G[u].size();
	while(c[u]+1!=x)
	{
		if(idx>=n)
			return;
		if(c[u]+1==x)
			return;
		auto it = G[u].find(p[idx]);
		if(it==G[u].end())
		{
			ans=false;
			return;
		}
		else
		{
			c[u]++;
			idx++;
			dfs(p[idx-1]);
		}
	}
	return;
}

int main()
{
	int m;
	si(n); si(m);
	vi temp(n);
	rep(i,0,n)
		si(temp[i]);
	p=temp;
	
	while(m--)
	{
		int u,v;
		si(u); si(v);
		G[u].insert(v);
		G[v].insert(u);
	}
	idx=1;
	G[1].insert(1);
	dfs(p[0]);
	if(idx<n)
		ans=false;
	pr(ans);
	return 0;
}