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

bool check(set<int> &x,set<int> &y,int p)
{
	if(x.size()<1 || y.empty())
		return true;
	auto it = x.lower_bound(p-1);
	if(it==x.end()) it = x.begin();
	if(*it>p)
		return true;
	// printf("%d %d %d\n",p,*it,(int)x.size());
	if(*(y.begin()) < *it)
		return false;
	else
		return true;
}

int main()
{
	int n,k;
	si(n); si(k);
	vi input;
	set<int> x,y;
	rep(i,1,n+1)
		y.insert(i);
	rep(i,0,k)
	{
		int p;
		si(p);
		input.pb(p);
		y.erase(p);
		if(!check(x,y,p))
		{
			// printf("Fail at : %d\n",p);
			pr(-1);
			return 0;
		}
		x.insert(p);
	}
	auto it = x.rbegin();
	vector<int> a,b;
	tr(i,y)
	{
		if(*i < *it)
			a.pb(*i);
		else
			b.pb(*i);
	}
	sort(all(a));
	sort(all(b));
	reverse(all(a));

	rep(i,0,input.size())
		printf("%d ",input[i]);
	rep(i,0,a.size())
		printf("%d ",a[i]);
	rep(i,0,b.size())
		printf("%d ",b[i]);
	
	printf("\n");
	return 0;
}