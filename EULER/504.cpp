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
#define lb lower_bound
#define ub upper_bound
 
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
#define MAX 101
using namespace std;

int pts[MAX][MAX];

bool isInside(int a,int b,int x,int y)
{
	return b*x+a*y-a*b<0;
}

bool isSquare(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

void pre()
{
	clr(pts);
	rep(i,1,MAX)
		rep(j,1,MAX)
		{
			rep(x,1,i)
				rep(y,1,j)
					if(isInside(i,j,x,y))
						pts[i][j]++;
					else
						break;
		}
}

void solve()
{
	pre();
	int ans = 0;
	rep(a,1,MAX)
	rep(b,1,MAX)
	rep(c,1,MAX)
	rep(d,1,MAX)
	{
		int numPoints = pts[a][b] + pts[b][c] + pts[c][d] + pts[d][a] + a+c-1 + b+d-1 -1;
		if(isSquare(numPoints))
		{
			// printf("%d %d %d %d : %d\n",a,b,c,d,numPoints);
			ans++;
		}
	}
	pr(ans);
	return;
}

int main()
{
	solve();
	return 0;
}