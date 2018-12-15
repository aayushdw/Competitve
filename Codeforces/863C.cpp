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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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

ll vis[4][4],vis1[4][4],L[4][4],d[4][4];
ll a[4][4],b[4][4],len=0;
ll alice=0,bob=0;

void dfs(ll A,ll B,ll dist)
{
	if(vis[A][B])
		return;
	vis[A][B] = 1;
	d[A][B] = dist;
	dfs(a[A][B],b[A][B],dist+1);
}

int dfs1(pll p,ll A,ll B,ll len)
{
	if(vis1[A][B] && A==p.F && B==p.S)
		return len;
	if(vis1[A][B])
		return -1;
	vis1[A][B] = 1;
	dfs1(p,a[A][B],b[A][B],len+1);
}

pll dfs2(ll A,ll B,ll step,pll p)
{
	if(!step)
		return p;
	if(A==1 && B==2)
		p.S++;
	if(A==1 && B==3)
		p.F++;
	if(A==2 && B==3)
		p.S++;
	if(A==2 && B==1)
		p.F++;
	if(A==3 && B==1)
		p.S++;
	if(A==3 && B==2)
		p.F++;
	return dfs2(a[A][B],b[A][B],step-1,p);
}

int main()
{
	ll k,A,B;
	sl(k); sl(A); sl(B);
	rep(i,1,4)
	rep(j,1,4)
		sl(a[i][j]);
	rep(i,1,4)
	rep(j,1,4)
		sl(b[i][j]);
	clr(vis);
	dfs(A,B,0);

	rep(i,1,4)
	rep(j,1,4)
	{
		clr(vis1);
		if(vis[i][j] && d[i][j]<=k && dfs1(mp(i,j),i,j,0)>0)
		{
			clr(vis1);
			len = dfs1(mp(i,j),i,j,0);
			pll q = dfs2(A,B,d[i][j],mp(0,0));
			alice += q.F;
			bob += q.S;
			k -= d[i][j];
			q = dfs2(i,j,len,mp(0,0));
			alice += (k/len)*q.F;
			bob += (k/len)*q.S;
			k%=len;
			q = dfs2(i,j,k,mp(0,0));
			alice += q.F;
			bob += q.S;
			printf("%lld %lld\n",alice,bob);
			return 0;
		}
	}

	pll q = dfs2(A,B,k,mp(0,0));
	printf("%lld %lld\n",q.F,q.S);

	return 0;
}