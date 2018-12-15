#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 100000000
#define MAX 500
#define MAXN 200000+5
#define MOD 1000000007
using namespace std;
bitset<MAX> t;
int primes[200],ct,a[MAXN],ans[MAXN],last[MAXN];
void seive()
{
	t.reset();
	t[0]=true; t[1]=true; t[2]=false;
	
	ll i=2,j;
	while(i*2<MAX)
	{
		t[i*2]=1;
		i++;
	}
	i=2;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j+=2;
		}
		i++;
	}
	
	j=0;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	//j++;
	//printf("%lld",j);
	
	ct=j;
	return;
}
int getAbs(int a)
{
	return a>0?a:-a;
}
int main()
{
	seive();
	int n,p,dist,prev,c;
	rep(i,0,MAXN)
	last[i]=-1;
	sc(n);
	rep(i,0,n)
	{
		sc(a[i]);
		ans[i]=INF;
		rep(j,0,ct)
		{
			c=0;
			p=primes[j];
			while(a[i]%p==0)
			{
				a[i]/=p;
				c++;
			}
			if(c)
			{
				if(last[p]>=0)
				{
					if(getAbs(last[p]-i)<getAbs(ans[i]-i))
						ans[i]=last[p];
					if(getAbs(ans[last[p]]-last[p])>getAbs(i-last[p]))
						ans[last[p]]=i;
				}
				last[p]=i;
			}
		}
		if(a[i]>1)
		{
			p=a[i];
			if(last[p]>=0)
			{
				if(getAbs(last[p]-i)<getAbs(ans[i]-i))
					ans[i]=last[p];
				if(getAbs(ans[last[p]]-last[p])>getAbs(i-last[p]))
					ans[last[p]]=i;
			}
			last[p]=i;
		}
	}
	rep(i,0,n)
	ans[i]==INF?ans[i]=-1:ans[i]++;
	rep(i,0,n)
	printf("%d ",ans[i]);
}