#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
ll a[MAX],b[MAX],c[MAX],d[MAX];
vector< pll > v;
vector<ll> s(MAX);
vector<ll>::iterator x,y;
void span1(ll a[],ll n,ll s[])
{
	stack<int> st;
	st.push(0);
	s[0]=1;
	rep(i,1,n)
	{
		while(!st.empty() && a[st.top()]<a[i])
			st.pop();
		s[i]=(st.empty())?(i+1):(i-st.top());
		st.push(i);
	}
}
void span2(ll a[],ll n,ll s[])
{
	stack<int> st;
	st.push(0);
	s[0]=1;
	rep(i,1,n)
	{
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		s[i]=(st.empty())?(i+1):(i-st.top());
		st.push(i);
	}
}
int main()
{
	ll t,n,q,p;
	scll(t);
	while(t--)
	{
		v.clear();
		scll(n); scll(q);
		rep(i,0,n)
		scll(a[i]);

		span1(a,n,b);
		/*
		rep(i,0,n)
		printf("%2d ",b[i]);
		printf("\n");
		*/
		reverse(a,a+n);

		span2(a,n,c);
		reverse(c,c+n);

		/*
		rep(i,0,n)
		printf("%2d ",c[i]);
		printf("\n");
		int sum=0;
		*/

		reverse(a,a+n);

		rep(i,0,n)
			v.pb(mp(a[i],c[i]*b[i]));

		sort(v.rbegin(),v.rend());
		s[0]=v[0].second;
		rep(i,1,v.size())
		s[i]=v[i].second+s[i-1];
		/*
		rep(i,0,n)
		printf("%3lld ",v[i].first);
		printf("\n");
		rep(i,0,n)
		printf("%3lld ",s[i]);
		printf("\n");
		*/
		while(q--)
		{
			scll(p);
			if(p<s[0])
				printf("%lld\n",v[0].first);
			else
			{
				printf("%lld\n",v[lower_bound(s.begin(),s.begin()+n,p)-s.begin()].first);
			}
		}
	}
	return 0;
}