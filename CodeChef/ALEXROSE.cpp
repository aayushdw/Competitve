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

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

map<ll,ll> m,used;
set< pll > s;
typeof(s.begin()) sit; typeof(s.rbegin()) rit;
typeof(m.begin()) mit,prev;
int main()
{
	ll t,n,p,k,a,b,req,q,ans,u;
	scll(t);
	while(t--)
	{
		s.clear();
		m.clear();
		used.clear();
		ans=0;
		scll(n); scll(k);
		rep(i,0,n)
		{
			scll(p);
			mit=m.find(p);
			if(mit==m.end())
				m.insert(mp(p,1));
			else
				mit->S++;
		}

		tr(m,i)
		{
			i->S%=k;
			if(i->S)
			{
				s.insert(mp(i->S,i->F));
				used.insert(mp(i->F,0));
			}
		}

		mit=m.begin();
		while(mit!=m.end())
		{
			if(mit->S==0)
			{
				prev=mit;
				mit++;
				m.erase(prev);
			}
			else
			mit++;
		}

		while(!s.empty())
		{
			mit=m.begin();
			a=mit->F; b=mit->S; req=k-b;
			ans+=req;
			m.erase(mit);
			sit=s.find(mp(b,a));
			s.erase(sit);
			mit=used.find(a);
			u=mit->S;
			mit->S=0;
			ans-=u;
			printf("Bundle of %lld, Initial Sticks = %lld, Ans = %lld\n",a,b,ans);
			while(req)
			{
				sit=s.begin();
				if(sit->S==a)
					sit++;
				p=sit->F;
				q=sit->S;
				s.erase(sit);
				if(req>=p)
				{
					printf("Fully used %lld, Number used = %lld\n",q,p);
					req-=p;
					mit=m.find(q);
					m.erase(mit);
				}
				else
				{
					printf("Partially used %lld, Number used = %lld\n",q,req);
					p-=req;
					mit=used.find(q);
					mit->S+=req;
					req=0;
					mit=m.find(q);
					mit->second=p;
					s.insert(mp(p,q));
				}
			}
			printf("After using %lld:\n",a);
			tr(m,i)
			printf("(%lld %lld), ",i->F,i->S);
			printf("\n");
			tr(s,i)
			printf("[%lld,%lld], ",i->F,i->S);
				printf("\n");
				printf("\n");
		}
		prll(ans);
	}
	return 0;
}