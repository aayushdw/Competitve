#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
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
using namespace std;
int main()
{
	ll t,i,n,p,sum,k,l;
	char s[100000+5];
	scll(t);
	while(t--)
	{
		ll m=100000000;
		scanf("%s",s);
		printf("%s\n",s);
		scll(k);
		ll a[26]={0};
		l=strlen(s);
		for(i=0;i<l;i++)
		a[s[i]-'a']++;
		sort(a,a+26);
		vector<ll> v;
		for(i=0;i<26;i++)
		if(a[i])
		v.pb(a[i]);
		for(ll j=0;v.size();j++)
		{
			sum=0;
			p=v[0]+k;
			for(i=1;i<v.size();i++)
			if(a[i]>p)
			sum+=p-a[i];
			v.erase(v.begin());
			m=min(m,sum);
		}
		printf("%lld\n",m);
	}
	return 0;
}
