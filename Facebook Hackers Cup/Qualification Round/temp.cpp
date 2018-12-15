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

vi prime ; 
void generate_prime()
{
	int is_prime[MAXP+1] ; 
	memset(is_prime,0,sizeof(is_prime)) ; 
	forall(i,2,MAXP+1)
	{
		if(!is_prime[i])
		{
			prime.pb(i) ; 
			int temp = i ; 
			while(temp<=MAXP)
			{
				is_prime[temp] = 1 ; 
				temp += i ; 
			}
		}
	}	
}

ll find_power(ll x , ll n)
{
	if(n==0)
		return 1 ;
	if(n==1)
		return x ; 
	ll temp = find_power(x , n/2) ;
	temp = temp * temp ; 
	if(n%2==0)
		return temp ; 
	return (temp*x) ; 
}

//Global Variables

int main()
{
	int t ; 
	s(t) ; 
	forall(i,0,t)
	{
		int n ; 
		s(n) ; 
		vi array ;  
		forall(j,0,n)
		{ 
			int temp ; 
			s(temp) ; 
			array.pb(temp) ;  
		}
		sort(array.begin() , array.end()) ;

		int left=0,right=n-1,ans=0 ; 
		while(1)
		{

			
			if(left > right)
				break ; 

			if(array[right] >= 50)
			{
				right-- ; 
				ans++ ; 
				continue ; 
			}

			
			
			int temp = left ; 
			while( (temp<=right) && ( ((temp-left+1 + ((temp==right)?0:1) )  *array[right]) < 50) )
			{
				//cout<<(temp-left+1+1)*array[right]<<"sum \n " ; 
				temp++ ; 
			}

			
			//cout<<left<<"  "<<right<<"  "<<temp<<"  "<<array[right]<<"  "<<(temp-left+2)*array[right]<<endl ;  

			if(temp>right)
			{
				break ; 
			}
			

			ans++ ; 
			left = temp + 1 ; 
			right-- ; 
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl ; 

	}
	return 0 ; 
}