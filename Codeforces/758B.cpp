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
#define INF 10000000000000000
#define MAX 1000
using namespace std;

char s[MAX];
int ans[4]={0};

bool check(int idx)
{
	int a[5]={0},p;
	rep(i,idx,idx+4)
	{
		if(s[i]=='R')
			a[0]++;
		else if(s[i]=='B')
			a[1]++;
		else if(s[i]=='Y')
			a[2]++;
		else if(s[i]=='G')
			a[3]++;
		else
		{
			p=i;
			a[4]++;
		}
	}
	//printf("a[4]=%d\n",a[4]);
	if(a[4]==1)
	{
		//printf("asdf");
		if(!a[0])
		{
			s[p]='R';
			ans[0]++;
		}
		if(!a[1])
		{
			s[p]='B';
			ans[1]++;
		}
		if(!a[2])
		{
			s[p]='Y';
			ans[2]++;
		}
		if(!a[3])
		{
			s[p]='G';
			ans[3]++;
		}
		return true;
	}
	return false;
}

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	int c=0,n;
	rep(i,0,l)
	if(s[i]=='!')
		c++;
	while(c)
	{
		rep(i,0,l-3)
			if(check(i))
				c--;
		//pr(c);
	}
	rep(i,0,4)
	printf("%d ",ans[i]);
	return 0;
}