#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "Urlmon.lib")
int downloadurl(char* url,char* destination)
{
  
  typedef HRESULT (WINAPI * URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void * lpfnCB);
    URLDownloadToFileA_t URLDownloadToFileA;
    URLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");

  if (S_OK == URLDownloadToFileA(NULL, url, destination, 0, NULL))
  {
    printf("Saved to 'myfile.txt'");

    return 0;

  }

  else 
  {

    printf("Failed");

    return -1;

  }

}
