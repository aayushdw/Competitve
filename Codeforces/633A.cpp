#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
#define prll(x) printf("%I64d",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 300000+5
using namespace std;
int main()
{
	int a,b,c,i,j,f=0;
	sc(a); sc(b); sc(c);
	for(i=0;i<=c;i+=a)
	for(j=0;j+i<=c;j+=b)
	if(i+j==c)
	f=1;
	if(f)
	printf("Yes");
	else
	printf("No");
	return 0;
}
