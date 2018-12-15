#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
int main()
{
	ll n,m,p,j,b,y;
	scll(n); scll(m);
	ll a[n],c[n],x[m+1];
	rep(i,0,n)
	scll(a[i]);
	set<pair<ll,ll> > s,v;
	vector<ll> d[n],t[m+1];
	rep(i,0,n)
	{
		p=a[i];
		for(j=1;j*j<p && j<=m;j++)
		{
			if(!(p%j))
			{
				d[i].pb(j), t[j].pb(i),c[i]++;
				if(p/j<=m)
				{
					d[i].pb(p/j);
					t[p/j].pb(i);
					c[i]++;
				}
			}
		}
		if(j<=m && j*j==p)
			d[i].pb(j), t[j].pb(i), c[i]++;
	}
	rep(i,1,m+1)
	{
		if(!t[i].empty())
			s.insert(mp(t[i].size(),i));
		x[i]=t[i].size();
	}
	typeof(s.begin()) it,iter;
	ll num=0;
	while(!s.empty())
	{
		it=s.begin();
		b=it->first;
		if(b==INT_MAX)
		{
			s.erase(it);
			continue;
		}
		b=it->second;
		v.clear();
		rep(i,0,t[b].size())
		v.insert(mp(c[t[b][i]],t[b][i]));
		p=(v.begin())->second;
		rep(i,0,t[b].size())
		{
			c[t[b][i]]--;
			rep(k,0,d[t[b][i]].size())
			{
				y=d[t[b][i]][k];
				iter=s.find(mp(x[y],y));
				if(iter!=s.end())
					s.erase(iter), s.insert(mp(--x[y],y));
			}
		}
		c[p]=INT_MAX;
		s.erase(it);
		num++;
	}
	prll(num);
	return 0;
}