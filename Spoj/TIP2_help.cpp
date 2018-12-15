#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 10000000+5
using namespace std;
bitset<MAX> t;
ll primes[665000],ct;
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
	ct=j;
	return;
}
bool isPerm(ll x,ll y)
{
	int a[10]={0}, b[10]={0};
	while(x)
	{
		a[x%10]++;
		x/=10;
	}
	while(y)
	{
		b[y%10]++;
		y/=10;
	}
	for(int i=0;i<10;i++)
	if(a[i]!=b[i])
		return false;
	return true;
}
ll bin_search(ll low,ll high,ll key)
{
	if(high-low<2)
		return low;
	ll mid=(high+low)/2;
	if(primes[mid]>key)
		return bin_search(low,mid,key);
	else
		return bin_search(mid,high,key);
}
ll solve(ll p)
{
	if(p<=21)
		return -1;
	else if(p>63&&p<292)
		return 63;
	else if(p>2817 && p<2992)
		return 2817;
	ll x=sqrt(p),tol=25000,l,u,i,j,phi,n,y;
	l=x-tol; if(l<0) l=2;
	u=x+tol;
	l=bin_search(0,ct,l);
	u=bin_search(0,ct,u);
	//printf("%lld %lld, %lld %lld\n",l,primes[l],u,primes[u]);
	double m=1.75,q;
	ll im=21;
	for(i=l;i<=u;i++)
	{
		x=primes[i];
		j=bin_search(0,ct-2,p/primes[i]);
		while(j)
		{
			y=primes[j];
			j--;
			phi=(x-1)*(y-1); n=x*y; q=(n*1.0)/phi ;
			if(q>m)
				break;
			if(isPerm(n,phi) && q < m)
			{
				im=n;
				m=q;
			}
		}
	}
	//printf("%0.9lf ",m);
	return im;
}
int main()
{
	seive();
	ll t,p,ans;
	scll(t);
	while(t--)
	{
		scll(p);
		ans=solve(p);
		if(ans==-1)
			printf("No solution.\n");
		else
			printf("%lld\n",ans);
	}
}