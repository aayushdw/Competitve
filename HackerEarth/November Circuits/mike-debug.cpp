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
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
bitset<MAX> t;
int primes[20000],ct,a[MAX],ans[MAX];
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
	int n,p,dist,prev;
	sc(n);
	rep(i,0,n)
	{
		sc(a[i]);
		ans[i]=INF;
	}
	rep(i,0,ct)
	{
		p=primes[i]; prev=-1;
		rep(j,0,n)
		if(a[j]%p==0)
		{
			if(prev>=0)
			{
				dist=j-prev;
				if(dist<getAbs(ans[prev]-prev))
					ans[prev]=j;
				if(dist<=getAbs(ans[j]-j))
					ans[j]=prev;
			}
			prev=j;
		}
	}
	rep(i,0,n)
	if(ans[i]==INF)
		ans[i]=-2;
	rep(i,0,n)
	printf("%d ",ans[i]+1);
	return 0;
}