#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
	ll t,i,j,n,m;
	char c;
	scll(t);
	while(t--)
	{
		scll(n); scll(m);
		ll a[n][m];
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				c=getchar();
				a[i][j]=c-'0';
			}
		}
		ll ans=0;
		for(j=0;j<m;j++)
		{
			c=0;
			for(i=0;i<n;i++)
			if(a[i][j]==1)
			c++;
			ans+=c*(c-1)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
