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


int main()
{
	int n,k;
	si(n); si(k);
	vector< ii > v;
	rep(i,0,k)
	{
		int p;
		si(p);
		v.pb(mp(p,0));
	}
	rep(i,0,k)
	{
		int p;
		si(p);
		v.pb(mp(p,1));
	}
	sort(all(v));
	int cur = v[0].S , cur_pos = v[0].F , len = 1 , used = 0, ans = 0;
	rep(i,1,v.size())
	{
		if(v[i].F==cur_pos+1 && v[i].S!=cur)
		{
			cur = !cur;
			cur_pos++;
			len++;
		}
		else
		{

			if(i==len && len%2==0)
				used = 1;

			ans += len/2;
			cur_pos = v[i].F;
			cur = v[i].S;
			len = 1;
		}
	}
	if(used || v[0].F!=1 || v.back().F!=n || v[0].S==v.back().S)
		ans += len/2;
	else
		ans += (len+1)/2;
	ans = ans + (k-ans)*2;
	pr(ans);
	return 0;
}