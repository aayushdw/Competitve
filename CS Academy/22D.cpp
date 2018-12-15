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
#define MAX 500+5
using namespace std;

ll dp[MAX][MAX];
string s;

bool ispossible(int l)
{
	rep(i,0,l)
	{
		bool f=false;
		char c='?';
		for(int j=i;j<s.size();j+=l)
			if(f && s[j]!='?' && c!=s[j])
				return false;
			else if(s[j]!='?')
			{
				c=s[j];
				f=true;
			}
		//printf("%c\n",c);
	}
	return true;
}

void fillstring(int l)
{
	rep(i,0,l)
	{
		char c='0';
		for(int j=i;j<s.size();j+=l)
			if(s[j]!='?')
			{
				c=s[j];
				break;
			}
		for(int j=i;j<s.size();j+=l)
			s[j]=c;
	}
}

int main()
{
	cin>>s;
	int n=s.size();
	rep(i,1,n+1)
	if(n%i==0 && ispossible(i))
	{
		//pr(i);
		fillstring(i);
		cout<<s;
		return 0;
	}
	return 0;
}