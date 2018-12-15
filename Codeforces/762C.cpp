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
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

char a[MAX],b[MAX];
int v[MAX][26],curr[26],ans1[MAX],ans2[MAX],f[26],ans3[MAX],ans4[MAX];
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	int la=strlen(a);
	int lb=strlen(b);
	int p1;
	
	memset(v,-1,sizeof(v));
	memset(curr,-1,sizeof(curr));
	memset(ans1,0,sizeof(ans1));
	rep(i,0,26)
	f[i]=MAX+100;
	for(int i=la-1;i>=0;i--)
	{
		rep(j,0,26)
		v[i][j]=curr[j];
		curr[a[i]-'a']=i;
		f[a[i]-'a']=min(f[i],i);
	}

	p1=-2;
	rep(j,0,lb)
	{
		if(p1==-2)
		{
			p1=f[b[j]-'a'];
			if(p1>MAX)
				p1=-1;
		}
		else
			p1=v[p1][b[j]-'a'];
		//printf("fwd p1=%d\n",p1);
		if(p1<0)
			break;
		ans1[p1]=j+1;
	}


	reverse(a,a+la);
	reverse(b,b+lb);

	memset(v,-1,sizeof(v));
	memset(curr,-1,sizeof(curr));
	memset(ans2,0,sizeof(ans2));
	rep(i,0,26)
	f[i]=MAX+100;
	for(int i=la-1;i>=0;i--)
	{
		rep(j,0,26)
		v[i][j]=curr[j];
		curr[a[i]-'a']=i;
		f[a[i]-'a']=min(f[i],i);
	}
	p1=-2;
	rep(j,0,lb)
	{
		if(p1==-2)
		{
			p1=f[b[j]-'a'];
			if(p1>MAX)
				p1=-1;
		}
		else
			p1=v[p1][b[j]-'a'];
		//printf("bck p1=%d\n",p1);
		if(p1<0)
			break;
		ans2[p1]=j+1;
	}


	rep(i,0,la)


	return 0;
}