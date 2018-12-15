#include<bits/stdc++.h>
 
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
#define MAX 1000+5
using namespace std;

vii special,v;
vi city[MAX];
int cities[MAX]={0};


int absolute(int p)
{
	return p>0?p:(-p);
}

int main()
{
	int n,t,p,x,y;
	si(n); si(t);
	rep(i,0,n)
	{
		si(p); si(x); si(y);
		if(p)
			special.pb(mp(x,y));
		v.pb(mp(x,y));
	}

	rep(i,0,n)
	{
		int m=5000;
		int a;
		rep(j,0,special.size())
		{
			a=absolute(v[i].F-special[j].F)+absolute(v[i].S-special[j].S);
			if(a<m)
				m=a;
		}
		cities[i]=m;
	}

	int q;
	si(q);
	while(q--)
	{
		si(x); si(y);
		x--; y--;
		int ans=absolute(v[x].F-v[y].F)+absolute(v[x].S-v[y].S);
		ans=min(cities[x]+cities[y]+t,ans);
		pr(ans);

	}
	return 0;
}