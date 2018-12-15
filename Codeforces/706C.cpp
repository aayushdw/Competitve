#include<bits/stdc++.h>
#include<string.h>
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
#define MAX 100000+5
using namespace std;
ll a[MAX][2]={0},cost[MAX]={0};
char* strrev(char s[], ll l)
{
    char* ret;
    ret=(char*)malloc(MAX*sizeof(char));
    rep(i,0,l)
    ret[i]=s[l-i-1];
    return ret;
}
int main()
{
	ll n,m=0,l;
	bool f=true;
	scll(n);
	rep(i,0,n)
	scll(cost[i]);
	a[0][1]=cost[0];
	char s[MAX],dest[MAX];
	char *rev,*revdest;
	getchar();
	scanf("%s",s);
	//printf("%s\n",s);
	strcpy(dest,s);
	revdest=strrev(dest,strlen(dest));
	//printf("%s\n",revdest);
	rep(i,1,n)
	{
		a[i][0]=INT_MAX; a[i][1]=INT_MAX;
		getchar();
		scanf("%s",s);
		//printf("%s\n",s);
		l=strlen(s);
		if(f && l<m)
		f=false;
		else
		m=l;
		if(f)
		{
			rev=strrev(s,l);
			//printf("%s\n",rev);
			
			if(a[i-1][0]>=0)
			{
				if(strcmp(s,dest)>=0)
				a[i][0]=min(a[i][0],a[i-1][0]);
				
				if(strcmp(rev,dest)>=0)
				a[i][1]=min(a[i][1],a[i-1][0]+cost[i]);
				
			}
			
			if(a[i-1][1]>=0)
			{
				if(strcmp(s,revdest)>=0)
				a[i][0]=min(a[i][0],a[i-1][1]);
				
				if(strcmp(rev,revdest)>=0)
				a[i][1]=min(a[i][1],a[i-1][1]+cost[i]);
			}
			
			if(a[i][0]==INT_MAX)
			a[i][0]=-1;
			if(a[i][1]==INT_MAX)
			a[i][1]=-1;
			
			strcpy(dest,s);
			strcpy(revdest,rev);
			
		}
	}
	if(!f)
	printf("-1");
	else if(a[n-1][0]==-1 && a[n-1][1]==-1)
	printf("-1");
	else if(a[n-1][0]==-1)
	printf("%lld",a[n-1][1]);
	else if(a[n-1][1]==-1)
	printf("%lld",a[n-1][0]);
	else
	printf("%lld",min(a[n-1][0],a[n-1][1]));
	return 0;
}
