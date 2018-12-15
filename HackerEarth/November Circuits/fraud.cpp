#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
bitset<MAX> t;
ll primes[20000],ct;
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
int factors[15][2],fcount=0;
int dp[15][MAX];
int bin_search(int arr[],int start,int end, int key)
{
	if(key<0 || start>end)
		return -2;
	if(arr[0]>key)
		return -1;
	if(start==end)
		return start;
	if(end==start+1)
	{
		if(arr[end]<=key)
			return end;
		else
			return start;
	}
	int mid=(start+end)/2;
	if(arr[mid]<=key)
		return bin_search(arr,mid,end,key);
	else
		return bin_search(arr,start,mid-1,key);
}
int main()
{
	int n,k,c,p,idx;
	ll ans=0;
	sc(n); sc(k);
	seive();
	rep(i,0,ct)
	if(k%primes[i]==0)
	{
		c=0;
		while(k%primes[i]==0)
			k/=primes[i], c++;
		factors[fcount][0]=primes[i]; factors[fcount++][1]=c;
	}
	if(k>1)
		factors[fcount][0]=k, factors[fcount++][1]=1;
	rep(i,0,n)
	{
		sc(p);
		rep(j,0,fcount)
		{
			c=0;
			while(p%factors[j][0]==0)
				p/=factors[j][0], c++;
			i>0?dp[j][i]=dp[j][i-1]+c:dp[j][i]=c;
		}
		idx=i+1;
		rep(j,0,fcount)
			idx=min(idx,bin_search(dp[j],0,i,dp[j][i]-factors[j][1]));
		if(idx==-1)
			ans++;
		if(idx>=0)
			ans+=idx+2;
	}
	prll(ans);
	return 0;
}