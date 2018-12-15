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

int a[MAX],b[MAX];

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int cur=0;
	rep(i,0,n)
	{
		a[i]=cur;
		if(s[i]=='0')
			cur++;
		else
			cur=0;
	}
	cur=0;
	for(int i=n-1;i>=0;i--)
	{
		b[i]=cur;
		if(s[i]=='0')
			cur++;
		else
			cur=0;
	}


	vi p;
	p.pb(s[0]=='1');
	rep(i,0,s.size())
	if(s[i]!=s[i-1])
		p.pb(s[i]=='1');
	int inv=0;
	rep(i,0,p.size())
	inv+=!p[i];


	int x=0;
	rep(i,0,n)
	x+=s[i]=='1';
	if(x==1)
	{
		pr(n-1);
		return 0;
	}
	//printf("afaf");
	int ans=0;
	rep(i,0,n)
	ans=max(ans,a[i]);
	rep(i,0,n)
	if(s[i]=='1')
	{
		if(inv==1 && i+1<n && s[i+1]=='0')
			continue;
		if(inv==1 && i-1>=0 && s[i-1]=='0')
			continue;
		if(inv==2 && i>0 && i<n-1 && s[i-1]=='0' && s[i+1]=='0')
			continue;
		ans=max(a[i]+b[i]+1,ans);
	}
	pr(ans);
	return 0;
}