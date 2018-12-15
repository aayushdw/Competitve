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
#define MAX 20
#define MAXN 10000+5
using namespace std;

vi v[MAX];
vi qry[MAXN];

int main()
{
	int n;
	si(n);
	if(n==2)
	{
		printf("Q 1 2\n");
		fflush(stdout);
		int p;
		si(p);
		if(p==1)
			printf("A 2\n");
		else
			printf("A 1\n");
		return 0;
	}
	int c=0;
	rep(i,1,n+1)
	v[0].pb(i);
	while(v[c].size()>2)
	{
		int b=c;
		c++;
		int i;
		for(i=0;i+1<v[b].size();i+=2)
		{
			printf("Q %d %d\n",v[b][i],v[b][i+1]);
			qry[v[b][i]].pb(v[b][i+1]);
			qry[v[b][i+1]].pb(v[b][i]);
			fflush(stdout);
			int p;
			si(p);
			v[c].pb(p);
		}
		if((int)(v[b].size())%2)
			v[c].pb(v[b][i]);
	}
	printf("Q %d %d\n",v[c][0],v[c][1]);
	fflush(stdout);
	int p;
	si(p);

	int q;
	if(v[c][0]!=p)
		q=v[c][0];
	else
		q=v[c][1];

	n=qry[p].size()+1;
	rep(i,0,MAX)
	v[i].clear();

	v[0]=qry[p];
	v[0].pb(q);
	c=0;
	while(v[c].size()>2)
	{
		int b=c;
		c++;
		int i;
		for(i=0;i+1<v[b].size();i+=2)
		{
			printf("Q %d %d\n",v[b][i],v[b][i+1]);
			fflush(stdout);
			int p;
			si(p);
			v[c].pb(p);
		}
		if((int)(v[b].size())%2)
			v[c].pb(v[b][i]);
	}

	printf("Q %d %d\n",v[c][0],v[c][1]);
	fflush(stdout);
	si(p);

	printf("A %d",p);

	return 0;
}