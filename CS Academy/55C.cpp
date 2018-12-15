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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

int n,m,k;
int arr[26];


int foo(int i,int j,bool col,vector< vector<int> >& v)
{
	if(col)
	{
		int c = 1;
		clr(arr);
		arr[v[i][j]]++;
		if(j!=m-j-1)
			arr[v[i][m-j-1]]++, c++;
		if(i!=n-i-1)
			arr[v[n-i-1][j]]++, c++;
		if(i!=n-i-1 && j!=m-j-1)
			arr[v[n-i-1][m-j-1]]++, c++;
		int ret = c;
		rep(k,0,26)
			ret = min(ret,c-arr[k]);
		return ret;
	}
	else
	{
		//printf("(%d,%d) = %d , (%d,%d) = %d\n",i,j,v[i][j], i,m-j-1,v[i][m-j-1] );
		return v[i][j]!=v[i][m-j-1];
	}
}

int main()
{
	si(n); si(m); si(k);
	vector< vector<int> > v(n,vector<int>(m,0));
	rep(i,0,n)
	{
		getchar();
		rep(j,0,m)
			v[i][j] = getchar()-'a';
	}

	// rep(i,0,n)
	// {
	// 	rep(j,0,m)
	// 		printf("%2d ",v[i][j]);
	// 	printf("\n");
	// }

	int lim;
	if(k%2)
		lim = (m+1)/2;
	else
		lim = m/2;

	// printf("\n");

	vector<int> a(lim,0);
	rep(i,0,n)
	{
		rep(j,0,lim)
		{
			a[j] += foo(i,j,0,v);
			// printf("%d ",foo(i,j,0,v));
		}
		// printf("\n");
	}

	// printf("\n");

	vector<int> b(lim,0);
	rep(i,0,(n+1)/2)
	{
		rep(j,0,lim)
		{
			b[j] += foo(i,j,1,v);
			// printf("%d ",foo(i,j,1,v));
		}
		// printf("\n");
	}

	int ans = 0;
	rep(i,0,lim)
	{
		// printf("%d %d\n",a[i],b[i]);
		ans+=a[i];
		b[i]-=a[i];
	}

	sort(all(b));

	// printf("\n");
	// rep(i,0,lim)
	// 	printf("%d ",b[i]);
	// printf("\n");

	rep(i,0,(k+1)/2)
		ans+=b[i];

	pr(ans);

	return 0;
}