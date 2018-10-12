/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author: felipe.schreiber $
$Date: 2017/06/01 17:16:01 $
$Log: fsfUmlFunctions.h,v $
Revision 1.1  2017/06/01 17:16:01  felipe.schreiber
Initial revision


*/
#ifndef _FSF_UML_FUNCTIONS_H
#define _FSF_UML_FUNCTIONS_H "@(#)fsfUmlFunctions.h $Revision: 1.1 $"

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "fsfUmlErrors.h"
#include "fsfUmlTypes.h"
#include "fsfUmlConst.h"
#include "fsfUmlUserInterface.h"
#include <curses.h>
#include <time.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <crypt.h>  

/*
fsfUmlLanguageType
FsfUmlGetLanguageIndex (char *);


Arguments:

Char* - Pointer to the first string element. This string represents the language
chosen.(I)


Return:

0 case language choice is english or the input argument is invalid.

1 case language choice is portuguese.


Description:
This function returns an integer corresponding to the language defined.

*/
fsfUmlLanguageType
FsfUmlGetLanguageIndex (char *);

/*
 fsfUmlErrorType
 FsfUmlCheckStringField(char * fsfUmlFilename, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)


 Arguments:
 
 char *fsfUmlFilename - This argument corresponds to a pointer which points to the beginnig of a string(I)

 char *fsfValidCharacters - This argument corresponds to a pointer that points to the beginning of the string of valid characters. It means,
 a vector of valid characters (I)

 size_t fsfUmlMinimumLength - This argument corresponds to the minimum size required (I)

 size_t fsfUmlMaximumLength - This argument corresponds to the maximum size allowed (I)


 Returned code:

 fsfUmlNullFilename - If the pointer corresponding to fsfUmlName got the NULL value

 fsfUmlNullValidCharacters - If the pointer corresponding to fsfUmlValidCharacters got the NULL value

 fsfUmlInvalidCharacter - If a character in fsfUmlFilename isn't included at the fsfValidCharacters

 fsfUmlLengthOverflow - If fsfUmlFileame surpass fsfUmlMaximumLength characters

 fsfUmlLengthUnderflow - If fsfUmlFilename contains less then fsfUmlMaximumLength characters

 fsfUmlOk - If fsfUmlFilename is a valid string

 
 Description:

 This functions returns whether the string is valid or not arccording to the parameters specified. Case it isn't valid, an error code will
 be returned

*/
fsfUmlErrorType
FsfUmlCheckStringField(char * fsfUmlFilename, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength);

/*
 fsfUmlErrorType
 FsfUmlCheckNickname(char * fsfUmlName, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)


 Arguments:
 
 char *fsfUmlName - This argument corresponds to a pointer which points to the beginnig of a string(I)

 char *fsfValidCharacters - This argument corresponds to a pointer that points to the beginning of the string of valid characters. It means,
 a vector of valid characters (I)

 size_t fsfUmlMinimumLength - This argument corresponds to the minimum size required (I)

 size_t fsfUmlMaximumLength - This argument corresponds to the maximum size allowed (I)


 Returned code:

 fsfUmlNullName - If the pointer corresponding to fsfUmlName got the NULL value

 fsfUmlNullValidCharacters - If the pointer corresponding to fsfUmlValidCharacters got the NULL value

 fsfUmlInvalidCharacter - If a character in fsfUmlName isn't included at the fsfValidCharacters

 fsfUmlDotOverflow - If fsfUmlName contains more than one dot

 fsfUmlLengthOverflow - If fsfUmlName surpass fsfUmlMaximumLength characters

 fsfUmlLengthUnderflow - If fsfUmlName contains less then fsfUmlMaximumLength characters

 fsfUmlOk - If fsfUmlName is a valid string

 
 Description:

 This functions returns whether the string is valid or not arccording to the parameters specified. Case it isn't valid, an error code will
 be returned

*/

fsfUmlErrorType
FsfUmlCheckNickname(char * fsfUmlName, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength);

