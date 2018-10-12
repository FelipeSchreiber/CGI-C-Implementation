/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$i
  
*/

#include "fsfUmlGetPendingRegistrationRequests.h"

/*
fsfUmlErrorType
FsfUmlGetPendingRegistrationRequests(fsfUmlConfigurationOptionsType *fsfUmlConfigurations,fsfUmlUserDataType **fsfUmlFirstData)


Arguments:

fsfUmlConfigurations - This argument represents the configurations chosen (I)

fsfUmlFirstData this is the the pointer to the first element of a list (O)


Returned code:

fsfUmlNullConfigurationData - The pointer to struct fsfUmlConfigurationsType got NULL value

fsfUmlNullUserData - Case the fsfUmlFirstData is NULL

fsfUmlFileOpeningError - Case a problem occured while opening a file

fsfUmlNoValidRequests -  Case there isn't any valid request

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
FsfUmlGetPendingRegistrationRequests(fsfUmlConfigurationOptionsType *fsfUmlConfigurations,fsfUmlUserDataType **fsfUmlFirstData)   
{
 int fsfUmlErrNo,fsfUmlColonCounter,fsfUmlCounter,fsfUmlPos;
 unsigned long long fsfUmlUserId;
 fsfUmlUserProfileType fsfUmlProfile;
 time_t fsfUmlActualTime,fsfUmlAbsolutExpirationTime;
 fsfUmlUserIdentifierType fsfUmlAnalistId,fsfUmlRequestingUserId;
 char fsfUmlNicknameBuffer[FSF_UML_NICKNAME_MAX_LENGTH +1];
 char fsfUmlPasswd[FSF_UML_PASSWORD_MAX_LENGTH + 1];
 char fsfUmlBuffer[FSF_UML_FULLNAME_MAX_LENGTH + 1],fsfUmlIdBuffer[20],fsfUmlProfileBuffer[20],
 fsfUmlFullNameBuffer[FSF_UML_FULLNAME_MAX_LENGTH + 1],fsfUmlEmailBuffer[FSF_UML_EMAIL_MAX_LENGTH + 1],fsfUmlGetCh,*fsfUmlCheck;
 /*The size of fsfUmlBuffer corresponds to the largest length possible among all the variables found in users file*/
 FILE *fsfUmlRequestingUsersFile,*fsfUmlUsersFile;
 fsfUmlUserDataType *fsfUmlFirst,*fsfUmlLast,*fsfUmlNew;
 
 fsfUmlFirst = NULL;
 fsfUmlLast = NULL;
 fsfUmlCounter = 0;
 
 if(!fsfUmlConfigurations)
  return fsfUmlNullConfigurationData;

 /*if(!*fsfUmlFirstData)
  return fsfUmlNullUserData;*/
 
 #ifdef _MY_DEBUG_
  printf("\n fsfUmlRequestingUsersDataFileName: %s ",fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename);
 #endif

 if((fsfUmlErrNo = 
 FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
  return fsfUmlErrNo;

 if(!(fsfUmlRequestingUsersFile = fopen(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,"rb")))
  return fsfUmlFileOpeningError;
 
 #ifdef _MY_DEBUG_
  printf("\n fsfUmlUsersDataFileName: %s ",fsfUmlConfigurations->fsfUmlUsersDataFilename);
 #endif
 if((fsfUmlErrNo = 
 FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlUsersDataFilename,FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
  return fsfUmlErrNo;
 
 if(!(fsfUmlUsersFile = fopen(fsfUmlConfigurations->fsfUmlUsersDataFilename,"r")))
  return fsfUmlFileOpeningError;
 
 while(!feof(fsfUmlUsersFile))
 {
  /*first we take all the user data, store at buffer and then we check the id in the request users file*/
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
   return fsfUmlInvalidUserId;
   
  fsfUmlCounter = 0;
  while(':' !=(fsfUmlGetCh = fgetc(fsfUmlUsersFile)))
  {
   fsfUmlNicknameBuffer[fsfUmlCounter] = fsfUmlGetCh;
   fsfUmlCounter++;
  }
  fsfUmlNicknameBuffer[fsfUmlCounter] = '\0';

  if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlNicknameBuffer,FSF_UML_NICKNAME_ ,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
   return fsfUmlErrNo;

  while(':' !=(fsfUmlGetCh = fgetc(fsfUmlUsersFile)));/*Jumps just password field in the text file*/
  while(':' != (fsfUmlGetCh = fgetc(fsfUmlUsersFile)))
  {
   fsfUmlProfileBuffer[fsfUmlCounter] = fsfUmlGetCh;
   fsfUmlCounter++;
  }
  fsfUmlProfileBuffer[fsfUmlCounter] = '\0';
  /*The fsfUmlProfileBuffer contains the user profile */
  fsfUmlProfile = strtoull(fsfUmlProfileBuffer,&fsfUmlCheck,10);

  if(*fsfUmlCheck != '\0')
   return fsfUmlInvalidProfile;
  
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
   return fsfUmlErrNo;
  
  fsfUmlCounter = 0;
  fgets(fsfUmlEmailBuffer,(FSF_UML_EMAIL_MAX_LENGTH + 2),fsfUmlUsersFile); 
  
  if(fsfUmlEmailBuffer[strlen(fsfUmlEmailBuffer) - 1] == '\n')
   fsfUmlEmailBuffer[strlen(fsfUmlEmailBuffer) - 1] = '\0';
  /*the fsfUmlBuffer now contains the user's email*/
  if((fsfUmlErrNo = 
  FsfUmlCheckEmail(fsfUmlEmailBuffer,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
   return fsfUmlErrNo;

  if(ferror(fsfUmlUsersFile))
  {
   fclose(fsfUmlUsersFile);
   return fsfUmlFileError;
  }
  /*No problems occured up to now,so the all the user data are valid. Now we can search at the requesting users file by the given id*/
  while(!feof(fsfUmlRequestingUsersFile))
  { 
   if((fread(&fsfUmlAbsolutExpirationTime,sizeof(time_t),1,fsfUmlRequestingUsersFile) != 1))
   {
    fclose(fsfUmlRequestingUsersFile);
    return fsfUmlFileReadingError;
   }
  
   if((fread(&fsfUmlAnalistId,sizeof(fsfUmlUserIdentifierType),1,fsfUmlRequestingUsersFile) != 1))
   {
    fclose(fsfUmlRequestingUsersFile);
    return fsfUmlFileReadingError;
   }
  
   if((fread(&fsfUmlRequestingUserId,sizeof(fsfUmlUserIdentifierType),1,fsfUmlRequestingUsersFile) != 1))
   {
    fclose(fsfUmlRequestingUsersFile);
    return fsfUmlFileReadingError;
   }
  
   if((fread(&fsfUmlPasswd,sizeof(char),FSF_UML_PASSWORD_MAX_LENGTH,fsfUmlRequestingUsersFile) != 1))
   {
    fclose(fsfUmlRequestingUsersFile);
    return fsfUmlFileReadingError;
   }

   if(fsfUmlRequestingUserId == fsfUmlUserId)
   {
    fsfUmlActualTime = time(NULL);
   
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
      fclose(fsfUmlRequestingUsersFile);
      return fsfUmlMemoryAllocationError;
     }
   
     fsfUmlNew->fsfUmlId = fsfUmlUserId;
     strcpy(fsfUmlNew->fsfUmlNickname,fsfUmlNicknameBuffer);
     strcpy(fsfUmlNew->fsfUmlPassword,fsfUmlPasswd);
     strcpy(fsfUmlNew->fsfUmlPasswordVerification,fsfUmlPasswd);
     fsfUmlNew->fsfUmlProfile = fsfUmlProfile;
     strcpy(fsfUmlNew->fsfUmlName,fsfUmlFullNameBuffer);
     strcpy(fsfUmlNew->fsfUmlNameVerification,fsfUmlFullNameBuffer);
     strcpy(fsfUmlNew->fsfUmlEmail,fsfUmlEmailBuffer);
     fsfUmlNew->fsfUmlNext = NULL;
     fsfUmlNew->fsfUmlPrevious = NULL;

     if(!fsfUmlFirst)
     {
      fsfUmlFirst = fsfUmlNew;
      fsfUmlLast = fsfUmlNew;
     }
     else
     {
      fsfUmlLast->fsfUmlNext = fsfUmlNew;
      fsfUmlNew->fsfUmlPrevious = fsfUmlLast;
      fsfUmlLast = fsfUmlNew;
     }/*else ends*/
    }/* if(fsfUmlActualTime <= fsfUmlAbsolutExpirationTime) ends */
   }/* if(fsfUmlRequestingUserId == fsfUmlUserId) ends */  
  }/* while(!feof(fsfUmlRequestingUsersFile)) ends */
  rewind(fsfUmlRequestingUsersFile);/* Go back to the beginning of the file*/
 }/* while(!feof(fsfUmlUsersFile)) ends */
 
 if(fsfUmlFirst == NULL)
  return fsfUmlNoValidRequests;
 
 if(ferror(fsfUmlRequestingUsersFile))
 {
  fclose(fsfUmlRequestingUsersFile);
  return fsfUmlFileError;
 }
 
 fclose(fsfUmlRequestingUsersFile);
 fclose(fsfUmlUsersFile);

 *fsfUmlFirstData = fsfUmlFirst;
 return fsfUmlOk; 
}

/*$RCSFile$*/
