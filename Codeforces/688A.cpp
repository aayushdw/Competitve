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
	ll n,d,ans=0,m=0,i,j,p;
	scll(n); scll(d);
	for(i=0;i<d;i++)
	{
		getchar();
		bool f=false;
		for(j=0;j<n;j++)
		{
			p=getchar()-'0';
			
			if(p==0)
			f=true;
		}
		
		if(f)
		{
			m++;
			if(m>ans)
			ans=m;
		}
		else
		m=0;
	}
	prll(ans);
	return 0;
}
