#include<bits/stdc++.h>
#include<unordered_map>
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

unordered_map<int,int> m;
int a[MAX];

int main()
{
	int t,n;
	ll ans;
	si(t);
	while(t--)
	{
		m.clear();
		ans=0;
		si(n);
		rep(i,0,n)
		si(a[i]);
		
		int tmax=a[0], cmax=a[0];
		rep(i,1,n)
		{
			cmax=max(a[i],cmax+a[i]);
			tmax=max(tmax,cmax);
		}

		int presum=0;
		rep(i,0,n)
		{
			presum+=a[i];
			ans+=m[presum-tmax];
			if(presum==tmax)
				ans++;
			//pr(ans);
			m[presum]++;
		}
		printf("%d %lld\n",tmax,ans);
	}
	return 0;
}