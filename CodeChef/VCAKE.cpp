#include<stdio.h>
#include<vector>
#include<map>
#include<set>
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
using namespace std;
bool fun(ll a,ll b,ll r, ll c)
{
	
	if(a+b!=r*c || r<0 || c<0)
	return false;
	if(a%r==0 || a%c==0)
	return true;
	return false;
}
int main()
{
	ll r,c,m,k,j,t;
	scll(t);
	while(t--)
	{
	scll(r); 
	scll(c);
	scll(m);
	scll(k);
	scll(j);
	bool f=false;
	if(m%r==0)
	{
		f=f || fun(k,j,r,c-m/r);
		//printf("m%r==0\n");
	}
	if(k%r==0)
	{
		f=f || fun(m,j,r,c-k/r);
		//printf("k%r==0");
	}
	if(j%r==0)
	{
		f=f || fun(k,m,r,c-j/r);
		//printf("j%r==0");
	}
	if(m%c==0)
	{
		f=f || fun(k,j,r-m/c,c);
		//printf("m%c==0");
	}
	if(k%c==0)
	{
		f=f || fun(m,j,r-k/c,c);
		//printf("k%c==0\n");
	}
	if(j%c==0)
	{
		f=f || fun(k,m,r-j/c,c);
		//printf("j%c==0\n");
	}
	if(f)
	printf("Yes\n");
	else
	printf("No\n");
	}
	return 0;
}
