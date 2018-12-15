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
#define MAX 1000+5
using namespace std;

int n,m;
ii ex,st;
int dist[MAX][MAX],vis[MAX][MAX]={0},a[MAX][MAX];
queue< pair< ii,int > > q;

bool check(int x,int y,int val)
{
	if(x<0 || x>=n || y<0 || y>=m)
		return false;
	if(vis[x][y])
		return false;
	vis[x][y]=1;
	if(a[x][y]<0)
		return false;
	dist[x][y]=min(dist[x][y],val);
	return true;
}

void flood(int x,int y)
{
	q.push(mp(mp(x,y),0));
	pair< ii,int > p;
	int val;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		x=p.F.F; y=p.F.S; val=p.S;
		if(check(x,y,val))
		{
			q.push(mp(mp(x+1,y),val+1));
			q.push(mp(mp(x-1,y),val+1));
			q.push(mp(mp(x,y+1),val+1));
			q.push(mp(mp(x,y-1),val+1));
		}
		//cout<<q.size()<<endl;
	}
}

int main()
{
	string str;
	si(n); si(m);
	rep(i,0,MAX)
	rep(j,0,MAX)
	dist[i][j]=INT_MAX; //CHECK
	rep(i,0,n)
	{
		cin>>str;
		rep(j,0,m)
		if(str[j]=='T')
			a[i][j]=-1;
		else if(str[j]=='E')
			ex=mp(i,j), a[i][j]=0;
		else if(str[j]=='S')
			st=mp(i,j), a[i][j]=0;
		else
			a[i][j]=str[j]-'0';
	}
	flood(ex.F,ex.S);
	int d=dist[st.F][st.S],ans=0;
	
	/*rep(i,0,n)
	{
		rep(j,0,m)
		printf("%3d",dist[i][j]);
		printf("\n");
	}*/


	rep(i,0,n)
	rep(j,0,m)
	if(dist[i][j]<=d && a[i][j]>=0)
		ans+=a[i][j];
	pr(ans);
	return 0;
}