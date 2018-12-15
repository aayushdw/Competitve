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
#define MAX 40
using namespace std;

int a[MAX],m;

int maxPos(vector<int> &v,int key)
{
	if(v[0]>key)
		return 0;
	int low = 0, high = v.size()-1;
	while(low+1<high)
	{
		int mid = (low+high)>>1;
		if(v[mid]>key)
			high = mid-1;
		else
			low = mid;
	}
	if(v[high]<=key)	return v[high];
	else	return v[low];
}

vector<int> poss(vector<int> v)
{
	sort(all(v));
	vector<int> ret;
	set<int> s;
	s.insert(0);
	rep(i,0,v.size())
	{
		vector<int> temp;
		tr(it,s)
			temp.pb(((*it)+v[i])%m);
		rep(j,0,temp.size())
			s.insert(temp[j]);
	}
	tr(it,s)
		ret.pb(*it);
	return ret;
}

int main()
{
	int n;
	si(n); si(m);
	rep(i,0,n)
		si(a[i]);

	int _n = n/2;
	vector<int> h1;
	vector<int> h2;
	rep(i,0,_n)
		h1.pb(a[i]%m);
	rep(i,_n,n)
		h2.pb(a[i]%m);

	vector<int> x = poss(h1);
	vector<int> y = poss(h2);


	int ans = 0;
	rep(i,0,x.size())
		ans = max(ans,x[i]);
	rep(i,0,y.size())
		ans = max(ans,y[i]);

	rep(i,0,x.size())
		ans = max(ans , x[i] + maxPos(y,m-x[i]-1));

	rep(i,0,y.size())
		ans = max(ans , y[i] + maxPos(x,m-y[i]-1));

	pr(ans);

	return 0;
}