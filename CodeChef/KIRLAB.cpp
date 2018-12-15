#include<bits/stdc++.h>
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define pb push_back
#define MAX 10000000+100
#define MAXN 100000+100
using namespace std;
bitset<MAX> t;
int primes[2000];
int a[MAXN],ans[MAXN],dp[MAX];
vector<int> primefactors[MAX];
void seive()
{
	t.reset();
	t[0]=t[1]=true;
	int i=2,j;
	while(i*2<MAX)
	{
		t[i*2]=true;
		i++;
	}
	i=3;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i+=2;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=true;
			j+=2;
		}
		i+=2;
	}
	j=0;
	for(i=2;i<4000;i++)
		if(!t[i])
			primes[j++]=i;
	return;
}

int main()
{
	seive();
	/*rep(i,0,50)
	printf("%d %d\n",i+1,primes[i]);
	return 0;*/
	int q,n,p;
	sd(q);
	while(q--)
	{
		sd(n);
		memset(dp,-1,sizeof(dp));
		memset(ans,-1,sizeof(ans));
		rep(i,0,n)
		{
			sd(a[i]);
			if(primefactors[a[i]].empty())
			{
				if(!t[a[i]])
					primefactors[a[i]].pb(a[i]);
				else
				{
					p=a[i];
					for(int j=0;primes[j]*primes[j]<=p;j++)
					if(a[i]%primes[j]==0)
					{
						primefactors[a[i]].pb(primes[j]);
						//printf("%d ",primes[j]);
						while(p%primes[j]==0)
							p/=primes[j];
						if(!t[p] || p==1)
							break;
					}
					if(p>1)
						primefactors[a[i]].pb(p);
				}
			}
		}
		rep(i,0,n)
		{
			p=a[i];
			//printf("iter = %d, num = %d\nPrime Factors: ",i,p);
			rep(j,0,primefactors[p].size())
			{
				//printf("%d ",primefactors[p][j]);
				if(dp[primefactors[p][j]]>=0)
				ans[i]=max(ans[i],ans[dp[primefactors[p][j]]]+1);
			}
			if(ans[i]<=0)
				ans[i]=1;
			rep(j,0,primefactors[p].size())
			dp[primefactors[p][j]]=i;
		}
		int print=0;
		rep(i,0,n)
		print=max(print,ans[i]);
		pd(print);
	}
	return 0;
}