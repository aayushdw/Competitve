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
#define MAX 100000+5
using namespace std;

int main()
{
	string str;
	cin >> str;
	string s;
	char prev = '$';
	rep(i,0,str.size())
	{
		if(str[i]=='a' || ( str[i] == 'b' && prev != 'b' ) )
		{
			s.pb(str[i]);
			prev = str[i];
		}
	}

	vl v;
	prev = '$';
	ll curr = 0;
	rep(i,0,s.size())
	{
		if( s[i] == 'b' and curr )
		{
			v.pb(curr);
			curr = 0;
		}
		else if( s[i] == 'a' )
			curr++;
		prev = s[i];
	}

	// cout << s << endl;

	if( curr )
		v.pb(curr);

	if( v.empty() )
	{
		pr(0);
		return 0;
	}

	// rep(i,0,v.size())
	// 	printf( "%lld ", v[i] );
	// printf( "\n" );

	vl dp( v.size() );
	dp[0] = v[0];
	rep(i,1,v.size())
	{
		dp[i] = v[i] + dp[i-1] + dp[i-1] * v[i];
		dp[i] %= MOD;
	}
	// rep(i,0,dp.size())
	// 	printf( "%lld ", dp[i] );
	// printf( "\n" );
	
	prll( dp.back() );
	return 0;
}