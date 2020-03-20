#include<string.h>

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchFirstOccurrence(char *pattern, char *text)
{
	int t = strlen(text);
	int p = strlen(pattern);
	int i,j;
	
	for(i = 0; i <= t-p; i++)
	{
		for(j = 0; j < p; j++)
		{
			if(text[i+j] != pattern[j]) break;
		}
		if(j == p) return i;
	}
	return -1;
}

// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text)
{
	int t = strlen(text);
	int p = strlen(pattern);
	int i,j;
	
	for(i = t-1; i >= p-1; i--)
	{
		for(j = p-1; j >= 0; j--)
		{
			if(text[i-p+j+1] != pattern[j]) break;
		}
		if(j == -1) return i-p+1;
	}	
	return -1;
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
	int index = searchFirstOccurrence(&pattern[0], &text[0]);
	if(index == -1) return 0;
	else return 1+numOccurrences(&pattern[0], &text[index+1]);
}

// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
	int t = strlen(text);
	int p = strlen(pattern);
	int i,j;
	int max = 0;
	int count = 0;
	
	for(i = 0; i <= t-p; i++)
	{
		count = 0;
		for(j = 0; j < p; j++)
		{			
			if(text[i+j] != pattern[j]) break;
			count++;
			if(count > max) max = count;
		}
	}
	return max;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
	int t = strlen(text);
	int p = strlen(pattern);
	int i,j;
	int count = 0;
	
	for(i = 0; i <= t-p; i++)
	{
		for(j = 0; j < p; j++, count++)
		{
			if(text[i+j] != pattern[j])
			{
				count++;
				break;
			}
		}
	}
	return count;
}
