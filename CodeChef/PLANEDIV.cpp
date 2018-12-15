#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
#define MAX 100000+5
ll frac_compare(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2,ll p);
ll gcd(ll a, ll b)
{
	if (b == 0)
	return a;
	if (a==0)
	return b;
	if (a > b)
	return gcd(b, a%b);
	return gcd(a, b%a);
}


ll frac(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2)
{
	if(a1*b1)
	return frac_compare(a1,c1,b1,a2,c2,b2,0);
	if(!a1)
	return frac_compare(b1,c1,a1,b2,c2,a2,0);
	if(!b1)
	return frac_compare(a1,c1,b1,a2,c2,b2,0);
}

ll frac_compare(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2,ll p)
{
	if(p)
	return frac(a1,c1,b1,a2,c2,b2);
	ll c=a1*b2,d=a2*b1;
	if(c==d)
	return 0;
	if(a1==0)
	{
		if(b1<0)
		return -1;
		else
		return 1;
	}
	if(a2==0)
	{
		if(b2<0)
		return 1;
		else
		return -1;
	}
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

void merge(ll **arr, ll l, ll m, ll r,ll a,ll b,ll c)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
    ll L[3][n1], R[3][n2];
    for(i = 0; i < n1; i++)
    {
        L[0][i] = arr[0][l + i];
        L[1][i] = arr[1][l + i];
        L[2][i] = arr[2][l + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[0][j] = arr[0][m + 1+ j];
        R[1][j] = arr[1][m + 1+ j];
        R[2][j] = arr[2][m + 1+ j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (frac_compare(R[a][j],R[b][j],R[c][j],L[a][i],L[b][i],L[c][i],b-1)==1)
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
void mergeSort(ll **arr, ll l, ll r,ll a,ll b,ll c)
{
    if (l < r)
    {
        ll m = l+(r-l)/2;
        mergeSort(arr, l, m, a, b, c);
        mergeSort(arr, m+1, r, a, b, c);
        merge(arr, l, m, r, a, b, c);
    }
}
int main()
{
	ll i,j,t,A,B,C,n,f,max,count;
	sc(t);
	while(t--)
	{
		sc(n);
		ll **arr;
		arr=(ll**)calloc(3,sizeof(ll*));
		arr[0]=(ll*)calloc(n,sizeof(ll));
		arr[1]=(ll*)calloc(n,sizeof(ll));
		arr[2]=(ll*)calloc(n,sizeof(ll));
		for(i=0;i<n;i++)
		{
			sc(arr[0][i]); sc(arr[1][i]); sc(arr[2][i]);
			A=abs(arr[0][i]);
			B=abs(arr[1][i]);
			C=abs(arr[2][i]);
			f=gcd(A,gcd(B,C));
			arr[0][i]/=f;
			arr[1][i]/=f;
			arr[2][i]/=f;
			if(arr[0][i]==0)
			if(arr[1][i]<0)
			{
				arr[1][i]*=-1;
				arr[2][i]*=-1;
			}
			if(arr[1][i]==0)
			if(arr[0][i]<0)
			{
				arr[0][i]*=-1;
				arr[2][i]*=-1;
			}
		}

		mergeSort(arr,0,n-1,0,1,2);
		/*
		for(i=0;i<3;i++)
		{
			for(j=0;j<n;j++)
			printf("%lld ",arr[i][j]);
			printf("\n");
		}
		*/
		
		i=0;
		while(i<n)
		{
			j=i;
			while(frac_compare(arr[0][i],arr[1][i],arr[2][i],arr[0][j],arr[1][j],arr[2][j],0)==0)
			{
				j++;
				if(j==n)
				break;
			}
			mergeSort(arr,i,j-1,0,2,1);
			i=j;
		}
		/*
		for(i=0;i<3;i++)
		{
			for(j=0;j<n;j++)
			printf("%lld ",arr[i][j]);
			printf("\n");
		}
		*/
		
		ll max=0,count;
		i=0;
		while(i<n)
		{
			count=1; j=i+1;
			while(frac_compare(arr[0][i],arr[1][i],arr[2][i],arr[0][j],arr[1][j],arr[2][j],0)==0)
			{
				if(frac_compare(arr[0][j],arr[2][j],arr[1][j],arr[0][j-1],arr[2][j-1],arr[1][j-1],1)==0)
				j++;
				else
				{
					count++;
					j++;
				}
			}
			if(count>max)
			max=count;
			i=j;
		}
		printf("%lld\n",max);
		
	}
	return 0;
}
