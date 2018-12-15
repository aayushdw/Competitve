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
#define MAX 100000+5
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

PT pts[4];

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

bool check(int i,int j,int k,int l)
{
	if(SegmentsIntersect(pts[i],pts[j],pts[k],pts[l]))
		return false;
	if(LinesParallel(pts[i],pts[j],pts[k],pts[l]))
	{
		if(LinesParallel(pts[i],pts[k],pts[j],pts[l]))
		{
			PT p = pts[i] + (pts[j]-pts[i])*2;
			PT q = ComputeLineIntersection(pts[i],pts[k],p,pts[l]);
			printf("YES %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf\n",p.x,p.y,q.x,q.y,pts[i].x,pts[i].y);
			return true;
		}
		if(LinesParallel(pts[i],pts[l],pts[j],pts[k]))
		{
			PT p = pts[i] + (pts[j]-pts[i])*2;
			PT q = ComputeLineIntersection(pts[i],pts[l],p,pts[k]);
			printf("YES %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf\n",p.x,p.y,q.x,q.y,pts[i].x,pts[i].y);
			return true;
		}
		return false;
	}
	printf("YES ");
	PT ans=ComputeLineIntersection(pts[i],pts[j],pts[k],pts[l]);

	printf("%.015lf %0.15lf ",ans.x,ans.y);

	if(dist2(ans,pts[i])>dist2(ans,pts[j]))
		printf("%0.15lf %0.15lf ",pts[i].x,pts[i].y);
	else
		printf("%0.15lf %0.15lf ",pts[j].x,pts[j].y);

	if(dist2(ans,pts[k])>dist2(ans,pts[l]))
		printf("%0.15lf %0.15lf ",pts[k].x,pts[k].y);
	else
		printf("%0.15lf %0.15lf ",pts[l].x,pts[l].y);

	printf("\n");
	return true;
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		rep(i,0,4)
		{
			sf(pts[i].x);
			sf(pts[i].y);
		}



		if(LinesParallel(pts[0],pts[1],pts[1],pts[2]) && LinesParallel(pts[1],pts[2],pts[2],pts[3]))
		{
			vector< pair<double , double> > v;
			rep(i,0,4)
			v.pb(mp(pts[i].x , pts[i].y));
			sort(all(v));
			printf("YES %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf %0.15lf\n",v[0].F,v[0].S,v[1].F,v[1].S,v[3].F,v[3].S);
			continue;
		}

		bool f=true;

		rep(i,0,4)
		rep(j,i+1,4)
		{
			rep(k,0,4)
			rep(l,k+1,4)
			{

				if(!f)
					continue;

				if(i==k || i==l || j==k || j==l)
					continue;

				if(check(i,j,k,l))
					f=false;

			}
		}

		if(f)
			printf("NO\n");

	}


	return 0;
}