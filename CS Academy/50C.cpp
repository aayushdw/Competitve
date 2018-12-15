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

int x[4],y[4];

int main()
{
	int t;
	si(t);
	while(t--)
	{
		rep(i,0,4)
		{
			si(x[i]);
			si(y[i]);
		}
		map<int,int> m;
		rep(i,0,4)
		rep(j,i+1,4)
		{
			int p = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			auto it = m.find(p);
			if(it==m.end())
				m.insert(mp(p,1));
			else
				it->S++;
		}
		bool f = true;
		if(m.size()!=2)
		{
			//pr(1);
			pr(0);
			continue;
		}
		auto it1 = m.begin();
		it1++;
		auto it2  = m.begin();
		//printf("(%d %d),(%d %d)\n",it1->F,it1->S,it2->F,it2->S);
		if((it2->F)*2!=(it1->F) || it1->S!=2 || it2->S!=4)
			pr(0);
		else
			pr(1);
	}
	return 0;
}