/*
 fsfUmlErrorType
 FsfUmlFilenameValidation(char * fsfUmlFilename, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)


 Arguments:
 
 char *fsfUmlFilename - This argument corresponds to a pointer which points to the beginnig of a string(I)

 char *fsfValidCharacters - This argument corresponds to a pointer that points to the beginning of the string of valid characters. It means,
 a vector of valid characters (I)

 size_t fsfUmlMinimumLength - This argument corresponds to the minimum size required (I)

 size_t fsfUmlMaximumLength - This argument corresponds to the maximum size allowed (I)


 Returned code:

 fsfUmlNullFilename - If the pointer corresponding to fsfUmlName got the NULL value

 fsfUmlNullValidCharacters - If the pointer corresponding to fsfUmlValidCharacters got the NULL value

 fsfUmlInvalidCharacter - If a character in fsfUmlFilename isn't included at the fsfValidCharacters

 fsfUmlLengthOverflow - If fsfUmlFileame surpass fsfUmlMaximumLength characters

 fsfUmlLengthUnderflow - If fsfUmlFilename contains less then fsfUmlMaximumLength characters

 fsfUmlOk - If fsfUmlFilename is a valid string

 
 Description:

 This functions returns whether the string is valid or not arccording to the parameters specified. Case it isn't valid, an error code will
 be returned

*/

fsfUmlErrorType
FsfUmlFilenameValidation(char * fsfUmlFilename, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength);

/*
 fsfUmlErrorType
 FsfUmlCheckEmail(char * fsfUmlEmail, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)


 Arguments:
 
 char *fsfUmlEmail - This argument corresponds to a pointer which points to the beginnig of a string(I)

 char *fsfValidCharacters - This argument corresponds to a pointer that points to the beginning of the string of valid characters. It means,
 a vector of valid characters (I)

 size_t fsfUmlMinimumLength - This argument corresponds to the minimum size required (I)

 size_t fsfUmlMaximumLength - This argument corresponds to the maximum size allowed (I)


 Returned code:

 fsfUmlNullEmail - If the pointer corresponding to fsfUmlEmail got the NULL value

 fsfUmlNullValidCharacters - If the pointer corresponding to fsfUmlValidCharacters got the NULL value

 fsfUmlInvalidCharacter - If a character in fsfUmlEmail isn't included at the fsfValidCharacters

 fsfUmlAtSignOverflow - If fsfUmlEmail contains more than one at sign

 fsfUmlLengthOverflow - If fsfUmlEmail surpass fsfUmlMaximumLength characters

 fsfUmlLengthUnderflow - If fsfUmlEmail contains less then fsfUmlMaximumLength characters

 fsfUmlOk - If fsfUmlEmail is a valid string

 
 Description:

 This functions returns whether the string is valid or not arccording to the parameters specified. Case it isn't valid, an error code will
 be returned

*/
fsfUmlErrorType
FsfUmlCheckEmail(char * fsfUmlEmail, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength);

/*
fsfUmlErrorType
FsfUmlCreateRandomString (char *fsfUmlValidCharacters, size_t fsfUmlLength, char *fsfUmlRandomString)


Arguments:

char *fsfUmlValidCharacters - This represents a string containing all the valid characters(I)

size_t fsfUmlLength - This represents the maximum length desired of the string generated(I)

char *fsfUmlRandomString - This is the random string generated after the process(O)


Returning code:

fsfUmlNullRandomString - If fsfUmlRandomString got null value

fsfUmlNullValidCharacters - If fsfUmlValidCharacters got null value

fsfUmlZeroLength - If fsfUmlLength got a zero value

fsfUmlOk - If there is no error during the process


Description:

This function creates a fsfUmlLength size random string containing only fsfUmlValidCharacters
*/

fsfUmlErrorType
FsfUmlCreateRandomString (char *fsfUmlValidCharacters, size_t fsfUmlLength, char *fsfUmlRandomString);

/*
fsfUmlErrorType
FsfUmlGetAbsolutFileName (char *fsfUmlPath, char *fsfUmlFilename, char *fsfUmlAbsolutPath)

Arguments:
char *fsfUmlPath - This argument represents a path to a specific file (I)
char *fsfUmlFilename - This argument corresponds to a filename (I)
char *fsfUmlAbsolutPath - This argument represents the absolut path to a specific file (O)

Return Code:

fsfUmlErrorNo - Returns the same error number as FsfUmlFilenameValidation(char *, char *,size_t ,size_t )

fsfUmlUmlNullPath - Got a null path

fsfUmlPathSizeOverflow - File absolut path surpass the maximum length allowed

fsfUmlNullFilename - Got a null filename

fsfUmlOk - The absolut file path is valid

Description:

This function concatenates two file paths in order to obtain the absolut one.Case the absolut one is not valid, an error will be returned

*/

