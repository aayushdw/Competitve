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

//bitset<MAX> vis;
set<int> G[MAX];
int c[MAX]={0};
int n;
int idx;


int main()
{
	int m;
	si(n); si(m);
	vi p(n);
	rep(i,0,n)
		si(p[i]);
	
	while(m--)
	{
		int u,v;
		si(u); si(v);
		G[u].insert(v);
		G[v].insert(u);
	}
	int idx=1;
	stack<int> s;
	s.push(p[0]);
	while(!s.empty())
	{
		if(idx==n)
			break;
		int u = s.top();
		//pr(u);
		if(G[u].size()==c[u])
		{
			s.pop();
			continue;
		}
		int v = p[idx];
		pr(v);
		auto it = G[u].find(v);
		if(it == G[u].end())
		{
			pr(0);
			return 0;
		}
		else
		{
			s.push(v);
			c[v]++;
			c[u]++;
			idx++;
		}
	}
	if(idx==n)
		pr(1);
	else
		pr(0);
	return 0;
}