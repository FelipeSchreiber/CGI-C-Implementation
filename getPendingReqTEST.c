#include <stdio.h>
#include "fsfUmlGetPendingRegistrationRequestsPerUser.h"
#include "fsfUmlTypes.h"
#include "fsfUmlErrors.h"

/*This is a test program only*/ 
void display(fsfUmlUserDataType*);

int main()
{
 fsfUmlConfigurationOptionsType fsfUmlConfigurations;
 char fsfUmlNickname[] = "joao.rafael";
 fsfUmlUserDataType *first;
 int fsfUmlErrNo;
 first = NULL;
 
 fsfUmlConfigurations.fsfUmlUserId = FSF_UML_ADMINISTRATOR_USER_IDENTIFIER;
 sprintf(fsfUmlConfigurations.fsfUmlPrivateRootDirectory,"%s",FSF_UML_PRIVATE_ROOT_DIRECTORY);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlPrivateRootDirectory);
 strcpy(fsfUmlConfigurations.fsfUmlDataDirectory,FSF_UML_DATA_DIRECTORY);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlDataDirectory);
 strcpy(fsfUmlConfigurations.fsfUmlCookiesDirectory,FSF_UML_COOKIES_DIRECTORY);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlCookiesDirectory);
 strcpy(fsfUmlConfigurations.fsfUmlUsersDataFilename,FSF_UML_USERS_DATA_FILENAME);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlUsersDataFilename);
 strcpy(fsfUmlConfigurations.fsfUmlInvitedUsersDataFilename,FSF_UML_INVITED_USERS_DATA_FILENAME);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlInvitedUsersDataFilename);
 strcpy(fsfUmlConfigurations.fsfUmlRequestingUsersDataFilename,FSF_UML_REQUESTING_USERS_DATA_FILENAME);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlRequestingUsersDataFilename);
 strcpy(fsfUmlConfigurations.fsfUmlLockedUsersDataFilename,FSF_UML_LOCKED_USERS_DATA_FILENAME);
 printf("\n<%s>\n",fsfUmlConfigurations.fsfUmlLockedUsersDataFilename);

 fsfUmlErrNo = FsfUmlGetPendingRegistrationRequestsPerUser(&fsfUmlConfigurations,fsfUmlNickname,&first);
 printf("%s",FsfUmlGetCliErrorMessage(fsfUmlErrNo,fsfUmlEnglish));
 
 #ifdef _MY_DEBUG_
  printf("\nDebug set\n");
 #endif
 printf("\n\nOK\n\n");

 /*printf("\nNome: %s",(first)->fsfUmlName);
 printf("\nId: %llu",(first)->fsfUmlId);
 printf("\nProfile: %llu",(first)->fsfUmlProfile);
 printf("\nPass: %s",(first)->fsfUmlPassword);
 printf("\nEmail : %s",(first)->fsfUmlEmail);
 */
 display(first);

 return fsfUmlOk;
}

void display(fsfUmlUserDataType *first)
{
 fsfUmlUserDataType *aux;
 aux = first;
 while (aux != NULL)
 {
  printf("\nNome: %s",/*difftime(timeTest,localTime)*/(aux)->fsfUmlName);
  printf("\nId: %llu",(aux)->fsfUmlId);
  printf("\nProfile: %llu",(aux)->fsfUmlProfile);
  printf("\nPass: %s",(aux)->fsfUmlPassword);
  printf("\nEmail : %s",(aux)->fsfUmlEmail);
  aux = aux->fsfUmlNext;
 }
 printf("\nALL DONE\n\n");
}
