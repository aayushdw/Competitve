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
#define INF 10000000000000000
#define MAX 100000+5
#define pi acos(-1.0)
#define eps 1e-3
using namespace std;



int main()
{
	int t,p,x,y;
	si(t);
	rep(i,1,t+1)
	{
		si(p); si(x); si(y);
		x-=50; y-=50;
		double deg=p*3.6,d;


		if(x*x+y*y>2500)
		{
			printf("Case #%d: white\n",i);
			continue;
		}

		if(deg==0)
		{
			printf("Case #%d: white\n",i);
			continue;
		}

		if(x==0 && y==0)
		{
			printf("Case #%d: black\n",i);
			continue;
		}



		if(y==0)
		{
			if(x>0)
				d=90.0;
			else
				d=270.0;
		}
		else if(x==0)
		{
			if(y>0)
				d=0.0;
			else
				d=180.0;
		}
		else
		{
			if(x>0 && y>0)
				d=atan(x*1.0/y)*180/pi;
			else if(x>0 && y<0)
				d=90.0+atan(-y*1.0/x)*180/pi;
			else if(x<0 && y<0)
				d=180.0+atan(x*1.0/y)*180/pi;
			else
				d=270.0+atan(-y*1.0/x)*180/pi;
		}

		//printf("Prog : %lf , Query : %lf\n",deg,d);

		if(deg+eps>=d)
			printf("Case #%d: black\n",i);
		else
			printf("Case #%d: white\n",i);

	}
	return 0;
}