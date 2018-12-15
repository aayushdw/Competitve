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

string s;
vi vec[900];
int prev[900]={0};

int getnum(char a[])
{
	return 26*(a[0]-'a')+(a[1]-'a');
}

void pre(int n)
{
	int len=2;
	bool f=false;
	char a[2];
	a[0]=s[0]; a[1]=s[1];
	rep(i,2,n)
	{
		if(s[i]!=a[f])
		{
			vec[getnum(a)].pb(len);
			a[0]=s[i-1];
			a[1]=s[i];
			len=2;
			f=false;
		}
		else
		{
			f=!f;
			len++;
		}
	}
	vec[getnum(a)].pb(len);
}

int foo(vi& v)
{
	
}

int main()
{
	int k;
	cin>>s;
	int n=s.size();
	int ans=min(2,n);
	if(n<=2)
	{
		pr(ans);
		return 0;
	}
	else if(n==3)
	{

	}
	pre(n);
	return 0;
}