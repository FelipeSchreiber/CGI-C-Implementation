/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$i
  
*/

#include "fsfUmlGetPendingRegistrationRequestsPerUser.h"
#include "fsfUmlUserInterface.h"
#include <errno.h>

/*
fsfUmlErrorType
FsfUmlGetPendingRegistrationRequestsPerUser(fsfUmlConfigurationOptionsType *fsfUmlConfigurations, char *fsfUmlNickname,fsfUmlUserDataType **fsfUmlFirstData)


Arguments:

fsfUmlConfigurations - This argument represents the configurations chosen (I)

fsfUmlNickname - This is the target user (I)

fsfUmlFirstData this is the the pointer to the first element of a list (O)


Returned code:

fsfUmlNullConfigurationData - The pointer to struct fsfUmlConfigurationsType got NULL value

fsfUmlNullUserData - Case the fsfUmlFirstData is NULL

fsfUmlFileOpeningError - Case a problem occured while opening a file

fsfUmlNicknameNotFound - Case the nickname desired wasn't found at the users file

fsfUmlInvalidUserId - Case the user's id found at users file contains more than just numbers

fsfUmlInvalidProfile - Case the user's profile found at users file contains more than just numbers

fsfUmlFileError - Case the error pointer is set at users or requesting users file

fsfUmlFileReadingError - Case a problem occured while reading the file's data

fsfUmlMemoryAllocationError - Case a problem occured while allocating memory

fsfUmlErrNo - This equals to the returned value by the following functions: FsfUmlCheckNickname,FsfUmlFilenameValidation or
FsfUmlCheckStringField


Description:

This function search for the user's nickname in users file, takes the id, email address,full name and his profile.Then serach at 
requesting users file for his id.Once the id is found and the absolut time expiration is valid, a structure is put in the list, containing all
his information.   

*/

