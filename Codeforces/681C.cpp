#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string>
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
ll ins[1000005][2];
int main()
{
	char a[15],b[15],c[15],s[15];
	a[0]='i'; a[1]='n'; a[2]='s'; a[3]='e'; a[4]='r'; a[5]='t'; a[6]='\0';
	b[0]='r'; b[1]='e'; b[2]='m'; b[3]='o'; b[4]='v'; b[5]='e'; b[6]='M'; b[7]='i'; b[8]='n'; b[9]='\0';
	c[0]='g'; c[1]='e'; c[2]='t'; c[3]='M'; c[4]='i'; c[5]='n'; c[6]='\0';
	
	ll n, j=0, p;
	set<ll> v;
	scll(n);
	while(n--)
	{
		getchar();
		scanf("%s",s);
		if(s[0]=='i')
		{
			scll(p);
			v.insert(p);
			ins[j][0]=1;
			ins[j][1]=p;
			j++;
		}
		if(s[0]=='r')
		{
			if(!v.empty())
			v.erase(v.begin());
			ins[j][0]=2;
			j++;
		}
		if(s[0]=='g')
		{
			scll(p);
			ll f=0;
			
			while(!v.empty() && *(v.begin()) < p)
			{
				ins[j][0]=2;
				j++;
				v.erase(v.begin());
			}
			if(!v.empty() && *(v.begin()) > p)
			{
				v.insert(p);
				ins[j][0]=1;
				ins[j][1]=p;
				j++;
				f=1;
			}
			if(v.empty() && f==0)
			{
				ins[j][0]=1;
				ins[j][1]=p;
				j++;
				ins[j][0]=3;
				ins[j][1]=p;
				j++;
				continue;
			}
			ins[j][0]=3;
			ins[j][1]=p;
			j++;
		}
	}
	//return 0;
	printf("%lld\n",j);
	for(ll i=0;i<j;i++)
	{
		if(ins[i][0]==1)
		{
			printf("insert %lld\n",ins[i][1]);
		}
		if(ins[i][0]==2)
		{
			printf("removeMin\n");
		}
		if(ins[i][0]==3)
		{
			printf("getMin %lld\n",ins[i][1]);
		}
	}
	return 0;
}
