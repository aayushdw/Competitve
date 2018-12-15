#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
int main()
{
	ll n,m,x,y,idx;
	scll(n); scll(m);
	ll cost[n],amt[n]; 
	vector<ll> v[n];
	rep(i,0,n)
	scll(cost[i]), amt[i]=0;
	while(m--)
	{
		scll(x); scll(y);
		x--; y--;
		v[x].pb(y); amt[x]+=cost[y];
		v[y].pb(x);	amt[y]+=cost[x];
	}
	set<pair<ll,ll> > s;
	typeof(s.begin()) it,iter;
	rep(i,0,n)
	s.insert(mp(amt[i],i));
	rep(i,0,n)
	{
		it=s.begin();
		idx=it->second;
		rep(j,0,v[idx].size())
		{
			iter=s.find(mp(amt[v[idx][j]],v[idx][j]));
			s.erase(iter);
			s.insert(mp(amt[v[idx][j]],v[idx][j]));
		}
	}
	return 0;
}
