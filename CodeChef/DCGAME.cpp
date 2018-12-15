#include<stdio.h>
#include<stdlib.h>
#define sc(x) scanf("%d",&x)
int b[2][1000005]={0};
int binary_search(int A[], int key, int imin, int imax)
{
  // test if array is empty
  if (imax < imin)
    // set is empty, so return value showing not found
    return -1;
  else
    {
      // calculate midpoint to cut set in half
      int imid = (imin+ imax)/2;
      
      // three-way comparison
      if (A[imid] = key)
        // key is in lower subset
        return imid;
      else if (A[imid] < key && A[imid+1]>key)
        // key is in upper subset
        return imid;
      else if (A[imid]<key)
	  	return binary_search(A, key, imid + 1, imax);
	  else if (A[imid]>key)
	  	return binary_search(A, key, imin, imid - 1);  
    }
}
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 	int L1[n1],R1[n2];
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        L1[i]=a[l+i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        R1[j]=a[m+1+j];
 	}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            a[k]=L1[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            a[k]=R1[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        a[k]=L1[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        a[k]=R1[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int a[],int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, a, l, m);
        mergeSort(arr, a, m+1, r);
        merge(arr, a, l, m, r);
    }
}
int main()
{
	int n,m,*a,x,i,j,count,p,k,y;
	char c;
	sc(n); sc(m);
	a=(int*)calloc(n+1,sizeof(int));
	for(i=0;i<n;i++)
	sc(a[i]);
	for(i=0;i<n;i++)
	{
		j=i-1;
		x=0;
		while(j>=0)
		{
			if(a[j]>=a[i])
			break;
			x++;
			j--;
		}
		y=0;
		j=i+1;
		while(j<n)
		{
			if(a[j]>a[i])
			break;
			y++;
			j++;
		}
		b[0][i]=a[i];
		b[1][i]=(x+1)*(y+1);
	}
	mergeSort(b[0],b[1],0,n-1);
	while(m--)
	{
		getchar();
		c=getchar();
		sc(k);
		getchar();
		p=getchar()-'C';
		y=binary_search(b[0],k,0,n-1);
		x=0;
		if(c=='=')
		{
			i=y;
			while(b[0][i]==k&&i>=0)
			{
				x+=b[1][i];
				i--;
			}
			i=y+1;
			while(b[0][i]==k&&i<n)
			{
				x+=b[1][i];
				i++;
			}
		}
		else if(c=='<')
		{
			i=y;
			while(b[0][i]<k&&i>=0)
			{
				x+=b[1][i];
				i--;
			}
			i=y+1;
			while(b[0][i]<k&&i<n)
			{
				x+=b[1][i];
				i++;
			}
		}
		else
		{
			i=y;
			while(b[0][i]>k&&i>=0)
			{
				x+=b[1][i];
				i--;
			}
			i=y+1;
			while(b[0][i]>k&&i<n)
			{
				x+=b[1][i];
				i++;
			}
		}
		x=(p+(x%2)+1)%2;
		printf("%c",'C'+x);
	}
	return 0;
}
