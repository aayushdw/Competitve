#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;
 
typedef struct Tree_node
{
    int max_sum ,sum , prefix_sum , suffix_sum;
 
} TN ;
 
 
TN Query(int node , int low ,int high , int x, int y);
void Build_Tree(int node , int low , int high);
int maximum(int a ,int b); 
 
 
TN Tree[150000] ; 
int A[50000]  ,N;
 
int main()
{
    int  Q , x , y ,counter;
    scanf("%d",&N);
    for(counter=0;counter<N;counter++)
    {
        scanf("%d",&A[counter]);
        
    }
    
    
    Build_Tree(1,0,N-1);
    
    /*
    for(counter=1;counter<=size_tree;counter++)
    {
        
        printf("%d     %d\n", counter , Tree[counter].max_sum ) ; 
    }
    */
    
    scanf("%d",&Q);
    for(counter=0;counter<Q;counter++)
    {
        scanf("%d %d",&x,&y);
        TN temp = Query(1,0,N-1,x-1,y-1);
        printf("%d\n",temp.max_sum );
 
    }
    
 
    
    
 
    return 0;
}
 
TN Query(int node, int low, int high ,int x , int y)
{
    TN result , left_result , right_result ; 
    if( (high<x) || (low>y) )
    {
        result.sum = -1000000000;
        result.max_sum = 0;
        result.prefix_sum = 0; 
        result.suffix_sum = 0 ; 
        
    }
    else if((low>=x)&&(high<=y))
    {
        result = Tree[node] ; 
         
    }
    else if ( (low==x) && (high==y) )
    {
        result = Tree[node];
    }
    else
    {
        int mid = (low+high)/2;
        left_result = Query(2*node,low,mid,x,y);
        right_result = Query(2*node+1,mid+1,high,x,y);
        if(left_result.sum==(-1000000000))
        {
            result = right_result ;
        }
        else if(right_result.sum==-1000000000)
        {
            result = left_result ; 
        }
        else
        {
            result.sum = left_result.sum + right_result.sum ;
            result.prefix_sum =  maximum(left_result.prefix_sum , left_result.sum + right_result.prefix_sum);
            result.suffix_sum = maximum(right_result.sum + left_result.suffix_sum , right_result.suffix_sum);
            result.max_sum = maximum(left_result.max_sum , right_result.max_sum );
            result.max_sum = maximum(result.max_sum , ( left_result.suffix_sum + right_result.prefix_sum ) );
        }
    }
    
    return result;
}
 
 
void Build_Tree(int node , int low , int high)
{
 
    if(low==high)
    {
        Tree[node].max_sum = A[low];
        Tree[node].prefix_sum = A[low];
        Tree[node].suffix_sum = A[low];
        Tree[node].sum = A[low];
        
    }
    else
    {
        int mid = (low+high)/2;
        
        Build_Tree(2*node,low,mid);
        
        Build_Tree(2*node+1,mid+1,high);
        Tree[node].sum = Tree[2*node].sum + Tree[2*node+1].sum ;
        Tree[node].prefix_sum = maximum(Tree[2*node].prefix_sum , ( Tree[2*node].sum + Tree[2*node+1].prefix_sum ) );
        Tree[node].suffix_sum = maximum(Tree[2*node+1].suffix_sum , ( Tree[2*node+1].sum + Tree[2*node].suffix_sum ) );
        Tree[node].max_sum = maximum(Tree[2*node].max_sum, maximum(Tree[2*node+1].max_sum , Tree[2*node].suffix_sum + Tree[2*node+1].prefix_sum ) ); 
    }
    
}
 
int maximum(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}