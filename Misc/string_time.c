//This program converts date in string to number, it also has capability to give current time but check for a better function.
#include <stdio.h>  
#include <time.h>

int main()
{
    char buf[100]="01/10/2020";
    //char buff[100];
    time_t t;
    struct tm result;
    //struct tm *timeptr;
    /*
    setlocale(LC_ALL,"/QSYS.LIB/EN_US.LOCALE");
    t = time(NULL);
    timeptr = localtime(&t);
    strftime(buf,sizeof(buf), "%a %m/%d/%Y %r", timeptr);
    */
    
    if (strptime(buf, "%m/%d/%Y",&result) == NULL)
          printf("\nstrptime failed\n");
    else
    {
          printf("tm_mon:  %d\n",result.tm_mon+1);
          printf("tm_mday:  %d\n",result.tm_mday);
          printf("tm_year:  %d\n",result.tm_year+1900);
          printf("tm_yday:  %d\n",result.tm_yday+1);
          printf("tm_wday:  %d\n",result.tm_wday+1);
    }
 
    return 0;
}
