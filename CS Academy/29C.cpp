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
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000ll
#define MAX 100000+5
#define LIM 10000000000
using namespace std;

ll num[MAX]={0},a[MAX];

int main()
{
	ll n,k,m=0;
	sl(n); sl(k);
	rep(i,0,n)
	{
		sl(a[i]);
		num[a[i]]++;
		m=max(m,a[i]);
	}
	ll il=0,ih=0,dl=0,dh=0;
	ll low=0,high=low+k;
	ll vil=0,vih=0,vdl=0,vdh=0;
	ll ans=INF;
	rep(i,0,n)
	{
		if(a[i]<high)
		{
			ih++;
			vih+=high-a[i];
		}
		if(a[i]<low)
		{
			il++;
			vil+=low-a[i];
		}
		if(a[i]>high)
		{
			dh++;
			vdh+=a[i]-high;
		}
		if(a[i]>low)
		{
			dl++;
			vdl+=a[i]-low;
		}
	}

	{
		ll p=max(vil,vdh);
		ll q=min(vih,vdl);
		if(p<=q)
			ans=min(ans,p);
	}

	/*printf("il=%lld , vil=%lld\n",il,vil);
	printf("ih=%lld , vih=%lld\n",ih,vih);
	printf("dl=%lld , vdl=%lld\n",dl,vdl);
	printf("dh=%lld , vdh=%lld\n",dh,vdh);*/
	low=1;
	high=low+k;	
	for(;high<=m;low++,high++)
	{
		//prll(low);
		
		il+=num[low-1];
		vil+=il;
		ih+=num[high-1];
		vih+=ih;

		vdl-=dl;
		dl-=num[low];
		
		vdh-=dh;
		dh-=num[high];

		/*printf("il=%lld , vil=%lld\n",il,vil);
		printf("ih=%lld , vih=%lld\n",ih,vih);
		printf("dl=%lld , vdl=%lld\n",dl,vdl);
		printf("dh=%lld , vdh=%lld\n",dh,vdh);*/

		ll p=max(vil,vdh);
		ll q=min(vih,vdl);
		if(p<=q)
			ans=min(ans,p);
	}
	prll(ans);
	return 0;
}