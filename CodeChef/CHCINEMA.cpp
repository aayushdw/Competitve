#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
ll odd_rows[2][2],even_rows[2][2];
void odd(ll n,ll m, ll lr)
{
	ll a=lr/n,b=lr%n,i,j;
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	{
		even_rows[i][j]=0;
		odd_rows[i][j]=0;
	}
	
	if(m==1)
	{
		odd_rows[0][0]=n-lr;
		odd_rows[0][1]=1;
		return;
	}
	
	if(a%2)
	{
		a--;
		b+=n;
	}
	if(!b)
	{
		odd_rows[0][0]=n;
		odd_rows[0][1]=m-a;
	}
	else
	{
		m-=a;
		if(m==1)
		{
			odd_rows[0][0]=n-b;
			odd_rows[0][1]=1;
			return;
		}
		a=b/2;
		b%=2;
		odd_rows[0][0]=a;
		odd_rows[0][1]=m-2;
		if(b)
		{
			odd_rows[1][0]=n-a-1;
			odd_rows[1][1]=m;
			even_rows[0][0]=1;
			even_rows[0][1]=m-1;
		}
		else
		{
			odd_rows[1][0]=n-a;
			odd_rows[1][1]=m;
		}
	}
}
int main()
{
	ll n,m,l,r,z,b,t,o,e,lr,nm,v,bf,i,j;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		nm=n*m; v=0; bf=0;
		sc(z); sc(l); sc(r); sc(b);
		lr=l+r;
		if(l+r+z>=nm)
		{
			printf("%lld\n",nm);
			continue;
		}
		if(m%2)
		{
			//printf("odd seats\n");
			odd(n,m,lr);
			v+=(odd_rows[0][1]/2)*odd_rows[0][0];
			v+=(odd_rows[1][1]/2)*odd_rows[1][0];
			v+=(even_rows[0][1]/2)*even_rows[0][0];
			v+=(even_rows[1][1]/2)*even_rows[1][0];
			bf+=((odd_rows[0][1]+1)/2)*odd_rows[0][0];
			bf+=((odd_rows[1][1]+1)/2)*odd_rows[1][0];
			bf+=(even_rows[0][1]/2)*even_rows[0][0];
			bf+=(even_rows[1][1]/2)*even_rows[1][0];
			if(bf>b)
			v+=bf-b;
			else
			v+=0;
			
			if(z>v)
			v=0;
			else
			v-=z;
		}
		else
		{
			//printf("even seats\n");
			if(lr<=n)
			{
				//printf("much vacant\n");
				e=n-lr;
				o=lr;
				bf+=nm/2;
				v=nm/2-lr;
				if(bf>b)
				v+=bf-b;
				else
				v+=0;
				if(z>v)
				v=0;
				else
				v-=z;
			}
			else
			{
				//printf("not so vacant\n");
				lr-=n;
				odd(n,m-1,lr);
				v+=(odd_rows[0][1]/2)*odd_rows[0][0];
				v+=(odd_rows[1][1]/2)*odd_rows[1][0];
				v+=(even_rows[0][1]/2)*even_rows[0][0];
				v+=(even_rows[1][1]/2)*even_rows[1][0];
				bf+=((odd_rows[0][1]+1)/2)*odd_rows[0][0];
				bf+=((odd_rows[1][1]+1)/2)*odd_rows[1][0];
				bf+=(even_rows[0][1]/2)*even_rows[0][0];
				bf+=(even_rows[1][1]/2)*even_rows[1][0];
				if(bf>b)
				v+=bf-b;
				else
				v+=0;
			
				if(z>v)
				v=0;
				else
				v-=z;
			}
		}
		printf("%lld\n",nm-v);
	}
	return 0;
} 
