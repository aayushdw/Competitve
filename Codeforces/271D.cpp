#include<bits/stdc++.h>     

#define F first
#define S second
#define mp make_pair
#define pii pair<int,int>

#define ll long long
#define pb push_back
#define sz(a) (int)(a.size())

#define y1     NOT
#define left   NEEDED
#define right  THINGS

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 4611686018427387903;
const int Sz = 1500 * 1500 + 1;

using namespace std;

inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
}
string s;

bool bad[Sz];
            
int t[Sz][26], nodes = 1;

int ans;

int k;

inline void add_suff (int l) {
  int v = 1;
  int badness = 0;  

  for (int i = l;i < sz(s);i ++) {
    int to = s[i] - 'a';
    
    if (bad[to] == 0)
      badness ++;

    if (!t[v][to]&&badness<=k) {
      t[v][to] = ++nodes;
        ans ++;
    }
    v = t[v][to];
  }
}

int main()
{
  Read_rap ();
  cin >> s;
  for (int i = 0;i < 26;i ++) { 
    char c; cin >> c;
    bad[i] = c - '0';
  }        
  cin >> k;     
  for (int i = 0;i < sz(s);i ++)
    add_suff (i);

  cout << ans;

  return 0;
}