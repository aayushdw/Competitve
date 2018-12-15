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
#define MAX 37
using namespace std;

int len[MAX];

string f(int N) {
  if (N == 0) return "A";
  if (N == 1) return "B";
  if (N == 2) return "C";
  return f(N - 1) + f(N - 2) + f(N - 3);
}

void pre()
{
	len[0]=len[1]=len[2]=1;
	rep(i,3,MAX)
	len[i]=len[i-1]+len[i-2]+len[i-3];
}

char solve(int n,int k)
{
	if(n==0 && k==1)
		return 'a';
	if(n==1 && k==1)
		return 'b';
	if(n==2 && k==1)
		return 'c';
	if(n==3)
	{
		if(k==1)
			return 'c';
		else if(k==2)
			return 'b';
		else
			return 'a';
	}
	if(k<=len[n-1])
		solve(n-1,k);
	else
		solve(n-1,k-len[n-1]);
}

int main()
{
	pre();
	int n,k;
	si(n); si(k);
	if(k>len[n])
	{
		pr(-1);
		return 0;
	}
	cout<<solve(n,k);
	return 0;
}