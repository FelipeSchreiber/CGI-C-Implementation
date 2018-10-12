#include <stdio.h>
#include <time.h>
#include <string.h>
/*esse eh um arquivo somente para testes*/

int
main()
{
 FILE * fd;
 char senha[30] = "cccccccccccccccc\0";
 char file[50] = "requesting.users\0";
 char pass[30];
 time_t localTime,plusTime,timeTest;
 unsigned long long analystId,userId,analystTest,userTest;
 analystId = 9;
 userId = 0;
 
 fd = fopen(file,"ab");
 clearerr(fd);
 localTime = time(NULL);
 plusTime = localTime + 300;
 fwrite(&plusTime,sizeof(time_t),1,fd);
 fwrite(&analystId,sizeof(unsigned long long),1,fd);
 fwrite(&userId,sizeof(unsigned long long),1,fd);
 printf("\nTotal written: %i\n",(int)fwrite(senha,sizeof(char),29,fd));
 fclose(fd);

 fd = fopen(file,"rb");
 while(fread(&timeTest,sizeof(time_t),1,fd))
 {
  printf("\n\n-----------------------------------------------------------\n\n");
  printf("\nHorario: %i",(int) /*difftime(timeTest,localTime)*/timeTest);
  fread(&analystTest,sizeof(unsigned long long),1,fd);
  printf("\nAnalyst: %llu",analystTest);
  fread(&userTest,sizeof(unsigned long long),1,fd);
  printf("\nUser: %llu",userTest);
  printf("\nTotal read: %i\n",(int)fread(pass,sizeof(char),29,fd));
  pass[strlen(pass)] = '\0';
  printf("\nPass: %s",pass);
  printf("\n\n-----------------------------------------------------------\n\n");
 }
 fclose(fd);
 return 0;
}
