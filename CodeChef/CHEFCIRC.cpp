#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
#define x first
#define y second

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
#define MAX 501
#define eps 1e-6
#define tol 1e-2
#define dist(a,b,c,d) sqrt((a-c)*(a-c)+(b-d)*(b-d))
using namespace std;

#define pi acos(-1.0)
#define pt pair<double,double>
int n,m;
vector< pt > pts;
bitset< MAX > active;
vector< pair<double,int> > event;

double dis(pt p,pt q)
{
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

//Returns argument of vector pq (p!=q)
double agrument(pt p,pt q)
{
	q.x-=p.x; q.y-=p.y;
	if(abs(q.x)<eps)
	{
		if(q.y>0)
			return 0.0;
		else
			return 180.0;
	}
	else
	{
		if(q.x>0 && q.y>0)
			return atan(q.y/q.x)*180/pi;
		else if(q.x<0 && q.y>0)
			return 180.0-atan(-q.y/q.x)*180/pi;
		else if(q.x<0 && q.y<0)
			return 180.0+atan(q.y/q.x)*180/pi;
		else
			return 360.0-atan(-q.y/q.x)*180/pi;
	}
}

//Make events
void foo(pt p,pt q,double r,int idx)
{
	double d=dis(p,q);
	if(d>2*r)
		return;
	double theta=acos(d/(2*r))*180/pi;
	if(theta<eps)
		theta=eps;
	double arg=agrument(p,q);
	double theta1=arg-theta, theta2=arg+theta;

	//printf("(%lf %lf) (%lf %lf)	d=%lf arg=%lf,theta=%lf\n",p.x,p.y,q.x,q.y,d,arg,theta);

	//INSERT in set
	//Checks for theta1 and theta2

	if(theta1<-eps)
	{
		event.pb(mp(eps,idx));
		event.pb(mp(theta2,idx));
		event.pb(mp(theta1+360.0,idx));
		event.pb(mp(360.0-eps,idx));
	}
	else if(theta2>=360.0)
	{
		event.pb(mp(theta1,idx));
		event.pb(mp(360.0-eps,idx));
		event.pb(mp(0.0,idx));
		event.pb(mp(theta2-360.0,idx));
	}
	else
	{
		event.pb(mp(theta1,idx));
		event.pb(mp(theta2,idx));
	}
}


//Does Angular Sweep
int getMaxCount(double r)
{
	//printf("R=%lf\n",r);

	int ret=-1,curr;
	rep(i,0,pts.size())
	{
		event.clear();
		rep(j,0,pts.size())
		if(i!=j)
			foo(pts[i],pts[j],r,j);

		sort(all(event));
		active.reset();
		curr=1;	//MODIFY

		//printf("Event for point %d: \n",i);
		rep(j,0,event.size())
		{
			//printf("%lf %d\n",event[j].F,event[j].S);

			if(active[event[j].S])
			{
				active[event[j].S]=false;
				curr--;
			}
			else
			{
				active[event[j].S]=true;
				curr++;
			}
			ret=max(ret,curr);
		}
	}
	return ret;
}

//Binary search over radius
double solve()
{
	//getMaxCount(1500.0);
	double high=1500.0, low=eps, mid;
	int vhigh=getMaxCount(high), vlow=getMaxCount(low),vmid;
	//printf("vhigh=%d vlow=%d\n",vhigh,vlow);
	while(high-low>tol)
	{
		mid=(high+low)/2;
		vmid=getMaxCount(mid);
		//printf("r=%lf count=%d\n",mid,vmid);
		if(vmid>=m)
			high=mid, vhigh=vmid;
		else
			low=mid, vlow=vmid;
	}
	return (high+low)/2;
}

int main()
{
	double a,b;
	si(n); si(m);
	rep(i,0,n)
	{
		sf(a); sf(b);
		pts.pb(mp(a,b));
	}
	printf("%0.15lf",solve());
	return 0;
}