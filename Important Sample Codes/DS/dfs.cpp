#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>
#include<bitset>
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
#define MAX 100
using namespace std;
vector<ll> v[MAX];
void dfsrec(ll p, bool vis[])
{
	if(vis[p])
	return;
	vis[p]=true;
	printf("%lld ",p);
	for(ll i=0;i<v[p].size();i++)
	if(!vis[v[p][i]])
	dfsrec(v[p][i],vis);
}
void dfs(ll n,ll p)
{
	bool vis[n];
	for(ll i=0;i<n;i++)
	vis[i]=false;
	dfsrec(p,vis);
}

int main()
{
	ll n,t,x,y;
	scll(n);
	scll(t);
	while(t--)
	{
		scll(x); scll(y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<v[i].size();j++)
	    printf("%lld ",v[i][j]);
	    printf("\n");
	}
	dfs(n,0);
	return 0;
}
