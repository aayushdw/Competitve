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

int pairs=0,quad=0, singles=0 ; 

int main() {
	int n,k ; scanf("%d %d",&n,&k) ; 
	for(int i=0;i<k;i++){
		int a ; scanf("%d",&a) ; 
		
		if(a%8 == 1){
			singles++ ; 
		}
		else if(a%8 == 2){
			pairs++ ; 
		}
		else if(a%8 == 3){
			singles++ ; 
			pairs++ ; 
		}
		else if(a%8 == 4){
			quad++ ; 
		}
		else if(a%8 == 5){
			singles++ ; 
			quad++ ; 
		}
		else if(a%8 == 6){
			pairs++ ; 
			quad++ ; 
		}
		else if(a%8 == 7){
			quad++;
			pairs++;
			singles++;
		}
		quad += 2*(a/8);
	}
	if(n < 0){
		printf("NO") ; 
		return 0 ; 
	}
	int a_pairs = n*2,a_quad=n ; 
	if(quad <= a_quad){
		a_quad -= quad ;
		int temp = min(singles,min(pairs,a_quad)) ; 
		singles -= temp ; 
		pairs -= temp ; 
		a_quad -= temp ; 
		temp = min(singles/2,a_quad) ; 
		singles -= 2*temp ; 
		a_quad -= temp ; 
		pairs += singles ; 
		a_pairs += a_quad ; 
		if(pairs <= a_pairs){
			printf("YES") ; 
		}
		else{
			printf("NO") ; 
		}
	}
	else{
		quad -= a_quad ; 
		pairs += 2*quad ; 
		if(pairs + singles <= a_pairs){
			printf("YES") ; 
		}
		else{
			printf("NO") ; 
		}
	}
	return 0;
}