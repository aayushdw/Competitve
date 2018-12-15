

#include <bits/stdc++.h>
using namespace std ; 


//USUAL
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sc(n) scanf("%c",&n)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define ll long long int


//STL
#define ii pair<int , int >
#define F first
#define S second
#define ic pair<int , char >
#define li pair < long long int , int >
#define mp make_pair 
#define vi vector<int>
#define vvi vector< vi >
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define pb push_back
#define tr(it,c) for( typeof ( (c).begin() ) it = c.begin();it!=(c).end();++it)

//Constants
#define pi 3.141592653
#define e 2.7182818284
#define MAXP 1000000
#define MOD 1000000007

//Global Variables

map<vii , int> M ; 
vii cnt[1000005] ;  
ll modulo[1000005] ; 

int main()
{
	int n ,m ;
	s(n) ; s(m) ;

	modulo[1] = 1 ; 
	for(int i=2 ; i<=m ; i++)
	{
		modulo[i] = (modulo[i-1]*i)%MOD ; 
	}
	
	forall(i,0,n)
	{
		int k ; 
		s(k) ; 
		forall(j,0,k)
		{
			int x ; 
			s(x) ;
			if(cnt[x].size()==0)
			{
				cnt[x].pb(mp(i,1)) ; 
				continue ; 
			}
			vii:: iterator it = cnt[x].end() ; 
			it-- ; 
			if(it->first==i)
				(it->second)++ ; 
			else
				cnt[x].pb(mp(i,1)) ; 
		}
	}

	for(int i=1 ; i<=m ; i++)
	{
		if(M.find(cnt[i])==M.end())
		{
			M[cnt[i]] = 1 ; 
		}
		else
			M[cnt[i]]++ ; 
	}

	ll ans = 1 ; 
	tr(it,M)
	{
		ans = (ans * modulo[it->second]) % MOD ; 
	}

	cout<<ans; 

	return 0 ; 
}