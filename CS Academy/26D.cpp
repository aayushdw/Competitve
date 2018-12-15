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

int a[MAX];
vi v;

int main()
{
	int n;
	si(n);
	rep(i,0,n)
	si(a[i]);
	rep(i,1,n)
	if( (a[i]==1 && a[i-1]==1) || (a[i]==2 && a[i-1]==2) || (a[i]==3 && a[i-1]==3) )
	{
		printf("-1");
		return 0;
	}

	if(a[0]==3 || a[n-1]==3)
	{
		printf("-1");
		return 0;
	}

	rep(i,2,n)
	if( a[i]==3 && a[i-1]==2 && a[i-2]==3 )
	{
		printf("-1");
		return 0;
	}

	//CHECK

	rep(i,0,n)
	if(a[i]==3)
	{
		v.pb(i);
		v.pb(i+1);
		v.pb(i-1);
		v.pb(i);
	}

	rep(i,0,n)
	if(a[i]==2)
	{
		if(i+1<n && a[i+1]!=3)
		{
			v.pb(i+1);
			v.pb(i);
		}
		else if(i-1>=0 && a[i-1]!=3)
		{
			v.pb(i-1);
			v.pb(i);
		}
		else
		{
			printf("-1");
			return 0;
		}
	}

	rep(i,0,n)
	if(a[i]==1)
		v.pb(i);

	cout<<v.size()<<endl;
	rep(i,0,v.size())
	printf("%d ",v[i]+1);

	return 0;
}