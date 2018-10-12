/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$
 
*/

#ifndef _FSF_UML_ERRORS_H_
#define _FSF_UML_ERRORS_H_ "@(#)fsfUmlErrors.h $Revision$"

#include "fsfUmlTypes.h"

typedef enum {fsfUmlOk = 0,fsfUmlInvalidErrorNumber,fsfUmlFileError,fsfUmlMemoryAllocationError,fsfUmlInvalidPassword,fsfUmlNullName,fsfUmlNullValidCharacters,fsfUmlInvalidCharacter,fsfUmlLengthOverflow,fsfUmlLengthUnderflow,fsfUmlNullPath,fsfUmlNullFilename,fsfUmlPathSizeOverflow,fsfUmlDotOverflow,fsfUmlNullEmail,fsfUmlAtSignOverflow,fsfUmlNullRandomString,fsfUmlZeroLength,fsfUmlNullStringField,fsfUmlSurnameNotFound,fsfUmlInvalidCrypt,fsfUmlInvalidCryptLength,fsfUmlInvalidId,fsfUmlInvalidSalt,fsfUmlInvalidEncrypted,fsfUmlInvalidPasswd,fsfUmlIncompatiblePassword,fsfUmlNullCrypted,fsfUmlNullId,fsfUmlNullSalt,fsfUmlNullConfigurationData,fsfUmlFileOpeningError,fsfUmlFileReadingError,fsfUmlUnrecognizedConfigurationOption,fsfUmlErrorClosingWindow,fsfUmlKeypadUnabled,fsfUmlErrorPrintingWindow,fsfUmlErrorReloadingWindow,fsfUmlErrorMovingCursor,fsfUmlWborderErr,fsfUmlErrorGettingString,fsfUmlUnknownMessage,fsfUmlNullWindow,fsfUmlNullBorder,fsfUmlNullExit,fsfUmlZeroDots,fsfUmlNullUserData,fsfUmlNicknameNotFound,fsfUmlInvalidUserId,fsfUmlIdAndNicknameDontMatch,fsfUmlInvalidProfile,fsfUmlIdNotFoundInRequestFile,fsfUmlNoValidRequests,fsfUmlZeroAtSigns,fsfUmlInvalidLanguage,fsfUmlTokenAlreadyProcessed,fsfUmlNotAdmin,fsfUmlDifferentUsers,fsfUmlDifferentEmails,fsfUmlDifferentPasswords,fsfUmlErrorsAmount} fsfUmlErrorType;

/*
char *
FsfUmlGetCliErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);


Arguments:

fsfUmlErrorType - Equivalent integer to a specific error (I)

fsfLanguageType- Equivalent integer to the language defined (I)


Return code:

fsfUmlCliErrorMessages [fsfUmlLanguage] [fsfUmlError]

This function returns a pointer which points to the begining of a string that contains the error message


Description:

Returns an error message corresponding to the error number in the language specified

*/ 

char *
FsfUmlGetCliErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage);
/*
char *
FsfUmlGetNcursesErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);


Arguments:

fsfUmlErrorType - Equivalent integer to a specific error (I)

fsfLanguageType- Equivalent integer to the language defined (I)


Return code:

fsfUmlNcursesErrorMessages [fsfUmlLanguage] [fsfUmlError]

This function returns a pointer which points to the begining of a string that contains the error message


Description:

Returns an error message corresponding to the error number in the language specified
*/ 
char*
FsfUmlGetNcursesErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage); 
/*
 * char *
 * FsfUmlGetWebErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);
 *
 *
   Arguments:
 *
 * fsfUmlErrorType - Equivalent integer to a specific error (I)
 * 
   fsfLanguageType- Equivalent integer to the language defined (I)
 *
 *
   Return code:
 *
   fsfUmlWebErrorMessages [fsfUmlLanguage] [fsfUmlError]  
 *
   This function returns a pointer which points to the begining of a string that contains the error message
 *
 * 
   Description:
 * 
   Returns an error message corresponding to the error number in the language specified
*/
char *
FsfUmlGetWebErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage); 

#endif
/*RCSFile*/
