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
#define INF 1000000000000000000+5
#define MAX 105
using namespace std;

ll foo[MAX][MAX];

int main()
{
	ll n,m,k,x,y,a,b,c;
	sl(n); sl(m); sl(k); sl(x); sl(y);
	ll num=n*m,p;



	if(n==1)
	{
		ll r=k%num;
		ll z=k/num;
		rep(i,1,m+1)
		foo[1][i]=z;
		rep(i,1,m+1)
		if(r>0)
		{
			r--;
			foo[1][i]++;
		}

		ll mx=-1,mn=INF;

		rep(i,1,n+1)
		rep(j,1,m+1)
		{
			mx=max(mx,foo[i][j]);
			mn=min(mn,foo[i][j]);
		}

		printf("%lld %lld %lld",mx,mn,foo[x][y]);
		return 0;

	}


	if(k>=num)
	{
		p=1;
		k-=num;
	}
	else
	{
		ll r=k;
		rep(i,1,n+1)
		rep(j,1,m+1)
		if(r>0)
		{
			r--;
			foo[i][j]++;
		}

		ll mx=-1,mn=INF;

	rep(i,1,n+1)
	rep(j,1,m+1)
	{
		mx=max(mx,foo[i][j]);
		mn=min(mn,foo[i][j]);
	}

	printf("%lld %lld %lld",mx,mn,foo[x][y]);
	return 0;

	}


	num=(n-1)*m;
	p+=k/num;
	ll r=k%num;
	

	if(p==1)
		a=1,b=1,c=1;
	else
	{
		if(p%2==0)
		{
			a=p/2+1;
			c=p/2;
		}	
		else
		{
			a=c=(p+1)/2;
		}
		b=p;
	}

	rep(i,1,m+1)
	foo[1][i]=a;

	rep(i,1,m+1)
	foo[n][i]=c;

	rep(i,2,n)
	rep(j,1,m+1)
	foo[i][j]=b;

	if(n==1)
	{
		rep(i,1,m+1)
		if(r>0)
		{
			r--;
			foo[1][i]++;
		}



	}

	if(p%2)
	{
		for(int i=n-1;i>0;i--)
		rep(j,1,m+1)
		if(r>0)
		{
			r--;
			foo[i][j]++;
		}

		rep(i,2,n+1)
		rep(j,1,m+1)
		if(r>0)
		{
			r--;
			foo[i][j]++;
		}


	}
	else
	{
		rep(i,2,n+1)
		rep(j,1,m+1)
		if(r>0)
		{
			r--;
			foo[i][j]++;
		}

		for(int i=n-1;i>0;i--)
		rep(j,1,m+1)
		if(r>0)
		{
			r--;
			foo[i][j]++;
		}

	}

	ll mx=-1,mn=INF;

	rep(i,1,n+1)
	rep(j,1,m+1)
	{
		mx=max(mx,foo[i][j]);
		mn=min(mn,foo[i][j]);
	}

	printf("%lld %lld %lld",mx,mn,foo[x][y]);

	return 0;
}