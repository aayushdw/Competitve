#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long int
#define sc(x) scanf("%lld",&x)

ll gcd(ll a, ll b)
{
if (b == 0)
return a;
if(a==0)
return b;
if (a > b)
return gcd(b, a%b);
return gcd(a, b%a);
}

ll frac_comp(ll a1,ll b1,ll a2,ll b2)
{
	
	ll c=a1*b2,d=a2*b1;
	if(c==d)
	return 0;
	if(a1==0)
	return 1;
	if(a2==0)
	return -1;
	if(a1*a2>0)
	{
		if(d>c)
		return 1;
		return -1;
	}
	if(a1*a2<0)
	{
		if(d>c)
		return -1;
		return 1;
	}
}

ll frac(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2)
{
	if(a1*b1)
	return frac_comp(a1,c1,a2,c2);
	if(!a1)
	return frac_comp(b1,c1,b2,c2);
	if(!b1)
	return frac_comp(a1,c1,a2,c2);
}

void merge(ll **arr, ll l, ll m, ll r,ll x)
{
    ll i, j, k, p;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
    ll L[3][n1], R[3][n2];
    for(i = 0; i < n1; i++)
    {
        for(p=0;p<3;p++)
        L[p][i] = arr[p][l + i];
    }
    for(j = 0; j < n2; j++)
    {
        for(p=0;p<3;p++)
        R[p][j] = arr[p][m + 1+ j];
    }
    i = 0;
    j = 0;
    k = l;
    
    if(x==0)
	{
	  	while (i < n1 && j < n2)
	    {
    	    if (frac_comp(R[0][j],R[1][j],L[0][i],L[1][i])==1)
        	{
        	    arr[0][k] = L[0][i];
        	    arr[1][k] = L[1][i];
        	    arr[2][k] = L[2][i];
        	    i++;
        	}
        	else
        	{
        	    arr[0][k] = R[0][j];
        	    arr[1][k] = R[1][j];
        	    arr[2][k] = R[2][j];
        	    j++;
        	}
        	k++;
    	}
	}
	else if(x==1)
	{
		while (i < n1 && j < n2){
		if(frac(R[0][j],R[1][j],R[2][j],L[0][i],L[1][i],L[2][i])>0)
		{
			arr[0][k] = L[0][i];
            arr[1][k] = L[1][i];
            arr[2][k] = L[2][i];
            i++;
		}
		else
        {
            arr[0][k] = R[0][j];
            arr[1][k] = R[1][j];
            arr[2][k] = R[2][j];
            j++;
        }
        k++;
		}
	}
    while (i < n1)
    {
        arr[0][k] = L[0][i];
        arr[1][k] = L[1][i];
        arr[2][k] = L[2][i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[0][k] = R[0][j];
        arr[1][k] = R[1][j];
        arr[2][k] = R[2][j];
        j++;
        k++;
    }
}
void mergeSort(ll **arr, ll l, ll r, ll x)
{
    if (l < r)
    {
        ll m = l+(r-l)/2;
        mergeSort(arr, l, m, x);
        mergeSort(arr, m+1, r, x);
        merge(arr, l, m, r, x);
    }
}

int main()
{
	ll t,i,j,n,A,B,C,g,count,max;
	sc(t);
	while(t--)
	{
		sc(n);
		ll **a;
		a=(ll**)calloc(3,sizeof(ll*));
		for(i=0;i<3;i++)
		a[i]=(ll*)calloc(n,sizeof(ll));
		for(i=0;i<n;i++)
		{
			sc(a[0][i]);
			sc(a[1][i]);
			sc(a[2][i]);
			A=abs(a[0][i]);
			B=abs(a[1][i]);
			C=abs(a[2][i]);
			g=gcd(A,gcd(B,C));
			a[0][i]/=g;
			a[1][i]/=g;
			a[2][i]/=g;
		}
		
		mergeSort(a,0,n-1,0);
		
		/*
		for(i=0;i<3;i++)
		{
			for(j=0;j<n;j++)
			printf("%4lld ",a[i][j]);
			printf("\n");
		}
		*/
		
		i=0;
		while(i<n)
		{
			j=i+1;
			while(frac_comp(a[0][j-1],a[1][j-1],a[0][j],a[1][j])==0)
			{	
				j++;
				if(j==n)
				break;
			}
			mergeSort(a,i,j-1,1);
			i=j;
		}
		/*
		for(i=0;i<3;i++)
		{
			for(j=0;j<n;j++)
			printf("%4lld ",a[i][j]);
			printf("\n");
		}
		*/
		i=0; max=0;
		
		while(i<n)
		{
			j=i+1; count=1;
			while(frac_comp(a[0][i],a[1][i],a[0][j],a[1][j])==0)
			{
				if(frac(a[0][j],a[1][j],a[2][j],a[0][j-1],a[1][j-1],a[2][j-1])==0)
				j++;
				else
				{
					j++;
					count++;
				}
				if(j==n)
				break;
			}
			i=j;
			if(max<count)
			max=count;
		}
		printf("%lld\n",max);
		free(a);
	}
	return 0;
}
