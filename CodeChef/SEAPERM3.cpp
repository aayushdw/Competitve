#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
vector< ii > rules;
bool check(int a[],int n)
{
	rep(i,1,n+1)
	rep(j,1,n+1)
	if(i<j && a[i]>j && a[j]>i)
		return true;
	return false;
}
int main()
{
	int t,n,m,x,y,c,a[25];
	bool f;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		rules.clear();
		rep(i,0,m)
		{
			sc(x); sc(y);
			rules.pb(mp(x,y));
		}
		rep(i,1,n+1)
		a[i]=i;
		c=0;
		do
		{
			if(!check(a,n))
				continue;
			f=true;
			rep(i,0,m)
			if(a[rules[i].first]!=rules[i].second)
				f=false;
			if(f)
			{
				c++;
			}
		} while(next_permutation(a+1,a+n+1));
		pr(c);
	}
	return 0;
}