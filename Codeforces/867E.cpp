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
#define MAX 300000+5
using namespace std;

const int inf = 1<<28;

int tree[4*MAX],v[MAX];

void update(int st, int end, int q,int idx)
{
	//printf("%d %d %d %d\n",st,end,q,idx);
	//fflush(stdout);
	if(st>end || st>q || end<q)
		return;
	if(st==end)
	{
		tree[idx]=q;
		return;
	}
	//printf("%d %d %d %d\n",st,end,q,idx);
	int mid = (st+end)>>1;
	update(st,mid,q,2*idx+1);
	update(mid+1,end,q,2*idx+2);
	if(v[tree[2*idx+1]]>=v[tree[2*idx+2]])
		tree[idx] = tree[2*idx+2];
	else
		tree[idx] = tree[2*idx+1];
	return;
}

int query(int st,int end,int qs,int qe,int idx)
{
	if(st>end || st>qe || end<qs)
		return MAX-1;
	if(st==end)
		return tree[idx];
	int mid = (st+end)>>1;
	int x = query(st,mid,qs,qe,2*idx+1) , y = query(mid+1,end,qs,qe,2*idx+2);
	if(v[y]<=v[x])
		return y;
	else
		return x;
}

int main()
{
	int n;
	si(n);
	ll ans = 0;
	rep(i,0,4*MAX)
		tree[i] = MAX-1;
	v[MAX-1]=inf;
	set< ii > s;
	rep(i,0,n)
	{
		int p;
		si(p);
		v[i]=p;
		update(0,n-1,i,0);
		s.insert(mp(p,-i));
	}
	//return 0;
	while(!s.empty())
	{
		auto it = s.rbegin();
		int num = it->F;
		int idx = -it->S;
		int i = query(0,n-1,0,idx-1,0);
		//fflush(stdout);
		s.erase(mp(num,-idx));
		s.erase(mp(v[i],-i));
		if(v[idx]-v[i]>0)
		{

			ans+=v[idx]-v[i];
			printf("%d %d %d %d\n",v[idx],idx,i,v[i]);

		
		}
		v[i]=inf;
		v[idx]=inf;

		update(0,n-1,i,0);
		update(0,n-1,idx,0);
	}
	prll(ans);
	return 0;
}