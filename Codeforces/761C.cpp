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
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

vii x,y,z;
char s[MAX];

int main()
{
	int n,m,a,b,c,l;
	si(n); si(m);
	rep(j,0,n)
	{
		scanf("%s",s);
		l=strlen(s);
		a=MAX; b=MAX; c=MAX;
		rep(i,0,l)
		{
			if(s[i]>='a'&&s[i]<='z')
				a=min(a,min(i,l-i));
			if(s[i]>='0'&&s[i]<='9')
				b=min(b,min(i,l-i));
			if(s[i]=='*'||s[i]=='#'||s[i]=='&')
				c=min(c,min(i,l-i));
		}
		if(a!=MAX)
			x.pb(mp(a,j));
		if(b!=MAX)
			y.pb(mp(b,j));
		if(c!=MAX)
			z.pb(mp(c,j));
	}
	int ans=MAX;
	rep(i,0,x.size())
	rep(j,0,y.size())
	rep(k,0,z.size())
	{
		if(x[i].S==y[j].S || y[j].S==z[k].S || z[k].S==x[i].S)
			continue;
		ans=min(ans,x[i].F+y[j].F+z[k].F);
	}
	printf("%d",ans);
	return 0;
}