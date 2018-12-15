#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
ll a[MAX],cl[MAX],acl[MAX];
ll maxSum(ll a[], ll size)
{
   ll max_so_far = a[0];
   ll curr_max = a[0];
 
   for (ll i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far>0?max_so_far:0;
}
int main()
{
	ll n,s,e,t,j,k,scl,sacl,cm,cmi,am,ami,cem,cemi,aem,aemi,ans,p,q;
	scll(t);
	while(t--)
	{
		scll(n);
		rep(i,0,n)
		scll(a[i]);
		scll(s); scll(e);
		s--; e--; j=0; k=0; scl=0; sacl=0;
		rep(i,0,n)
		if(i>=s && i<e)
		cl[j++]=a[i], scl+=a[i];
		else
		acl[k++]=a[i], sacl+=a[i];
		p=maxSum(cl,e-s); q=maxSum(acl,n-e+s);
		printf("%lld %lld %lld %lld\n",scl,sacl,p,q);
		ans=min(sacl+2*(scl-p),scl+2*(sacl-q));
		
		printf("%lld\n",ans);
	}
	return 0;
}
