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
#define MAX 100000+5
using namespace std;

int tot[5]={0},ans=MOD+1;

int calc(int n,int m,int pts)
{
	int ret;
	if(pts==500)
	{
		if(2*m>n)
			return INT_MAX;
		return n-2*m+1;
	}
	if(pts==1000)
	{
		ret=max(2*m-n,(n-4*m)/3+1);
		if(ret<0)
			return INT_MAX;
		else
			return ret;
	}
	if(pts==1500)
	{
		ret=max(4*m-n,(n-8*m)/7+1);
		if(ret<0)
			return INT_MAX;
		else
			return ret;
	}
	if(pts==2000)
	{
		ret=max(8*m-n,(n-16*m)/7+1);
		if(ret<0)
			return INT_MAX;
		else
			return ret;
	}
	if(pts==2500)
	{
		ret=max(16*m-n,(n-32*m)/7+1);
		if(ret<0)
			return INT_MAX;
		else
			return ret;
	}
	if(pts==3000)
	{
		ret = 32*m-n,0;
		if(ret<0)
			return INT_MAX;
		else
			return ret;
	}
}

int main()
{
	int n;
	si(n);
	int v[5]={0},p[5]={0},time[5]={0},a[5][6]={0};
	rep(i,0,5)
	{
		si(v[i]);
		if(v[i]>=0)
			tot[i]++;
	}
	rep(i,0,5)
	{
		si(p[i]);
		if(p[i]>=0)
			tot[i]++;
	}
	int x;
	rep(i,2,n)
	{
		rep(j,0,5)
		{
			si(x);
			if(x>=0)
				tot[j]++;
		}
	}
	rep(i,0,5)
	{
		if(v[i]==-1 && p[i]==-1)
			time[i]=0;
		else if(v[i]>=0 && p[i]>=0)
			time[i]=v[i]-p[i];
		else if(v[i]>=0)
			time[i]=v[i];
		else
			time[i]=-p[i];
	}
	rep(i,0,5)
	{
		rep(j,0,6)
		{
			a[i][j]=calc(n,tot[i],500*(j+1));
		}
	}

	rep(i1,0,6)
	{
		rep(i2,0,6)
		{
			rep(i3,0,6)
			{
				rep(i4,0,6)
				{
					rep(i5,0,6)
					{
						int diff=(i1+1)*2*(250-time[0]);
						diff+=(i2+1)*2*(250-time[1]);
						diff+=(i3+1)*2*(250-time[2]);
						diff+=(i4+1)*2*(250-time[3]);
						diff+=(i5+1)*2*(250-time[4]);
						if(diff>0)
						{
							ans=min(ans,max(a[0][i1],max(a[1][i2],max(a[2][i3],max(a[3][i4],a[4][i5])))));
						}	
					}
				}
			}
		}
	}
	if(ans==MOD+1)
		pr(-1);
	else
		pr(ans);
	return 0;
}