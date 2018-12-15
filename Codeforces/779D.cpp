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
#define MAX 200000+5
using namespace std;

string t,p;
int a[MAX];

bool isSubSequence(string str1, string str2)
{
   int j = 0;
 	int m=str1.length(),n=str2.length();
   for (int i=0; i<n&&j<m; i++)
       if (str1[j] == str2[i])
         j++;
   return (j==m);
}

int main()
{
	cin>>t;
	getchar();
	cin>>p;
	rep(i,0,t.length())
	si(a[i]);
	/*rep(i,0,t.length())
	x[t[i]-'a']++;
	rep(i,0,p.length())
	y[p[i]-'a']++;
	int ans,z;
	rep(i,0,t.length())
	{
		z=a[i]-1;
		printf("%d %c\n",i,t[z]);
		if(x[t[z]-'a']>y[t[z]-'a'])
			x[t[z]-'a']--;
		else
			ans=i;
	}
	pr(ans);*/
	int low=0, high=t.length();
	while(low<high)
	{
		if(low+1==high)
		{
			string x;
			vi v;
			rep(i,high,t.length())
			v.pb(a[i]-1);
			sort(all(v));
			rep(i,0,v.size())
			x.pb(t[v[i]]);
			if(isSubSequence(p,x))
				break;
			else
			{
				high=low;
				break;
			}
		}
		int mid=(low+high)/2;
		string x;
		vi v;
		rep(i,mid,t.length())
		v.pb(a[i]-1);
		sort(all(v));
		rep(i,0,v.size())
		x.pb(t[v[i]]);
		bool f=isSubSequence(p,x);
		if(f)
		{
			low=mid;
		}
		else
		{
			high=mid-1;
		}
	}
	pr(high);
	return 0;
}