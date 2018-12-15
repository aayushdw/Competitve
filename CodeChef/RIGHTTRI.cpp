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
	ll t,h,s;
	double b,p,x,y,c;
	scll(t);
	while(t--)
	{
		scll(h); scll(s);
		if(h*h-4*s<0)
		printf("-1\n");
		else
		{
			x=sqrt(h*h+4*s);
			y=sqrt(h*h-4*s);
			p=(x-y)/2;
			b=(x+y)/2;
			c=(double)h;
			printf("%lf %lf %lf\n",p,b,h);
		}
	}
	return 0;
}
