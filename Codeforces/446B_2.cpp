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
#define MAX 4000+5
using namespace std;

ll row[MAX]={0},col[MAX]={0},rowcount=0,colcount=0;
priority_queue<ll> r,c;

int main()
{	
	ll n,m,k,p,temp;
	sl(n); sl(m); sl(k); sl(p);
	rep(i,0,n)
	rep(j,0,m)
	{
		sl(temp);
		row[i]+=temp;
		col[j]+=temp;
	}

	rep(i,0,n)
	r.push(row[i]);

	rep(j,0,m)
	c.push(col[j]);

	ll ans=0;
	
	while(k--)
	{
		if(r.top()-rowcount*p > c.top()-colcount*p)
		{
			ll x=r.top();
			ans+=r.top()-rowcount*p;
			r.pop();
			r.push(x-m*p);
			colcount++;
		}
		else
		{
			ll x=c.top();
			ans+=c.top()-colcount*p;
			c.pop();
			c.push(x-n*p);
			rowcount++;
		}
		//prll(ans);
	}
	prll(ans);
	return 0;
}