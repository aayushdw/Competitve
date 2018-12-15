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
 
vl a,b ; 
vi c ; 
set<ll> S ; 
set<ii> X ; 
vi m ; 
 
int main()
{
	int t ;
	s(t);  
	
	while(t--)
	{
		int n,k ; 
		s(n) ; 
		s(k) ; 
 
		a.clear() ; 
		b.clear() ; 
		c.clear() ; 
		m.clear() ; 
		X.clear() ; 
		S.clear() ; 
		forall(i,0,n)
		{
			ll temp ; 
			sl(temp) ; 
			a.pb(temp) ;
			S.insert(temp) ; 
		}
		tr(it,S)
		{
			b.pb(*it) ; 
		}
		forall(i,0,n)
		{
			vector<ll>::iterator it = lower_bound(b.begin() , b.end() , a[i]) ;
			a[i] = it - b.begin() ;
			//cout<<a[i]<<" " ; 
 
		}
		//cout<<endl ; 
		c.resize(b.size(),0) ;
		forall(i,0,n)
		{
			c[a[i]]++ ; 
			if(c[a[i]]>k)
				c[a[i]] -= k ;	 
		} 
		forall(i,0,c.size())
		{
			//cout<<c[i]<<" " ; 
		}
		forall(i,0,c.size())
		{
			if(c[i]!=0)
				X.insert(mp(c[i],i)) ;
		}
 
		/*cout<<"\n" ; 
		tr(it,X)
			cout<<it->first<<" "<<it->second<<endl ; 
		*/
		m.resize(b.size(),0) ; 
		int ans = 0 ; 
		//cout<<"\n\n";
 
		forall(i,0,c.size())
		{
			{
				set<ii>::iterator it  = X.find(mp(c[i],i)) ; 
				if(it!=X.end())
					X.erase(it) ; 
			}
			if(c[i]==0)
			{	
				continue ; 
			}
			while((c[i]<k))
			{
 
				/*cout<<"The values of the count are\n" ; 
				forall(j,0,c.size())
				{
					cout<<j<<"  "<<c[j]<<endl ; 
				}
				cout<<"contents of the set\n" ; 
				tr(it,X)
					cout<<it->first<<"  "<<it->second<<endl ; 
				cout<<"the answer is"<<ans<<endl ; 	*/
				
				int q,l ; 
				{
					set<ii>::iterator it = X.begin() ; 
					if(it!=X.end()) 
					{
						q = it->first ; 
						l = it->second ;
						X.erase(it) ; 
					}
				}
 
				if((q+c[i]<=k)&&(q<=m[i]))
				{
					c[i]+=q ; 
					m[i]-=q ; 
					c[l]=0 ; 
					m[l]+=q ; 
					q = 0 ; 
				}
				else if((q+c[i]<=k)&&(q>m[i]))
				{
					c[i] += q ; 
					//m[i] = 0 ;
					c[l] = 0 ; 
					m[l] +=q ; 
					ans += (q-m[i]) ;
					m[i] = 0 ; 
					q=0 ;  
				}
				else if((q+c[i]>k))
				{
					 
					q -= (k-c[i]) ; 
					c[l] -= (k-c[i]) ; 
					m[l] += (k-c[i]) ; 
					ans += (k-c[i]-m[i]) ; 
					m[i] = 0 ; 
					c[i] = k ; 
					if(q!=0)
					X.insert(mp(q,l)) ; 
				}
				
			}
			c[i] = 0 ; 
		}
		cout<<ans<<endl ; 
 
	}
	return 0 ;
} 