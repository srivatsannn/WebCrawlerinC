#include <unistd.h>
 #include<stdlib.h>
 #include<string.h>
int httpubuntu (char *filename) {
//char filename[20] = "myfile1.txt";
 // char *arg1 = "-o";
 char fil[100];
  //char *arg2 = "https?://[^\"]+' url.txt";
  //char *fil="";
  strcat (fil,"grep -Eo 'https?://[^\";]+'  ");
  strcat(fil,filename);
  strcat(fil," > newFile.txt");
int r;
r=system(fil);
   //grep -o -E 'https?://[^"]+' myfile1.txt
  //execlp(programName, programName, arg1, arg2,NULL);
 //grep -Eo 'https?://[^";]+'  myfile1.txt > newFile.txt
  //execlp("grep","grep", "-Eo", "'https?://[^\";]+'", "myfile1.txt > newFile.txt", NULL);

 
  return r;
 

}
    
