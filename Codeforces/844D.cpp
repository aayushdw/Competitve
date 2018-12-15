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

vi v;
vii ans(MAX);
bitset<MAX> asked;

int main()
{
	asked.reset();
	srand(time(NULL));
	int n,start,x,a,b;
	si(n); si(start); si(x);
	rep(i,0,n)
		v.pb(i+1);
	v[0]=start;
	random_shuffle(v.begin()+1,v.end());

	int curr=-1,next;

	rep(i,0,min(n,1000))
	{
		//pr(v[i]);
		if(asked[v[i]])
			continue;
		asked[v[i]]=true;
		printf("? %d\n",v[i]);
		fflush(stdout);
		si(a);
		si(b);
		ans[v[i]]=mp(a,b);
		if(a>x)
			continue;
		if(a==x)
		{
			printf("! %d\n",a);
			fflush(stdout);
			return 0;
		}
		if(a<=curr)
			continue;
		if(a<x)
		{
			curr=a;
			next=b;
		}
	}
	if(curr==-1)
	{
		printf("! %d\n",ans[start].F);
		fflush(stdout);
		return 0;
	}
	if(next==-1)
	{
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}
	while(1)
	{
		printf("? %d\n",next);
		fflush(stdout);
		si(a);
		si(b);
		if(a>=x)
		{
			printf("! %d\n",a);
			fflush(stdout);
			return 0;
		}
		if(b==-1)
		{
			printf("! -1\n");
			fflush(stdout);
			return 0;
		}
		next=b;
	}
	return 0;
}