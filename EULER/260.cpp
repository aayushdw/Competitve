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
#define MAX 10
using namespace std;

bitset<MAX> g[MAX][MAX];

int main()
{
	ll ans = 0;
	clr(g);
	g[0][0][0] = false;
	rep(i,0,MAX)
	rep(j,i,MAX)
	rep(k,j,MAX)
		if(i||j||k)
		{
			bool f = false;

			// rep(ii,0,i)
			// 	if(!g[ii][j][k])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)
			// rep(jj,0,j)
			// 	if(!g[i][jj][k])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)	
			// rep(kk,0,k)
			// 	if(!g[i][j][kk])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)
			// rep(ii,1,min(i,j)+1)
			// 	if(!g[i-ii][j-ii][k])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)
			// rep(jj,1,min(j,k)+1)
			// 	if(!g[i][j-jj][k-jj])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)	
			// rep(kk,1,min(i,k)+1)
			// 	if(!g[i-kk][j][k-kk])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			// if(!f)
			// rep(ii,1,min(i,min(j,k))+1)
			// 	if(!g[i-ii][j-ii][k-ii])
			// 	{
			// 		f = true;
			// 		break;
			// 	}

			if(i && !g[0][j][k])	f = true;
			if(j && !g[i][0][k])	f = true;
			if(k && !g[i][j][0])	f = true;
			if(i && !g[0][j-i][k])	f = true;
			if(j && !g[i][0][k-j])	f = true;
			if(i && !g[0][j][k-i])	f = true;
			if(i && !g[0][j-i][k-i]) f = true;
			
			g[i][j][k] = f;
			g[j][i][k] = f;
			g[i][k][j] = f;
			g[j][k][i] = f;
			g[k][i][j] = f;
			g[k][j][i] = f;
			if(!f)
			{
				ans += i+j+k;
				// printf("%3d %3d %3d\n",i,j,k);
			}
			if(!g[i][j][k])
			printf("(%d,%d,%d) = %d\n",i,j,k,(int)g[i][j][k]);
		}
	prll(ans);
	return 0;
}