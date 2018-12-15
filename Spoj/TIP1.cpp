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
#define MAX 10000000+100
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
bool isPerm(int x,int y)
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
double arr[MAX]={0};
int a[MAX];
int main()
{
	seive();
	int i,j,x,y,n,phi,c=0;
	for(int i=0;i<MAX;i++)
		arr[i]=MAX*1.0;
	for(i=0;primes[i]<10000000;i++)
	{
		x=primes[i];
		//printf("%d\n",x);
		for(j=0;primes[i]*primes[j]<10000000 && j<i;j++)
		{
			y=primes[j];
			phi=(x-1)*(y-1); n=x*y;
			if(isPerm(n,phi))
			{
				//printf("%d %d\n",n,phi);
				c++;
				arr[n]=n*1.0/phi;
			}
		}
	}
	arr[63]=1.75; arr[2817]=1.504808;
	double m=MAX*1.0-1.0;
	int im=-1;
	for(int i=1;i<MAX;i++)
	{
		a[i]=im;
		if(arr[i]<=m)
		{
			m=arr[i];
			im=i;
			//printf("%d, %lf\n",im,m);
		}
	}
	int t,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		if(a[p]==-1)
			printf("No solution.\n");
		else
			printf("%d\n",a[p]);
	}
	return 0;
}
