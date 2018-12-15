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
#define B 1000000009
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

int a[MAX],arr[MAX];

vi pal_array(vi& s)
{
    int n = s.size()-2;
    //s = "@" + s + "$";
    vector<int> len(n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++)
    {
        len[i] = min(r - i, len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if(i + len[i] > r)
        {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(begin(len));
    for(int i=0;i<len.size();i++)
        len[i]=2*len[i]-1;
    return len;
}

int main()
{
	int n;
	si(n);
	int p=1;
	vi v;
	v.pb(INT_MAX);
	rep(i,1,n+1)
	{
		si(a[i]);
		if(a[i]==1)
		{
			arr[i]=p;
			p++;
		}
		else
			arr[i]=arr[i-(a[i]-1)];
		v.pb(arr[i]);
	}
	v.pb(INT_MAX-1);
	
	vi lps=pal_array(v);
	rep(i,0,lps.size())
	printf("%d ",lps[i]);
	cout<<endl;
	return 0;
}