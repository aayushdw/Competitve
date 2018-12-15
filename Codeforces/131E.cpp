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
#define MAX 400000+5
using namespace std;

vi h[MAX],v[MAX],d1[MAX],d2[MAX];
int n;

int getd1(int x,int y)
{
	return x+y;
}

int getd2(int x,int y)
{
	int ret = x>y ? x-y : 2*n+y-x+5;
	return ret;
}

int main()
{
	int m,t[9]={0},x,y;
	si(n); si(m);
	rep(i,0,m)
	{
		si(x); si(y);
		h[x].pb(y);
		v[y].pb(x);
		d1[getd1(x,y)].pb(x);
		d2[getd2(x,y)].pb(x);
	}

	rep(i,0,MAX)
	{
		sort(all(h[i]));
		sort(all(v[i]));
		sort(all(d1[i]));
		sort(all(d2[i]));
	}
	rep(i,0,MAX)
	{
		rep(j,0,h[i].size())
		{
			int curr = (j==0 || j+1==h[i].size()) ? 1 : 2;
			if(h[i].size()==1)
				curr=0;
			x=i; y=h[i][j];

			if(v[y].size()==1)
				curr=curr;
			else if(v[y].front()==x || v[y].back()==x)
				curr++;
			else
				curr+=2;

			y=getd1(x,h[i][j]);

			if(d1[y].size()==1)
				curr=curr;
			else if(d1[y].front()==x || d1[y].back()==x)
				curr++;
			else
				curr+=2;

			
			y=getd2(x,h[i][j]);
			
			if(d2[y].size()==1)
				curr=curr;
			else if(d2[y].front()==x || d2[y].back()==x)
				curr++;
			else
				curr+=2;
			t[curr]++;
		}
	}
	for(int i=0;i<=8;i++)
	printf("%d ",t[i]);
	return 0;
}