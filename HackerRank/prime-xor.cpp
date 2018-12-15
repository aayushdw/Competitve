#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)    //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))       //set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
vector< pll > v;
ll ans[8192]={0},cont[5000]={0};
bitset<MAX> t;
void seive()
{
    t.reset();
    t[0]=true; t[1]=true; t[2]=false;
    
    ll i=2,j;
    while(i*2<MAX)
    {
        t[i*2]=1;
        i++;
    }
    i=2;
    while(i*i<MAX)
    {
        if(t[i])
        {
            i++;
            continue;
        }
        j=i;
        while(j*i<MAX)
        {
            t[i*j]=1;
            j+=2;
        }
        i++;
    }
    return;
}
int main()
{
    seive();
    ll q,p,n;
    scll(q);
    while(q--)
    {
        memset(ans,0,sizeof(ans));
        memset(cont,0,sizeof(cont));
        ans[0]=1;
        scll(n);
        rep(i,0,n)
        {
            scll(p);
            cont[p]++;
        }
        rep(i,3500,4501)
        {
            v.clear();
            rep(j,0,8192)
            if(ans[j])
            {
                v.pb(mp(i^j,(cont[i]/2+cont[i]%2)*ans[j]));
                v.pb(mp(j,ans[j]*(cont[i]/2)));
            }
            rep(j,0,v.size())
            {
                ans[v[j].first]+=v[j].second;
                ans[v[j].first]%=MOD;
            }
        }
        p=0;
        rep(i,2,8192)
        if(!t[i]&& ans[i])
        {
            //printf("%lld %lld\n",i,ans[i]);
            p+=ans[i], p%=MOD;
        }
        prll(p);
    }
    return 0;
}