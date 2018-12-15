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
#define MAX 1005
using namespace std;

int cur[MAX];
int x[MAX];
double y[MAX];

int main()
{
	int n,r;
	si(n); si(r);
	rep(i,0,n)
		si(x[i]);
	rep(i,0,MAX)
		cur[i] = -1;
	rep(i,0,n)
	{
		int xst = max(x[i]-r,0);
		int xend = min(x[i]+r,MAX-1);
		// printf("(%d %d)\n",xst,xend);
		double ymax = 0;
		rep(j,xst,xend+1)
		{
			if(cur[j]==-1)
				ymax = max(r*1.0,ymax);
			else
			{
				int xdiff = abs(x[i]-x[cur[j]]);
				double ydiff = sqrt(4*r*r*1.0-xdiff*xdiff*1.0);
				// printf("%d [%d %0.4lf]\n",cur[j],xdiff,ydiff);
				ymax = max(y[cur[j]] + ydiff , ymax);
			}
			cur[j] = max(cur[j],i);
		}
		y[i] = ymax;
	}
	rep(i,0,n)
	printf("%0.9lf ",y[i]);
	printf("\n");
	return 0;
}