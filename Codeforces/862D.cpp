#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
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



int main()
{
	int n;
	si(n);
	string s;
	s.resize(n);

	rep(i,0,n)
		s[i]='0';

	int l=0,r=n-1;
	int ll , rr;
	int curr = 1;
	int pos[2];
	pos[0] = -1; pos[1] = -1;
	int newh = 0 , prevh = 0;
	while(1)
	{
		if(pos[0] >=0 && pos[1] >=0 )
			break;
		printf("? ");
		cout<<s<<endl;
		fflush(stdout);
		si(newh);
		int len = r-l+1;
		if(newh == prevh + len )
		{
			//CHECK cuur or ! curr
			pos[curr] = l;
			l = ll;
			r = rr;
			curr = !curr;
		}
		else if(newh == prevh - len)
		{
			//CHECK cuur or ! curr
			pos[!curr] = l;
			l = ll;
			r = rr;
			curr = !curr;
		}
		prevh = newh;
		int mid = (l+r)>>1;
		ll = mid+1;
		rr = r;
		r = mid;

		rep(i,l,r+1)
			s[i] = '0'+curr;
		curr = !curr;
	}
	cout<< "! "<< pos[0]+1 << " " << pos[1]+1 << endl;
	return 0;
}