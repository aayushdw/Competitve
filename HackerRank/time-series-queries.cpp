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
#define MAX 100000+5
using namespace std;

map<int,int> Time;
vi lol;
int t[MAX],p[MAX];

const int N = 1 << 20;
const int inf = 1 << 28;

struct RMQ {
    int a[N*2];
    RMQ() {
        rep(i,0,N*2)
            a[i] = 0;
    }
    void SetMax(int pos, int x) {
        for (int i = pos + N; i; i >>= 1)
            a[i] = max(a[i], x);
    }
    int GetMax(int L, int R) const
    {
        int res = 0;
        for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
            if (L & 1) {
                res = max(res, a[L]);
                L++;
            }
            if (R & 1) {
                R--;
                res = max(res, a[R]);
            }
        }
        return res;
    }
};

RMQ rmq;

void pre(int n)
{
	rep(i,0,n)
		Time.insert(mp(t[i],i));
	rep(i,0,n)
		rmq.SetMax(i,p[i]);

	lol.clear();
	lol.resize(n);
	lol[0]=p[0];
	rep(i,1,n)
		lol[i] = max(lol[i-1],p[i]);

}

int getMaxVal(int t,int n)
{
	if(t>=n || t<0)
		return -1;
	return rmq.GetMax(t,n);
}

int foo(int key, int n)
{
	if(t[n-1]<key)
		return -1;
	if(t[0]>=key)
		return 0;
	int low = 0,high = n-1;
	while(low!=high)
	{
		if(low+1==high)
		{
			if(t[low]>=key)
				return low;
			else
				return high;
		}
		int mid = (low + high)/2;
		if(t[mid]>=key)
			high = mid;
		else
			low = mid;
	}
	return -1;
}

int query(int key,int n)
{
	int low = 0, high = n-1;
	int idx;
	if(key>lol[high])
		return -1;
	if(key<lol[low])
		idx = 0;
	else
	{
		while(low!=high)
		{
			if(low+1 == high)
			{
				if(lol[low]>=key)
					idx = low;
				else
					idx = high;
				break;
			}
			int mid = (low + high)/2;
			if(lol[mid]<key)
				low = mid;
			else
				high = mid;
		}
	}
	return t[idx];
}

int main()
{
	int n,q,type,x;
	si(n); si(q);
	
	rep(i,0,n)
		si(t[i]);
	rep(i,0,n)
		si(p[i]);

	pre(n);

	while(q--)
	{
		si(type);
		si(x);
		if(type==1)
			pr(query(x,n));
		else
			pr(getMaxVal(foo(x,n),n));
	}
	return 0;
}