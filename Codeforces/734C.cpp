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
vector< pll > va,vb;
ll a[MAX],b[MAX],c[MAX],d[MAX],profit1[MAX],profit2[MAX];
int main()
{
	ll n,m,k,x,s,t,num,p;
	scll(n); scll(m); scll(k);
	scll(x); scll(s);
	rep(i,0,m)
	scll(a[i]);
	rep(i,0,m)
	{
		scll(b[i]);
		va.pb(mp(b[i],a[i]));
	}
	sort(va.begin(),va.end());
	profit1[0]=va[0].second;
	rep(i,1,m)
	{
		profit1[i]=min(profit1[i-1],va[i].second);
	}
	rep(i,0,k)
	scll(c[i]);
	rep(i,0,k)
	{
		scll(d[i]);
		vb.pb(mp(d[i],c[i]));
	}
	sort(vb.begin(),vb.end());
	profit2[0]=vb[0].second;
	rep(i,0,k)
	{
		profit2[i]=max(profit2[i-1],vb[i].second);
	}


	ll i1=0, i2=k-1,ans=n*x;


	while(1)
	{
		if(i1==m)
			break;
		p=va[i1].first;
		if(p>s)
			break;

		while(i2>=0 && vb[i2].first>s-p)
			i2--;
		num=i2>0?n-profit2[i2]:n;
		t=num*profit1[i1];
		//printf("%lld %lld %lld\n",i1+1,i2+1,t);
		if(t<ans)
			ans=t;
		i1++;
		
	}


	i1=m-1; i2=0;
	while(1)
	{
		if(i2==k)
			break;
		p=vb[i2].first;
		if(p>s)
			break;

		while(i1>=0 && va[i1].first>s-p)
			i1--;

		num=n-profit2[i2];
		i1>=0?(t=num*profit1[i1]):(t=num*x);
		//printf("%lld %lld %lld\n",i1+1,i2+1,t);
		if(t<ans)
			ans=t;
		i2++;
		
	}

	prll(ans);
	return 0;
}