#include "quickSort.h"
#include<stdio.h>

ptrPair divide(int *a, int n){
	ptrPair gen;
	int q=getPartitionIndex(a,n);
	gen.first=&a[0];
	gen.second=&a[q]+1;
	gen.firstLen=q+1;
	gen.secondLen=n-q-1;
	return gen;
}
/**
 * getPartitionIndex():
 * Choose the first element from the array A[0..n-1] as the pivot element
 * Partition the array using hoare's partitioning scheme, 
 * and return the index of the split
 * HOARE-PARTITION(A, p, r)
    x = A[p]
    i = p - 1
    j = r + 1
    while true
        repeat
            j = j - 1
        until A[j] ≤ x
        repeat
            i = i + 1
        until A[i] ≥ x
        if i < j
            exchange A[i] with A[j]
        else return j
 */
int getPartitionIndex(int *a, int n){
	int z=0;	
	int x=a[z];
	int y=n;
	int i=z-1;
	while(1){
		do{
			y=y-1;		
		}while(y>=0 && a[y]>x);
		do{
			i=i+1;		
		}while(i<n && a[i]<x);
		if(i>=y)
			return y;		
		int temp=a[i];
		a[i]=a[y];
		a[y]=temp;
	}
}
/**
 * conquer():
 * Call the divide function to divide the array,
 * and then conquer the two sub arrays recursively
 */
void conquer(int *a, int n){
	if(n>1)
	{
		ptrPair new=divide(a,n);
		conquer(new.first,new.firstLen);
		conquer(new.second,new.secondLen);
	}
	
}
// Wrapper function to call conquer() for the first time.
void quickSort(int *a, int n){
	conquer(a,n);
}

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n){
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1])
			return 0;	
	}
	return 1;
}

