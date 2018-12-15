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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
 
#define MOD 500500507
#define INF 4000000000000000000
#define MAX 8000000
using namespace std;

bitset<MAX> t;

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
	set< pll > s;
	rep(i,0,MAX)
		if(!t[i])
			s.insert(mp(i,i));
	ll div = 500500;
	ll ans = 1;
	while(div--)
	{
		auto it = s.begin();
		ans *= it->F;
		ans %= MOD;
		pll temp = *it;
		temp.F = temp.F*temp.F;
		s.erase(it);
		s.insert(temp);
	}
	prll(ans);
	return 0;
}