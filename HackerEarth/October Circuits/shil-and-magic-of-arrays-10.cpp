#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
ll a[MAX]={0};
map<ll,ll> s[350],m;
map<ll,ll>::iterator it,iter;
ll powmod(ll a,ll b)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x%MOD;
}
int main()
{
	ll n,q,p,u,v,ans;
	scll(n); scll(q);
	ll k=sqrt(n);
	for(u=0;u*u<=n;u++)
		s[u].insert(mp(0,k));
	s[u].insert(mp(0,n-u*k));
	while(q--)
	{
		scll(p);
		if(p==1)
		{
			scll(u); scll(v);
			it=s[u/k].find(a[u-1]);
			if(it->second == 1)
				s[u/k].erase(it);
			else
				it->second--;
			a[u-1]=v;
			it=s[u/k].find(v);
			if(it==s[u/k].end())
				s[u/k].insert(mp(v,1));
			else
				it->second++;
			printf("After Update %lld %lld\n",u,v);
			for(it=s[u/k].begin();it!=s[u/k].end();it++)
				printf("(%lld %lld) ",it->first,it->second);
			printf("\n");
		}
		else
		{
			scll(u);
			m.clear();
			rep(i,0,u/k)
			for(iter=s[i].begin();iter!=s[i].end();iter++)
			{
				it=m.find(iter->first);
				if(it==m.end())
					m.insert(mp(iter->first,1));
				else
					it->second+=iter->second;
			}
			rep(i,(u/k)*k,u)
			{
				it=m.find(a[i]);
				if(it==m.end())
					m.insert(mp(iter->first,1));
				else
					it->second++;
			}
			ans=1;
			for(it=m.begin();it!=m.end();it++)
			{
				ans*=powmod(it->second+1,it->second+1);
				ans%=MOD;
			}

			printf("Query %lld\n",u);
			for(it=m.begin();it!=m.end();it++)
				printf("(%lld %lld) ",it->first,it->second);
			printf("\n");
			printf("%lld\n",ans);
		}
	}
	return 0;
}