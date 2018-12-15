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
#define MAX 200000+5
using namespace std;

vector< pair< int,ii > > query;
int a[MAX];

int main()
{
	int n,q,m;
	si(n); si(q); si(m);
	rep(i,1,n+1)
		si(a[i]);
	query.resize(q);
	rep(i,0,q)
	{
		int t,l,r;
		si(t); si(l); si(r);
		query[i] = mp(t,mp(l,r));
	}
	reverse(all(query));
	rep(i,0,m)
	{
		int idx;
		si(idx);
		rep(i,0,query.size())
		{
			int t = query[i].F , l = query[i].S.F , r = query[i].S.S;
			if(idx<l || idx>r)
				continue;
			if(t==1)
			{
				//CHECK
				if(idx==r)	idx = l;
				else	idx = idx-1;
			}
			else
				idx = r+l-idx;
		}
		printf("%d ",a[idx]);
	}
	return 0;
}