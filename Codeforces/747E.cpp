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
#define MAX 2000000+5

using namespace std;
vi v[MAX];
char s[MAX];
string str;
int idx,len;

void getString()
{
	str.clear();
	for(len=0 ; s[idx]!=',' && s[idx]!='\0' ; idx++, len++)
		str.pb(s[idx]);
		
	idx++;
	/*rep(i,0,str.length())
	printf("%c",str[i]);
	printf("\n");*/
}

int getNum()
{
	int ret=0,mul=1;
	for(;s[idx]!=',' && s[idx]!='\0' ; idx++ )
	{
		ret*=mul;
		ret+=(s[idx]-'0');
		mul*=10;
	}

	if(s[idx]==',')
		idx++;

	//printf("Num = %d\n",ret);

	return ret;

	
}

void solve(int lvl)	//MODIFY
{
	if(!lvl)
	{
		getString();
		while(len)
		{
			//insert in set
			v[lvl].pb(idx-len-1);
			int n=getNum();
			rep(i,0,n)
			solve(lvl+1);		//MODIFY
			getString();
		}

	}
	else
	{
		getString();
		v[lvl].pb(idx-len-1);
		int n=getNum();
		//insert in set
		rep(i,0,n)
		solve(lvl+1);
	}
}

void print(int id)
{
	for(int i=id ; s[i] != ',' ; i++)
		printf("%c",s[i]);
	printf(" ");
}

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	//s[l]=',';
	//s[l+1]='\0';
	idx=0;
	solve(0);
	int c=0;
	rep(i,0,MAX)
	{
		if(v[i].size())
		{
			c++;
			//sort(all(v[i]));
		}
	}
	pr(c);
	rep(i,0,c)
	{
		rep(j,0,v[i].size())
		print(v[i][j]);
		printf("\n");
	}
	return 0;
}.