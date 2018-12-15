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
#define MAX 100000+5
using namespace std;
ll a[MAX],b[MAX];
set<ll> s;
int main()
{
	ll t,n,j,k;
	scll(t);
	while(t--)
	{
		scll(n);
		rep(i,0,n)
		scll(a[i]);
		
		rep(i,0,n)
		{
			if(b[i])
			continue;
			j=i;
			s.clear();
			while(1)
			{
				j=(j+a[j]+1)%n;
				if(b[j]||s.find(j)!=s.end())
				{
					k=i;
					b[k]=2;
					k=(k+a[k]+1)%n;
					while(k!=j)
					{
						b[k]=2;
						k=(k+a[k]+1)%n;
					}
					break;
				}
				else if(j==i)
				{
					k=j;
					b[k]=1;
					k=(k+a[k]+1)%n;
					while(k!=j)
					{
						b[k]=1;
						k=(k+a[k]+1)%n;
					}
					break;
				}
				s.insert(j);
			}
		}
		ll ans=0;
		rep(x,0,n)
		if(b[x]==1)
	    ans++;
		printf("%lld\n",ans);
		rep(i,0,n)
		b[i]=0;
	}
	return 0;
}
