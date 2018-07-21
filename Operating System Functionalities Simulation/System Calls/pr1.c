#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

main()
{
   int descrptr=creat("myfirst.txt",0777);
   
   if(descrptr<0)
   printf("Error opening the file!\n");
   else
   printf("File created!");
   
   int des2=open("myfirst.txt", O_RDWR,0777);
   if(des2>=0)
   printf("Successfully opened!");
   else
   printf("File not opened!");
   
   if(write(des2,"Good",4)<0)
   printf("Write error occured!");
   
   lseek(des2,0,SEEK_SET);
  
   
   char data[30];
   if(read(des2,data,4)<0)
   printf("Read error has occured!");
   
   printf("%s",data);
   
   int newfdes=dup(des2);
   write(newfdes," Excellent",10);
   
   printf("A new file will get created!");
   if(link("myfirst.txt","linkedfile.txt")<0)
   printf("New link not created\n");
   
   printf("\nNew file will get deleted!");
   unlink("linkedfile.txt");
   
   if(access("myfirst.txt",F_OK|R_OK|W_OK)==0)
   printf("File exists and has read/write permissions\n");
   
   if(chmod("myfirst.txt",00400)<0)
   printf("Couldn't change file mode!");
   
   if(access("myfirst.txt",F_OK|W_OK)<0)
   printf("File can no longer be written!");
   
   umask(S_IRUSR);  
  
}
