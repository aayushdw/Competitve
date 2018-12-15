#include <bits/stdc++.h>
 
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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 10000000
using namespace std;

int phi(int n)
{
  int result=n,i;
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    result-=result/i;
    while(n%i==0)
    n/=i;
    //printf("i=%d result=%d n=%d\n",i,result,n);
  }
  if(n>1)
  result-=result/n;
  return result;
}

bool isHamming(int n)
{
	while(n%2==0) n/=2;
	while(n%3==0) n/=3;
	while(n%5==0) n/=5;
	return n==1;
}

int main()
{
	ll ans = 0;
	rep(i,2,MAX+1)
	{
		ans += i*isHamming(phi(i));
		// if(isHamming(phi(i)))
		// 	pr(i);
	}
	prll(ans);
	return 0;
}