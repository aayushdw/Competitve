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
#define MAX 1000000+5
using namespace std;

vector< pair < int , ii > > a(MAX),tree(4*MAX);

pair< int,ii > query(int idx,int l,int r,int ql,int qr)
{
	if(r<ql || l>qr)
		return mp(0,mp(0,0));
	if(l>=ql && r<=qr)
		return tree[idx];
	int m=(l+r)>>1;
	pair< int,ii > a=query(2*idx+1,l,m,ql,qr);
	pair< int,ii > b=query(2*idx+2,m+1,r,ql,qr);
	pair< int,ii > c;
	c.F=a.F+b.F+min(a.S.F,b.S.S);
	c.S.F=a.S.F+b.S.F-min(a.S.F,b.S.S);
	c.S.S=a.S.S+b.S.S-min(a.S.F,b.S.S);
	return c;
}

void build(int idx,int l,int r)
{
	if(l==r)
	{
		tree[idx]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(2*idx+1,l,m);
	build(2*idx+2,m+1,r);
	tree[idx].F=tree[2*idx+1].F+tree[2*idx+2].F+min(tree[2*idx+1].S.F,tree[2*idx+2].S.S);
	tree[idx].S.F=tree[2*idx+1].S.F+tree[2*idx+2].S.F-min(tree[2*idx+1].S.F,tree[2*idx+2].S.S);
	tree[idx].S.S=tree[2*idx+1].S.S+tree[2*idx+2].S.S-min(tree[2*idx+1].S.F,tree[2*idx+2].S.S);
}

int main()
{
	string s;
	cin>>s;
	int n=s.length();
	rep(i,0,n)
	if(s[i]=='(')
	{
		a[i].F=0;
		a[i].S.F=1;
		a[i].S.S=0;
	}
	else
	{
		a[i].F=0;
		a[i].S.F=0;
		a[i].S.S=1;
	}
	build(0,0,n-1);
	int l,r,q;
	si(q);
	while(q--)
	{
		si(l); si(r);
		l--; r--;
		pr(2*query(0,0,n-1,l,r).F);
	}
	return 0;
}