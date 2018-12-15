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
int n;
vi v;
set< ii > s;
void solve(int x, int y, int lvl, int dis,int slope)
{
	s.insert(mp(x,y));
	if(dis==v[lvl])
	{
		if(lvl==n-1)
			return;

		if(slope==0)
		{
			solve(x+1,y+1,lvl+1,1,1);
			solve(x-1,y+1,lvl+1,1,7);
		}
		else if(slope==1)
		{
			solve(x,y+1,lvl+1,1,0);
			solve(x+1,y,lvl+1,1,2);
		}
		else if(slope==2)
		{
			solve(x+1,y+1,lvl+1,1,1);
			solve(x+1,y-1,lvl+1,1,3);
		}
		else if(slope==3)
		{
			solve(x+1,y,lvl+1,1,2);
			solve(x,y-1,lvl+1,1,4);
		}
		else if(slope==4)
		{
			solve(x+1,y-1,lvl+1,1,3);
			solve(x-1,y-1,lvl+1,1,5);
		}
		else if(slope==5)
		{
			solve(x,y-1,lvl+1,1,4);
			solve(x-1,y,lvl+1,1,6);
		}
		else if(slope==6)
		{
			solve(x-1,y-1,lvl+1,1,5);
			solve(x-1,y+1,lvl+1,1,7);
		}
		else
		{
			solve(x,y+1,lvl+1,1,0);
			solve(x-1,y,lvl+1,1,6);
		}
	}
	else
	{
		if(slope==0)
			solve(x,y+1,lvl,dis+1,slope);
		else if(slope==1)
			solve(x+1,y+1,lvl,dis+1,slope);
		else if(slope==2)
			solve(x+1,y,lvl,dis+1,slope);
		else if(slope==3)
			solve(x+1,y-1,lvl,dis+1,slope);
		else if(slope==4)
			solve(x,y-1,lvl,dis+1,slope);
		else if(slope==5)
			solve(x-1,y-1,lvl,dis+1,slope);
		else if(slope==6)
			solve(x-1,y,lvl,dis+1,slope);
		else
			solve(x-1,y+1,lvl,dis+1,slope);
	}
}

int main()
{
	si(n);
	int p;
	rep(i,0,n)
	{
		si(p);
		v.pb(p);
	}
	solve(0,0,0,1,0);
	int ans=s.size();
	printf("%d",ans);
	return 0;
}