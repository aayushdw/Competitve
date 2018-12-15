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

bitset<MAX> t;
int primes[9600],ct;
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
	i=3;
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
		i+=2;
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

int a[MAX],ans[MAX]={0};

int main()
{
	seive();
	int n;
	si(n);
	rep(i,0,n)
		si(a[i]);

	if(n==1)
	{
		printf("1");
		return 0;
	}

	int p,c=0;
	for(int i=0;primes[i]<500;i++)
	{
		p=primes[i];
		rep(j,0,n)
		if(a[j]%p==0)
		{
			ans[p]++;
			while(a[j]%p==0)
				a[j]/=p;
		}
	}

	rep(i,0,n)
	ans[a[i]]++;

	c=1;
	rep(i,2,MAX)
	c=max(c,ans[i]);

	printf("%d",c);
	
	return 0;
}