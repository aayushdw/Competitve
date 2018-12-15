#include <bits/stdc++.h>
#define mod 1000000007
#define Big 30000000000000
#define inf (1<<30)
#define V 55
#define EPS 1e-12
#define clr(m) memset(m,0,sizeof m)
#define clri(m) memset(m,-1,sizeof m)
#define lp(i,n) for(int i=0;i<n;i++)
#define sc(n) scanf("%d",&n)
#define re(a) cin>>a
#define rea(a,b) cin>>a>>b
#define read(a,b,c) cin>>a>>b>>c
#define init(Adj,n) Adj.resize(n+1);
#define sca(n,m) scanf("%d %d",&n,&m)
#define scan(n,m,k) scanf("%d %d %d",&n,&m,&k)
#define lp1(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
//#define N (200005)
#define MAX (1<<18)
#define MAX_N (2*100002)
#define ll  long long
#define N 100005

//#define ind 101
//#define push(n) push_back(n)
//#define DFS_WHITE -1 
//#define DFS_BLACK 1
//#define int ll
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ii> vii;
int dp[MAX_N];

int main() {
    dp[0] = 1;
    int r, g, h = 1;
    sca(r, g);
    while (r + g >= h * (h + 1) / 2) h++;
    if (r + g < h * (h + 1) / 2) h--;

    lp1(i, h) {
        //printf("i=%d\n",i);
        for (int j = r; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
            //printf("%d %d\n",j,dp[i]);
        }
        //printf("\n");
    }
    int res = 0;
    for (int i = 0; i <= r; i++) if (h * (h + 1) / 2 - i <= g) res = (res + dp[i]) % mod;
    cout << res;
    return 0;
}