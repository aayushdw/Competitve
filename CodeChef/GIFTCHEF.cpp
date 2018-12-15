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
#define MAX 300000+5
#define MOD 1000000007
using namespace std;
ll pat[MAX];
ll ans[MAX];
//  Z Algo Source: http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
void getZarr(string str, ll Z[]);
void search(string text, string pattern)
{
    string concat=pattern+"$"+text;
    ll l=concat.length();
    ll Z[l];
    getZarr(concat,Z);
    rep(i,0,l)
    {
        if (Z[i]==pattern.length())
            pat[i-pattern.length() -1]=1;
    }
}
void getZarr(string str, ll Z[])
{
    ll n=str.length();
    ll L,R,k;
    L=R=0;
    for(ll i=1;i<n;++i)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n&&str[R-L]==str[R])
                R++;
            Z[i]=R-L;
            R--;
        }
        else
        {
            k=i-L;
            if(Z[k]<R-i+1)
                 Z[i]=Z[k];
            else
            {
                L=i;
                while(R<n&&str[R-L]==str[R])
                    R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
    ll t,l,p;
    scll(t);
    string a,b;
    while(t--)
    {
        cin>>a; cin>>b;
        memset(pat,0,sizeof(pat));
        memset(ans,0,sizeof(ans));
        l=a.length(); p=b.length();
        search(a,b);
        pat[l-1]?ans[l-1]=1:ans[l-1]=0;
        for(ll i=l-2;i>=0;i--)
            if(pat[i])
            {
                ans[i]=ans[i+1]+1+ans[i+p];
                ans[i]%=MOD;
            }
            else
                ans[i]=ans[i+1];
        prll(ans[0]);
    }
    return 0;
}