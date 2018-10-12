/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author: felipe.schreiber $
$Date: 2017/06/01 16:06:57 $
$Log: fsfUmlTypes.h,v $
Revision 1.1  2017/06/01 16:06:57  felipe.schreiber
Initial revision
  
*/

#include "fsfUmlConfig.h"
#include "fsfUmlConst.h"
#include <time.h>
#ifndef _FSF_UML_TYPES_H_
#define _FSF_UML_TYPES_H_ "@(#)fsfUmlTypes.h $Revision$" 


typedef enum {fsfUmlDes = 0,fsfUmlMd5 = 1,fsfUmlSha256 = 5, fsfUmlSha512 = 6}fsfUmlCryptAlgorithmsTypes;
typedef unsigned long long fsfUmlUserProfileType;
typedef unsigned long long fsfUmlUserIdentifierType;
typedef enum {fsfUmlEnglish,fsfUmlPortuguese,fsfUmlLanguagesAmount}fsfUmlLanguageType;
typedef enum {fsfUmlFalse = 0,fsfUmlTrue} boolean;
typedef 
struct fsfUmlUserData
{
 fsfUmlUserIdentifierType fsfUmlId;
 char fsfUmlNickname [FSF_UML_NICKNAME_MAX_LENGTH + 1];
 char fsfUmlPassword [FSF_UML_PASSWORD_MAX_LENGTH + 1];
 char fsfUmlPasswordVerification [FSF_UML_PASSWORD_MAX_LENGTH + 1];
 fsfUmlUserProfileType fsfUmlProfile;
 char fsfUmlName[FSF_UML_FULLNAME_MAX_LENGTH];
 char fsfUmlNameVerification[FSF_UML_FULLNAME_MAX_LENGTH + 1];
 char fsfUmlEmail [FSF_UML_EMAIL_MAX_LENGTH + 1];
 struct fsfUmlUserData *fsfUmlNext, *fsfUmlPrevious;

}fsfUmlUserDataType;

typedef 
struct fsfUmlConfigurationOptionsType
{
 fsfUmlUserIdentifierType fsfUmlUserId;
 char fsfUmlPrivateRootDirectory[FSF_UML_FILEPATH_MAX_LENGTH];
 char fsfUmlDataDirectory[FSF_UML_FILEPATH_MAX_LENGTH]; 
 char fsfUmlCookiesDirectory[FSF_UML_FILEPATH_MAX_LENGTH];
 char fsfUmlUsersDataFilename [FSF_UML_FILENAME_MAX_LENGTH + 1];
 char fsfUmlInvitedUsersDataFilename [FSF_UML_FILENAME_MAX_LENGTH + 1];
 char fsfUmlRequestingUsersDataFilename [FSF_UML_FILENAME_MAX_LENGTH + 1];
 char fsfUmlLockedUsersDataFilename [FSF_UML_FILENAME_MAX_LENGTH + 1]; 
}fsfUmlConfigurationOptionsType;

typedef
struct fsfUmlPendingRequestType
{
 time_t fsfUmlAbsolutExpirationTime;
 fsfUmlUserIdentifierType fsfUmlAnalistId;
 fsfUmlUserIdentifierType fsfUmlUserId;
 char fsfUmlPasswd[FSF_UML_PASSWORD_MAX_LENGTH]; 

}fsfUmlPendingRequestType;

#endif
/* $RCSFile$ */
