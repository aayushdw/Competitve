#include <bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%ld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(long int i=x;i<y;i++)
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
#define MAX 200000+5
using namespace std;

long int ans[MAX]={0};
map<long int,long int> m;

int main()
{
	string s;
	cin>>s;
	int n = s.size();
	m.insert(mp(0,0));
	bitset<26> t;
	t.reset();
	rep(i,0,n)
	{
		ans[i]=i+1;
		t.flip(s[i]-'a');
		long int p = t.to_ulong();
		auto it = m.find(p);
		if(it!=m.end())
			ans[i] = min(ans[i],it->S+1);
		for(long int j=0;j<26;j++)
		{
			t.flip(j);
			p = t.to_ulong();
			t.flip(j);
			it = m.find(p);
			if(it!=m.end())
				ans[i] = min(ans[i],it->S+1);
		}
		p = t.to_ulong();
		it = m.find(p);
		if(it==m.end())
			m.insert(mp(p,ans[i]));
		else
			it->S = min(it->S,ans[i]);
	}
	prll(ans[n-1]);
	return 0;
}