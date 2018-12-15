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
	string s;
	cin>>s;
	string t;
	rep(i,0,s.size())
		if(s[i]!='x')
			t.pb(s[i]);
	string _t = t;
	reverse(_t.begin(),_t.end());
	if(t!=_t)
	{
		pr(-1);
		return 0;
	}
	int n = t.size();
	t.clear();
	_t.clear();
	int _i=0,c=0;
	while(c<(n+1)/2)
	{
		if(s[_i]!='x')
			c++;
		t.pb(s[_i]);
		// cout<<s[_i];
		_i++;
	}

	_i = s.size()-1;
	c=0;
	while(c<(n+1)/2)
	{
		if(s[_i]!='x')
			c++;
		_t.pb(s[_i]);
		_i--;
	}
	reverse(all(t));
	reverse(all(_t));
	// cout<<t<<" "<<_t<<endl;
	int ans = 0;
	int i=0,j=0;
	while(i<t.size() && j<_t.size())
	{
		if(t[i]==_t[j])
		{
			i++;
			j++;
		}
		else if(t[i]=='x')
		{
			i++;
			ans++;
		}
		else if(_t[j]=='x')
		{
			j++;
			ans++;
		}
	}
	ans += (t.size()-i) + (_t.size()-j);
	pr(ans);
	return 0;
}