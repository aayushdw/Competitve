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
#define MAX 10000+5
#define LOGMAX 14
using namespace std;
vector<int> adj[MAX],costs[MAX],ind[MAX];
int par[LOGMAX][MAX],level[MAX],baseArray[MAX],chainInd[MAX],otherEnd[MAX],chainHead[MAX],posInBase[MAX],subsize[MAX];
int chainNum,ptr;
int st[4*MAX],qt[4*MAX];

//LCA Query
int LCA(int u, int v) {
	if(level[u] < level[v])
		swap(u,v);
	int diff = level[u] - level[v];
	for(int i=0; i<LOGMAX; i++) if( (diff>>i)&1 ) u = par[i][u];
	if(u == v) return u;
	for(int i=LOGMAX-1; i>=0; i--) if(par[i][u] != par[i][v]) {
		u = par[i][u];
		v = par[i][v];
	}
	return par[0][u];
}

//Bottom Up LCA precomputation
void LCA_pre(int n)
{
	rep(i,1,LOGMAX)
		rep(j,0,n)
			if(par[i-1][j]!=-1)
				par[i][j]=par[i-1][par[i-1][j]];
}

//Make SegTree from baseArray
void makeTree(int idx,int start,int end)
{
	if(start==end)
	{
		st[idx]=baseArray[start];
		return;
	}
	int mid=(start+end)>>1;
	makeTree(2*idx+1,start,mid);
	makeTree(2*idx+2,mid+1,end);
	st[idx]=max(st[2*idx+1],st[2*idx+2]);
}

//Point update over baseArray
void updateTree(int idx,int start,int end, int x, int val)
{
	if(start>x || end<x)
		return;
	if(start==end)
	{
		st[idx]=val;
		return;
	}
	int mid=(start+end)>>1;
	updateTree(2*idx+1,start,mid,x,val);
	updateTree(2*idx+2,mid+1,end,x,val);
	st[idx]=max(st[2*idx+1],st[2*idx+2]);
}

//change cost of xth edge to val
void change(int x,int val)
{
	int u=otherEnd[x];
	updateTree(0,0,ptr,posInBase[u],val);
}

//Query over baseArray in range [qs,qe]
void queryTree(int idx,int start,int end,int qs,int qe)
{
	if(start>end || start>qe || end<qs)
		return;
	if(start>=qs && end<=qe)
	{
		qt[idx]=st[idx];
		return;
	}
	int mid=(start+end)>>1;
	queryTree(2*idx+1,start,mid,qs,qe);
	queryTree(2*idx+2,mid+1,end,qs,qe);
	qt[idx]=max(qt[2*idx+1],qt[2*idx+2]);
}

//v is ancestor of u
//Complexity: O(log^2(n))
int query_up(int u,int v)
{
	if(u==v)
		return 0;

	int uchain,vchain=chainInd[v],ans=-1;
	while(1)
	{
		uchain=chainInd[u];

		if(uchain==vchain)
		{
			if(u==v)
				break;
			queryTree(0,0,ptr,posInBase[v],posInBase[u]);
			ans=max(ans,qt[1]);
			break;
		}

		queryTree(0,0,ptr,posInBase[chainHead[uchain]],posInBase[u]);
		ans=max(ans,qt[1]);
		u=chainHead[uchain];
		u=par[0][u];
	}
	return ans;
}

int query(int u,int v)
{
	int lca=LCA(u,v);
	return max(query_up(u,lca),query_up(v,lca));	//WATCH TIME change due to max()
}

//Decompse the tree and make baseArray for SegTree formation
//Complexity: O(n log(n))
void hld(int u,int p, int cost)
{
	if(chainHead[chainNum]==-1)
		chainHead[chainNum]=u;

	chainInd[u]=chainNum;
	posInBase[u]=ptr;
	baseArray[ptr++]=u;

	//Finding Special Child
	int sc=-1, scCost;
	rep(i,0,adj[u].size())
		if( adj[u][i]!=p && ( sc==-1 || subsize[sc]<subsize[adj[u][i]] ) )
		{
			sc=adj[u][i];
			scCost=costs[u][i];
		}

	//Expand chain
	if(sc!=-1)
		hld(sc,u,scCost);


	//Start new chain
	rep(i,0,adj[u].size())
		if(adj[u][i]!=p && adj[u][i]!=sc)
		{
			chainNum++;
			hld(adj[u][i],u,costs[u][i]);
		}
}

// Setup Subtree size, level and parent
void dfs(int u,int p,int lvl)
{
	level[u]=lvl;
	par[0][u]=p;
	subsize[u]=1;
	rep(i,0,adj[u].size())
		if(adj[u][i]!=p)
		{
			otherEnd[ind[u][i]]=adj[u][i];
			dfs(adj[u][i],u,lvl+1);
			subsize[u]+=subsize[adj[u][i]];
		}
}

int main()
{
	int t,n,u,v,c;
	char s[10];
	sc(t);
	while(t--)
	{
		sc(n);

		//clear
		rep(i,0,n)
		{
			adj[i].clear();
			costs[i].clear();
			chainHead[i]=-1;
			ind[i].clear();
			rep(j,0,LOGMAX)
				par[j][i]=-1;
		}

		//scan edges
		rep(i,0,n-1)
		{
			sc(u); sc(v); sc(c);
			u--; v--;

			adj[u].pb(v);
			costs[u].pb(c);
			ind[u].pb(i);

			adj[v].pb(u);
			costs[v].pb(c);
			ind[v].pb(i);
		}

		chainNum=0; ptr=0;
		dfs(0,-1,0);
		hld(0,-1,-1);
		ptr--;
		makeTree(0,0,ptr);
		LCA_pre(n);

		while(1)
		{
			scanf("%s",s);
			if(s[0]=='Q')
			{
				sc(u); sc(v);
				u--; v--;
				printf("%d\n",query(u,v));
			}
			else if(s[0]=='C')
			{
				sc(u); sc(v);
				u--;
				change(u,v);
			}
			else
				break;
		}
	}
}