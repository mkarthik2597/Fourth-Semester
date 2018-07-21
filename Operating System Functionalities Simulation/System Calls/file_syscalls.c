#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
main()
{
   //int des1=creat("readonly.txt",S_IRUSR);      /*You will be able to type text, but you cannot read it*/
   
   /*if(des1<0)
   printf("Error opening the file!\n");
   else
   printf("File created!"); */
   
   //int des2=creat("writeonly.txt",S_IWUSR);      /* You will not be able to read file contents*/
   /*if(des2<0)
   printf("Error opening the file!\n");
   else
   printf("File created!");*/
   
   int des3=creat("readwriteexecute.txt",0777);    /* You can read, write and execute the file. The file will have a green highlight*/          
   /*if(des3<0)
   printf("Error opening the file!\n");
   else
   printf("File created!");*/
   
   int des4=creat("readwrite.txt", S_IRUSR|S_IWUSR);  /*Read and write for a file*/
   /*if(des4<0)
   printf("Error opening the file!\n");
   else
   printf("File created!");*/
   
   int odes=open("readwrite.txt",O_RDWR);
   if(odes<0)
   printf("File not opened!");
   
   
   write(odes,"Hello",5);                             /* Writes hello to the terminal*/
   lseek(odes,2,SEEK_SET);
   write(odes,"bbal He",7);  
   
   char data[20];
   lseek(odes,0,SEEK_SET);              /*This is needed before you can start reading the file*/
   read(odes,data,7);
   puts(data);
   
   int odes1=dup(odes);
   lseek(odes1,0,SEEK_END);
   write(odes,"ro",2);                         
   
   link("readwrite.txt","readwrite(1).txt");
   
}
