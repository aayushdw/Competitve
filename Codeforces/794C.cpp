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
#define MAX 300000+5
using namespace std;

vector<char> x,y;
char ans[MAX];

int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	int n=a.length();
	rep(i,0,n)
	x.pb(a[i]);
	rep(i,0,n)
	y.pb(b[i]);
	sort(all(x));
	sort(all(y));
	reverse(all(y));
	int xp=0,yp=0,next=0;
	int xmax=n/2+n%2;
	int ymax=n-xmax;
	int flag=INT_MAX;
	rep(i,0,n)
	{
		if(i%2)	//from y
		{
			if(x[xp]>y[yp] && flag==INT_MAX)
			{
				//pr(i);
				if(n%2)
					flag=i;
				else
				flag=-1;
			}
			ans[next]=y[yp];
			next++;
			yp++;
		}
		else	//from x
		{
			if(y[yp]<x[xp] && flag==INT_MAX)
				flag=i;
			ans[next]=x[xp];
			next++;
			xp++;
		}
	}
	//pr(flag);
	if(flag!=INT_MAX && flag!=-1)
	{
		for(int i=flag;i+1<n;i+=2)
			swap(ans[i],ans[i+1]);
	}
	rep(i,0,n)
	printf("%c",ans[i]);
	return 0;
}