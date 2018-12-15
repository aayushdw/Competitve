#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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

#define MOD 359999
#define INF 10000000000000000
#define MAX 1000000+5
#define MAXN 360000+5
#define M 1000000007
using namespace std;

ll p[MAXN],arr[1005],a[MAXN],dp[MAXN];

void mobius()
{
	int j;
	rep(i,2,MAXN)
	{
		j=i;
		while(j<MAXN)
		{
			if(!p[j])
				p[j]=i;
			j+=i;
		}
	}

	dp[1]=1;
	rep(i,2,MAXN)
	if(p[i/p[i]]==p[i])
		dp[i]=0;
	else
		dp[i]=-1*dp[i/p[i]];
}

int main()
{
	ll t,n,k,p;
	ll b,zero,one,two,three,ans;
	mobius();
	sl(t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		one=0;
		zero=0;
		two=0;
		three=0;
		ans=0;
		sl(n);
		rep(i,0,n)
		sl(arr[i]);

		k=0;

		rep(i,0,n)
		rep(j,0,n)
		{
			b=arr[i]*arr[j];
			b%=MOD;
			if(!b)
				zero++;
			else
			{
				if(b==1)
					one++;
				a[b]++;
			}
		}
		//printf("%lld %lld %lld %lld\n",zero,one,two,three);

		rep(i,1,MAXN)
		{
			if(!dp[i])
				continue;

			k=i;
			p=0;
			while(k<MAXN)
			{
				p+=a[k];
				k+=i;
			}
			three+=p*(p-1)*(p-2)*dp[i]/6;
			three%=M;
			two+=p*(p-1)*dp[i]/2;
			two%=M;
		}


		ans+=6*three;
		ans%=M;
		if(ans<0)
			ans+=M;
		ans+=6*two;
		ans%=M;
		if(ans<0)
			ans+=M;
		ans+=6*zero*two;
		ans%=M;
		if(ans<0)
			ans+=M;
		ans+=3*zero*zero*one;
		ans%=M;
		if(ans<0)
			ans+=M;
		ans+=3*zero*one;
		ans%=M;
		if(ans<0)
			ans+=M;
		ans+=one;
		ans%=M;
		if(ans<0)
			ans+=M;


		/*
		ans=((((3*zero)*zero)%M)*one)%M;
		ans+=three;
		ans%=M;
		ans+=3*two*zero;
		ans%=M;
		*/
		prll(ans);
	}
	return 0;
}