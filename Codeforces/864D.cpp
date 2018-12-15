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
#define MAX 200000+5
using namespace std;

bitset<MAX> t;
bitset<MAX> done;
map<int,int> m;
int a[MAX];

int main()
{
	int n;
	si(n);
	t.reset();
	done.reset();
	int c = 0;
	rep(i,0,n)
	{
		si(a[i]);
		t[a[i]]=true;
		auto it = m.find(a[i]);
		if(it==m.end())
			m.insert(mp(a[i],1));
		else
		{
			it->S++;
			c++;
		}
	}
	pr(c);
	int cur = 1;
	while(t[cur]) cur++; 
	rep(i,0,n)
	{
		//pr(cur);
		auto it = m.find(a[i]);
		if(it->S==1)
		{
			done[a[i]] = true;
			continue;
		}
		if(cur<a[i] || done[a[i]])
		{
			a[i]=cur;
			it->S--;
			cur++;
			while(t[cur]) cur++;
			//done[a[i]] = true;
		}
		done[a[i]] = true;
		
	}
	rep(i,0,n)
	printf("%d ",a[i]);
	return 0;
}