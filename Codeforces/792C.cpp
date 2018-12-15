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
#define MAX 100000+5
using namespace std;

int a[MAX],n;

int getStart(int k)
{
	int i=k;
	while(i<n-1 && a[i]==0) i++;
	return i;
}

int main()
{
	string s;
	cin>>s;
	n=s.length();
	int poss1,poss2,sum=0;
	rep(i,0,s.length())
	{
		a[i]=s[i]-'0';
		sum+=a[i];
	}
	sum%=3;
	if(!sum)
	{
		int i=getStart(0);
		for(;i<n;i++)
			printf("%d",a[i]);
		return 0;
	}
	else if(sum==1)
	{
		int k=getStart(0);
		rep(i,k+1,n)
		{
			if(a[i]==1)
			{
				rep(j,k,i)
				printf("%d",a[j]);
				rep(j,i+1,n)
				printf("%d",a[j]);
				return 0;
			}
		}
		int count2=0;
		rep(i,0,n)
			if(a[i]==2)
				count2++;
		if(count2<2)
			poss2=INT_MAX;
		else if(count2>2 || a[0]!=2)
			poss2=2;
		else
			poss2=getStart(1);

		if(a[0]==1)
			poss1=getStart(1);
		else
			poss1=INT_MAX;

		if(poss1==n)
			poss1=INT_MAX;
		if(poss2==n)
			poss2=INT_MAX;


		if(poss1<poss2)
		{
			rep(i,poss1,n)
			printf("%d",a[i]);
			return 0;
		}
		else if(poss2<poss1)
		{
			if(count2>2 || a[0]!=2)
			{
				int num2=0;
				printf("%d",a[0]);
				rep(i,1,n)
				if(a[i]!=2 || num2>=2)
					printf("%d",a[i]);
				else
					num2++;
				return 0;
			}
			else
			{
				vi v;
				int k=getStart(1);
				int num2=1;
				rep(i,k,n)
				if(a[i]!=2 || num2>=2)
					v.pb(a[i]);
				else
					num2++;

				if(v.empty())
					pr(-1);
				else
				{
					rep(i,0,v.size())
					printf("%d",v[i]);
				}
				return 0;
			}
		}
		else
		{
			if(poss1<INT_MAX)
			{
				rep(i,poss1,n)
				printf("%d",a[i]);
				return 0;
			}
			else
				printf("-1");
		}

	}

	else
	{
		int k=getStart(0);
		rep(i,k+1,n)
		{
			if(a[i]==2)
			{
				rep(j,k,i)
				printf("%d",a[j]);
				rep(j,i+1,n)
				printf("%d",a[j]);
				return 0;
			}
		}
		int count1=0;
		rep(i,0,n)
			if(a[i]==1)
				count1++;
		if(count1<2)
			poss1=INT_MAX;
		else if(count1>2 || a[0]!=1)
			poss1=2;
		else
			poss1=getStart(1);

		if(a[0]==2)
			poss1=getStart(1);
		else
			poss2=INT_MAX;

		if(poss1==n)
			poss1=INT_MAX;
		if(poss2==n)
			poss2=INT_MAX;

		if(poss2<poss1)
		{
			rep(i,poss2,n)
			printf("%d",a[i]);
			return 0;
		}
		else if(poss1<poss2)
		{
			if(count1>2 || a[0]!=1)
			{
				int num1=0;
				printf("%d",a[0]);
				rep(i,1,n)
				if(a[i]!=1 || num1>=2)
					printf("%d",a[i]);
				else
					num1++;
				return 0;
			}
			else
			{
				vi v;
				int k=getStart(1);
				int num1=1;
				rep(i,k,n)
				if(a[i]!=1 || num1>=2)
					v.pb(a[i]);
				else
					num1++;

				if(v.empty())
					pr(-1);
				else
				{
					rep(i,0,v.size())
					printf("%d",v[i]);
				}
				return 0;
			}
		}
		else
		{
			if(poss2<INT_MAX)
			{
				rep(i,poss2,n)
				printf("%d",a[i]);
				return 0;
			}
			else
				printf("-1");
		}
	}

	return 0;
}