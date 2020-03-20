#include"horspool.h"
#include<stdlib.h>
#include<string.h>
/*typedef struct
{
    int firstOccurrence;
    int lastOccurrence;
    int numOccurrences;
    int charactersCompared;
} Result;
*/
/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern    
* The table size can be 256
*/
int *buildShiftTable(char *pattern)
{
    int* table=(int*)malloc(sizeof(int)*256);
    int m=strlen(pattern);
    for(int j=0;j<256;j++)
        table[j]=m;
    for(int i=0;i<m-1;i++)
        table[(int)(pattern[i])]=m-1-i;
    return table;
}

/*
* Implement the horspool's string matching algoritm using the buildShiftTable()
  function to build the shift table.
* Compute offset of the first and last occurence of pattern in the text,
  In case of no occurrences of the pattern the value should be set to -1.
* Compute the number of occurences of the pattern in the text.
* Compute the number of characters compared while finding all occurences of the pattern in the given text
* Characters must be matched from left to right
*/

Result *horspoolStringMatch(char *pattern, char *text)
{
    int *shift=buildShiftTable(pattern);
    int m=strlen(pattern);
    int n=strlen(text);
    int k;
    Result* r=(Result*)malloc(sizeof(Result));
    (*r).firstOccurrence=-1;
    (*r).lastOccurrence=-1;
    (*r).numOccurrences=0;
    (*r).charactersCompared=0;
    int i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(pattern[m-1-k]==text[i-k])
            k++;
        if(k==m)
            {
                if((*r).numOccurrences==0)
                        (*r).firstOccurrence=i-m+1;
                (*r).lastOccurrence=i-m+1;
                (*r).numOccurrences+=1;
                (*r).charactersCompared+=m;
                i=i+m;
            }
        else
        {
            (*r).charactersCompared=(*r).charactersCompared+k+1;
            i=i+shift[(int)text[i]];
        }
    }
    return r;
}
