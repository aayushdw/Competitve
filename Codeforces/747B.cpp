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
#define MAX 100000+5

using namespace std;

int main()
{
	int n;
	si(n);
	getchar();
	vi v;
	vector<char> ans;
	char p;
	int a=0,c=0,g=0,t=0;
	rep(i,0,n)
	{
		p=getchar();
		if(p=='A')
		{
			a++;
		}
		else if(p=='C')
		{
			c++;
		}
		else if(p=='G')
		{
			g++;
		}
		else if(p=='T')
		{
			t++;
		}
		else
			v.pb(i);
		ans.pb(p);
	}
	if(n%4!=0 || a>n/4 || c>n/4 || g>n/4 || t>n/4)
	{
		printf("===");
		return 0;
	}
	else
	{
		//printf("%d\n",(int)(v.size()));
		//rep(i,0,)
		int idx=0;
		while(a<n/4)
		{
			ans[v[idx]]='A';
			idx++;
			a++;
		}
		while(c<n/4)
		{
			ans[v[idx]]='C';
			idx++;
			c++;
		}
		while(g<n/4)
		{
			ans[v[idx]]='G';
			idx++;
			g++;
		}
		while(t<n/4)
		{
			ans[v[idx]]='T';
			idx++;
			t++;
		}
		rep(i,0,n)
	printf("%c",ans[i]);
	}
	
	return 0;
}