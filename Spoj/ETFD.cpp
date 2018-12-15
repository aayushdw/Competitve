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

int sievephi[MAX+5],depth[MAX],ans[MAX][21];  //seivephi[i]=phi(i)
 
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

void dfs()
{
	clr(ans);
	depth[1]=0;
	ans[1][0]=1;
	rep(i,2,MAX)
	{
		depth[i]=depth[sievephi[i]]+1;
		ans[i][depth[i]]=1;
		//printf("(%d %d)\n",i,depth[i]);
	}
	rep(i,1,MAX)
	{
		rep(j,0,21)
		{
			ans[i][j]+=ans[i-1][j];
			//printf("%2d ",ans[i][j]);
		}
		//printf("\n");
	}
}

int main()
{
	precalc();
	dfs();
	int t,m,n,p;
	si(t);
	while(t--)
	{
		si(m);	si(n);
		si(p);
		//pr(depth[p]);
		//printf("%d %d %d\n",depth[p],ans[n][p],ans[m-1][p]);
		pr(ans[n][p]-ans[m-1][p]);
	}
	return 0;
}