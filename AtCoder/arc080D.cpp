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
#define MAX 10000+5
using namespace std;

int a[MAX];
int F[105][105];

int main()
{
	int h,w,n;
	si(h); si(w); si(n);
	clr(a); clr(F);
	rep(i,0,n)
	si(a[i]);
	int x=0,y=0;
	bool flag = true;
	rep(i,0,n)
	{
		int num = a[i];
		while(num)
		{
			F[x][y]=i+1;
			if(flag) y++;
			else y--;
			num--;
			if(y==w)
			{
				x++;
				y=w-1;
				flag=!flag;
			}
			else if(y==-1)
			{
				x++;
				y=0;
				flag=!flag;
			}
		}
	}
	rep(i,0,h)
	{
		rep(j,0,w)
		printf("%d ",F[i][j]);
		printf("\n");
	}
	return 0;
}