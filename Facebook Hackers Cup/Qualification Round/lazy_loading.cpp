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
#define MAX 100+5
using namespace std;

int a[MAX];
set< ii > s;
int main()
{
	int t,n,ans,p,num,c;
	si(t);
	rep(j,1,t+1)
	{
		s.clear();
		si(n);
		rep(i,0,n)
		{
			si(p);
			s.insert(mp(p,i));
		}
		ans=0;
		while(1)
		{
			num=s.rbegin()->F;
			p=s.rbegin()->S;
			s.erase(mp(num,p));
			c=(50%num)?(50/num):(50/num-1);
			
			if((int)(s.size())<c)
				break;
			ans++;
			while(c--)
				s.erase(s.begin());

			if(s.empty())
				break;

		}
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}