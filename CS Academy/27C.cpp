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
#define MAX 100000+5
using namespace std;

vector< pair< int,ii > > event;
int color[11]={0};

int main()
{
	int n,m,l,r,w,ans=0;
	si(n); si(m);

	rep(i,0,n)
	{
		si(l); si(r); si(w);

		if(l!=1)
		{
			event.pb(mp(1,mp(0,0)));
			event.pb(mp(l-1,mp(1,0)));
		}

		event.pb(mp(l,mp(0,w)));
		event.pb(mp(r,mp(1,w)));

		if(r!=m)
		{
			event.pb(mp(r+1,mp(0,0)));
			event.pb(mp(m,mp(1,0)));
		}
	}
	sort(all(event));
	//printf("\n");
	rep(i,0,event.size())
	{
		int type=event[i].S.F;
		int idx=event[i].F;
		int col=event[i].S.S;
		//printf("%d %d %d\n",idx,type,col);
		if(!type)
		{
			color[col]++;
			int c=0;
			rep(j,0,11)
			c+=(color[j]!=0);
			ans=max(ans,c);
		}
		else
			color[col]--;
	}
	pr(ans);
	return 0;
}