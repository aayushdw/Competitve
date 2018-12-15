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
#define MAX 5000+5
using namespace std;

int a[MAX],ways[MAX][MAX];

int main()
{
	int n;
	si(n);
	rep(i,1,n+1)
	{
		getchar();
		char c = getchar();
		if(c=='s')
			a[i] = 0;
		else
			a[i] = 1;
	}
	int prevSum = 1;
	ways[0][0] = 1;
	bool prev = false;
	rep(i,1,n+1)
	{
		if(prev)
		{
			rep(j,0,MAX-1)
				ways[i][j+1] = ways[i-1][j];
		}
		else
		{
			int cur = 0;
			rep(j,0,MAX)
			{
				ways[i][j] = prevSum;
				cur += ways[i][j];
				cur %= MOD;
				prevSum -= ways[i-1][j];
				prevSum %= MOD;
			}
			prevSum = cur;
		}
		prev = a[i];
	}
	pr((prevSum+MOD)%MOD);
	return 0;
}