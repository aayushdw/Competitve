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

vi v;

void foo(int l,int idx,int num,int zero)
{
	int a=idx/num;
	int b=idx%num;
	double x=a*l/num, y=b*l/num;
	printf("%lf %lf\n",zero+x,zero+y);
}

int main()
{
	int n,s,skip,p,rmax=0,r;
	si(n); si(s); si(skip);
	rep(i,0,2*n)
	{
		si(p);
		v.pb(p);
		rmax=max(rmax,p);
	}
	int x=n-skip;
	int num=(int)(sqrt(n-skip))+1;
	pr(num);
	sort(v.rbegin(),v.rend());
	int mx=v[skip-1];
	pr(mx);
	int mn=v[n-2*skip],c=0,skipped=0;
	rep(i,0,n)
	{
		si(r);
		if(r>mx)
		{
			printf("-1 -1\n");
			skipped++;
		}
		else
		{
			if(n-i<=skip-skipped)
			{
				printf("-1 -1\n");
				skipped++;
			}
			else
			{
				foo(n-2*rmax,c,num,rmax);
				c++;
			}
		}
		fflush(stdout);
	}
	return 0;
}