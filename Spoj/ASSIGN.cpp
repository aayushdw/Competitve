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
#define ison(x,i) (((x) >> (i)) & 1)  //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))   //set ith bit in x to be zero
#define INF 10000000000000000
#define MAX_N 21
using namespace std;
int n, T;
ll dp[1 << MAX_N];
int a[MAX_N][MAX_N];

int main(){
  ios::sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cin >> a[i][j];
      }
    }
    int i, j, k;
    dp[0] = 1;
    for(i = 1; i < (1 << n); i++){
      j = 0;
      dp[i] = 0;
      for(k = 0; k < n; k++){
         j += ison(i, k); 
      }
      for(k = 0; k < n; k++){
         if(a[j - 1][k] && ison(i, k)){
            dp[i] += dp[i & ~(1 << k)];
         }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }
  return 0;
}