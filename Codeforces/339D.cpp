#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define INF 10000000000000000
#define MAX 150000+5
using namespace std;

int tree[4*MAX],ind[MAX],base[MAX];
bitset<MAX> t;
void build(int idx, int start, int end)
{
	if(start==end)
	{
		t[idx]=true;
		tree[idx]=base[start];
		ind[start]=idx;
		return;
	}
	ll mid=(start+end)>>1;
	build(2*idx+1,start,mid);
	build(2*idx+2,mid+1,end);
	if(t[2*idx+1])
		tree[idx]=tree[2*idx+1] | tree[2*idx+2];
	else
		tree[idx]=tree[2*idx+1] ^ tree[2*idx+2];
	t[idx]=!t[2*idx+1];
}

void update(int idx, int val)
{
	base[idx]=val;
	idx=ind[idx];
	tree[idx]=val;
	idx--; idx>>=1;
	while(1)
	{
		if(t[idx])
			tree[idx]=tree[2*idx+1] ^ tree[2*idx+2];
		else
			tree[idx]=tree[2*idx+1] | tree[2*idx+2];
		if(!idx)
			break;
		idx--; idx>>=1;
	}
}

int main()
{
	int n,m,idx,val;
	si(n); si(m);
	n=1<<n;
	rep(i,0,n)
	si(base[i]);
	build(0,0,n-1);
	while(m--)
	{
		si(idx); si(val);
		idx--;
		update(idx,val);
		pr(tree[0]);
	}
	return 0;
}