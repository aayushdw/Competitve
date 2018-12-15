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
	ll n,q,un=0,i,j,a,b,notif=0,c;
	scll(n); scll(q);
	vector<ll> app[n+1];
	rep(i,1,q+1)
	{
		scll(a); scll(b);
		if(a==1)
		{
			notif++;
			app[b].pb(notif);
			un++;
		}
		else if(a==2)
		{
			un-=app[b].size();
			app[b].clear();
		}
		else
		{
			rep(j,1,n+1)
			{
				c=0;
				for(int k=0;k<app[j].size();k++)
				{
					if(app[j][k]<=b)
					c++;
					else
					break;
				}
				if(c)
				{
					un-=c;
					app[j].erase(app[j].begin(),app[j].begin()+c);
				}
			}
		}
		/*
		rep(j,1,n+1)
		{
			rep(k,0,app[j].size())
			printf("%lld ",app[j][k]);
			printf("\n");
		}*/
		printf("%lld\n",un);
	}
	return 0;
}
