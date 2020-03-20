#include "session5_sort.h"

long int InsertionSort(Record* A, int n)
{
    long int count = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i - 1;
        Record temp = A[i];
        while(j >= 0 && A[j].serialnumber > temp.serialnumber)
        {
            count++;
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
        if(j != -1)
            count++;
    }
    return count;
}

long int BubbleSort(Record* A, int n)
{
    long int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int noSwaps = 0;
        for (int j = 0; j < n - 1 - i ; j++)
        {
            count++;
            if (A[j + 1].serialnumber < A[j].serialnumber)
            {
                Record temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                noSwaps = 1;
            }
        }
        if(noSwaps == 0)
            return count;
    }
    return count;
}

long int SelectionSort(Record* A, int n)
{
    long int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            count++;
            if(A[j].serialnumber < A[min].serialnumber)
            {
                min = j;
            }
        }
        if(min != i)
        {
            Record temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    return count;
}