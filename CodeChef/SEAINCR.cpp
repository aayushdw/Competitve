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
#define clr(x) memset(x,0,sizeof(x))

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 1000+5
using namespace std;

//LCS Code: Hackerearth.com, Problem Boogeyman

int a[MAX],b[MAX],c[MAX],p[MAX],res[MAX][MAX];
void foo(int j,int n)
{
	int ret=0,i;
	rep(i,0,n)
	{
		c[i]=lower_bound(b+1,b+ret+1,a[i])-b;
		ret=ret>c[i]?ret:c[i];
		res[j][i+j]=ret;
		b[c[i]]=a[i];
	}
}
int main()
{
	int t,n,m,x,y;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		rep(i,0,n)
		sc(p[i]);
		rep(i,0,n)
		{
			clr(b); clr(c);
			int j=0;
			rep(k,i,n)
				a[j++]=p[k];
			foo(i,j);
		}
		while(m--)
		{
			sc(x); sc(y);
			x--; y--;
			pr(res[x][y]);
		}
	}
	return 0;
}