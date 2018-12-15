#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
#define prll(x) printf("%I64d",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
int bot=0,tow=0;
void fun(int n,int b,int p)
{
	if(n==1)
	return;
	int k=1;
	while(k*2<=n)
	k*=2;
	bot+=(k/2)*(2*b+1);
	n=n-k+k/2;
	fun(n,b,p);
	return;
}
int main()
{
	int n,b,p;
	sc(n); sc(b); sc(p);
	fun(n,b,p);
	pr(bot); printf(" "); pr(n*p);
	return 0;
}
