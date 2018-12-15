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

int solve(int p,int prev)
{
	vi v;
	int k,x;
	while(1)
	{
		v.clear();
		printf("? %d\n",p);
		fflush(stdout);
		si(k);
		rep(i,0,k)
		{
			si(x);
			v.pb(x);
		}

		if(k==1)
			return -1;
		else if(k==2)
			return p;
		else
		{
			rep(i,0,k)
			if(v[i]!=prev)
			{
				prev=p;
				p=v[i];
				break;
			}
		}
	}
}

int main()
{
	int t,h,k,p,ans,x,q;
	si(t);
	vi v;
	while(t--)
	{
		v.clear();
		si(h);
		printf("? 1\n");
		fflush(stdout);
		si(k);
		rep(i,0,k)
		{
			si(p);
			v.pb(p);
		}
		if(k==1)
		{
			q=v[0];

			v.clear();
			printf("? %d\n",q);
			fflush(stdout);
			si(k);
			rep(i,0,k)
			{
				si(x);
				v.pb(x);
			}

			if(k==2)
			{
				ans=q;
				printf("! %d\n",ans);
				fflush(stdout);
				continue;
			}

			rep(i,0,k)
			{
				if(v[i]==1)
					continue;
				ans=solve(v[i],q);
				if(ans>0)
					break;
			}

			printf("! %d\n",ans);
			fflush(stdout);
			continue;
		}
		else if(k==2)
		{
			printf("! 1\n");
			fflush(stdout);
			continue;
		}
		else
		{
			bool flag=false;
			rep(i,0,3)
			{
				if(flag)
					break;
				p=v[i];
				ans=solve(p,1);
				//printf("ans = %d\n",ans);
				if(ans>0)
				{
					printf("! %d\n",ans);
					fflush(stdout);
					flag=true;
					break;
				}
			}
		}
	}
	return 0;
}	