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
#define MAX 100000+5
using namespace std;

int a[MAX],c[MAX],ans[MAX];

vi v[MAX];

int main()
{
	int n;
	si(n);
	clr(a); clr(c);
	rep(i,0,n)
	{
		si(a[i]);
		c[a[i]]++;
	}

	if(c[0]==n)
	{
		printf("Possible\n");
		rep(i,0,n)
			printf("%d ",1);
		return 0;
	}
	else if(c[0])
	{
		printf("Impossible\n");
		return 0;
	}

	rep(i,0,n)
		v[n-a[i]].pb(i);

	rep(i,1,MAX)
		if(v[i].size() && (v[i].size() % i) )
		{
			printf( "Impossible\n" );
			return 0;
		}

	int curr = 1;
	rep(i,0,n+1)
	{
		int k = 0;
		rep(j,0,v[i].size())
		{
			ans[v[i][j]] = curr;
			k++;
			if(k == i)
			{
				curr++;
				k = 0;
			}
		}
	}

	printf("Possible\n");
	rep(i,0,n)
		printf( "%d ", ans[i] );
	printf("\n");
	return 0;
}