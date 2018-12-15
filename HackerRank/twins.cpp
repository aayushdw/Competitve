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
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
bitset<MAX> t;
bool arr[1000005];
ll primes[9600],ct;
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
/*
MAX = 10^5 , ct = 9600
MAX = 10^6 , ct = 78500
MAX = 10^7 , ct = 665000
MAX = 10^8 , ct = 5761500
MAX = 10^9 , ct = 50847600
*/
int main()
{
	seive();
	int n,m,c=0,p,j;
	//sc(n); sc(m);
	n=1000000000-1000000; m=1000000000;
	rep(i,0,1000005)
	arr[i]=true;
	rep(i,0,ct)
	{
		p=primes[i];
		j=(n%p)?(n/p+1):(n/p);
		if(j==1)
			j++;
		while(j*p<=m)
		{
			arr[j*p-n]=false;
			//printf("Prime = %d , j = %d , num = %d\n",p,j,j*p);
			j++;
		}
	}
	rep(i,n+2,m+1)
	{
		if(arr[i-n]&&arr[i-n-2])
			c++;
	}
	pr(c);
}
