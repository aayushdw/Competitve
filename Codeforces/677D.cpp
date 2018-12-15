#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%I64d",x)
#define ll long long int
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
using namespace std;
int main()
{
	ll n,m,p,i,j,x,a,b,c,d,l,k;
	scll(n); scll(m); scll(p);
	vector <pair<ll,pair<ll,ll> > > v[p+1];
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		scll(x);
		if(x==1)
	    	v[x].pb(mp(i,mp(j,i+j)));
	    else
	        v[x].pb(mp(i,mp(j,100000000)));
	}
	
	for(i=2;i<=p;i++)
	{
	    //printf("%lld\n",i);
		for(j=0;j<v[i].size();j++)
		for(k=0;k<v[i-1].size();k++)
		{
			a=v[i][j].first;
			b=v[i][j].second.first;
			c=v[i-1][k].first;
			d=v[i-1][k].second.first;
			l=v[i-1][k].second.second;
			l+=a>c?a-c:c-a;
			l+=b>d?b-d:d-b;
			v[i][j].second.second=min(v[i][j].second.second,l);
		}
	}
	//return 0;
	ll ans=100000000;
	//printf("%d\n",v[p].size());
	for(i=0;i<v[p].size();i++)
	{
		ans=min(ans,v[p][i].second.second);
		//printf("%lld\n",v[p][i].second.second);
	}
	printf("%lld",ans);
}
