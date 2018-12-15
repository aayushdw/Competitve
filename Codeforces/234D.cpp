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

vii v;

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int m,k;
	si(m); si(k);
	vi fav(k);
	set<int> s;
	rep(i,0,k)
	{
		si(fav[i]);
		s.insert(fav[i]);
	}
	int n,mn=0,mx=0;
	si(n);
	rep(i,0,n)
	{
		string S;
		cin>>S;
		int d; si(d);
		int x=0,y=0,z=0;
		rep(i,0,d)
		{
			int p;
			si(p);
			if(s.find(p)!=s.end())
				x++;
			else if(p)
				y++;
			else
				z++;
		}
		v.push_back(mp(0,0));
		v.back().S = x + min(z,k-x);
		v.back().F = x + z - min(z,m-k-y);
		mn = max(mn,v.back().F);
		mx = max(mx,v.back().S);
	}
	// cout<<endl;
	rep(i,0,n)
	{
		// printf("%d %d\n",v[i].F,v[i].S);
		int ans = 0;
		rep(j,0,n)
		{
			if(i==j)
				continue;
			if(v[i].S<v[j].F)
			{
				ans = 1;
				break;
			}
			if(v[i].F<v[j].S)
				ans = 2;
		}
		pr(ans);
	}
	return 0;
}