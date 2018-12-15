
#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;



int main()
{
	char s[MAX];
	scanf("%s",s);
	int l=strlen(s);
	int a[7]={0};
	rep(i,0,l)
	{
		if(s[i]=='B')
			a[0]++;
		else if(s[i]=='u')
			a[1]++;
		else if(s[i]=='l')
			a[2]++;
		else if(s[i]=='b')
			a[3]++;
		else if(s[i]=='a')
			a[4]++;
		else if(s[i]=='s')
			a[5]++;
		else if(s[i]=='r')
			a[6]++;
	}
	a[1]/=2;
	a[4]/=2;
	int ans=a[0];
	rep(i,1,7)
	ans=min(ans,a[i]);
	printf("%d",ans);
	return 0;
}