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
#define MAX 1000000+5
using namespace std;

string c;
int a[MAX]={0},b[MAX]={0};
void pre()
{
	rep(i,0,c.length())
	if(c[i]=='A')
		a[i+1]=a[i]+1, b[i+1]=b[i];
	else
		b[i+1]=b[i]+1, a[i+1]=a[i];
}

int foo(int i,int j,int p)
{
	int len=j-i+1,ret;
	if(len%4)
	{
		if(len==2)
		{
			if(c[i]==c[i+1])
			{
				if(c[i]=='A')
					ret=0;
				else
					ret=1;
			}
			else
				ret=2;
		}
		else
		{
			if(a[j+1]-a[i]==len)
				ret=0;
			else if(b[j+1]-b[j]==len)
				ret=1;
			else
				ret=2;
		}
		//printf("Base Case %d %d %d %d\n",i,j,p,ret);
		return ret;
	}
	if(foo(i,i+len/2-1,!p)==p)
	{
		//printf("%d %d %d %d a\n",i,j,p,p);
		return p;
	}
	if(foo(i+len/2,j,!p)==p)
	{
		//printf("%d %d %d %d x=%db\n",i,j,p,p,foo(i+len/2,j,!p));
		return p;
	}
	if(foo(i,i+len/2-1,!p)==2)
	{
		//printf("%d %d %d %d c\n",i,j,p,2);
		return 2;
	}
	if(foo(i+len/2,j,!p)==2)
	{
		//printf("%d %d %d %d d\n",i,j,p,2);
		return 2;
	}
	//printf("%d %d %d %d e\n",i,j,p,!p);
	return !p;
}

int main()
{
	int n,p;
	si(n);
	string x,y;
	cin>>x>>y;
	c=x+y;
	//cout<<c.length()<<'\n';
	pre();
	if(n%2==0)
		p=foo(0,c.length()-1,0);
	else
		p=2;
	if(p==0)
		printf("Alice");
	else if(p==1)
		printf("Bob");
	else
		printf("Draw");
	return 0;
}
