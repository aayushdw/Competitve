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
using namespace std;
bool down(ll p)
{
	if(p==7 || p==0 || p==9)
	return false;
	return true;
}
bool up(ll p)
{
	if(p==1 || p==2 || p==3)
	return false;
	return true;
}
bool right(ll p)
{
	if(p==3 || p==6 || p==9 || p==0)
	return false;
	return true;
}
bool left(ll p)
{
	if(p==1 || p==4 || p==7 || p==0)
	return false;
	return true;
}
int main()
{
	ll n,a[10],i;
	scll(n); getchar();
	for(i=0;i<n;i++)
	a[i]=getchar()-'0';
	bool f=true,ans=false;
	for(i=0;i<n;i++)
	f = f && down(a[i]);
	ans= ans || f;
	
	f=true;
	for(i=0;i<n;i++)
	f = f && up(a[i]);
	ans= ans || f;
	
	f=true;
	for(i=0;i<n;i++)
	f = f && left(a[i]);
	ans= ans || f;
	
	f=true;	
	for(i=0;i<n;i++)
	f = f && right(a[i]);
	ans= ans || f;
	
	if(!ans)
	printf("YES");
	else
	printf("NO");
	return 0;
}
