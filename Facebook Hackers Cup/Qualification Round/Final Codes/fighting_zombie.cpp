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
#define vl vector<double>
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

vl v[21][21];

void multiply(vl &a, vl &b, vl &c)
{
	ll asize=a.size(), bsize=b.size();
	ll csize=asize+bsize-1;
	c.resize(csize);
	rep(i,0,asize)
	rep(j,0,bsize)
	c[i+j]+=a[i]*b[j];
}

void pre(ll p)
{
	v[p][1].pb(0);
	rep(i,1,p+1)
	v[p][1].pb(1.0);
	rep(i,2,21)
	multiply(v[p][1],v[p][i-1],v[p][i]);
}

pair< pll,ll > scan()
{
	pair< pll,ll > ret;
	char s[50];
	scanf("%s",s);
	ll l=strlen(s),x=0,y=0,z=0,i;

	for(i=0;s[i]!='d';i++)
	{
		x*=10;
		x+=s[i]-'0';
	}

	i++;
	
	for(;s[i]!='\0' && s[i]!='-' && s[i]!='+';i++)
	{
		y*=10;
		y+=s[i]-'0';
	}
	
	if(s[i]=='\0')
	ret=mp(mp(x,y),z);
	else
	{
		ll mul;
		if(s[i]=='-')
			mul=-1;
		else
			mul=1;

		i++;
		for(;s[i]!='\0';i++)
		{
			z*=10;
			z+=s[i]-'0';
		}
		z*=mul;
		ret=mp(mp(x,y),z);
	}
	return ret;
}

int main()
{
	pre(4); pre(6); pre(8); pre(10); pre(12); pre(20);
	/*rep(i,1,21)
	{
		printf("Number of Throws : %d\n",i);
		int asize=v[6][i].size();
		
		ll sum=0;
		rep(j,0,asize)
		//printf("%2lld ",v[4][i][j]);
		sum+=v[6][i][j];
		prll(sum);
	}*/

	ll t,h,n,x,y,z;
	pair< pll,ll > s;
	double ans;
	sl(t);
	rep(j,1,t+1)
	{
		ans=-1.0;
		sl(h); sl(n);
		//printf("START\n");
		while(n--)
		{
			s=scan();
			//printf("%lld %lld %lld\n",s.F.F,s.F.S,s.S);
			x=s.F.F, y=s.F.S, z=s.S;
			double favor=0.0,total=0.0;
			rep(i,0,v[y][x].size())
			{
				if(i+z>=h)
					favor+=v[y][x][i];
				total+=v[y][x][i];
			}
			//printf("(%lf / %lf)\n",favor,total);
			ans=max(ans,favor*1.0/total);
		}
		printf("Case #%d: %0.15lf\n",j,ans);
	}

	return 0;
}