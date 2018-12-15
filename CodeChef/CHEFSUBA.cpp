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
#define MAX 100000+5
using namespace std;

int main()
{
	int n,k,p,x;
	si(n); si(k); si(p);
	vi a,q;
	rep(i,0,n)
	{
		si(x);
		a.pb(x);
	}
	k=min(k,n);
	int shift=0;
	getchar();
	rep(i,0,p)
	{
		char c=getchar();
		if(c=='!')
		{
			shift++;
			q.pb(0);
		}
		else
			q.pb(1);
	}
	vi v;
	for(int i=shift-1,j=n-1;i>=0;i--,j--)
	{
		if(j<0)
			j=n-1;
		v.pb(a[j]);
	}
	reverse(all(v));
	rep(i,0,n)
	v.pb(a[i]);

	//pr(shift);
	int num=0;
	rep(i,0,k)
	if(v[i])
		num++;

	vi vec;
	vec.pb(num);

	rep(i,1,shift+n-k+1)
	{
		if(v[i-1])
			num--;
		if(v[i+k-1])
			num++;
		vec.pb(num);
	}
	reverse(all(vec));
	map<int,int> m;
	rep(i,0,n-k+1)
	{
		//printf("insert %d\n",vec[i]);
		auto it=m.find(vec[i]);
		if(it!=m.end())
			it->S++;
		else
			m.insert(mp(vec[i],1));
	}
	int curr=0;
	rep(i,0,q.size())
	{
		if(q[i])
			pr(m.rbegin()->F);
		else
		{
			//printf("delete (%d idx=%d) , insert (%d idx=%d) , curr %d\n",vec[curr],curr,vec[curr+n-k+1],curr+n-k+1,curr);
			auto it=m.find(vec[curr]);
			if(it->S==1)
				m.erase(it);
			else
				it->S--;

			it=m.find(vec[n-k+curr+1]);
			if(it!=m.end())
				it->S++;
			else
				m.insert(mp(vec[n-k+curr+1],1));

			curr++;
			
		}
	}
	return 0;
}