/*
fsfUmlErrorType
FsfUmlCreateNickname(char *fsfUmlName, char *fsfUmlNickname1, char *fsfUmlNickname2)


Arguments:

char *fsfUmlName - This arguments represents the name of someone (I)

char *fsfUmlNickname1 - This arguments represents the created nickname by taking the first and the last names (O)

char *fsfUmlNickname2- This arguments represents another created nickname by taking the first and the last-but-one names (O)


Returned code:

fsfUmlErrorNo - If the name got any invalid characters or surpass the maximum length allowed

fsfUmlSurnameNotFound - In case the name doesn't contain any surname

fsfUmlOk - In case everything is ok


Description:

This function proposes 2 possible nicknames, in case there more than one surname, or 1, incase there is only one surname.
If there isn't any surname, an error will occur.
If the final nickname has more than 65 characters, the surname will be partially erased 


*/

fsfUmlErrorType
FsfUmlCreateNickname(char *fsfUmlName, char *fsfUmlNickname1, char *fsfUmlNickname2);

/*
fsfUmlErrorType
FsfUmlGetCryptAlgorithm (char *fsfUmlCrypted,fsfUmlCryptAlgorithmsTypes *fsfUmlId)


Arguments:

char *fsfUmlCrypted - This represents the encrypted password (I)

fsfUmlCryptAlgorithmsTypes *fsfUmlId - This represents the crypting algorithm used in this password (O)


Returned code:

fsfUmlInvalidCrypt - If there is an error in the password, a missing '$' character or unmatched crypting algorithm

fsfUmlInvalidCryptLength - If the crypted password contains less the required characters amount of the specific algorithm

fsfUmlInvalidId - If the algorithm identification does not match with anyone else

fsfInvalidSalt - If the salt contains invalid characters or invalid length

fsfUmlInvalidEncrypted - If the encrypted part of password contains invalid charaters or length out of the following range: 22 - 86 

fsfUmlOk - If no problems ocurred


Description:

This function identifies which crypting algorithm was used to generate the password
*/

fsfUmlErrorType
FsfUmlGetCryptAlgorithm (char *fsfUmlCrypted,fsfUmlCryptAlgorithmsTypes *fsfUmlId);

/*
fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificAlgorithm (char *fsfUmlPasswd,fsfUmlCryptAlgorithmsTypes fsfUmlId,char *fsfUmlEncrypted);


Arguments:

char *fsfUmlPasswd - This is the user's input password (I)

fsfUmlCryptAlgorithmsTypes fsfUmlId - This is the chosen crypting algorithm (I)

char *fsfUmlEncrypted - This is the crypting result (O)


Returned Code:

fsfUmlInvalidPasswd - If the password contains invalid characters or invalid length

fsfUmlInvalidId - If the crypting algorithm did not match with anyone 

fsfUmlOk - No problems ocurred


Description:

This function takes user's password and the chosen crypt algorithm to generate an encrypted one.
*/
fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificAlgorithm(char *fsfUmlPasswd,fsfUmlCryptAlgorithmsTypes fsfUmlId,char *fsfUmlEncrypted);

/*
fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificSalt(char *fsfUmlPasswd, char *fsfUmlSalt, char *fsfUmlEncrypted)


Arguments:

char *fsfUmlPasswd - This is the user's password input (I)

char *fsfUmlSalt - This is the full salt, which is used to encrypt

char *fsfUmlEncrypted - This is the user's password encrypted


Returned code:

fsfUmlInvalidPasswd - If the password contains invalid characters or invalid length

fsfUmlInvalidId - If the crypting algorithm did not match with anyone 

fsfInvalidSalt - If the salt contains invalid characters or invalid length


Description:

This functon takes the user's password and the chosen salt to encrypt the information
*/

fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificSalt(char *fsfUmlPasswd, char *fsfUmlSalt, char *fsfUmlEncrypted);

