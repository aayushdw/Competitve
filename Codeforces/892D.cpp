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
#define MAX 22+5
using namespace std;

bool foo(vector<ll> &a,vector<ll> &b,ll i,ll c,ll sa, ll sb)
{
    if(c==a.size())
        return false;
    if(i==a.size())
    {
        if(c)
            return sa==sb;
        else
            return false;
    }
    bool f = false;
    f |= foo(a,b,i+1,c,sa,sb);
    if(f)   return f;
    f |= foo(a,b,i+1,c+1,sa+a[i],sb+b[i]);
    return f;
}

bool check(vector<ll> &a, vector<ll> &b)
{
    return foo(a,b,0,0,0,0);
}

vector<ll> random_derangement(vector<ll> &v)
{
    ll n = v.size();
    vl temp(n,0),ret(n,-1);
    rep(i,0,n) temp[i] = i;
    rep(i,0,n)
    {
        if(i==n-1 && temp[0]==n-1)
            return v;
        ll idx = rand()%(n-i);
        while(temp[idx]==i)
            idx = rand()%(n-i);
        ret[temp[idx]] = v[i];
        temp.erase(temp.begin()+idx);
    }
    return ret;
}

int main()
{
    srand(time(NULL));
    ll n;
    // sl(n);
    // n = rand()%15 + 2;
    n = 22;
    printf("n = %lld \n",n);
    vector<ll> temp(100000,0);
    rep(i,0,100000)
        temp[i] = i;
    random_shuffle(all(temp));

    vector<ll> v(n,0);
    rep(i,0,n)
        v[i] = temp[i];

    rep(i,0,v.size())
        printf("%lld ",v[i]);
    cout<<endl;

    // vector<ll> v(n,0);
    // rep(i,0,n)
    //     sl(v[i]);

    vector<ll> p = v;
    ll c = 0;
    while(check(v,p))
    {
        p = random_derangement(p);
        //reverse(all(p));
        c++;
        // rep(i,0,n)
        //     printf("%lld ",p[i]);
        // printf("\tcheck = %d\n",check(v,p));
    }
    
    rep(i,0,p.size())
        printf("%lld ",p[i]);
    cout<<endl;
    printf("iter = %lld\n",c);
	return 0;
}