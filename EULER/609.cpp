#include <bits/stdc++.h>
 
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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000000 + 1
using namespace std;

bitset<MAX> t;
int pi[MAX],p[MAX];

void sieve()
{
	t.reset();
	t[0] = t[1] = true;
	t[2] = false;
	for(int i=4;i<MAX;i+=2)
		t[i] = true;
	for(int i=3;i*i<MAX;i+=2)
	{
		if(t[i])	continue;
		for(int j=i+i+i;j<MAX;j+=i+i)
			t[j] = true;
	}
}

int main()
{
	sieve();
	clr(pi);
	rep(i,1,MAX)
			pi[i] = pi[i-1]+!t[i];
	p[1] = 1;
	rep(i,2,MAX)
		p[i] = p[pi[i]] + 1;
	// rep(i,1,11)
	// printf("%d %d\n",i,pi[i]);
	ll a[p[MAX-1]+1];
	// pr(p[MAX-1]);
	clr(a);
	rep(i,2,MAX)
	{
		vi temp;
		int j = i;
		while(j-1)
		{
			temp.pb(j);
			j = pi[j];
		}
		temp.pb(1);
		// rep(j,0,temp.size())
		// 	printf("%d ",temp[j]);
		// printf("\n");
		int cur = t[i];
		rep(k,1,temp.size())
		{
			cur += t[temp[k]];
			a[cur]++;
		}
	}
	printf("\n");
	rep(i,0,p[MAX-1]+1)
		printf("%lld ",a[i]);
	printf("\n");
	ll ans = 1;
	rep(i,0,p[MAX-1]+1)
	if(a[i])
		ans = (ans*a[i])%MOD;
	prll(ans);
	return 0;
}