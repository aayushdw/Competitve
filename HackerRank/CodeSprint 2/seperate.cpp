#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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

string s;

ll getnum(int x,int y)
{
	if(y>s.length() || s[x]=='0')
		return -1;
	ll ret=0;
	rep(i,x,y)
	{
		ret*=10;
		ret+=s[i]-'0';
	}
	return ret;
}

bool check(int l)
{
	//printf("Checking: %d\n",l);
	ll p=l;
	ll x=getnum(0,p),y;
	prll(x);
	while(1)
	{
		y=getnum(p,p+l);
		//prll(y);
		if(y==x+1)
		{
			x=getnum(p,p+l);
			p+=l;
			continue;
		}
		y=getnum(p,p+l+1);
		//prll(y);
		if(y==x+1)
		{
			x=getnum(p,p+l+1);
			p+=l+1;
			continue;
		}
		if(p==s.length())
			return true;
		else
			return false;
	}
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		bool f=false;
		cin>>s;
		rep(i,1,s.length()/2+1)
		if(check(i))
		{
			f=true;
			cout<<"YES "<<s.substr(0,i)<<endl;
			break;
		}
		if(!f)
			cout<<"NO"<<endl;
	}
	return 0;
}