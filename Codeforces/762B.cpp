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

char s[10];
vl x,y;
int main()
{
	ll a,b,c,m,p,ans1=0,ans2=0,v,z;
	sl(a); sl(b); sl(c);
	sl(m);
	while(m--)
	{
		sl(p);
		scanf("%s",s);
		if(s[0]=='U')
			x.pb(p);
		else
			y.pb(p);
	}
	sort(all(x)); sort(all(y));
	/*
	rep(i,0,x.size())
		printf("%lld ",x[i]);
	printf("\n");
	rep(i,0,x.size())
		printf("%lld ",y[i]);
	printf("\n");
	*/
	ll p1=0,p2=0;
	while(p1<x.size() || p2<y.size())
	{
		if(p1==x.size())
		{
			v=y[p2];
			p2++;
			z=2;
		}
		else if(p2==y.size())
		{
			v=y[p1];
			p1++;
			z=1;
		}
		else
		{
			if(x[p1]<y[p2])
			{
				v=x[p1];
				p1++;
				z=1;
			}
			else
			{
				v=y[p2];
				p2++;
				z=2;
			}
		}
		if(z)
		{
			if(a)
			{
				a--;
				ans1++;
				ans2+=v;
			}
			else if(c)
			{
				c--;
				ans1++;
				ans2+=v;
			}
		}
		else
		{
			if(b)
			{
				b--;
				ans1++;
				ans2+=v;
			}
			else if(c)
			{
				c--;
				ans1++;
				ans2+=v;
			}
		}
		printf("aa %lld %lld\n",v,z);
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}