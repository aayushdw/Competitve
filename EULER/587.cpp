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
#define MAX 100000+5
using namespace std;

double foo(int N)
{
	double n = N*1.0;
	double y = (1+n-sqrt(2*n))/(1+n*n);
	double x = n*y;
	double X = 1-x;
	double theta = asin(X);
	double area = x*y/2 + tan(theta)/2 - theta/2 - pow(tan(theta)-X,2)/(2*tan(theta));
	// printf("x = %lf , y = %lf , theta = %lf\n",x,y,theta);
	return area/(1-acos(-1.0)/4);
}

void solve()
{
	int low = 1,high = 100000;
	double req = 0.001;
	while(low+1<high)
	{
		int mid = (low+high)/2;
		if(foo(mid)>req)
			low = mid+1;
		else
			high = mid;
	}
	if(foo(low)<req)
		pr(low);
	else
		pr(high);
	// rep(i,0,1000)
	// 	printf("%lf\n",foo(i));
}

int main()
{
	solve();
	return 0;
}