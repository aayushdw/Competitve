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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 70000+5
using namespace std;

map< int , ii > m[10];
int ans[MAX][2];

void store(string &s,int idx)
{
	set<int> S[10];
	rep(i,0,9)
	{
		int num = 0;
		rep(j,i,9)
		{
			num*=10;
			num+=s[j]-'0';
			S[j-i+1].insert(num);
		}
	}
	rep(i,0,10)
		tr(j,S[i])
		{
			int num = *j;
			auto it = m[i].find(num);
			if(it==m[i].end())
				m[i].insert(mp(num,mp(1,idx)));
			else
				it->S.F++;
		}
}

void solve()
{
	memset(ans,-1,sizeof(ans));
	rep(i,0,10)
		tr(it,m[i])
		{
			//printf("%d - (%d %d)\n",it->F,it->S.F,it->S.S);
			if(it->S.F!=1 || ans[it->S.S][0]!=-1)
				continue;
			ans[it->S.S][0] = it->F;
			ans[it->S.S][1] = i;
		}
}

int main()
{
	int n;
	si(n);
	string str[n];
	rep(i,0,n)
	{
		cin>>str[i];
		store(str[i],i);
	}
	solve();
	rep(i,0,n)
	cout<<setw(ans[i][1])<<setfill('0')<<ans[i][0]<<endl;
	return 0;
}