#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

long long int A[2][2]  , res[2][2]  ; 

void find_pow(long long int x){
	// cout<<x<<endl ; 
	if(x == 1){
		return ; 
	}
	find_pow(x/2) ; 
	long long int x1 = ( res[0][0] * res[0][0] + res[0][1] * res[1][0] ) % (1000000) ; 
	long long int x2 = ( res[0][0] * res[0][1] + res[0][1] * res[1][1] ) % (1000000) ; 
	long long int x3 = ( res[1][0] * res[0][0] + res[1][1] * res[1][0] ) % (1000000) ;
	long long int x4 = ( res[1][0] * res[0][1] + res[1][1] * res[1][1] ) % (1000000) ; 
	res[0][0] = x1 ; 
	res[0][1] = x2 ; 
	res[1][0] = x3 ; 
	res[1][1] = x4 ; 
	if(x%2 == 0)
		return ; 
	long long int y1 = ( res[0][0] * A[0][0] + res[0][1] * A[1][0] ) % (1000000) ; 
	long long int y2 = ( res[0][0] * A[0][1] + res[0][1] * A[1][1] ) % (1000000) ; 
	long long int y3 = ( res[1][0] * A[0][0] + res[1][1] * A[1][0] ) % (1000000) ;
	long long int y4 = ( res[1][0] * A[0][1] + res[1][1] * A[1][1] ) % (1000000) ;  
	res[0][0] = y1 ; 
	res[0][1] = y2 ; 
	res[1][0] = y3 ; 
	res[1][1] = y4 ; 
}



int main()
{
	long long int n,k,l ; 
	cin>>n>>k>>l ; 
	k %= 1000000 ; 
	l %= 1000000 ; 
	n /= 5 ;

	A[0][0] = k ; 
	A[0][1] = l ; 
	A[1][0] = 1 ; 
	A[1][1] = 0 ; 


	res[0][0] = k ; 
	res[0][1] = l ; 
	res[1][0] = 1 ; 
	res[1][1] = 0 ; 

	if(n == 1){
		// find_ans(k%(1000000)) ;
		printf("%06lld\n", k%(1000000)); 
		return 0 ; 
	}


	find_pow(n-1) ; 

	long long int ans = (res[0][0] * k + res[0][1]) % (1000000) ; 
	// find_ans(ans) ; 
	printf("%06lld",ans);
	return 0;
}