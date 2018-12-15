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

int a[6]={0},p=0;
double ans=0;

void haha(int i)
{
	if(i==5)
		a[i]--;
	else
	{
		a[i]--;
		rep(j,i+1,6)
		a[j]++;
	}
}

void rofl(int i)
{
	if(i==5)
		a[i]++;
	else
	{
		a[i]++;
		rep(j,i+1,6)
		a[j]--;
	}
}

void foo(double prob)
{
	int c=0;
	rep(i,1,6)
	c+=a[i];
	if(c==0 || a[5]==c)
		return;
	
	if(c==1 && a[1]!=1 && a[5]!=1)
	{
		p++;
		pr(p);
		printf("c(%d) %d %d %d %d %d %lf\n",c,a[1],a[2],a[3],a[4],a[5],prob);
		ans+=prob;
	}
	rep(i,1,6)
	if(a[i])
	{
		int k=a[i];
		haha(i);
		foo(prob*k/c);
		rofl(i);
	}
}

int main()
{
	a[1]=1;
	foo(1.0);
	pr(p);
	cout<<ans;
	return 0;
}