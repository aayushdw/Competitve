#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5+10; 
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
class DSU{
  public:
    vector<int> par,rank,sum;
    void init(int n){
      par.assign(n,0);
      rank.assign(n,1);
      sum.assign(n,0);
      for(int i = 0; i < n ; ++i)par[i] = i;
    }
    int find(int x){
      return  ((par[x] == x) ? x : find(par[x]) );
    }
    int findsum(int x){
    	if(par[x] == x)return 0;
    	return sum[x]^findsum(par[x]);
    }
    void unite(int x, int y,int val){
      x=find(x); y=find(y);
      if(x == y) return;
      if(rank[x] > rank[y])swap(x,y);
      par[x] = y;
      rank[y] += rank[x];
      sum[x] = val;
    }
}d;
map<string,int> M;
string a[N];
int main(){
  fast;
  int n,m,q;
  cin >> n >> m >> q;
  FOR(i,1,n){
  	cin >> a[i];
  	M[a[i]] = i;
  }
  d.init(n + 100);
  FOR(i,0,m-1){
  	int tt;
  	cin >> tt;
  	string a,b;
  	cin >> a >> b;
  	int u = M[a];
  	int v = M[b];
  	if(tt == 1){
  		int uu = d.find(u);
  		int vv = d.find(v);
  		int su = d.findsum(u);
  		int sv = d.findsum(v);
  		if(uu != vv){
  			cout << "YES\n";
  			int c = su != sv;
  			d.unite(u,v,c);
  		}
  		if(uu == vv){
  			if(su != sv){
  				cout << "NO\n";
  			}
  			else{
  				cout << "YES\n";
  			}
  		}
  	}
  	if(tt == 2){
  		int uu = d.find(u);
  		int vv = d.find(v);
  		int su = d.findsum(u);
  		int sv = d.findsum(v);
  		if(uu != vv){
  			cout << "YES\n";
  			int c = (su == sv);
  			d.unite(u,v,c);
  		}
  		if(uu == vv){
  			if(su == sv){
  				cout << "NO\n";
  			}
  			else{
  				cout << "YES\n";
  			}
  		}

  	}
  FOR(i,0,q-1){
  	string a,b;
  	cin >> a >> b;
  	int u = M[a];
  	int v = M[b];
  	int uu = d.find(u);
	int vv = d.find(v);
	int su = d.findsum(u);
	int sv = d.findsum(v);
	//cout << su << " " << sv << "\n";
	if(uu != vv){
		cout << 3 << "\n";
	}
	else if(uu == vv){
		if(su == sv){
			cout << 1 << "\n";
		}
		else cout << 2 << "\n";
	}
  }
  return 0;
}