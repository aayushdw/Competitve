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
#define MAX 5300000
using namespace std;

int sievephi[MAX+5];  //sievephi[i]=phi(i)
vi v[1100000];
void precalc(){
  for(int i=1;i<=MAX;i++)
    sievephi[i]=i;
    
  for(int i=2;i<=MAX;i+=2)
    sievephi[i]-=sievephi[i]/2;
 
  for(int i=3;i<=MAX;i+=2)
    if(sievephi[i]==i)
      for(int j=i;j<=MAX;j+=i)
        sievephi[j]-=sievephi[j]/i;
}

bool check(ll a,ll b, ll c)
{
	return (b*b>=4*a*c);
}

int main()
{
	precalc();

	int m=0;
	rep(i,1,MAX)
	if(sievephi[i]<=1000000)
	{
		v[sievephi[i]].pb(i);
		//printf("%d %d\n",sievephi[i],i);
	}

	/*rep(i,0,10)
	{
		printf("%d -> ",i);
		rep(j,0,v[i].size())
		printf("%d ",v[i][j]);
		printf("\n");
	}*/

	int t;
	ll a,b,c,k;
	bool f;
	si(t);
	while(t--)
	{
		f=false;
		sl(a); sl(b); sl(c);
		sl(k);
		rep(i,0,v[k].size())
		if(check(a,b,c-v[k][i]))
		{
			//pr(v[k][i]);
			f=true;
			break;
		}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}