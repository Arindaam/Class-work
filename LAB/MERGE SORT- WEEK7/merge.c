#include <stdio.h>
#include<stdlib.h>
// Merges two sorted halfs of an array into a single sorted array
void mergeSortedHalfs(int *a, int start, int mid, int end){
	int i=0;
	int j=1;
	int mid1=mid;
	while(i<=mid1 && ((mid+j)<=end)){
		if(a[start+i]<a[mid+j]){
			i++;
		}
		else{
			int iter=mid+j - start-i;			
			int ele=a[mid+j];
			for(int k=0;k<iter;k++){
				a[mid+j-k]=a[mid+j-k-1];
			}			
			a[start+i]=ele;
			j++;
			mid1++;
			i++;
		}
	}
}


// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end){
	if(start<end){
		int mid1=(start+end)/2;
		mergeSort(a,start,mid1);
		mergeSort(a,mid1+1,end);
		mergeSortedHalfs(a,start,mid1,end);
	}
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *a, int start, int end){
    int size = (end-start+1),i,j,temp;
    for(i =1;i<size;++i)
    {
        j=i-1;
        temp = a[i];
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = temp;
    }

}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter){
	if((end-start+1) > parameter)
        mergeSort(a,start,end);
    else 
        insertionSort(a,start,end);
}

