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
#define INF 1000000000000000
#define MAX 200+2
using namespace std;
vector<vector<ll> > v[MAX];
set<ll> s;
ll dp[MAX]={0,1,2};
int main()
{
	typeof(s.begin()) it;
	vector<ll> vec;
	vec.pb(1);
	v[1].pb(vec);
	vec.pb(2);
	v[2].pb(vec);
	rep(i,3,MAX)
	{
		dp[i]=INF;
		//printf("\ndp[%lld]=%lld\n",i-1,dp[i-1]);
		printf("%lld\n",i);
		rep(j,1,i/2+1)
		{
			//printf("j = %lld\n",j);
			rep(p,0,v[j].size())
			rep(q,0,v[i-j].size())
			{
				//printf("p = %lld\n",p);
				s.clear();
				rep(k,0,v[j][p].size())
				s.insert(v[j][p][k]);
				rep(k,0,v[i-j][q].size())
				s.insert(v[i-j][q][k]);
				s.insert(i);
				if(s.size()<dp[i])
				{
					dp[i]=s.size();
					vec.clear();
					v[i].clear();
					copy(s.begin(),s.end(),back_inserter(vec));
					v[i].pb(vec);
				}
				else if(s.size()==dp[i])
				{
					vec.clear();
					copy(s.begin(),s.end(),back_inserter(vec));
					v[i].pb(vec);
				}
			}
		}
	}
	ll su=0;
	rep(i,1,201)
	{
		printf("%lld %lld\n",i,--dp[i]);
		su+=dp[i];
	}
	prll(su);
	return 0;
}
