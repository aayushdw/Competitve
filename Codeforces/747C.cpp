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
#define INF 10000000000000000
#define MAX 100000+5

using namespace std;
bitset<105> m;
vi v[MAX];
int ans[MAX]={0};
vector< pair< pair<int,int> , pair<int,int> > > events;
int main()
{
	int n,q,t,k,d;
	si(n); si(q);
	int numfree=n;
	m.reset();
	rep(i,0,q)
	{
		si(t); si(k); si(d);
		events.pb(mp(mp(t,1),mp(i,k)));
		events.pb(mp(mp(t+d,0),mp(i,k)));
	}
	sort(all(events));
	rep(i,0,events.size())
	{
		int time=events[i].F.F, flag=events[i].F.S, idx=events[i].S.F, num=events[i].S.S;
		if(flag)
		{
			if(num>numfree)
			{
				v[idx].clear();
				ans[idx]=-1;
				//printf("%d %d\n",idx,numfree);
			}
			else
			{
				int j=0;
				while(num)
				{
					if(!m[j])
					{
						m[j]=true;
						num--;
						numfree--;
						ans[idx]+=(j+1);
						v[idx].pb(j);
					}
					j++;
				}
			}
		}
		else
		{
			rep(j,0,v[idx].size())
			{
				m[v[idx][j]]=false;
				numfree++;
			}
			
		}
	}
	rep(i,0,q)
	printf("%d\n",ans[i]);
	return 0;
}