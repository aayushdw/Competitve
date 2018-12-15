#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
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
#define priority_queue pq;
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
#define MAX 1000+5
using namespace std;

int n;
double x[MAX],y[MAX];

double findmin()
{
	double d=1e10;
	rep(i,0,n)
	rep(j,0,n)
	if(i!=j)
		d=min( d, sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ));
	return d/2;
}

double distp2l(double x1, double x2, double x,double y1, double y2, double y)
{
	double a=y2-y1;
	double b=x1-x2;
	double c=-x1*(y2-y1)+y1*(x2-x1);
	double ret=fabs(a*x+b*y+c)/sqrt(a*a+b*b);
	//printf("%lf %lf %lf\n",a,b,c);
	//printf("ret=%lf\n",ret);
	return ret;
}

bool check(double d)
{
	rep(i,0,n)
	{
		//printf("%lf %d %d %d\n",distp2l(x[i],x[i+2],x[i+1],y[i],y[i+2],y[i+1]),i,i+2,i+1);
		if(distp2l(x[i],x[i+1],x[i+2],y[i],y[i+1],y[i+2]) < 2*d)
		{
			//printf(" %d %d %d %lf , %lf\n",i,i+1,i+2,distp2l(x[i],x[i+1],x[i+2],y[i],y[i+1],y[i+2]) , 2*d);
			return false;
		}
		if(distp2l(x[i],x[i+2],x[i+1],y[i],y[i+2],y[i+1]) < 2*d)
		{
			//printf(" %d %d %d %lf , %lf\n",i,i+2,i+1,distp2l(x[i],x[i+2],x[i+1],y[i],y[i+2],y[i+1]) , 2*d);
			return false;
		}
		if(distp2l(x[i+2],x[i+1],x[i],y[i+2],y[i+1],y[i]) < 2*d)
		{
			//printf(" %d %d %d %lf , %lf\n",i+2,i+1,i,distp2l(x[i+2],x[i+1],x[i],y[i+2],y[i+1],y[i]) , 2*d);
			return false;
		}
	}
	return true;
}

double solve()
{
	double low=0.0,high=findmin(),mid;
	//printf("%lf\n",high);
	bool f;
	double eps=1e-6;
	//check(1.5);
	int iter=70;
	while(iter--)
	{
		mid=(high+low)/2;
		//printf("%0.9lf %0.9lf %0.9lf\n",low,mid,high);
		f=check(mid);
		if(f)
			low=mid;
		else
			high=mid;
	}
	return (low+high)/2;
}

int main()
{
	si(n);
	rep(i,0,n)
	{
		sf(x[i]);
		sf(y[i]);
	}
	x[n]=x[0];
	x[n+1]=x[1];
	y[n]=y[0];
	y[n+1]=y[1];
	printf("%0.10lf\n",solve());
	return 0;
}