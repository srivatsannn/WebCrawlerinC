#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#define BAD(x) (!(x) || (*(x) == '\0'))
int offset1=0;
static char *extract_link1(char *string, char url[10000])
{
        int length;
        char *st;
        char *rl;
        url[0] = '\0';
        rl = strstr(string, "https://");
        offset1=rl-string;;
        if (BAD(rl))
                goto www;
        if (!BAD(rl) && strchr(rl, ' '))
        {
                st = strstr(rl,"\"");
                length = strlen(rl) - strlen(st);
                if(length<140)
                strncpy(url, rl, length);
                else
                strncpy(url, " ", length);
                url[length] = '\0';
                return url;
        }
        else
                return rl;
        www:
                rl = strstr(string, "www://");
                offset1=rl-string;;
                if (BAD(rl))
                        return NULL;
                if (!BAD(rl) && strchr(rl, ' '))
                {
                        st = strstr(rl, "\"");
                        length = strlen(rl) - strlen(st);
                        strncpy(url, rl, length);
                        url[length] = '\0';

                        return url;
                }
                else
                        return rl;
}
void https(char* filename){
    char * buffer = 0;
long length;
FILE * f = fopen (filename, "rb");
FILE *urlfile = fopen("urls.txt", "a");


if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = (char*)malloc(length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}

if (buffer)
{
  char x[10000];
        
        while(extract_link1(buffer,x)!=0){
        	//printf("%s\n",x);
        	if(!isspace(x[0])){
        	fputs(x, urlfile);
        	fputs("\n", urlfile);
        }
        	buffer=buffer+offset1+strlen(x);
	}      
}
fclose(urlfile);
fclose(f);
}
