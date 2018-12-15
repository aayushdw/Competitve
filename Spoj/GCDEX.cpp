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
#define MAX 1000000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
ll store[MAX];
int sievephi[MAX+5];
 
void precalc(){
	for(int i=1;i<=MAX;i++)
		sievephi[i]=i;
		
	for(int i=2;i<=MAX;i+=2)
		sievephi[i]-=sievephi[i]/2;
 
	for(int i=3;i<=MAX;i+=2)
		if(sievephi[i]==i)
			for(int j=i;j<=MAX;j+=i)
				sievephi[j]-=sievephi[j]/i;
				
	store[0]=0;
	
	for(int i=1;i<MAX;i++){
		store[i]=store[i-1]+sievephi[i];
	}
}
int main()
{
	precalc();
	
	return 0;
}