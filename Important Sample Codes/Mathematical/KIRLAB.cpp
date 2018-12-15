#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 10000000+5
using namespace std;

bitset<MAX> t;
int primes[665000],ct;
void seive()
{
	t.reset();
	t[0]=true; t[1]=true; t[2]=false;
	
	int i=2,j;
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
	ct=j;
	return;
}

int ans[100005],arr[MAX],a[100005];

void initialise()
{
	memset(ans,-1,sizeof(ans));
}

int main()
{
	seive();

	int t,n,p;
	sc(t);
	while(t--)
	{
		sc(n);
		initialise();
		rep(i,0,n)
		{
			sc(a[i]);
			p=a[i];
			ans[i]=1;

			for(int j=0; primes[j]*primes[j]<=a[i]; j++)
				if(p%primes[j]==0)
				{
					ans[i]=max(ans[i],ans[arr[primes[j]]]+1);
					while(p%primes[j]==0)
						p/=primes[j];
				}
			if(p>1)
				ans[i]=max(ans[i],ans[arr[p]]+1);

			p=a[i];

			for(int j=0; primes[j]*primes[j]<=a[i]; j++)
				if(p%primes[j]==0)
				{
					arr[primes[j]]=i;
					while(p%primes[j]==0)
						p/=primes[j];
				}

			if(p>1)
				arr[p]=i;
		}

		int ret=0;
		rep(i,0,n)
			ret=max(ret,ans[i]);

		pr(ret);
	}
	return 0;
}