#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE 10000

int downloadurlubuntu(char* url,char* destination)
{
curl_global_init(CURL_GLOBAL_ALL);

CURL * myHandle;
CURLcode setop_result;
FILE *file;

if((file = fopen(destination, "wb")) == NULL)
{
    perror("Error");
    exit(EXIT_FAILURE);
}

if((myHandle = curl_easy_init()) == NULL)
{
    perror("Error");
    exit(EXIT_FAILURE);
}

if((setop_result = curl_easy_setopt(myHandle, CURLOPT_URL, url)) != CURLE_OK)
{
    perror("Error");
    exit(EXIT_FAILURE);
}

    if((setop_result = curl_easy_setopt(myHandle, CURLOPT_WRITEDATA, file))     != CURLE_OK)
{
    perror("Error");
    exit(EXIT_FAILURE);
}

if((setop_result = curl_easy_perform(myHandle)) != 0)
{
    perror("Error");
    exit(EXIT_FAILURE);
}
curl_easy_cleanup(myHandle);
fclose(file);


return 0;
}
