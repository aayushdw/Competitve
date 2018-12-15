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
#define INF 1000000000
#define MAX 100000+5

using namespace std;

bool flag=true;

ii inter(ii a, ii b)
{
	ii ans;
	ans.F=max(a.F,b.F);
	ans.S=min(a.S,b.S);
	if(ans.F>ans.S)
		flag=false;
	return ans;
}

int main()
{
	int n,a=0,c,d,b,prev=0;
	ii x,rat=mp(-INF,INF);
	si(n);
	while(n--)
	{
		si(c); si(d);
		if(rat.F==-INF && rat.S==INF)
		{
			if(d==1)
			{
				x=mp(1900,INF);
				rat=inter(x,rat);
			}
			if(d==2)
			{
				x=mp(-INF,1899);
				rat=inter(x,rat);
			}
			a+=c;
		}
		else
		{
			if(d==1)
			{
				x=mp(1900-a,INF);
				rat=inter(rat,x);
			}
			else
			{
				x=mp(-INF,1899-a);
				rat=inter(rat,x);
			}
			a+=c;
		}
	}
	if(!flag)
	{
		printf("Impossible");
		return 0;
	}
	if(rat.S==INF)
		printf("Infinity");
	else
		printf("%d",rat.S+a);
	return 0;
}