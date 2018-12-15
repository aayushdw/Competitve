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


ll gcd(ll n1,ll n2)
{
	if(!n1 && !n2)
		return 0;
    else if(!n2)
       return n1;
	else if(!n1)
		return n2;
    else 
       return gcd(n2,n1%n2);
}

int arr[305];
set<ll> v[305][305];
ll num[305][12];

void store(int m,int n)
{
	rep(i,0,n)
	{
		num[i][1]=arr[i];
		rep(j,2,m+1)
		if(i+j-1<n)
		num[i][j]=num[i][j-1]*10+arr[i+j-1];
	}
}

void print(set<ll> &s)
{
	tr(it,s)
	printf("%lld ",*it);
	printf("\n");
}

int main()
{
	int t,m,x,y,n,idx;
	ll p;
	ll ans;
	si(t);
	while(t--)
	{
		si(n);
		getchar();
		rep(i,0,n)
		arr[i]=getchar()-'0';

		si(m); si(x); si(y);

		memset(num,-1,sizeof(num));

		store(m,n);

		rep(i,0,n+1)
		rep(j,0,n+1)
		v[i][j].clear();

		rep(i,0,m)
		v[i][0].insert(num[0][i+1]);

		/*
		rep(i,0,5)
		{
			rep(j,0,5)
			printf("%lld ",num[i][j]);
			printf("\n");
		}
		*/


		rep(i,1,n)
		{
			printf("I = %d\n",i);
			rep(l,1,m+1)
			{
				printf(" L = %d\n",l);
				idx=i-l+1;
				if(idx<=0)
					continue;
				p=num[idx][l];

				printf("idx=%d p=%lld\n",idx,p);

				idx--;
				if(p>=0)
				{
					rep(j,0,idx+1)
					{
						printf("j = %d\n",j);
						tr(it,v[idx][j])
						{
							printf("gcd(%lld %lld) = %lld\n",*it,p,gcd(*it,p));
							v[i][j+1].insert(gcd(*it,p));
						}
					}
				}
			}
		}

		/*
		rep(i,0,5)
		rep(j,0,5)
		{
			printf("set(%d %d)\n",i,j);
			print(v[i][j]);
		}
		*/

		ans=-1;
		rep(i,x,y+1)
		{
			tr(it,v[n-1][i])
			ans=max(ans,*it);
		}
		prll(ans);
		
	}
	return 0;
}