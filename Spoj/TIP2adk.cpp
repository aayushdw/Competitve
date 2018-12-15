#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<map>

#define MOD 1000000007
#define MAX 1010000
#define identity 0
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define DBUG(x) cout<<x<<endl;
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)

using namespace std;

bool sieveprime[MAX/2+5];

void precalc_prime()
{
	int MAX_2=MAX/2+3;
	
	for(int i=1;i<=MAX_2;i++)
		sieveprime[i]=0;
		
	for(int i=3;i*i<=MAX;i+=2)
		if(!sieveprime[i/2])
			for(int j=i*i;j<=MAX;j+=2*i)
				sieveprime[j/2]=1;
}

pll start;

inline bool great(pll &a,pll &b)
{
	ll lhs=a.first*a.second;
	
	ll rhs=b.first*b.second + a.first*b.first*(a.second-b.second) + a.second*b.second*(a.first-b.first);
	
	if(lhs>rhs) return 1;
	else return 0;
}

bool permut(pll inp)
{
	ll a=inp.first*inp.second,b=(inp.first-1)*(inp.second-1);
	
	// check if a and b are permutation of each other
	
	ll diga[]={0,0,0,0,0,0,0,0,0,0},digb[]={0,0,0,0,0,0,0,0,0,0};
	
	ll ka=1,kb=1;
	
	while(a/ka!=0)
	{
		diga[(a/ka)%10]++;
		ka*=10;
	}
	
	while(b/kb!=0)
	{
		digb[(b/kb)%10]++;
		kb*=10;
	}
	
	for(int i=0;i<10;i++) if(diga[i]!=digb[i]) return 0;
	return 1;
}

ll solve(ll m)
{
	ll mid=sqrt(m)+1e-8;
	
	pll req=start;
	
	if(mid%2==0) mid--;
	
	for(ll i=mid;i>2;i-=2)
		if(!sieveprime[i>>1])
		{
			// find first prime less than or equal to m/i
			ll j=m/i;
			if(j%2==0) j--;
			
			for(;j>=i;j-=2) if(!sieveprime[j>>1]) break;
			
			pll f=mp(i,j);
			if(great(f,req)) break;
			
			for(;j>i;j-=2)
				if(!sieveprime[j>>1])
				{
					f=mp(i,j);
					if(great(f,req)) break;
					
					if(permut(f))
						req=f;
				}
 		}
 		
 	return req.first*req.second;
}

int main()
{
	precalc_prime();
	/*
	start.first=3;
	start.second=7;

	int t;
	sd(t);
	while(t--)
	{
		ll m;
		slld(m);
		
		if(m<22) printf("No solution.\n");
		else if(m>=64&&m<292) printf("63\n");
		else if(m>=2818&&m<2992) printf("2817\n");
		else plld(solve(m-1));
	}
	*/
}