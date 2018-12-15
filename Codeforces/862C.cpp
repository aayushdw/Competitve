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
#define MAX 1000000
using namespace std;

bitset<MAX> t;

int main()
{
	int n,x;
	si(n); si(x);
	t.reset();
	srand(time(NULL));

	if(n==2 && x==0)
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	if(n==1)
	{
		pr(x);
		return 0;
	}
	vi a(MAX);
	while(1)
	{
		rep(i,0,MAX)
			a[i] = i;
		random_shuffle(a.begin(),a.end());
		int j = 0;
		while(j+n<MAX)
		{
			int c = 0;
			rep(i,j,j+n-1)
			{
				c^=a[i];
				t[i]=true;
			}
			
			if((c^x) > MAX)
			{
				j+=n-1;
				//pr(c^x);
				continue;
			}

			if(!t[c^x])
			{
				printf("%d ",c^x);
				rep(i,j,j+n-1)
					printf("%d ",a[i]);
				printf("\n");
				return 0;
			}

			rep(i,j,j+n-1)
				t[i] = false;

			j+=n-1;
		}
	}
	return 0;
}