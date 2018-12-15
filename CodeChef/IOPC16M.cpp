#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 1000000+5
using namespace std;
int main()
{
	ll t,i,j,n,q,p,m,pow2[70]={1};
	for(i=1;i<70;i++)
	pow2[i]=2*pow2[i-1];
	//prll(pow2[10]);
	scll(t);
	while(t--)
	{
		scll(n); scll(q);
		while(q--)
		{
			scll(p);
			i=1;
			while(p*pow2[i+1]+pow2[i+1]-1<n)
			{
				//prll(p*pow2[i]+pow2[i]-1);
				i++;
			}
			prll(i);
			m=n-p*pow2[i+1]+1;
			prll(m);
			m+=pow2[i-1]-1;
			prll(m);
			prll(m-m/2);
		}
	}
}
