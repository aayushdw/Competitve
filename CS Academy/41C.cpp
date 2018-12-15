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
#define MAX 1000000+5
using namespace std;

vi v;
bitset<MAX> filled;

int main()
{
	int n,k,m;
	si(n); si(k); si(m);
	int num=1<<n;
	if(k<(1<<m) || (m!=n && k==num))
	{
		pr(-1);
		return 0;
	}
	filled.reset();
	v.resize(1<<n);
	rep(i,0,v.size())
	v[i]=0;
	rep(i,0,1<<m)
	v[i]=(i+1);
	v[(1<<m)-1]=k;
	/*rep(i,0,1<<m)
	filled[v[i]]=true;

	rep(i,1,n-m)
	{
		v[(i+1)*(1<<m)-1]=num-i-1;
		filled[num-i-1]=true;
	}
	vi tofill;
	rep(i,1,num+1)
	if(!filled[i])
		tofill.pb(i);
	int j=0;
	rep(i,0,num)
	if(!v[i])
		v[i]=tofill[j++];*/

	if((1<<m)+1 < num)
		v[(1<<m)+1] = num;

	rep(i,0,v.size())
	if(v[i])
	filled[v[i]]=true;

	rep(i,0,num)
	if(v[i])
	printf("%d ",v[i]);

	rep(i,1,(1<<n)+1)
	if(!filled[i])
		printf("%d ",i);
	return 0;
}