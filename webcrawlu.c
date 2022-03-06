#include <stdlib.h>
#include <stdio.h>
//#include "http.h"
//#include "downloadurl.h"
#include "ubuntudownloadurl.h"
//#include "https.h"
#//include "itoa.h"
#include<string.h>
#include <ctype.h>

char *strstrip(char *s)
{
        size_t size;
        char *end;

        size = strlen(s);

        if (!size)
                return s;

        end = s + size - 1;
        while (end >= s && isspace(*end))
                end--;
        *(end + 1) = '\0';

        while (*s && isspace(*s))
                s++;

        return s;
}
int main(void)
{
  int count=1;
  char url[100] = "https://www.google.com";//rottentomatoes.com/top/bestofrt/";
  char destination[100]="myfile";
  char fileno[20];
  int depth=0;
  sprintf(fileno,"%d",count);
  //itoa(count,fileno,10);
  strcat(fileno,".txt");
  strcat(destination,fileno);
  downloadurlubuntu(url,destination);
  //downloadurl(url,destination);
  count++;
  //https(destination);
  //http(destination);
  char fil[100];
  strcat (fil,"grep -Eo -h 'https?://[^\";]+'  ");
  strcat(fil,destination);
  strcat(fil," >> urls.txt");
  int r;
  r=system(fil);
  //char * line = NULL;
  char line[10000];
   FILE * fp;
   fp = fopen("urls.txt", "r");
  while (fgets(line, sizeof(line), fp)) {
    //printf("%s",line);
    int temp=0;
    char destinations[100]="myfile";
    //itoa(count,fileno,10);
    sprintf(fileno,"%d",count);
    strcat(fileno,".txt");
    strcat(destinations,fileno);
    printf("%s",line);
    char *a;
    a=strstrip(line);
    downloadurlubuntu(a,destinations);
    //downloadurl(line,destinations);
    while(temp<depth){
     //http(destinations);
     //https(destinations);
     //httpubuntu(destination);
     char fil1[100];
     strcat (fil1,"grep -Eo -h 'https?://[^\";]+'  ");
     strcat(fil1,destinations);
     strcat(fil1," >> urls.txt");
     int r;
     r=system(fil1);
     temp++;
     }
     count++;
  }
  fclose(fp);
}
