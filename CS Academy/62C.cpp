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

using namespace std;
#define maxn 200100
#define lowbit(x) x&(-x)

int bit[maxn],n;
int ans=-0x3f3f3f3f,id=200100;
int a[maxn];
int ax[maxn];

//vector <int> ve;
//ve.back();

void add(int pos,int val)
{
    while(pos<=n)
    {
        bit[pos]+=val;
        pos+=lowbit(pos);
    }
}

int sum(int pos)
{
    int ret=0;
    while(pos>0)
    {
        ret+=bit[pos];
        pos-=lowbit(pos);
    }
    return ret;
}

int main()
{
    si(n);
    vii v;
    rep(i,1,n+1)
    {
    	si(a[i]);
    	v.pb(mp(a[i],-i));
    }
    sort(all(v));
    rep(i,0,v.size())
    	a[-v[i].S] = i+1;
    // rep(i,1,n+1)
    // printf("%d ",a[i]);
    // printf("\n");
    // return 0;
    for(int i=1;i<=n;++i)
    {
        // scanf("%d",&a[i]);
        int num=sum(n)-sum(a[i]-1);
        if(num>1)
        {
            add(a[i],1);
            continue;
        }
        if(num==0)
        {
            add(a[i],1);
            --ax[a[i]];
            continue;
        }
        int lb=a[i],ub=n;
        while(ub>lb+1)
        {
            int mid=(lb+ub)>>1;
            if(sum(mid)>sum(a[i])) ub=mid;
            else lb=mid;
        }
        add(a[i],1); ++ax[ub];
    }
    for(int i=1;i<=n;++i)
        if(ax[i]>ans)
        {
            ans=ax[i];
            id=i;
        }
    // printf("%d\n",id);
    int cur = 0;
    int ans = 0;
    rep(i,1,n+1)
    {
    	if(a[i]==id)
    		continue;
    	// printf("%d ",a[i]);
    	if(a[i]>cur)
    		ans++;
    	cur = max(cur,a[i]);
    }
    pr(ans);
    return 0;
}