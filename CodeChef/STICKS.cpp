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
	ll t,i,j,n,p,ans;
	vector<ll> v;
	scll(t);
	while(t--)
	{
		scll(n);
		for(i=0;i<n;i++)
		{
			scll(p);
			v.pb(p);
		}
		sort(v.begin(),v.end());
		for(i=0;i<n;i++)
		printf("%lld ",v[i]);
		i=0;j=0; ans=1;
		while(i<n-1 && j<2)
		{
			if(v[i]==v[i+1])
			{
				j++; 
				ans*=v[i];
				i++;
			}
			i++;
		}
		if(j==2)
		printf("%lld\n",ans);
		else
		printf("-1\n");
		v.clear();
	}
	return 0;
}
