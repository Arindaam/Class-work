typedef struct
{
    int *a;
    int size;
} Heap;

void maxHeapify(Heap h, int idx)
{
    int x,temp,j,i;
    temp=idx;
    j=2*idx+2;
    i=2*idx+1;
    if(i<h.size && h.a[i]>h.a[temp])
        temp=i;
    if(j<h.size && h.a[j]>h.a[temp])
        temp=j;
    if(temp!=idx)
    {
        x=h.a[temp];
        h.a[temp]=h.a[idx];
        h.a[idx]=x;    
        maxHeapify(h,temp);
    }
}
Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a=a;
    h.size=n;
    int i= n/2-1;
    while(i>=0)
    {
       maxHeapify(h,i);
       i--;
    }
    return h;
}


void heapSort(int *const a, int n)
{
    Heap h;
    int x;
    h=buildMaxHeap(a,n);
    for(int i=n-1;i>=0;i--)
    {
        x=h.a[0];
        h.a[0]=h.a[i];
        h.a[i]=x;
        h.size--;
        maxHeapify(h,0);
    }
}

