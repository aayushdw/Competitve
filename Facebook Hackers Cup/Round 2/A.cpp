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
#define INF 100000000
#define MAX 32
using namespace std;



int main()
{
	int t,x,y,n,m,k,ans;
	si(t);
	rep(tt,1,t+1)
	{
		si(n); si(m); si(k);
		x=min(n,m);
		y=max(n,m);
		if(2*k+3>y)
		{
			printf("Case #%d: -1\n",tt);
			continue;
		}
		ans=INF;
		if(x%k==0)
			ans=min(ans,x/k);
		else
			ans=min(ans,x/k+1);
		if(2*k+3<=x)
		{
			if(k==1)
				ans=min(ans,5);
			else
				ans=min(ans,4);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}