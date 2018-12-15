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
set< ii > ans;
int main()
{
	int x1,x2,x3,y1,y2,y3,midx,midy;
	si(x1); si(y1);
	si(x2); si(y2);
	si(x3); si(y3);

	midx=(x1+x2);
	midy=(y1+y2);
	//if((x1+x2)%2==0 && (y1+y2)%2==0 )
	ans.insert(mp(-x3+midx,-y3+midy));

	midx=(x3+x2);
	midy=(y3+y2);
	//if((x3+x2)%2==0 && (y3+y2)%2==0 )
	ans.insert(mp(-x1+midx,-y1+midy));

	midx=(x1+x3);
	midy=(y1+y3);
	//if((x1+x3)%2==0 && (y1+y3)%2==0 )
	ans.insert(mp(-x2+midx,-y2+midy));

	int s=ans.size();
	printf("%d\n",s);
	tr(it,ans)
	printf("%d %d\n",it->F,it->S);

	return 0;
}