/*
fsfUmlErrorType
FsfUmlCheckPassword (char *fsfUmlPasswd, char *fsfUmlEncrypted)


Arguments:

char *fsfUmlPasswd - This is a not encrypted password (I)

char *fsfUmlEncrypted - This is the encrypted password (I)


Returned code:

fsfUmlErrorNo - If an error occurred in function FsfUmlGetCryptAlgorithm(char*,char*)

fsfUmlIncompatiblePassword - If the passwords are not equivalent

fsfUmlOk - The passwords are equivalent


Description:

This function encrypt the given password taking the same salt value as the encrypted one.
After encrypting, this function compares if the result is the same.


*/
fsfUmlErrorType
FsfUmlCheckPassword (char *fsfUmlPasswd, char *fsfUmlEncrypted);

/*
fsfUmlErrorType
FsfUmlGetConfigurationOptionsValues (char *fsfUmlConfigFilename, fsfUmlConfigurationOptionsType*fsfUmlConfigurations);


Arguments:

fsfUmlConfigFilename - This is the filename containing the chosen configuration (I)

fsfUmlConfigurations - This is the struct containig the all the configurations values(O)


Returned code:

fsfUmlNullConfigurationData - If the pointer to struct fsfUmlConfigurationsType got NULL value

fsfUmlErrNo - If the fsfUmlConfigFilename is a invalid filename or if any filename or directory in the configuration file has an invalid argument

fsfUmlFileOpeningError - If an error occurred while opening a file

fsfUmlFileReadingError - If an error occurred while reading a file or if the error indicator is set to this file

fsfUmlUnrecognizedConfigurationOption - If an configuration option in the configuration file did not match with any specified one

fsfUmlOk - If no problems occurred

*/
fsfUmlErrorType
FsfUmlGetConfigurationOptionsValues (char *, fsfUmlConfigurationOptionsType *);

/*
 FsfUmlPrintWindowMoveCursor(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,fsfUmlUserInterfaceMessageNumberType fsfUmlMessage,WINDOW* fsfUmlWindow,char* fsfUmlString,int fsfUmlMaxRow)


Arguments:

fsfUmlLanguage - This is the specified language (I)

fsfUmlField - This is the field to be printed at the specified window, which corresponds to nickname or password (I)

fsfUmlMessage - This is the message to be printed at the specified window, which corresponds to some instructions (I)

fsfUmlWindow - This is the window where things will be printed (I)

fsfUmlString - This is the pointer where information digited by the user will be stored (O)

fsfUmlMaxRow - This is the maximum height of the window where things will be prinnted on (I)


Description:

This function just print two messages: one at the top of the window and another at the bottom


Returned Code:

fsfUmlErrorPrintingWindow - An error occured while writing at window

fsfUmlErrorReloadingWindow - An error occured while reloading a window

fsfUmlErrorMovingCursor - An error occured while moving the cursor

fsfUmlErrorGettingString - An error occured while the user was digiting

fsfUmlOk - No problems occured
*/

fsfUmlErrorType
FsfUmlPrintWindowMoveCursor(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,fsfUmlUserInterfaceMessageNumberType fsfUmlMessage,WINDOW* fsfUmlWindow,char* fsfUmlString,int fsfUmlMaxRow);

/*
 FsfUmlPrintWindow(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,WINDOW* fsfUmlWindow,char* fsfUmlString)


Arguments:

fsfUmlLanguage - This is the specified language (I)

fsfUmlField - This is the first message to be printed at the specified window, which corresponds to nickname or password (I)

fsfUmlWindow - This is the window where things will be printed (I)

fsfUmlString - This is the pointer to the information to be printed (I)


Description:

This function just print the field correspondig to the password or login and it's value


Returned Code:

fsfUmlErrorPrintingWindow - An error occured while writing at window

fsfUmlErrorReloadingWindow - An error occured while reloading a window

fsfUmlOk - No problems occured
*/

fsfUmlErrorType
FsfUmlPrintWindow(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,WINDOW* fsfUmlWindow,char* fsfUmlString);

