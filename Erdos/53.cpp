#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
set<vector<int> > s;
int main()
{
	int c=0;
	rep(a,1,6)
	rep(b,1,3)
	rep(c,1,8)
	rep(d,1,9)
	rep(e,1,8)
	rep(f,1,5)
	rep(g,1,7)
	{
		vector<int> v;
		v.pb(a); v.pb(b); v.pb(c); v.pb(d); v.pb(e); v.pb(f); v.pb(g);
		sort(v.begin(),v.end());
		s.insert(v);
		/*typeof(s.begin()) it=s.find(v);
		if(it==s.end())
		{
			printf("adfad");
			c++;
			s.insert(v);
		}*/
	}
	printf("%d %d",c,(int)(s.size()));
	return 0;
}