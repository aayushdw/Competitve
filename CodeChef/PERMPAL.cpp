#include <bits/stdc++.h>
 
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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

vi get_permutation(string a,string b)
{
    vi ret(a.size());
    
    vii x, y;
	rep(i,0,a.size())
	{
		x.pb(mp(a[i],i));
		y.pb(mp(b[i],i));
	}
	sort(all(x));
	sort(all(y));

	// rep(i,0,x.size())
	// 	printf("(%c %d), ",x[i].F,x[i].S);

	// rep(i,0,y.size())
	// 	printf("(%c %d), ",y[i].F,y[i].S);
	// fflush(stdout);
	rep(i,0,x.size())
		ret[y[i].S] = x[i].S;
	return ret;
}

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    bool possible;
    vi count(26,0);
    rep(i,0,n)
        count[s[i]-'a']++;
    int num_odd = 0;
    rep(i,0,26)
        num_odd += count[i]%2;
    possible = num_odd <= 1;
    if(!possible)
    {
        pr(-1);
        return;
    }
    string start;
    rep(i,0,26)
        rep(j,0,count[i]/2)
            start.pb('a'+i);
    string mid;
    rep(i,0,26)
        if(count[i]%2)
            mid.pb('a'+i);
    string end = start;
    reverse(all(end));
    string palindrome = start + mid + end;
	// cout<<palindrome<<endl;
    vi perm = get_permutation(s,palindrome);
	rep(i,0,perm.size())
		printf("%d ",perm[i]+1);
	printf("\n");
	return;
}

int main()
{
	int t;
    si(t);
    while(t--)
        solve();
	return 0;
}