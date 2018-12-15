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
#define MAX 50+5
using namespace std;

char a[MAX][MAX];

int n,m;
ii start,end;
string s;
char dir[4];

bool check(vi &v)
{
	ii pos = start;
	rep(i,0,s.size())
	{
		if(dir[v[s[i]-'0']]=='U')
		{
			if(pos.F)
				pos.F--;
			else
				return false;
		}
		if(dir[v[s[i]-'0']]=='D')
		{
			if(pos.F!=n-1)
				pos.F++;
			else
				return false;
		}
		if(dir[v[s[i]-'0']]=='L')
		{
			if(pos.S)
				pos.S--;
			else
				return false;
		}
		if(dir[v[s[i]-'0']]=='R')
		{
			if(pos.S!=m-1)
				pos.S++;
			else
				return false;
		}
		if(a[pos.F][pos.S]=='#')
			return false;
		if(pos==end)
			return true;
		// printf("(%d %d)\n",pos.F,pos.S);
	}
}

int main()
{
	si(n); si(m);
	rep(i,0,n)
	{
		getchar();
		rep(j,0,m)
		{
			a[i][j] = getchar();
			if(a[i][j]=='S')
				start = mp(i,j);
			if(a[i][j]=='E')
				end = mp(i,j);
		}
	}

	// printf("(%d %d),(%d %d)\n",start.F,start.S,end.F,end.S);

	dir[0] = 'U';
	dir[1] = 'D';
	dir[2] = 'L';
	dir[3] = 'R';

	cin>>s;
	// cout<<s<<endl;
	vi v;
	rep(i,0,4)
		v.pb(i);
	int num = 24,ans = 0;
	while(num--)
	{
		ans += check(v);
		next_permutation(all(v));
	}
	pr(ans);
	return 0;
}