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
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
map< pll,pll > m;
typeof(m.begin()) it;
ll getAbs(ll p)
{
	return p>0?p:-p;
}
int main()
{
	ll n;
	ll x,y,u,v;
	char c;
	scll(n); scll(x); scll(y);
	while(n--)
	{
		getchar();
		c=getchar();
		scll(u); scll(v);
		//printf("%lld %lld\n",u,v);
		u-=x; v-=y;
		ll g=__gcd(u,v);
		g=getAbs(g);
		it=m.find(mp(u/g,v/g));
		if(it!=m.end() && it->second.first>getAbs(u)+getAbs(v))
		{
			it->second.first=getAbs(u)+getAbs(v);
			if(c=='B')
				it->second.second=1;
			if(c=='R')
				it->second.second=2;
			if(c=='Q')
				it->second.second=3;
		}
		else
		{
			if(c=='B')
				m.insert(mp(mp(u/g,v/g),mp(getAbs(u)+getAbs(v),1)));
			if(c=='R')
				m.insert(mp(mp(u/g,v/g),mp(getAbs(u)+getAbs(v),2)));
			if(c=='Q')
				m.insert(mp(mp(u/g,v/g),mp(getAbs(u)+getAbs(v),3)));
		}
	}
	bool f=false;
	ll p;
	for(it=m.begin();it!=m.end();it++)
	{
		u=it->first.first; v=it->first.second; p=it->second.second;
		//printf("%lld %lld %lld\n",u,v,p);
		if(p==1 && getAbs(u)==getAbs(v))
			f=true;
		if(p==2 && (u==0 || v==0))
			f=true;
		if(p==3 && (u==0 || v==0 || getAbs(u)==getAbs(v)))
			f=true;

	}
	if(f)
		printf("YES");
	else
		printf("NO");
	return 0;
}