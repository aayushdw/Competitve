#include <bits/stdc++.h>
using namespace std;
 
 
pair<int ,int > p1[100001] , p2[100001] ; 
int l[100001] = {0} ; 
 
int is_horizontal(int i)
{
	if(p1[i].second == p2[i].second)
		return  1 ; 
		
	return  0 ;	
}
 
int main() {
	// your code goes here
	int n ; 
	cin>>n ; 
	
	for(int i=0;i<n;i++)
	{
		cin>>p1[i].first>>p1[i].second>>p2[i].first>>p2[i].second ; 
	}
	
	int c = 0 ; 
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(is_horizontal(i) && is_horizontal(j))
				continue ; 
			if( !is_horizontal(i) && (!is_horizontal(j)) )
				continue ; 	
			
			int h,v ; 
			if(is_horizontal(i))
			{
				h = i;
				v = j ; 
			}
			else
			{
				h = j ; v = i ;  
			}
			
			if( ( (  ( p1[h].second - p1[v].second)  * (p1[h].second - p2[v].second) < 0 )
			&&  (  ( p1[v].first - p1[h].first  )  * (p1[v].first - p2[h].first  )  < 0    ) ) || 
			    ( (  ( p1[h].second - p1[v].second)  * (p1[h].second - p2[v].second) < 0 )
			&&  (  ( p1[v].first - p1[h].first  )  * (p1[v].first - p2[h].first  )  == 0    ) ) || 
			    ( (  ( p1[h].second - p1[v].second)  * (p1[h].second - p2[v].second) == 0 )
			&&  (  ( p1[v].first - p1[h].first  )  * (p1[v].first - p2[h].first  )  < 0    ) ) )
			{	c++ ; 
				l[i]++ ; 
				l[j]++ ; 
			}	
		}
	}
	
	cout<<c<<endl ; 
	for(int i=0;i<n;i++)
	cout<<l[i]<<" " ;
	return 0;
} 