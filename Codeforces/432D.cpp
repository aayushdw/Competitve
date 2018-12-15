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

int z[MAX],a[MAX];
bitset<MAX> isPreSuf;

#define MAXN 1000005

struct BIT	//	1-based indexing
{
	int ft[MAXN];
	void init()
	{	clr(ft);	}
	void update(int i,int v)
	{	for(; i<=MAXN ; i+=i&(-i)) ft[i]+=v;	}
	int query(int i)
	{
		int s=0;
		for(; i>0 ; i-=i&(-i))	s+=ft[i];
		return s;
	}
};

struct lazyBIT
{
	int B1[MAXN],B2[MAXN];
	void init()
	{	clr(B1); clr(B2);	}
	void update(int ft[],int i,int v)
	{	for(; i<=MAXN ; i+=i&(-i))	ft[i]+=v;	}
	void update(int a,int b,int v)
	{
		update(B1,a,v);
		update(B1,b+1,-v);
		update(B2,a,v*(a-1));
		update(B2,b+1,-v*b);
	}
	int query(int ft[],int i)
	{
		int s=0;
		for(; i>0 ; i-=i&(-i))	
			s+=ft[i];
		return s;
	}
	int query(int i)
	{	return query(B1,i)*i-query(B2,i);	}
	int query(int a,int b)
	{	return query(b)-query(a-1);		}
};

void calcZ(int Z[],string s)
{
	int L = 0, R = 0;
	int n=s.length();
	for (int i = 1; i < n; i++)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			Z[i] = R-L; R--;
		}
		else
		{
			int k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];
			else
			{
				L = i;
				while (R < n && s[R-L] == s[R])
					R++;
				Z[i] = R-L; R--;
			}
		}
	}
}

int main()
{
	clr(z); clr(a);
	isPreSuf.reset();
	string s;
	cin>>s;
	calcZ(z,s);
	int n=s.length(),num=1;
	isPreSuf[n]=true;
	lazyBIT tree;
	tree.init();
	rep(i,1,n)
	{
		if(n-i+z[n-i]==n)
		{
			num++;
			isPreSuf[i]=true;
		}
		if(z[i])
			tree.update(1,z[i],1);
	}
	pr(num);
	int sum=0;
	rep(i,1,n+1)
	{
		sum+=a[i-1];
		if(isPreSuf[i])
			printf("%d %d\n",i,tree.query(i,i)+1);
	}
	return 0;
}