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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define ison(x,i) (((x) >> (i)) & 1)    //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))       //set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

map< int,int > m;
typeof(m.begin()) it;
vi v,vec;

int main()
{
    int t;
    string s;
    si(t);
    ii ans=mp(0,0);
    while(t--)
    {
        v.clear();
        cin>>s;
        rep(i,0,s.size())
        if(s[i]=='H')
        v.pb(1);
        else
        v.pb(0);
        rep(i,1,11)
        {
            s.clear();
            vec.clear();
            m.clear();
            int p=v[0];
            rep(j,1,i)
            p+=(1<<j)*v[j];
            vec.pb(p);
            rep(j,i,v.size())
            {
                p-=v[j-i];
                p/=2;
                p+=v[j]*(1<<(i-1));
                vec.pb(p);
            }
            int lim=1<<i;
            rep(j,0,lim)
            {
                it=m.find(vec[j]);
                if(it!=m.end())
                    it->S++;
                else
                    m.insert(mp(vec[j],1));
            }
            if(m.size()==lim)
            ans=mp(i,0);
            rep(j,lim,vec.size())
            {
                it=m.find(vec[j-lim]);
                if(it->S==1)
                    m.erase(it);
                else
                    it->S--;
                
                it=m.find(vec[j]);
                if(it!=m.end())
                    it->S++;
                else
                    m.insert(mp(vec[j],1));
                if(m.size()==lim)
                {
                    if(i==1)
                    ans=mp(i,j-1);
                    else
                    ans=mp(i,j-(1<<i)*i);
                }
            }
            
        }
        printf("%d %d\n",ans.F,ans.S);
    }
}