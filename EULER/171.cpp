#include <bits/stdc++.h>
 
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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 1600
using namespace std;

vvi s;

void foo(int n,int d,vi v)
{
	if(v.size()>20)
		return;
	if(!n)
	{
		s.pb(v);
		return;
	}
	rep(i,2,d+1)
	{
		if(n>=i*i)
		{
			v.pb(i*i);
			foo(n-i*i,i,v);
			v.pop_back();
		}
	}
}

void pre()
{
	for(int i=1;i*i<=MAX;i++)
	{
		vi v;
		foo(i*i,9,v);
	}
}

int main()
{
	pre();
	pr((int)s.size());
	// rep(i,0,s.size())
	// {
	// 	rep(j,0,s[i].size())
	// 		printf("%d ",s[i][j]);
	// 	printf("\n");
	// }
	return 0;
}