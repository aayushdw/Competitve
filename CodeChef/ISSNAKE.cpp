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

char c[2][MAX];

bool check(int idx,int n)
{
	rep(i,idx,n)
	if(c[0][i]=='#' || c[1][i]=='#')
		return false;
	return true;
}

bool foo(int idx,int head,int n)
{
	if(c[!idx][head]=='#')
		idx=!idx;
	while(head<n)
	{
		if(c[idx][head]!='#')
			return check(head,n);
		if(c[!idx][head]=='#')
			idx=!idx;
		head++;
	}
	return true;
}

int main()
{
	int t,n;
	si(t);
	while(t--)
	{
		si(n);
		getchar();
		rep(i,0,n)
		c[0][i]=getchar();
		getchar();
		rep(i,0,n)
		c[1][i]=getchar();

		int pos;
		bool ans=false;
		rep(i,0,n)
		{
			if(c[0][i]=='#')
				ans|=foo(0,i,n);
			if(c[1][i]=='#')
				ans|=foo(1,i,n);
			if(c[0][i]=='#' || c[1][i]=='#')
				break;
		}

		reverse(&c[0][0],&c[0][n]);
		reverse(&c[1][0],&c[1][n]);

		rep(i,0,n)
		{
			if(c[0][i]=='#')
				ans|=foo(0,i,n);
			if(c[1][i]=='#')
				ans|=foo(1,i,n);
			if(c[0][i]=='#' || c[1][i]=='#')
				break;
		}
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}