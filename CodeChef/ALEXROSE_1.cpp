#include<bits/stdc++.h>
 
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) a.clear()
 
#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
map<ll,ll> m,used;
typeof(m.begin()) itm,itm_prev;
set< pll > s;
int main()
{
	ll t,n,k,p,len,qty,u,ans,req,a,b;
	scll(t);
	while(t--)
	{
 
		//RESET
		clr(m);
		clr(s);
		clr(used);
 
		scll(n); scll(k);
		rep(i,0,n)
		{
			scll(p);
			itm=m.find(p);
			if(itm!=m.end())
				itm->S++;
			else
				m.insert(mp(p,1));
		}

		/*tr(m,i)
			printf("(%lld %lld), ",i->F,i->S);
			printf("\n");*/
 
		//Make all quantities less than k;
		tr(m,it)
			it->S%=k;
 
		itm=m.begin();
		while(itm!=m.end())
		{
			if(itm->S==0)
			{
				itm_prev=itm;
				itm++;
				m.erase(itm_prev);
			}
			else
			{
				s.insert(mp(itm->S,itm->F));
				used.insert(mp(itm->F,0));
				itm++;
			}
		}
 
		
 
 
		ans=0;
		while(!m.empty())
		{
			itm=m.begin();
			len=itm->F;
			qty=itm->S;
			m.erase(itm);
 
			s.erase(mp(qty,len));
 
			u=used.find(len)->S;
			ans-=u;
 
			req=k-qty;
			ans+=req;
 
			while(req)
			{
				a=s.begin()->F;	//Quantity
				b=s.begin()->S;	//Length
				s.erase(s.begin());
 
				if(a>req)	//Partially Used
				{
					itm=used.find(b);
					itm->S+=req;
					itm=m.find(b);
					itm->S-=req;
					s.insert(mp(a-req,b));
					req=0;
				}
				else		//Fully Used
				{
					req-=a;
					m.erase(b);
					used.find(b)->S+=a;
				}
			}
			
		}
		prll(ans);
	}
	return 0;
} 