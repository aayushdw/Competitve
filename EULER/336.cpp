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
#define ii pair<int,in>t 
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
#define NUM 2011
using namespace std;

int foo(string s)
{
	int ret = 0;
	rep(i,0,s.size())
	{
		if(s[i]=='A'+i)
			continue;
		if(s.back()=='A'+i)
		{
			reverse(s.begin()+i,s.end());
			ret++;
		}
		else
		{
			int j = s.find('A'+i);
			reverse(s.begin()+j,s.end());
			reverse(s.begin()+i,s.end());
			ret+=2;
		}
	}
	return ret;
}

int main()
{
	string s;
	rep(i,0,11)
		s.pb('A'+i);
	// swap(s[0],s[1]);
	int m = 0 , c = 0;
	while(next_permutation(all(s)))
	{
		if(foo(s)==19)
		{
			c++;
			if(c==2011)
				cout<<s<<endl;
		}
		// m = max(m,foo(s));
	}
	pr(c);
	return 0;
}