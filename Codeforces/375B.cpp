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
#define MAX 5000+5
using namespace std;

int arr[MAX];
vi v[MAX];

int main()
{
	int n,m,cur,ans=0;
	si(n); si(m);
	rep(i,0,n)
	{
		getchar();
		rep(j,0,m)
		arr[j]=getchar()-'0';
		cur=0;
		for(int j=m-1;j>=0;j--)
		if(arr[j])
			v[j].pb(++cur);
		else
			v[j].pb(cur=0);
	}
	rep(i,0,m)
	{
		sort(v[i].rbegin(),v[i].rend());
		rep(j,0,n)
		ans=max(ans,(j+1)*v[i][j]);
	}
	pr(ans);
	return 0;
}