/*
fsfUmlErrorType
FsfUmlNcursesLogin(fsfUmlLanguageType fsfUmlLanguage,WINDOW* fsfUmlWindow,WINDOW* fsfUmlBorder,char* fsfUmlGetNickname,char* fsfUmlPassword,boolean *fsfUmlExit)


Arguments:

fsfUmlLanguage - This is the selected language (I)

fsfUmlWindow - The the window where will shown the login formulary (I)

fsfUmlBorder - The border of the window where will be show the login formulary (I)

fsfUmlGetNickname - This is where the nickname will be saved (O)

fsfUmlPassword - This is where the password will be stored (O)

fsfUmlExit - This is a variable that indicates whether the user left the formulary window without filling the required filds, or don't (O)


Description:

This function opens a window with the formulary requering nickname and password from user


Returned Code:

fsfUmlNullWindow - The pointer to WINDOW type is NULL

fsfUmlNullBorder - The pointer to WINDOW(border) is NULL

fsfUmlNullExit - The pointer to boolean type(fsfUmlExit) is NULL

fsfUmlNullStringField - The pointer to password or nickname is NULL

fsfUmlErrNo - The error returned by FsfUmlPrintWindowMoveCursor or FsfUmlPrintWindow functions

fsfUmlErrorClosingWindow - An error occured while closing a window

*/
fsfUmlErrorType
FsfUmlNcursesLogin(fsfUmlLanguageType fsfUmlLanguage,WINDOW* fsfUmlWindow,WINDOW* fsfUmlBorder,char* fsfUmlGetNickname,char* fsfUmlPassword,boolean *fsfUmlExit);

/*
fsfUmlErrorType 
FsfUmlNcursesMenu(WINDOW *fsfUmlWindow,int fsfUmlCounterMinValue,int fsfUmlCounterMaxValue,int *fsfUmlUnderline,
unsigned char fsfUmlUserInput,fsfUmlLanguageType fsfUmlLanguage);


Arguments:

fsfUmlWindow: Pointer to a WINDOW variable where the menu will be shown(I)

fsfUmlCounterMinValue: The initial value of the fsfUmlUnderline variable, which indicates what is the start element of menu(I)

fsfUmlCounterMaxValue: The last value of the fsfUmlUnderline variable, which indicates what is the final element of menu(I)

fsfUmlUnderline: This is the highlighted option of menu, and indicates the user's choice(O)

fsfUmlUserInput: This is the unsigned char corresponding to user input(I)

fsfUmlLanguage: This is the language in which the menu will be shown(I)


Returned code:

fsfUmlErrorPrintingWindow: If a problem occured while printing a window

fsfUmlOk: No problems occured


Description:

This function shows the menu and take the user's choice
*/
fsfUmlErrorType 
FsfUmlNcursesMenu(WINDOW **fsfUmlWindow,int fsfUmlCounterMinValue,int fsfUmlCounterMaxValue,int *fsfUmlUnderline,
int fsfUmlUserInput,fsfUmlLanguageType fsfUmlLanguage);

/*
fsfUmlErrorType
FsfUmlInitializeWindows(WINDOW **fsfUmlBorder,WINDOW **fsfUmlSecondaryWindow)


Arguments: 

fsfUmlBorder: this is a pointer to the border window (I)

fsfUmlSecondaryWindow: this is a pointer to the secondary border(I)


Returned code:

fsfUmlWborderErr: If the function (wborder) to set the window border fails

fsfUmlErrorReloadingWindow: If the function(wrefresh) to reload the current window fails


Description:

This function creates a secondary window and also set a border to it
*/
fsfUmlErrorType
FsfUmlInitializeWindows(WINDOW **fsfUmlBorder,WINDOW **fsfUmlSecondaryWindow);

/*
fsfUmlErrorType
FsfUmlGetAbsolutFileName (char *fsfUmlPath, char *fsfUmlFilename, char *fsfUmlAbsolutPath)


Arguments:

char *fsfUmlPath - This argument represents a path to a specific file (I)

char *fsfUmlFilename - This argument corresponds to a filename (I)

char *fsfUmlAbsolutPath - This argument represents the absolut path to a specific file (O)


Return Code:

fsfUmlErrorNo - Returns the same error number as FsfUmlFilenameValidation(char *, char *,size_t ,size_t )

fsfUmlUmlNullPath - Got a null path

fsfUmlPathSizeOverflow - File absolut path surpass the maximum length allowed

fsfUmlNullFilename - Got a null filename

fsfUmlOk - The absolut file path is valid

Description:

This function concatenates two file paths in order to obtain the absolut one.Case the absolut one is not valid, an error will be returned

*/

fsfUmlErrorType
FsfUmlGetAbsolutFileName (char * fsfUmlPath, char * fsfUmlFilename, char *fsfUmlAbsolutPath);


#endif

/*$RCSFiles*/
