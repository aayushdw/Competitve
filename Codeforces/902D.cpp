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
// #define ii pair<int,int> 
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
#define MAX 160
using namespace std;

vector<int> p[MAX];
vector<int> q[MAX];
int cur[MAX]={0};

vi foo(vi a,vi b)
{
	vi temp;
	vi ret;
	temp.pb(0);
	rep(i,0,a.size())
		temp.pb(a[i]);
	b.pb(0); b.pb(0);
	rep(i,0,temp.size())
		ret.pb(temp[i] + b[i]);
	bool f = false;
	rep(i,0,ret.size())
		if(abs(ret[i])>1)
			f = true;
	if(f)
		rep(i,0,temp.size())
			ret[i]=(temp[i] - b[i]);
	return ret;
}

int main()
{
	p[0].pb(1);
	p[1].pb(0); p[1].pb(1);
	rep(i,2,MAX)
		p[i] = foo(p[i-1],p[i-2]);
	// rep(i,0,MAX)
	// {
	// 	rep(j,0,p[i].size())
	// 		printf("%2d ",p[i][j]);
	// 	printf("\n");
	// }
	int n;
	si(n);
	pr((int)p[n].size()-1);
	rep(i,0,p[n].size())
		printf("%d ",p[n][i]);
	printf("\n");
	n--;
	pr((int)p[n].size()-1);
	rep(i,0,p[n].size())
		printf("%d ",p[n][i]);
	printf("\n");
	return 0;
}