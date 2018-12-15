#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
//#define Val(r) (897-14100*pow(r,5000)-3*r*(1-pow(r,4999))*1.0/(1-r))*1.0/(1-r)
#define req -6e11
double Val(double r)
{
	double ans=0.0;
	rep(i,1,5001)
	ans+=(900-3*i)*pow(r,i-1);
	return ans;
}
double binSearch(double low,double high)
{
	double eps=1e-13;
	if((high-low) < eps)
	{
		printf("%0.15lf %0.15lf\n",high,low);
		return high;
	}
	double vlow,vhigh,mid,vmid;
	vlow= Val(low) ;
	vhigh= Val(high) ;
	mid=(low+high)/2;
	vmid= Val(mid);
	if(vmid<req)
		return binSearch(low,mid);
	else
		return binSearch(mid,high);
}
int main()
{
	double ans=binSearch(1.002,1.004);
	printf("%0.12lf\n",ans);
	printf("%0.15lf\n",Val(1.002322108633));
	return 0;
}