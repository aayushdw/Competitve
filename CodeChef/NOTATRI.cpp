#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
	long long int n,i,f,j,k;
	long long int count,lim;
	int *a;
	scanf("%lld",&n);
	while(n)
	{
		a=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		mergeSort(a,0,n-1);
		f=0; count=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				k=j+1;
				while(a[k]<=a[i]+a[j]&&k<n)
				{
					count++;
					//printf("%d-%d %d-%d %d-%d\n",a[i],i,a[j],j,a[k],k);
					k++;
				}
			}
		}
		lim=n*(n-1)*(n-2)/6;
		printf("%lld\n",lim-count);
		scanf("%lld",&n);
	}
	return 0;
}
