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
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bool isPalin(char s[],int l)
{
	rep(i,0,l/2)
	if(s[i]!=s[l-i-1])
		return false;
	return true;
}
void rev(char s[],int x,int y)
{
	reverse(s+x,s+y+1);
}
bool check(char s[])
{
	int l=strlen(s);
	if(isPalin(s,l))
		return true;
	rep(i,0,l-1)
	rep(j,i+1,l) 
	{
		rev(s,i,j);
		if(isPalin(s,l))
			return true;
		rep(x,j+1,l-1)
		rep(y,x+1,l)
		{
			rev(s,x,y);
			if(isPalin(s,l))
				return true;
			rev(s,x,y);
		}
		rev(s,i,j);
	}
	return false;
}
int main()
{
	int n,l,c=0;
	sc(n); sc(l);
	char s[55];
	while(n--)
	{
		getchar();
		scanf("%s",s);
		if(check(s))
			c++;
	}
	printf("%d",c);
	return 0;
}