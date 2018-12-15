#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define MAX 1000000000000000
using namespace std;

ll a[70]={1};

map<ll,ll> m;
typeof(m.begin()) it;

int main()
{
	ll n,k,prev=0,ans=0,x,p,sz;
	sl(n); sl(k);
	if(k==1)
		sz=1;
	else if(k==-1)
	{
		a[1]=-1;
		sz=2;
	}
	else
	{
		for(sz=1;a[sz-1]<MAX;sz++)
			a[sz]=a[sz-1]*k;
	}
	m.insert(mp(0,1));
	rep(i,0,n)
	{
		sl(x);
		prev+=x;
		rep(i,0,sz)
		{
			p=prev-a[i];
			it=m.find(p);
			if(it!=m.end())
				ans+=it->S;
		}
		it=m.find(prev);
		if(it==m.end())
			m.insert(mp(prev,1));
		else
			it->S++;
	}
	prll(ans);
	return 0;
}