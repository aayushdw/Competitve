#include<stdio.h>
#include<string>
#define len 100
#define ll long long int
using namespace std;
ll f[100]={1,1};
bool D(ll n,ll d)
{
	if(n==1)
	return true;
	if(n==2)
	return false;
	if(f[n-2]>=d)
	return D(n-2,d);
	else
	return D(n-1,d-f[n-2]);
}
int main()
{
	ll i,p=1,n,m,j;
	bool flag;
	string a("1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
	string b("8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196");
	
	/*string a("1415926535");
	string b("8979323846");*/
	for(i=2;i<100;i++)
	f[i]=f[i-1]+f[i-2];
	for(i=0;i<=17;i++)
	{
		//printf("Iteration=%lld\n",i);
		n=(127+19*i)*p;
		printf("n=%lld\n",n);
		p*=7;
		n--;
		m=n%len;
		n/=len;
		printf("m=%lld n=%lld\n",m,n);
		for(j=0;n>=f[j];j++);
		printf("f=%lld\n",f[j]);
		flag=D(j,n);
		if(flag)
		printf("A=%c\n",a[m]);
		else
		printf("B=%c\n",b[m]);
	}
	/*n=48;
	n--;
	m=n%len;
	n/=len;
	for(j=0;n>=f[j];j++);
	printf("%lld\n",j);
	flag=D(j,n);
	if(flag)
	printf("%c",a[m]);
	else
	printf("%c",b[m]);*/
}
