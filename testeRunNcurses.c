#include <stdio.h>
#include "fsfUmlRunNcursesInterface.h"
#include "fsfUmlTypes.h"
int main()
{
 char nickname[]="felipe.schreiber";
 fsfUmlConfigurationOptionsType fsfUmlConfigurations;
 int fsfUmlErrNo;

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
 
 fsfUmlErrNo = FsfUmlRunNcursesInterface(&fsfUmlConfigurations,nickname,fsfUmlEnglish);

 printf("\nErro #%i --> %s\n",fsfUmlErrNo,FsfUmlGetNcursesErrorMessage (fsfUmlErrNo,fsfUmlEnglish));

 return fsfUmlOk;
}
