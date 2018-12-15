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

vector< pll > o,t;

int main()
{
	ll n,s;
	sl(n); sl(s);
	ll one =0 , two = 0 , ans=0;
	rep(i,0,n)
	{
		ll num,a,b;
		sl(num);
		sl(a);
		sl(b);
		//v.pb(mp(num,a-b));
		if(a>b)
		{
			one+=num;
			ans += num*a;
			o.pb(mp(a-b,num));
		}
		else
		{
			two+=num;
			ans += num*b;
			t.pb(mp(b-a,num));
		}
	}
	/*printf("%lld %lld\n",one,two);

	rep(i,0,o.size())
		printf("(%lld %lld) ",o[i].F,o[i].S);
	printf("\n");
	rep(i,0,t.size())
		printf("(%lld %lld) ",t[i].F,t[i].S);
	printf("\n");*/

	one%=s;
	two%=s;
	if(one+two>s || one+two==0)
	{
		prll(ans);
	}
	else
	{
		ll temp = one;
		ll temp1 = 0;
		sort(all(o));
		int i = 0;
		while(temp)
		{
			if(o[i].S)
			{
				o[i].S--;
				temp1+=o[i].F;
				temp--;
				//printf("sub = %lld\n",o[i].F);
			}
			else
				i++;
		}
		//printf("\n");
		temp = two;
		ll temp2 = 0;
		sort(all(t));
		i = 0;
		while(temp)
		{
			if(t[i].S)
			{
				t[i].S--;
				temp2+=t[i].F;
				temp--;
			}
			else
				i++;
		}

		//printf("%lld %lld %lld\n",ans,temp1,temp2);

		prll(ans-min(temp1,temp2));

	}
	return 0;
}