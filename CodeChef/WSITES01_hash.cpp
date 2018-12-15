#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
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
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD1 1000000007ll
#define B1 100000007ll
#define MOD2 1000000009ll
#define B2 100000081ll
#define MOD3 500000093ll
#define B3 200000039ll
#define INF 4000000000000000000
#define MAX 200000+5
using namespace std;

ll powB1[MAX],powB2[MAX],powB3[MAX];
set<ll> prefix1,prefix2,prefix3;
set<string> ans;

void pre()
{
	powB1[0]=1;	
	rep(i,1,MAX)
	{
		powB1[i]=B1*powB1[i-1];
		powB1[i]%=MOD1;
	}

	powB2[0]=1;	
	rep(i,1,MAX)
	{
		powB2[i]=B2*powB2[i-1];
		powB2[i]%=MOD2;
	}

	powB1[0]=1;	
	rep(i,1,MAX)
	{
		powB3[i]=B3*powB3[i-1];
		powB3[i]%=MOD3;
	}
}

void foo(string &s)
{
	ll h1=0,h2=0,h3=0;
	rep(i,0,s.size())
	{
		h1+=((ll)s[i])*powB1[i];
		h1%=MOD1;
		prefix1.insert(h1);
		
		h2+=((ll)s[i])*powB2[i];
		h2%=MOD2;
		prefix2.insert(h2);

		h3+=((ll)s[i])*powB3[i];
		h3%=MOD3;
		prefix3.insert(h3);
	}
}

bool hoo(string &s)
{
	ll h1=0,h2=0,h3=0;
	vl v1(s.size()),v2(s.size()),v3(s.size());
	rep(i,0,s.size())
	{
		h1+=((ll)s[i])*powB1[i];
		h1%=MOD1;
		v1[i]=h1;

		h2+=((ll)s[i])*powB2[i];
		h2%=MOD2;
		v2[i]=h2;

		h3+=((ll)s[i])*powB3[i];
		h3%=MOD3;
		v3[i]=h3;
	}
	if(prefix1.find(h1)!=prefix1.end() && prefix2.find(h2)!=prefix2.end() && prefix3.find(h3)!=prefix3.end())
	{
		//cout<<s<<endl;
		return false;
	}
	rep(i,0,s.size())
	if(prefix1.find(v1[i])==prefix1.end() || prefix2.find(v2[i])==prefix2.end() || prefix3.find(v3[i])==prefix3.end())
	{
		ans.insert(s.substr(0,i+1));
		break;
	}
	return true;
}

int main()
{
	pre();
	ll n;
	sl(n);
	vector<string> allow,block;
	string s;
	rep(i,0,n)
	{
		getchar();
		char c=getchar();
		getchar();
		s.clear();
		cin>>s;
		if(c=='+')
			allow.pb(s);
		else
			block.pb(s);
	}
	rep(i,0,allow.size())
	foo(allow[i]);

	//cout<<prefix.size()<<endl;

	rep(i,0,block.size())
	if(!hoo(block[i]))
	{
		pr(-1);
		return 0;
	}
	cout<<ans.size()<<endl;
	tr(it,ans)
	cout<<*it<<endl;
	return 0;
}