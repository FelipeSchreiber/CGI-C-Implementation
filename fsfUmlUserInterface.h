/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$
*/

#ifndef _FSF_UML_USER_INTERFACE_H_
#define _FSF_UML_USER_INTERFACE_H_ "@(#)fsfUmlUserInterface.h $Revision$" 

#include "fsfUmlTypes.h"
#include "fsfUmlErrors.h"
typedef enum {fsfUmlInitialMessage = 0,fsfUmlSelectedOption,fsfUmlNicknameWarning,fsfUmlPasswordWarning,fsfUmlEnter,fsfUmlHelp,fsfUmlLeave,fsfUmlShowConfigurationValues,
fsfUmlRequireRegistration,fsfUmlAcceptInvitation,fsfUmlRejectInvitation,fsfUmlAddUser,fsfUmlGetPendingRegistrationRequestsPerUser,
fsfUmlGetPendingRegistrationRequests,fsfUmlApproveRegistrationRequest,fsfUmlDisapproveRegistrationRequest,fsfUmlGetUnlockingRequests,
fsfUmlLockUserAccount,fsfUmlUnlockUserAccount,fsfUmlChangeUserPassword,fsfUmlResetUserPassword,fsfUmlChangeUserName,fsfUmlChangeUserEmail,
fsfUmlConfirmEmailChange,fsfUmlChangeUserProfile,fsfUmlGetUsers,fsfUmlSearchUsers,fsfUmlInsertNickname,fsfUmlInsertPassword,
fsfUmlUserIdentifier,fsfUmlPrivateRoot,fsfUmlData,fsfUmlCookies,fsfUmlUsersDataFile,fsfUmlInvitedUsersDataFile,fsfUmlRequestingUsersDataFile,
fsfUmlLockedUsersDataFile,fsfUmlSignInMessage,fsfUmlLicenseMessage,fsfUmlReturnMessage,fsfUmlFriendEmailMessage,fsfUmlUserNameMessage,fsfUmlUserNameConfirmationMessage,fsfUmlEmailMessage,fsfUmlEmailConfirmationMessage,fsfUmlRequestPasswordMessage,fsfUmlShowHelp,fsfUmlShowLicense,fsfUmlTotalInterfaceMessages}
fsfUmlUserInterfaceMessageNumberType;
/*
FsfUmlGetCliUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetCliUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

/*
FsfUmlGetUserNcursesInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetNcursesUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

/*
FsfUmlGetWebUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetWebUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType); 
#endif

/*RCSFile*/  
