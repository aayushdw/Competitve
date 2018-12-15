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

ll C[11][11],f[11],power[11][65];

void pre()
{
	rep(i,0,11)
	rep(j,0,11)
	{
		if(i==j)
			C[i][j]=1;
		else if(j>i)
			C[i][j]=0;
		else
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}

	f[0]=1;
	rep(i,1,11)
		f[i] = i*f[i-1];

	rep(i,0,11)
	{
		power[i][0]=1;
		rep(j,1,65)
			power[i][j] = power[i][j-1]*i;
	}
}

ll nPr(ll n,ll r)
{
	if(n<r)	return 0;
	else return C[n][r]*f[r];
}

ll foo(ll b,ll n)
{
	vl v;
	while(n)
	{
		v.pb(n%b);
		n/=b;
	}
	reverse(all(v));

	rep(i,0,v.size())
		printf("%lld ",v[i]);
	printf("\n");
	printf("\n");
	
	vl c(b);
	ll m = v.size();
	ll ans = 0 , odd=0;
	rep(i,0,m)
	{
		rep(j,0,v[i])
		{
			if(!(i==0 && j==0))
			{
				c[j]++;
				if(c[j]%2)
					odd++;
				else
					odd--;
			}


			rep(k,0,b)
				printf("%lld ",c[k]);
			printf("\n");

			ll num = m-i-1;

			printf("%lld %lld\n",num,odd);
			
			if((num-odd)%2==0)
			{
				ll temp = nPr(num,odd);
				prll(temp);
				ll _t = (num-odd)/2;
				ans += temp*power[b][_t];
			}

			prll(ans);

			if(!(i==0 && j==0))
			{
				c[j]++;
				if(c[j]%2)
					odd++;
				else
					odd--;
			}

		}
		c[v[i]]++;
		if(c[v[i]]%2)
				odd++;
			else
				odd--;
	}
	printf("foo(%lld %lld) = ",b,n);
	prll(ans);
	return ans-1;
}

ll solve(ll b,ll l,ll r)
{
	return foo(b,r)-foo(b,l-1);
}

int main()
{
	ll q;
	sl(q);
	pre();
	while(q--)
	{
		ll b,l,r;
		sl(b); sl(l); sl(r);
		prll(solve(b,l,r));
	}
	return 0;
}