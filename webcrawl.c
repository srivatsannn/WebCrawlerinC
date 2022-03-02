#include <stdlib.h>
#include <stdio.h>
#include "http.h"
#include "downloadurl.h"
//#include "ubuntudownloadurl.h"
#include "https.h"
//#include "itoa.h"
int main(void)
{
  int count=1;
  char url[1000] = "https://www.google.com"//rottentomatoes.com/top/bestofrt/";
  char destination[1000]="myfile";
  char fileno[20];
  int depth=0;
  itoa(count,fileno,10);
  strcat(fileno,".txt");
  strcat(destination,fileno);
  //downloadurlubuntu(url,destination);
  downloadurl(url,destination);
  count++;
  https(destination);
  http(destination);
  //char * line = NULL;
  char line[10000];
   FILE * fp;
   fp = fopen("urls.txt", "r");
  while (fgets(line, sizeof(line), fp)) {
    printf("%s",line);
    int temp=0;
    char destinations[1000]="myfile";
    itoa(count,fileno,10);
    strcat(fileno,".txt");
    strcat(destinations,fileno);
    //downloadurlubuntu(line,destinations);
    downloadurl(line,destinations);
    while(temp<depth){
     http(destinations);
     https(destinations);
    temp++;
    }
    count++;
  }
  fclose(fp);
}
