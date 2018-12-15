#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

void solve(int n)
{
	n--;
	int p=n/8,ans;
	n=n%8;
	switch(n)
	{
		case 0:
			ans=3;
			ans=8*p+ans+1;
			printf("%dLB\n",ans);
			break;
		case 1:
			ans=4;
			ans=8*p+ans+1;
			printf("%dMB\n",ans);
			break;
		case 2:
			ans=5;
			ans=8*p+ans+1;
			printf("%dUB\n",ans);
			break;
		case 3:
			ans=0;
			ans=8*p+ans+1;
			printf("%dLB\n",ans);
			break;
		case 4:
			ans=1;
			ans=8*p+ans+1;
			printf("%dMB\n",ans);
			break;
		case 5:
			ans=2;
			ans=8*p+ans+1;
			printf("%dUB\n",ans);
			break;
		case 6:
			ans=7;
			ans=8*p+ans+1;
			printf("%dSU\n",ans);
			break;
		case 7:
			ans=6;
			ans=8*p+ans+1;
			printf("%dSL\n",ans);
			break;
	}
}
int main()
{
	int t,n;
	sc(t);
	while(t--)
	{
		sc(n);
		solve(n);
	}
	return 0;
}