fsfUmlErrorType
FsfUmlGetPendingRegistrationRequestsPerUser(fsfUmlConfigurationOptionsType *fsfUmlConfigurations, char *fsfUmlNickname,fsfUmlUserDataType **fsfUmlFirstData)   
{
 #ifdef _MY_DEBUG_
  printf("\nDebug is set in fsfUmlGetPendingRegistrationRequestPerUser\n");
 #endif
   
 int fsfUmlErrNo,fsfUmlColonCounter,fsfUmlCounter,fsfUmlPos,fsfUmlRead;
 unsigned long long fsfUmlUserId;
 fsfUmlUserProfileType fsfUmlProfile;
 time_t fsfUmlActualTime,fsfUmlAbsolutExpirationTime;
 fsfUmlUserIdentifierType fsfUmlAnalistId,fsfUmlRequestingUserId;
 char fsfUmlPasswd[FSF_UML_PASSWORD_MAX_LENGTH];
 /*fsfUmlPendingRequestType fsfUmlPendingRegistration;*/
 char fsfUmlBuffer[FSF_UML_FULLNAME_MAX_LENGTH + 1],fsfUmlIdBuffer[20],fsfUmlProfileBuffer[20],
 fsfUmlFullNameBuffer[FSF_UML_FULLNAME_MAX_LENGTH + 1],fsfUmlEmailBuffer[FSF_UML_EMAIL_MAX_LENGTH + 1],fsfUmlGetC[2],fsfUmlGetCh,*fsfUmlCheck;
 /*The size of fsfUmlBuffer corresponds to the largest length possible among all the variables found in users file*/
 FILE *fsfUmlRequestingUsers,*fsfUmlUsersFile;
 boolean fsfUmlFound = fsfUmlFalse;
 fsfUmlUserDataType *fsfUmlFirst,*fsfUmlLast,*fsfUmlNew;
 
 fsfUmlFirst = NULL;
 fsfUmlLast = NULL;
 fsfUmlPos = fsfUmlColonCounter = fsfUmlCounter = 0;
 
 if(!fsfUmlConfigurations)
  return fsfUmlNullConfigurationData;

 if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlNickname,FSF_UML_NICKNAME_ ,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
 {
  #ifdef _MY_DEBUG_
   printf("\nfsfUmlNickname: %s \n",fsfUmlNickname);
  #endif
  #ifdef _MY_DEBUG_
   printf("\nErrNo:#%i ",fsfUmlErrNo);
  #endif
  return fsfUmlErrNo;
 } 

 if((fsfUmlErrNo = 
 FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,FSF_UML_VALID_FILENAME_,
                          FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
 {
  #ifdef _MY_DEBUG_
   printf("\nfsfUmlRequestingUsersDataFileName: %s\n\n ",fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename);
   printf("\nfsfUmlRequestingUsersDataFileName LENGTH: %i\n\n ",(int)strlen(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename));
  #endif
  return fsfUmlErrNo;
 }
 if(!(fsfUmlRequestingUsers = fopen(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,"rb")))
 {
  #ifdef _MY_DEBUG_
   printf("\nREQUESTING USERS FILE OPENING ERROR\n\n");
  #endif
  return fsfUmlFileOpeningError;
 }
 
 if((fsfUmlErrNo = 
 FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlUsersDataFilename,FSF_UML_VALID_FILENAME_,
                          FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
 {
  #ifdef _MY_DEBUG_
   printf("\nfsfUmlUsersDataFileName: %s\n\n ",fsfUmlConfigurations->fsfUmlUsersDataFilename);
   printf("\nfsfUmlUsersDataFileName LENGTH: %i\n\n ",(int)strlen(fsfUmlConfigurations->fsfUmlUsersDataFilename));
  #endif
  return fsfUmlErrNo;
 }
 
 if(!(fsfUmlUsersFile = fopen(fsfUmlConfigurations->fsfUmlUsersDataFilename,"r")))
 {
  #ifdef _MY_DEBUG_
   printf("\nFILE OPENING ERROR\n\n ");
  #endif
  return fsfUmlFileOpeningError;
 }

  while((fgets(fsfUmlGetC,2,fsfUmlUsersFile) != NULL) && (!fsfUmlFound))
  {
   if((':' != fsfUmlGetC[0]) && ('\n' != fsfUmlGetC[0]))
   {
    /*fsfUmlGetCh = fgetc(fsfUmlUsersFile);*/
    fsfUmlBuffer[fsfUmlCounter] = fsfUmlGetC[0];
    fsfUmlCounter++;
    fsfUmlBuffer[fsfUmlCounter] = '\0';
   }
   else
   {
    fsfUmlCounter = 0;
    #ifdef _MY_DEBUG_
     printf("\n BUFFER CONTENT : %s\n",fsfUmlBuffer);
     printf("\n NICKNAME TARGET: %s\n",fsfUmlNickname);
    #endif
    #ifdef _MY_DEBUG_
     printf("\nEOF? %s\n",feof(fsfUmlUsersFile) ? "sim":"nao");
    #endif
    if(!strcmp(fsfUmlBuffer,fsfUmlNickname))
     fsfUmlFound = fsfUmlTrue;
    else
     fsfUmlPos++;
   }
  } 
  /*The fsfUmlPos stores where the nickname was found, so the previus argument is the id of the target user*/
 
 #ifdef _MY_DEBUG_
  printf("\nSeg. Fault 2???\n");
 #endif

 if(feof(fsfUmlUsersFile) && !fsfUmlFound)
  return fsfUmlNicknameNotFound;

 rewind(fsfUmlUsersFile);
  #ifdef _MY_DEBUG_
   printf("\nSeg. Fault 1 ???\n");
  #endif
 while(fsfUmlColonCounter != (fsfUmlPos - 1)) 
 {
  fsfUmlGetCh = fgetc(fsfUmlUsersFile);
  if((fsfUmlGetCh == ':') || (fsfUmlGetCh == '\n'))  
   fsfUmlColonCounter++;
 }

 fsfUmlCounter = 0;
 while(':' != (fsfUmlGetCh = fgetc(fsfUmlUsersFile)))
 {
  fsfUmlIdBuffer[fsfUmlCounter] = fsfUmlGetCh;
  fsfUmlCounter++;
 }
 fsfUmlIdBuffer[fsfUmlCounter] = '\0';
 /*the fsfUmlIdBuffer now contains the id*/
 fsfUmlUserId = strtoull(fsfUmlIdBuffer,&fsfUmlCheck,10);

 if(*fsfUmlCheck != '\0')
 {
  #ifdef _MY_DEBUG_
   printf("\nINVALID USER ID:\nbuffer:%s\ninvalid char: %c\n\n ",fsfUmlIdBuffer,*fsfUmlCheck);
  #endif
  return fsfUmlInvalidUserId;
 }  
 fsfUmlCounter = 0;
 while(':' !=(fsfUmlGetCh = fgetc(fsfUmlUsersFile)));
 while(':' !=(fsfUmlGetCh = fgetc(fsfUmlUsersFile)));/*Jumps both nickname and crypted password fields in the text file*/
 while(':' != (fsfUmlGetCh = fgetc(fsfUmlUsersFile)))
 {
  fsfUmlProfileBuffer[fsfUmlCounter] = fsfUmlGetCh;
  fsfUmlCounter++;
 }
 fsfUmlProfileBuffer[fsfUmlCounter] = '\0';
 /*The fsfUmlProfileBuffer contains the user profile */
 fsfUmlProfile = strtoull(fsfUmlProfileBuffer,&fsfUmlCheck,10);
 
 if(*fsfUmlCheck != '\0')
 {
  #ifdef _MY_DEBUG_
   printf("\nINVALID USER PROFILE\n PROFILE: %s\n invalid char:%c\n\n ",fsfUmlProfileBuffer,*fsfUmlCheck);
  #endif
  return fsfUmlInvalidProfile;
 }
  
 fsfUmlCounter = 0;
 while(':' != (fsfUmlGetCh = fgetc(fsfUmlUsersFile)))
 {
  fsfUmlFullNameBuffer[fsfUmlCounter] = fsfUmlGetCh;
  fsfUmlCounter++;
 }
 fsfUmlFullNameBuffer[fsfUmlCounter] = '\0';

 /*the fsfUmlFullNameBuffer now contains the user's full name*/
 if((fsfUmlErrNo = 
 FsfUmlCheckStringField(fsfUmlFullNameBuffer,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
 {
  #ifdef _MY_DEBUG_
   printf("FULL NAME: %s\n\n ",fsfUmlFullNameBuffer);
   printf("\nLENGTH: %i\n\n ",(int)strlen(fsfUmlFullNameBuffer));
  #endif
  return fsfUmlErrNo;
 }
 /*fsfUmlCounter = 0;*/
 fgets(fsfUmlEmailBuffer,(FSF_UML_EMAIL_MAX_LENGTH + 2),fsfUmlUsersFile);
 /*while()
 {
  fsfUmlEmailBuffer[fsfUmlCounter] = fsfUmlGetCh;
  fsfUmlCounter++;
 }*/
 if(fsfUmlEmailBuffer[strlen(fsfUmlEmailBuffer) - 1] == '\n')
  fsfUmlEmailBuffer[strlen(fsfUmlEmailBuffer) - 1] = '\0';
 /*the fsfUmlFullNameBuffer now contains the user's full name*/
 if((fsfUmlErrNo = 
 FsfUmlCheckEmail(fsfUmlEmailBuffer,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
 {
  #ifdef _MY_DEBUG_
   printf("\nUSER EMAIL: %s\n\n ",fsfUmlEmailBuffer);
   printf("\nUSER EMAIL LENGTH: %i\n\n ",(int)strlen(fsfUmlEmailBuffer));
  #endif
  return fsfUmlErrNo;
 }

 if(ferror(fsfUmlUsersFile))
 {
  #ifdef _MY_DEBUG_
   printf("\nFILE ERROR NO: %i\n\n ",errno);
   printf("\nFILE ERROR CAUSE: %s\n\n ",strerror(errno));
  #endif
  fclose(fsfUmlUsersFile);
  return fsfUmlFileError;
 }
 
 /*No problems occured up to now, so the id,profile,name and email are valid. Now we can search at the requesting users file by the given id*/
 fsfUmlCounter = 0;
 #ifdef _MY_DEBUG_
  printf("\nSHOW ALL DATA STORED AT REQUESTING.USERS\n");
  while(fread(&fsfUmlAbsolutExpirationTime,sizeof(time_t),1,fsfUmlRequestingUsers))
  {
   printf("\n\n-----------------------------------------------------------\n\n");
   printf("\nHorario: %i",(int) /*difftime(timeTest,localTime)*/fsfUmlAbsolutExpirationTime);
   fread(&fsfUmlAnalistId,sizeof(unsigned long long),1,fsfUmlRequestingUsers);
   printf("\nAnalyst: %llu",fsfUmlAnalistId);
   fread(&fsfUmlRequestingUserId,sizeof(unsigned long long),1,fsfUmlRequestingUsers);
   printf("\nUser: %llu",fsfUmlRequestingUserId);
   fread(fsfUmlPasswd,sizeof(char),128,fsfUmlRequestingUsers);
   fsfUmlPasswd[strlen(fsfUmlPasswd)] = '\0';
   printf("\nPass: %s",fsfUmlPasswd);
   printf("\n\n-----------------------------------------------------------\n\n");
  }
  rewind(fsfUmlRequestingUsers);
  printf("\nEND OF SHOW\n");
 #endif
 
 while((fread(&fsfUmlAbsolutExpirationTime,sizeof(time_t),1,fsfUmlRequestingUsers)))
 { 
  #ifdef _MY_DEBUG_
   printf("\nLoop No: %i\n",fsfUmlCounter);
  #endif
  /*if((fread(&fsfUmlAbsolutExpirationTime,sizeof(time_t),1,fsfUmlRequestingUsers) != 1))
  {
   fclose(fsfUmlRequestingUsers);
   return fsfUmlFileReadingError;
  }*/
  
  if((fsfUmlRead = fread(&fsfUmlAnalistId,sizeof(fsfUmlUserIdentifierType),1,fsfUmlRequestingUsers)) != 1)
  {
   #ifdef _MY_DEBUG_
    printf("\nExpiration time: %i",(int)fsfUmlAbsolutExpirationTime);   
    printf("\nAnalist Id: %i\n",(int)fsfUmlAnalistId);
    printf("\nTotal read: %i\n",(int)fsfUmlRead);
    printf("\nERROR READING REQUESTING USERS FILE 1\n");
   #endif
   fclose(fsfUmlRequestingUsers);
   return fsfUmlFileReadingError;
  }
  
  if((fread(&fsfUmlRequestingUserId,sizeof(fsfUmlUserIdentifierType),1,fsfUmlRequestingUsers) != 1))
  {
   #ifdef _MY_DEBUG_
    printf("\nERROR READING REQUESTING USERS FILE 2\n");
   #endif
   fclose(fsfUmlRequestingUsers);
   return fsfUmlFileReadingError;
  }
  
  fread(fsfUmlPasswd,sizeof(char),(FSF_UML_PASSWORD_MAX_LENGTH),fsfUmlRequestingUsers);
  fsfUmlPasswd[strlen(fsfUmlPasswd)] = '\0';

  #ifdef _MY_DEBUG_
   printf("\n----------------------------------------------------------------\n");
   printf("\nExpiration time: %i",(int)fsfUmlAbsolutExpirationTime);   
   printf("\nAnalist Id: %i\n",(int)fsfUmlAnalistId);
   printf("\nUser Id: %i\n",(int)fsfUmlUserId);
   printf("\nPassword: %s\n",fsfUmlPasswd);
   printf("\n----------------------------------------------------------------\n");
  #endif 
   
  if(fsfUmlRequestingUserId == fsfUmlUserId)
  {
   fsfUmlActualTime = time(NULL);
   #ifdef _MY_DEBUG_
    printf("\nCurrent time: %i\nExpiration: %i",(int)fsfUmlActualTime,(int)fsfUmlAbsolutExpirationTime);   
   #endif
 
   if(fsfUmlActualTime <= fsfUmlAbsolutExpirationTime)
   {
    if(!(fsfUmlNew = (fsfUmlUserDataType *)malloc(sizeof(fsfUmlUserDataType)))) 
    {
     while(fsfUmlFirst)
     {
      fsfUmlLast = fsfUmlFirst;
      fsfUmlFirst = fsfUmlFirst->fsfUmlNext;
      free(fsfUmlLast);
     }
     fclose(fsfUmlRequestingUsers);
     return fsfUmlMemoryAllocationError;
    }
   
    fsfUmlNew->fsfUmlId = fsfUmlUserId;
    strcpy(fsfUmlNew->fsfUmlNickname,fsfUmlNickname);
    strcpy(fsfUmlNew->fsfUmlPassword,fsfUmlPasswd);
    strcpy(fsfUmlNew->fsfUmlPasswordVerification,fsfUmlPasswd);
    fsfUmlNew->fsfUmlProfile = fsfUmlProfile;
    strcpy(fsfUmlNew->fsfUmlName,fsfUmlFullNameBuffer);
    strcpy(fsfUmlNew->fsfUmlNameVerification,fsfUmlFullNameBuffer);
    strcpy(fsfUmlNew->fsfUmlEmail,fsfUmlEmailBuffer);
    fsfUmlNew->fsfUmlNext = NULL;
    fsfUmlNew->fsfUmlPrevious = NULL;
    
    #ifdef _MY_DEBUG_
     printf("\nFirst element got all parameters\n");
    #endif

    if(!fsfUmlFirst)
    {
     fsfUmlFirst = fsfUmlNew;
     fsfUmlLast = fsfUmlNew;
     #ifdef _MY_DEBUG_
      printf("\nFirst element allocated succesfully\n");
     #endif
    }
    else
    {
     #ifdef _MY_DEBUG_
      printf("\n Another element added to list\n");
     #endif
     fsfUmlLast->fsfUmlNext = fsfUmlNew;
     fsfUmlNew->fsfUmlPrevious = fsfUmlLast;
     fsfUmlLast = fsfUmlNew;
    }
   }/* if(fsfUmlActualTime <= fsfUmlAbsolutExpirationTime) ends */
  }/* if(fsfUmlRequestingUserId == fsfUmlUserId) ends */  
  #ifdef _MY_DEBUG_
   if(feof(fsfUmlRequestingUsers))
    printf("\nfsfUmlRequestingUser reached EOF\n");
  #endif
  fsfUmlCounter++;
 }/* while(!feof(fsfUmlRequestingUsers)) ends */
 
 if(fsfUmlFirst == NULL)
  return fsfUmlIdNotFoundInRequestFile;
 
 if(ferror(fsfUmlRequestingUsers))
 {
  fclose(fsfUmlRequestingUsers);
  return fsfUmlFileError;
 }
 
 fclose(fsfUmlRequestingUsers);
 fclose(fsfUmlUsersFile);

 *fsfUmlFirstData = fsfUmlFirst;
 return fsfUmlOk; 
}

/*$RCSFile$*/
