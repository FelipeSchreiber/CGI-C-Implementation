/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
          
$Author: felipe.schreiber $
$Date: 2017/06/01 16:29:18 $
$Log: fsfUmlFunctions.c,v $
Revision 1.1  2017/06/01 16:29:18  felipe.schreiber
Initial revision
  

*/
/*link w/ -lcrypt*/
#include "fsfUmlFunctions.h"

/*
fsfUmlLanguageType
FsfUmlGetLanguageIndex (char * fsfUmlLanguage)


Arguments:

Char* - Pointer to the first string element. This string represents the language

chosen.(I)


Returned code:
0 case language choice is english or the input argument is invalid.
1 case language choice is portuguese.


Description:
This function returns an integer corresponding to the language defined.

*/

fsfUmlLanguageType
FsfUmlGetLanguageIndex (char * fsfUmlLanguage)
{
 if(fsfUmlLanguage == NULL)
  return(fsfUmlEnglish);

 if(!(strlen(fsfUmlLanguage)))
  return(fsfUmlEnglish);

 if(!(strcmp(fsfUmlLanguage,"fsfUmlEnglish")))
  return(fsfUmlEnglish);

 if(!(strcmp(fsfUmlLanguage,"fsflUmlPortuguese")))
  return(fsfUmlPortuguese);

 return(fsfUmlEnglish);
}

/*
 fsfUmlErrorType
 FsfUmlCheckStringField(char * fsfUmlStringField, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)


 Arguments:
 
 char *fsfUmlStringField - This argument corresponds to a pointer which points to the beginnig of a string(I)

 char *fsfValidCharacters - This argument corresponds to a pointer that points to the beginning of the string of valid characters. It means,
 a vector of valid characters (I)

 size_t fsfUmlMinimumLength - This argument corresponds to the minimum size required (I)

 size_t fsfUmlMaximumLength - This argument corresponds to the maximum size allowed (I)


 Returned code:

 fsfUmlNullStringField - If the pointer corresponding to fsfUmlName got the NULL value

 fsfUmlNullValidCharacters - If the pointer corresponding to fsfUmlValidCharacters got the NULL value

 fsfUmlInvalidCharacter - If a character in fsfUmlStringField isn't included at the fsfValidCharacters

 fsfUmlLengthOverflow - If fsfUmlFileame surpass fsfUmlMaximumLength characters

 fsfUmlLengthUnderflow - If fsfUmlStringField contains less then fsfUmlMaximumLength characters

 fsfUmlOk - If fsfUmlStringField is a valid string

 
 Description:

 This functions returns whether the string is valid or not arccording to the parameters specified. Case it isn't valid, an error code will
 be returned

*/
fsfUmlErrorType
FsfUmlCheckStringField(char * fsfUmlStringField, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)
{
 size_t fsfUmlNameCounter,fsfUmlValidCounter;
   
 if(fsfUmlStringField == NULL)
 {
  return(fsfUmlNullStringField);
 }

 if(fsfUmlValidCharacters == NULL)
 {
  return(fsfUmlNullValidCharacters);
 }

 for(fsfUmlNameCounter = 0;fsfUmlStringField[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++)
 {
  for(fsfUmlValidCounter = 0; ((fsfUmlStringField[fsfUmlNameCounter] != fsfUmlValidCharacters[fsfUmlValidCounter])
      && (fsfUmlValidCharacters[fsfUmlValidCounter] != '\0')); fsfUmlValidCounter++);
  
  if(fsfUmlValidCharacters[fsfUmlValidCounter] == '\0')
  {
   return(fsfUmlInvalidCharacter);
  } 
 }

 if((strlen(fsfUmlStringField) > fsfUmlMaximumLength))
 {
  return(fsfUmlLengthOverflow);
 }

 if((strlen(fsfUmlStringField) < fsfUmlMinimumLength))
 {
  return(fsfUmlLengthUnderflow);
 }
  
 return(fsfUmlOk);
}

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
FsfUmlFilenameValidation(char * fsfUmlFilename, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)
{
 #ifdef _MY_DEBUG_
  printf("\n_MY_DEBUG_ is set in fsfUmlFunctions.c\n");
  printf("\n FILENAME : %s\n LENGTH: %i\n",fsfUmlFilename,(int)strlen(fsfUmlFilename)); 
 #endif
 size_t fsfUmlNameCounter,fsfUmlValidCounter;
   
 if(fsfUmlFilename == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL FILENAME \n\n");
  #endif 
  return(fsfUmlNullFilename);
 }

 if(fsfUmlValidCharacters == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL VALID CHARACTERS \n\n");
  #endif 
  return(fsfUmlNullValidCharacters);
 }
/*
 for(fsfUmlNameCounter = 0;fsfUmlFilename[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++)
 {
  for(fsfUmlValidCounter = 0; ((fsfUmlFilename[fsfUmlNameCounter] != fsfUmlValidCharacters[fsfUmlValidCounter])
      && (fsfUmlValidCharacters[fsfUmlValidCounter] != '\0')); fsfUmlValidCounter++);
  
  if(fsfUmlValidCharacters[fsfUmlValidCounter] == '\0')
  {
   return(fsfUmlInvalidCharacter);
  } 
 }*/
 for(fsfUmlNameCounter = 0;fsfUmlFilename[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++)
 {
  for(fsfUmlValidCounter = 0; ((fsfUmlFilename[fsfUmlNameCounter] != fsfUmlValidCharacters[fsfUmlValidCounter])
      && (fsfUmlValidCharacters[fsfUmlValidCounter] != '\0')); fsfUmlValidCounter++);
  
  if(fsfUmlValidCharacters[fsfUmlValidCounter] == '\0')
  {
   #ifdef _MY_DEBUG_
    printf("\n\nInvalid Character : %c\n\n",fsfUmlFilename[fsfUmlNameCounter]);
   #endif 
   return(fsfUmlInvalidCharacter);
  } 
 }

 if((strlen(fsfUmlFilename)> fsfUmlMaximumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nLength : %i\n\n",(int) strlen(fsfUmlFilename));
  #endif 
  return(fsfUmlLengthOverflow);
 }

 if((strlen(fsfUmlFilename) < fsfUmlMinimumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nLength : %i\n\n",(int) strlen(fsfUmlFilename));
  #endif 
  return(fsfUmlLengthUnderflow);
 }
 #ifdef _MY_DEBUG_
  printf("\n NO ERRORS OCCURED\n");
 #endif
 return(fsfUmlOk);
}


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
FsfUmlCheckNickname(char * fsfUmlName, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)
{
 size_t fsfUmlNameCounter,fsfUmlValidCounter;
 unsigned fsfUmlGotDot = 0;
  
 if(fsfUmlName == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL NICKNAME\n\n");
  #endif 
  return(fsfUmlNullName);
 }

 if(fsfUmlValidCharacters == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL NICKNAME VALID CHARACTERS \n\n");
  #endif 
  return(fsfUmlNullValidCharacters);
 }

 for(fsfUmlNameCounter = 0;fsfUmlName[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++)
 {
  fsfUmlValidCounter = 0;
  
  while((fsfUmlName[fsfUmlNameCounter] != fsfUmlValidCharacters[fsfUmlValidCounter])&& (fsfUmlValidCharacters[fsfUmlValidCounter] != '\0'))
  {
   fsfUmlValidCounter++;
  }
  
  if(fsfUmlName[fsfUmlNameCounter] == '.')
  {
   fsfUmlGotDot++;
  }
 
  if(fsfUmlValidCharacters[fsfUmlValidCounter] == '\0')
  {
   #ifdef _MY_DEBUG_
    printf("\n\nInvalid Character : %c\n\n",fsfUmlName[fsfUmlNameCounter]);
   #endif 
   return(fsfUmlInvalidCharacter);
  } 
 
  if(fsfUmlGotDot > 1)
  {  
   #ifdef _MY_DEBUG_
    printf("\n\nDOT OVERFLOW\n\n");
   #endif 
   return(fsfUmlDotOverflow);
  }
 }

 if((strlen(fsfUmlName) > fsfUmlMaximumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nMaximum Length : %i\n\n",(int)fsfUmlMaximumLength);
  #endif 
  return(fsfUmlLengthOverflow);
 }

 if((strlen(fsfUmlName) < fsfUmlMinimumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nMinimum Length : %i\n\n",(int)fsfUmlMinimumLength);
  #endif 
  return(fsfUmlLengthUnderflow);
 }
 
 if(fsfUmlGotDot == 0)
 { 
  return fsfUmlZeroDots;
 }
  
 #ifdef _MY_DEBUG_
  printf("\n NO ERRORS OCCURED\n");
 #endif
 return(fsfUmlOk);
}

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
FsfUmlCheckEmail(char * fsfUmlEmail, char *fsfUmlValidCharacters,size_t fsfUmlMinimumLength,size_t fsfUmlMaximumLength)
{
 #ifdef _MY_DEBUG_
  printf("\n_MY_DEBUG_ is set in fsfUmlFunctions.c\n");
  printf("\n EMAIL : %s\n LENGTH: %i\n",fsfUmlEmail,(int)strlen(fsfUmlEmail)); 
 #endif
 size_t fsfUmlEmailCounter,fsfUmlValidCounter;
 unsigned fsfUmlGotAtSign = 0;
  
 if(fsfUmlEmail == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL EMAIL\n\n");
  #endif 
  return(fsfUmlNullEmail);
 }

 if(fsfUmlValidCharacters == NULL)
 {
  #ifdef _MY_DEBUG_
   printf("\n\nNULL EMAIL VALID CHARACTERS \n\n");
  #endif 
  return(fsfUmlNullValidCharacters);
 }

 for(fsfUmlEmailCounter = 0;fsfUmlEmail[fsfUmlEmailCounter] != '\0';fsfUmlEmailCounter++)
 {
  fsfUmlValidCounter = 0;
  
  while((fsfUmlEmail[fsfUmlEmailCounter] != fsfUmlValidCharacters[fsfUmlValidCounter]) && (fsfUmlValidCharacters[fsfUmlValidCounter] != '\0'))
  {
   fsfUmlValidCounter++;
  }
  
  if(fsfUmlEmail[fsfUmlEmailCounter] == '@')
  {
   fsfUmlGotAtSign++;
  }
 
  if(fsfUmlValidCharacters[fsfUmlValidCounter] == '\0')
  {
   #ifdef _MY_DEBUG_
    printf("\n\nInvalid Character : %c\n\n",fsfUmlEmail[fsfUmlEmailCounter]);
   #endif 
   return(fsfUmlInvalidCharacter);
  } 
 
  if(fsfUmlGotAtSign > 1)
  {
   #ifdef _MY_DEBUG_
    printf("\n\nAT SIGN OVERFLOW\n\n");
   #endif 
   return(fsfUmlAtSignOverflow);
  }
 }

 if((strlen(fsfUmlEmail) > fsfUmlMaximumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nMaximum Length : %i\n\n",(int)fsfUmlMaximumLength);
  #endif 
  return(fsfUmlLengthOverflow);
 }

 if((strlen(fsfUmlEmail) < fsfUmlMinimumLength))
 {
  #ifdef _MY_DEBUG_
   printf("\n\nMinimum Length : %i\n\n",(int)fsfUmlMaximumLength);
  #endif 
  return(fsfUmlLengthUnderflow);
 }
  
 if(fsfUmlGotAtSign == 0)
 { 
  return fsfUmlZeroAtSigns;
 }
 #ifdef _MY_DEBUG_
  printf("\n NO ERRORS OCCURED\n");
 #endif
 return(fsfUmlOk);
}

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
FsfUmlCreateRandomString (char *fsfUmlValidCharacters, size_t fsfUmlLength, char *fsfUmlRandomString)
{
 unsigned short fsfUmlIndex;
 
 if(fsfUmlRandomString == NULL)
 {
  return(fsfUmlNullRandomString);
 }

 if(fsfUmlValidCharacters == NULL)
 {
  return(fsfUmlNullValidCharacters);
 }

 if(fsfUmlLength == 0)
 {
  return(fsfUmlZeroLength);
 }

 srand ((unsigned) time (NULL));

 for (fsfUmlIndex = 0; fsfUmlIndex < fsfUmlLength; fsfUmlIndex++)
   fsfUmlRandomString[fsfUmlIndex] = fsfUmlValidCharacters[rand () % strlen (fsfUmlValidCharacters)];
 
 return(fsfUmlOk);
}

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
FsfUmlCreateNickname(char *fsfUmlName, char *fsfUmlNickname1, char *fsfUmlNickname2)
{
 int fsfUmlErrorNo = 0;
 size_t fsfUmlNameCounter,fsfUmlSpaceCounter;
 fsfUmlNameCounter = fsfUmlSpaceCounter = 0;
 
 if((fsfUmlErrorNo = FsfUmlCheckStringField(fsfUmlName,FSF_UML_USERNAME_,1,FSF_UML_FULLNAME_MAX_LENGTH)))
 {
  return(fsfUmlErrorNo);
 }

 while(fsfUmlName[0] == ' ')
 {
  memmove(fsfUmlName,&fsfUmlName[1],sizeof(fsfUmlName[1]));
 }
 
 for(fsfUmlNameCounter = 0; fsfUmlName[fsfUmlNameCounter] != '\0'; fsfUmlNameCounter++)
 {
  if(fsfUmlName[fsfUmlNameCounter] == ' ')
  {
   fsfUmlSpaceCounter++;
  
   while(fsfUmlName[fsfUmlNameCounter + 1] == ' ')
   {
    memmove(&fsfUmlName[fsfUmlNameCounter],&fsfUmlName[fsfUmlNameCounter + 1],sizeof(fsfUmlName[fsfUmlNameCounter + 1]));
   }
  }
 }

 while(fsfUmlName[strlen(fsfUmlName) - 1] == ' ')
 {
  fsfUmlName[strlen(fsfUmlName) - 1] = '\0';
  fsfUmlSpaceCounter--;
 }

 if((fsfUmlSpaceCounter == 0))
 {
  return(fsfUmlSurnameNotFound);
 }
 
 for(fsfUmlNameCounter = 0;fsfUmlName[fsfUmlNameCounter] != ' ';fsfUmlNameCounter++)
 {
  fsfUmlNickname1[fsfUmlNameCounter] = fsfUmlName[fsfUmlNameCounter];
 }
 
 fsfUmlNickname1[strlen(fsfUmlNickname1)] = '\0';

 for(fsfUmlNameCounter = (strlen(fsfUmlName) - 1);fsfUmlName[fsfUmlNameCounter] != ' '; fsfUmlNameCounter--);
 
 fsfUmlNickname1[strlen(fsfUmlNickname1)] = '.';
 fsfUmlNickname1[strlen(fsfUmlNickname1)] = '\0';
 
 strcpy(fsfUmlNickname2, fsfUmlNickname1);
 
 snprintf(&fsfUmlNickname1[strlen(fsfUmlNickname1)],(sizeof(fsfUmlName[fsfUmlNameCounter])),"%s",&fsfUmlName[fsfUmlNameCounter]);
 
 while(strlen(fsfUmlNickname1) > 65)
 {
  fsfUmlNickname1[strlen(fsfUmlNickname1) - 1] = '\0'; 
 }
 
 if(fsfUmlSpaceCounter == 1)
 {
  fsfUmlNickname2 = NULL;
  return(fsfUmlOk);
 }
 
 for(;fsfUmlName[fsfUmlNameCounter] != ' '; fsfUmlNameCounter--);
 
 fsfUmlNameCounter++;

 for(;fsfUmlName[fsfUmlNameCounter] != ' '; fsfUmlNameCounter++)
 {
  fsfUmlNickname2[strlen(fsfUmlNickname2)] = fsfUmlName[fsfUmlNameCounter];
 }
  
 while((strlen(fsfUmlNickname2) > 65))
 {
  fsfUmlNickname2[strlen(fsfUmlNickname2) - 1] = '\0'; 
 }

 for(fsfUmlNameCounter = 0;fsfUmlNickname1[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++);
 {
  fsfUmlNickname1[fsfUmlNameCounter] = (char) tolower((unsigned char)fsfUmlNickname1[fsfUmlNameCounter]); 
 }

 for(fsfUmlNameCounter = 0;fsfUmlNickname2[fsfUmlNameCounter] != '\0';fsfUmlNameCounter++);
 {
  fsfUmlNickname2[fsfUmlNameCounter] = (char) tolower((unsigned char)fsfUmlNickname2[fsfUmlNameCounter]); 
 }

 return(fsfUmlOk);
}

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

fsfUmlNullCrypted - If the encrypted string got NULL value

fsfUmlNullId - If the Id got NULL value

fsfUmlOk - If no problems ocurred


Description:

This function identifies which crypting algorithm was used to generate the password
*/

fsfUmlErrorType
FsfUmlGetCryptAlgorithm (char *fsfUmlCrypted,fsfUmlCryptAlgorithmsTypes *fsfUmlId)
{
 char fsfUmlSalt[16];
 size_t fsfUmlCounter = 0;

 if(!fsfUmlCrypted)
  return(fsfUmlNullCrypted);
 
 if(!fsfUmlId)
  return(fsfUmlNullId);

 if(fsfUmlCrypted[0] != '$')
 {
  if(!(FsfUmlCheckStringField(fsfUmlCrypted,FSF_VALID_CRYPTED_,1,13)))
  {
   fsfUmlId = fsfUmlDes;
   return(fsfUmlOk);
  }
  return(fsfUmlInvalidCrypt);
 }

 if(strlen(fsfUmlCrypted) < 7)
 {
  return(fsfUmlInvalidCryptLength);
 }
  
 if(fsfUmlCrypted[0] != '$')
 {
  return(fsfUmlInvalidCrypt);
 }

 if(fsfUmlCrypted[2] != '$')
 {
  return(fsfUmlInvalidCrypt);
 }

 if(fsfUmlCrypted[5] != '$')
 {
  return(fsfUmlInvalidCrypt);
 }
 
 if((fsfUmlCrypted[1] != '1') && (fsfUmlCrypted[1] != '5')  && (fsfUmlCrypted[1] != '6'))
 {
  return(fsfUmlInvalidId);
 }
 
 for(fsfUmlCounter = 3; fsfUmlCrypted[fsfUmlCounter] != '$'; fsfUmlCounter++)
 {
  fsfUmlSalt[fsfUmlCounter - 3] = fsfUmlCrypted[fsfUmlCounter];
 }
 
 fsfUmlSalt[strlen(fsfUmlSalt)] = '\0';

 if(FsfUmlCheckStringField(fsfUmlSalt,FSF_VALID_CRYPTED_,1,16))
 {
  return(fsfUmlInvalidSalt);
 }

 if(FsfUmlCheckStringField(fsfUmlSalt,FSF_VALID_CRYPTED_,1,16))
 {
  return(fsfUmlInvalidSalt);
 }
 
 if(FsfUmlCheckStringField(&fsfUmlCrypted[6],FSF_VALID_CRYPTED_,22,86))
 {
  return(fsfUmlInvalidEncrypted);
 }

 if((fsfUmlCrypted[1]=='1') && (strlen (&fsfUmlCrypted[6]) == 22))
 {
  *fsfUmlId = fsfUmlMd5;
  return(fsfUmlOk);
 }

 if((fsfUmlCrypted[1]=='5') && (strlen (&fsfUmlCrypted[6])== 43))
 {
  *fsfUmlId = fsfUmlSha256;
  return(fsfUmlOk);
 }

 if((fsfUmlCrypted[1]=='6') && (strlen (&fsfUmlCrypted[6])== 86))
 {
  *fsfUmlId = fsfUmlSha512;
  return(fsfUmlOk);
 }

 return(fsfUmlInvalidCryptLength);
}


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

fsfUmlNullCrypted - If the encrypted string got NULL value

fsfUmlOk - No problems ocurred


Description:

This function takes user's password and the chosen crypt algorithm to generate an encrypted one.
*/
fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificAlgorithm(char *fsfUmlPasswd,fsfUmlCryptAlgorithmsTypes fsfUmlId,char *fsfUmlEncrypted)
{
 
 char fsfUmlSalt[16];

 if(!fsfUmlEncrypted)
  return(fsfUmlNullCrypted);

 if(FsfUmlCheckStringField(fsfUmlPasswd,FSF_UML_PASSWORD_,FSF_UML_PASSWORD_MIN_LENGTH,FSF_UML_PASSWORD_MAX_LENGTH))
 {
  return(fsfUmlInvalidPasswd);
 }

 if(fsfUmlId == fsfUmlDes)
 {
  fsfUmlSalt[2] = '\0';
  FsfUmlCreateRandomString (FSF_VALID_CRYPTED_,2,fsfUmlSalt);
  /*snprintf(fsfUmlSalt[strlen(fsfUmlSalt)],sizeof(fsfUmlPasswd),"%s",fsfUmlPasswd);*/
  fsfUmlEncrypted = crypt((const char *)&fsfUmlPasswd,(const char *)&fsfUmlSalt);
  return(fsfUmlOk);
 }
 
 if(fsfUmlId == fsfUmlMd5)
 {
  fsfUmlSalt[strlen(fsfUmlSalt)] = '\0';
  FsfUmlCreateRandomString (FSF_VALID_CRYPTED_,8,fsfUmlSalt);
  snprintf((char *)fsfUmlSalt,sizeof(fsfUmlSalt),"$1$%s$",fsfUmlSalt);
  fsfUmlEncrypted = crypt((char *)fsfUmlPasswd,(char *)fsfUmlSalt);
  return(fsfUmlOk);
 }

 if(fsfUmlId == fsfUmlSha256)
 {
  fsfUmlSalt[strlen(fsfUmlSalt)] = '\0';
  FsfUmlCreateRandomString (FSF_VALID_CRYPTED_,16,fsfUmlSalt);
  snprintf(fsfUmlSalt,sizeof(fsfUmlSalt),"$5$%s$",fsfUmlSalt);
  fsfUmlEncrypted = crypt(fsfUmlPasswd,fsfUmlSalt);
  return(fsfUmlOk);
 }

 if(fsfUmlId == fsfUmlSha512)
 {
  fsfUmlSalt[strlen(fsfUmlSalt)] = '\0';
  FsfUmlCreateRandomString (FSF_VALID_CRYPTED_,16,fsfUmlSalt);
  snprintf(fsfUmlSalt,sizeof(fsfUmlSalt),"$6$%s$",fsfUmlSalt);
  fsfUmlEncrypted = crypt(fsfUmlPasswd,fsfUmlSalt);
  return(fsfUmlOk);
 } 
 return(fsfUmlInvalidId);
}

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

fsfUmlNullEncrypted - If the encrypted string got NULL value

fsfUmlNullSalt - If the salt got NULL value

fsfUmlOk - No problems ocurred


Description:

This functon takes the user's password and the chosen salt to encrypt the information
*/

fsfUmlErrorType
FsfUmlEncodePasswordWithSpecificSalt(char *fsfUmlPasswd, char *fsfUmlSalt, char *fsfUmlEncrypted)
{
   
 char fsfUmlSaltVector[16];
 size_t fsfUmlCounter = 0;

 if(fsfUmlSalt == NULL)
 {
  return(fsfUmlNullSalt); 
 }
 
 if(!fsfUmlEncrypted)
  return(fsfUmlNullCrypted);

 if(FsfUmlCheckStringField(fsfUmlPasswd,FSF_UML_PASSWORD_,FSF_UML_PASSWORD_MIN_LENGTH,FSF_UML_PASSWORD_MAX_LENGTH))
 {
  return(fsfUmlInvalidPasswd);
 }

 if((fsfUmlSalt[1] != 0) && (fsfUmlSalt[1] != '1') && (fsfUmlSalt[1] != '5')  && (fsfUmlSalt[1] != '6'))
 {
  return(fsfUmlInvalidId);
 }
 
 for(fsfUmlCounter = 3; fsfUmlSalt[fsfUmlCounter] != '$'; fsfUmlCounter++)
 {
  fsfUmlSaltVector[fsfUmlCounter - 3] = fsfUmlSalt[fsfUmlCounter];
 }

 if(FsfUmlCheckStringField(fsfUmlSaltVector,FSF_VALID_CRYPTED_,1,16))
 {
  return(fsfUmlInvalidSalt);
 }
 
 fsfUmlEncrypted = crypt(fsfUmlPasswd,fsfUmlSalt);

 return(fsfUmlOk);
}
/*
fsfUmlErrorType
FsfUmlCheckPassword (char *fsfUmlPasswd, char *fsfUmlEncrypted)


Arguments:

char *fsfUmlPasswd - This is a not encrypted password (I)

char *fsfUmlEncrypted - This is the encrypted password (I)


Returned code:

fsfUmlErrorNo - If an error occurred in function FsfUmlGetCryptAlgorithm(char*,char*)

fsfUmlIncompatiblePassword - If the passwords are not equivalent

fsfUmlNullEncrypted - If the encrypted string got NULL value

fsfUmlOk - The passwords are equivalent


Description:

This function encrypt the given password taking the same salt value as the encrypted one.
After encrypting, this function compares if the result is the same.


*/
fsfUmlErrorType
FsfUmlCheckPassword (char *fsfUmlPasswd, char *fsfUmlEncrypted)
{
 int fsfUmlErrorNo = 0;
 char fsfUmlSaltVector[16];
 size_t fsfUmlGot$,fsfUmlCounter;
 fsfUmlGot$ = fsfUmlCounter = 0;
 fsfUmlCryptAlgorithmsTypes fsfUmlId;
 
 if((fsfUmlErrorNo = FsfUmlGetCryptAlgorithm(fsfUmlPasswd,&fsfUmlId)))
 {
  return(fsfUmlErrorNo);
 }
 
 if(!fsfUmlEncrypted)
  return(fsfUmlNullCrypted);

 if(fsfUmlEncrypted[0] != '$')
 {
  fsfUmlSaltVector[0] = fsfUmlEncrypted[0];
  fsfUmlSaltVector[1] = fsfUmlEncrypted[1];
  fsfUmlSaltVector[2] = '\0';

  if(strcmp(crypt(fsfUmlPasswd,fsfUmlSaltVector),fsfUmlEncrypted))
  {
   return(fsfUmlIncompatiblePassword);
  } 
  return(fsfUmlOk);
 }

 for(fsfUmlCounter = 0;((fsfUmlEncrypted[fsfUmlCounter] != '\0') && (fsfUmlGot$ < 3));fsfUmlCounter++)
 { 
  fsfUmlSaltVector[fsfUmlCounter] = fsfUmlEncrypted[fsfUmlCounter];
  if(fsfUmlEncrypted[fsfUmlCounter] == '$')
  {  
   fsfUmlGot$++;
  }
 }
 
 fsfUmlSaltVector[strlen(fsfUmlSaltVector)] = '\0';

 if(strcmp(crypt(fsfUmlPasswd,fsfUmlSaltVector),fsfUmlEncrypted))
 {
  return(fsfUmlIncompatiblePassword);
 } 
 return(fsfUmlOk);
}

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
FsfUmlGetConfigurationOptionsValues (char *fsfUmlConfigFilename, fsfUmlConfigurationOptionsType* fsfUmlConfigurations)
{
 int fsfUmlErrNo,fsfUmlCounter,fsfUmlPosition;
 char fsfUmlBuffer[2050],fsfUmlTemporaryBuffer[2050];
 FILE * fsfUmlFilePointer;

 char *fsfUmlConfigOptions[] = 
 {
  "fsf-uml-administrator-user-identifier",
  "fsf-uml-private-root-directory",
  "fsf-uml-data-directory",
  "fsf-uml-cookies-directory",
  "fsf-uml-users-data-filename",
  "fsf-uml-invited-users-data-filename",
  "fsf-uml-requesting-users-data-filename",
  "fsf-uml-locked-users-data-filename"
 };

 if(!fsfUmlConfigurations)
  return(fsfUmlNullConfigurationData);

 fsfUmlConfigurations->fsfUmlUserId = FSF_UML_ADMINISTRATOR_USER_IDENTIFIER;
 strcpy(fsfUmlConfigurations->fsfUmlPrivateRootDirectory,FSF_UML_PRIVATE_ROOT_DIRECTORY);
 strcpy(fsfUmlConfigurations->fsfUmlDataDirectory,FSF_UML_DATA_DIRECTORY);
 strcpy(fsfUmlConfigurations->fsfUmlCookiesDirectory,FSF_UML_COOKIES_DIRECTORY);
 strcpy(fsfUmlConfigurations->fsfUmlUsersDataFilename,FSF_UML_USERS_DATA_FILENAME);
 strcpy(fsfUmlConfigurations->fsfUmlInvitedUsersDataFilename,FSF_UML_INVITED_USERS_DATA_FILENAME);
 strcpy(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,FSF_UML_REQUESTING_USERS_DATA_FILENAME);
 strcpy(fsfUmlConfigurations->fsfUmlLockedUsersDataFilename,FSF_UML_LOCKED_USERS_DATA_FILENAME);
 
 fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlConfigFilename,FSF_UML_VALID_FILENAME_,1,FSF_UML_FILEPATH_MAX_LENGTH);
 
 if(fsfUmlErrNo)
  return(fsfUmlErrNo);
 
 if(!(fsfUmlFilePointer = fopen(fsfUmlConfigFilename,"r")))
 {
  printf ("Erro abrindo o arquivo: \"%s\"\n",fsfUmlConfigFilename);
  printf ("Erro (#%i): %s\n", errno, strerror (errno));
  return (fsfUmlFileOpeningError);
 }
 
 while ((fgets (fsfUmlBuffer,2050,fsfUmlFilePointer)) != NULL)
 {
    if (fsfUmlBuffer[strlen (fsfUmlBuffer) - 1] == '\n')
      fsfUmlBuffer [strlen (fsfUmlBuffer) - 1] = '\0';

    if (strlen (fsfUmlBuffer) > 2048)
    {
      printf ("Arquivo corrompido\nLinha muito longa\n");
      fclose (fsfUmlFilePointer);
      remove (fsfUmlConfigFilename);
      return(fsfUmlFileReadingError);
    }
   
    if(fsfUmlBuffer[0] != '#')
    {
     if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[0],strlen(fsfUmlConfigOptions[0])))
     {
      for(fsfUmlCounter = 0;(fsfUmlBuffer[fsfUmlCounter] != '=');fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlTemporaryBuffer[fsfUmlCounter - fsfUmlPosition] = fsfUmlBuffer[fsfUmlCounter];
      }
           
      fsfUmlConfigurations->fsfUmlUserId = strtod(fsfUmlTemporaryBuffer,NULL);
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[1],strlen(fsfUmlConfigOptions[1])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlPrivateRootDirectory[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
       if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlConfigurations->fsfUmlPrivateRootDirectory,
                        FSF_VALID_FILEPATH_,1,FSF_UML_FILEPATH_MAX_LENGTH)))
        return(fsfUmlErrNo); 
       
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[2],strlen(fsfUmlConfigOptions[2])))
     { 
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlDataDirectory[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
       if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlConfigurations->fsfUmlDataDirectory,FSF_VALID_FILEPATH_,1,FSF_UML_FILEPATH_MAX_LENGTH)))
        return(fsfUmlErrNo); 
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[3],strlen(fsfUmlConfigOptions[3])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlCookiesDirectory[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
      if((fsfUmlErrNo=FsfUmlCheckStringField(fsfUmlConfigurations->fsfUmlCookiesDirectory,FSF_VALID_FILEPATH_,1,FSF_UML_FILEPATH_MAX_LENGTH)))
       return(fsfUmlErrNo); 
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[4],strlen(fsfUmlConfigOptions[4])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlUsersDataFilename[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlUsersDataFilename,
                       FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
       return(fsfUmlErrNo);
     }

     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[5],strlen(fsfUmlConfigOptions[5])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlInvitedUsersDataFilename[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlInvitedUsersDataFilename,
                                                FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
       return(fsfUmlErrNo);
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[6],strlen(fsfUmlConfigOptions[6])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename,
                                                FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
       return(fsfUmlErrNo);
     }
    
     else if(!strncmp(fsfUmlBuffer,fsfUmlConfigOptions[7],strlen(fsfUmlConfigOptions[7])))
     {
      for(fsfUmlCounter = 0;fsfUmlBuffer[fsfUmlCounter] != '=';fsfUmlCounter++);
      fsfUmlCounter++;
      fsfUmlPosition = fsfUmlCounter;
      for(;(fsfUmlBuffer[fsfUmlCounter] != ' ') && (fsfUmlBuffer[fsfUmlCounter] != '\0')
            && (fsfUmlBuffer[fsfUmlCounter] != '\n');fsfUmlCounter++)
      {
       fsfUmlConfigurations->fsfUmlLockedUsersDataFilename[fsfUmlPosition - fsfUmlCounter] = fsfUmlBuffer[fsfUmlCounter];
      }
      
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlConfigurations->fsfUmlLockedUsersDataFilename,
                                                FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH)))
       return(fsfUmlErrNo);
        
     }
     else
      return(fsfUmlUnrecognizedConfigurationOption);
    }
 
 }  
 
 if (ferror (fsfUmlFilePointer))
 {
  printf ("Erro lendo arquivo: \"%s\"\n",fsfUmlConfigFilename);
  printf ("Erro (#%i): %s\n", errno, strerror (errno));
  fclose (fsfUmlFilePointer);
  return(fsfUmlFileReadingError);
 }
 
 fclose (fsfUmlFilePointer);
  
 return(fsfUmlOk);
}

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
FsfUmlPrintWindowMoveCursor(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,fsfUmlUserInterfaceMessageNumberType fsfUmlMessage,WINDOW *fsfUmlWindow,char *fsfUmlString,int fsfUmlMaxRow)
{
 int fsfUmlCursorY,fsfUmlCursorX;
 
 if((wprintw(fsfUmlWindow,"\n%s\n", FsfUmlGetNcursesUserInterfaceMessage(fsfUmlField,fsfUmlLanguage))) != OK)
  return fsfUmlErrorPrintingWindow;
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\n0 Refresh\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
 
 if((wrefresh(fsfUmlWindow)) != OK)
 {
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\n1 Refresh\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
  return fsfUmlErrorReloadingWindow;
 }
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nSurpass the first REFRESH\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
 getyx(fsfUmlWindow,fsfUmlCursorY,fsfUmlCursorX);
 wattron(fsfUmlWindow,A_BOLD|A_UNDERLINE);
 
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nMVWPRINTW ARG. : &WINDOW = %i, MaxRow= %i, String= %s \n",fsfUmlWindow,fsfUmlMaxRow,FsfUmlGetNcursesUserInterfaceMessage(fsfUmlMessage,fsfUmlLanguage));
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 

 if((mvwprintw(fsfUmlWindow,fsfUmlMaxRow - 5,1,"%s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlMessage,fsfUmlLanguage))) != OK)
  return fsfUmlErrorPrintingWindow;
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nMVWPRINTW OK\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
 
 if(((wrefresh(fsfUmlWindow)) != OK))
 {
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\n2 Refresh\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
  return fsfUmlErrorReloadingWindow;
 }
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nSurpass the second REFRESH\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
    
 if((wmove(fsfUmlWindow,fsfUmlCursorY,fsfUmlCursorX)) != OK)
  return fsfUmlErrorMovingCursor;

 if((wgetstr(fsfUmlWindow,fsfUmlString)) != OK)
  return fsfUmlErrorGettingString;
 
 if((wrefresh(fsfUmlWindow)) != OK)
 {
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\n3 Refresh\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
  return fsfUmlErrorReloadingWindow;
 }
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nSurpass the third REFRESH\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
 
 wattroff(fsfUmlWindow,A_BOLD|A_UNDERLINE);

 if((wrefresh(fsfUmlWindow)) != OK)
 {
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\n4 Refresh\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
  return fsfUmlErrorReloadingWindow;
 }
  #ifdef _MY_DEBUG_
   wclear(fsfUmlWindow);
   wprintw(fsfUmlWindow,"\nSurpass the forth REFRESH\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);
  #endif 
 return fsfUmlOk;
}

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
FsfUmlPrintWindow(fsfUmlLanguageType fsfUmlLanguage,fsfUmlUserInterfaceMessageNumberType fsfUmlField,WINDOW* fsfUmlWindow,char* fsfUmlString)
{
 if((wprintw(fsfUmlWindow,"%s\n", FsfUmlGetNcursesUserInterfaceMessage(fsfUmlField,fsfUmlLanguage))) != OK)
  return fsfUmlErrorPrintingWindow;
 
 if((wrefresh(fsfUmlWindow)) != OK)
  return fsfUmlErrorReloadingWindow; 
 
 wattron(fsfUmlWindow,A_BOLD|A_UNDERLINE);

 if((wprintw(fsfUmlWindow,"%s\n",fsfUmlString)) != OK)
  return fsfUmlErrorPrintingWindow;

 wattroff(fsfUmlWindow,A_BOLD|A_UNDERLINE);
 
 if((wrefresh(fsfUmlWindow)) != OK)
  return fsfUmlErrorReloadingWindow;
 
 return fsfUmlOk;
}

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
FsfUmlNcursesLogin(fsfUmlLanguageType fsfUmlLanguage,WINDOW* fsfUmlWindow,WINDOW* fsfUmlBorder,char* fsfUmlGetNickname,char* fsfUmlPassword,boolean *fsfUmlExit)
{
 int fsfUmlUserInput,fsfUmlMaxRow,fsfUmlMaxColumn;
 int fsfUmlErrNo;
 
 if(!fsfUmlWindow)
  return fsfUmlNullWindow;

 if(!fsfUmlBorder)
  return fsfUmlNullBorder;
 
 if(FsfUmlCheckStringField(fsfUmlPassword,FSF_UML_PASSWORD_,FSF_UML_PASSWORD_MIN_LENGTH,FSF_UML_PASSWORD_MAX_LENGTH) ==
    fsfUmlNullStringField)
  return fsfUmlNullStringField;

 if(FsfUmlCheckNickname(fsfUmlGetNickname,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH) ==
    fsfUmlNullStringField)
  return fsfUmlNullStringField; 

 if(!fsfUmlExit)
  return fsfUmlNullExit;

 getmaxyx(fsfUmlWindow,fsfUmlMaxRow,fsfUmlMaxColumn); 

 while((FsfUmlCheckNickname(fsfUmlGetNickname,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)) && ((fsfUmlUserInput) != 27))
 {
  fsfUmlGetNickname[0] = '\0';
  wclear(fsfUmlWindow);
  if((fsfUmlErrNo = FsfUmlPrintWindowMoveCursor(fsfUmlLanguage,fsfUmlInsertNickname,fsfUmlNicknameWarning,fsfUmlWindow,fsfUmlGetNickname,fsfUmlMaxRow)))
   return fsfUmlErrNo;

  noecho();
  fsfUmlUserInput = wgetch(fsfUmlWindow);
  wrefresh(fsfUmlWindow);
  echo();
 }
 fsfUmlGetNickname[strlen(fsfUmlGetNickname)] = '\0';

 if(fsfUmlUserInput == 27)
 {
  fsfUmlGetNickname[0] = '\0';

  wclear(fsfUmlWindow);
  wclear(fsfUmlBorder);
  wrefresh(fsfUmlWindow);
  wrefresh(fsfUmlBorder);    
  
  if(delwin(fsfUmlWindow) != OK)
   return(fsfUmlErrorClosingWindow);
  if(delwin(fsfUmlBorder) != OK)
   return(fsfUmlErrorClosingWindow);
  
  *fsfUmlExit = fsfUmlTrue;
 }/*The nickname was invalid and the user decided to quit*/
 else
 {
  while((FsfUmlCheckStringField(fsfUmlPassword,FSF_UML_PASSWORD_,FSF_UML_PASSWORD_MIN_LENGTH,FSF_UML_PASSWORD_MAX_LENGTH)) && ((fsfUmlUserInput) != 27))
  {
   fsfUmlPassword[0] ='\0';   
   wclear(fsfUmlWindow);
   
   if((fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlInsertNickname,fsfUmlWindow,fsfUmlGetNickname)))
    return fsfUmlErrNo;
  
   if((fsfUmlErrNo = FsfUmlPrintWindowMoveCursor(fsfUmlLanguage,fsfUmlInsertPassword,fsfUmlPasswordWarning,fsfUmlWindow,fsfUmlPassword,fsfUmlMaxRow)))
   {
    #ifdef _MY_DEBUG_
    mvwprintw(fsfUmlWindow,0,0,"\nVai sair da funcao.Erro: %i",fsfUmlErrNo);
    wrefresh(fsfUmlWindow);   
    delay_output(10000);
    #endif
    return fsfUmlErrNo;
   }
  
   noecho();
   fsfUmlUserInput = wgetch(fsfUmlWindow);
   wrefresh(fsfUmlWindow);
   echo();
  }/*The nickname was incorrect, and the user decided to keep the login process*/
  
  #ifdef _MY_DEBUG_
  wprintw(fsfUmlWindow,"\nSeg. Fault2?");
  wrefresh(fsfUmlWindow);
  delay_output(3000);  
  #endif

  wclear(fsfUmlWindow);
  if(fsfUmlUserInput == 27)
  {
   fsfUmlGetNickname[0] = '\0';
   fsfUmlPassword[0] ='\0';
 
   wclear(fsfUmlWindow);
   wclear(fsfUmlBorder);
   wrefresh(fsfUmlWindow);
   wrefresh(fsfUmlBorder);

   if(delwin(fsfUmlWindow) != OK)
    return(fsfUmlErrorClosingWindow);
   if(delwin(fsfUmlBorder) != OK)
    return(fsfUmlErrorClosingWindow);
 
   *fsfUmlExit = fsfUmlTrue;
  }
  else
  { 
   if((fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlInsertNickname,fsfUmlWindow,fsfUmlGetNickname)))
    return fsfUmlErrNo;
  
   wprintw(fsfUmlWindow,"\n%s\n",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlInsertPassword,fsfUmlLanguage));
   wattron(fsfUmlWindow,A_BOLD|A_UNDERLINE);
   wprintw(fsfUmlWindow,"%s",fsfUmlPassword);  
   wrefresh(fsfUmlWindow);

   getmaxyx(fsfUmlWindow,fsfUmlMaxRow,fsfUmlMaxColumn);
   mvwprintw(fsfUmlWindow,fsfUmlMaxRow - 2,fsfUmlMaxColumn - 10,"%s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlEnter,fsfUmlLanguage));
   wattroff(fsfUmlWindow,A_BOLD|A_UNDERLINE);
   wrefresh(fsfUmlWindow);
   wgetch(fsfUmlWindow);
   
   *fsfUmlExit = fsfUmlFalse;
  
   #ifdef _MY_DEBUG_
   wprintw(fsfUmlWindow,"\nSeg. Fault3?");
   wrefresh(fsfUmlWindow);
   delay_output(3000);  
   #endif
  } /*else ends*/
 } 
 return fsfUmlOk;
}

/*
fsfUmlErrorType
FsfUmlInitializeWindows(WINDOW **fsfUmlBorder,WINDOW **fsfUmlSecondaryWindow)


Arguments: 

*fsfUmlBorder: this is a pointer to the border window (I)

*fsfUmlSecondaryWindow: this is a pointer to the secondary border(I)


Returned code:

fsfUmlWborderErr: If the function (wborder) to set the window border fails

fsfUmlErrorReloadingWindow: If the function(wrefresh) to reload the current window fails


Description:

This function creates a secondary window and also set a border to it
*/
fsfUmlErrorType
FsfUmlInitializeWindows(WINDOW **fsfUmlBorder,WINDOW **fsfUmlSecondaryWindow)
{
 *fsfUmlBorder = newwin(17,FSF_UML_NICKNAME_MAX_LENGTH + 5,3,3);
 if((wborder(*fsfUmlBorder,'F','F','S','S','F','S','F','S')) != OK)
  return fsfUmlWborderErr;
 if(wrefresh(*fsfUmlBorder) != OK)
  return fsfUmlErrorReloadingWindow;
 *fsfUmlSecondaryWindow = newwin(15,FSF_UML_NICKNAME_MAX_LENGTH + 3,4,4);

 return fsfUmlOk;
}

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
int fsfUmlUserInput,fsfUmlLanguageType fsfUmlLanguage)
{
 int fsfUmlCounter;
 fsfUmlCounter = 0;
 
 do
 {
  if((wprintw(*fsfUmlWindow,"%s\n",FsfUmlGetNcursesUserInterfaceMessage(0,fsfUmlLanguage))) != OK)
   return fsfUmlErrorPrintingWindow;

  fsfUmlCounter = fsfUmlCounterMinValue;

  while(fsfUmlCounter < (fsfUmlCounterMaxValue + 1))
  {
   if(fsfUmlCounter == *fsfUmlUnderline)
   {
    wattron(*fsfUmlWindow,A_UNDERLINE);
    if((wprintw(*fsfUmlWindow, "\n %s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlCounter,fsfUmlLanguage))) != OK)
     return fsfUmlErrorPrintingWindow;
    wattroff(*fsfUmlWindow,A_UNDERLINE);
   }
   else
    if((wprintw(*fsfUmlWindow, "\n %s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlCounter,fsfUmlLanguage))) != OK)
     return fsfUmlErrorPrintingWindow;
  
   fsfUmlCounter++;
  }
  
  wrefresh(*fsfUmlWindow);
  
  fsfUmlUserInput = wgetch(*fsfUmlWindow);
  
  switch(fsfUmlUserInput)
  {
   case(KEY_UP):
   {
    if(*fsfUmlUnderline == fsfUmlCounterMinValue)
     *fsfUmlUnderline = fsfUmlCounterMaxValue;
    else
     (*fsfUmlUnderline)--;
   }
   break;
   
   case(KEY_DOWN):
   {
    if(*fsfUmlUnderline == fsfUmlCounterMaxValue)
     *fsfUmlUnderline = fsfUmlCounterMinValue;
    else
     (*fsfUmlUnderline)++;
   }
   break;
 
   default:
   /*mvwprintw(fsfUmlWindow,,"Unrecognized key.Only KEY_UP,KEY_DOWN and ENTER are allowed");*/
   break;
  }
  wclear(*fsfUmlWindow);
 }while(fsfUmlUserInput != 10);/*This is the code associated with KEY_ENTER*/
 
 return fsfUmlOk;
}

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
FsfUmlGetAbsolutFileName (char * fsfUmlPath, char * fsfUmlFilename, char *fsfUmlAbsolutPath)
{
 unsigned fsfUmlErrorNo = 0;
 char fsfUmlTerminatingCharacters[2] = {'/','\0'};
 if(fsfUmlPath == NULL)
 {
  return (fsfUmlNullPath);
 }

 if(fsfUmlFilename == NULL)
 {
  return (fsfUmlNullFilename);
 }

 if(fsfUmlPath[strlen(fsfUmlPath) - 1] != '/')
 {
  snprintf(&fsfUmlPath[strlen(fsfUmlPath)],2,"%s",fsfUmlTerminatingCharacters);
 }

 if((strlen(fsfUmlPath) + strlen(fsfUmlFilename)) > FSF_UML_FILEPATH_MAX_LENGTH)
 {
  return (fsfUmlPathSizeOverflow);
 }
 
 if((fsfUmlErrorNo = (FsfUmlFilenameValidation(fsfUmlFilename,FSF_UML_VALID_FILENAME_,1,FSF_UML_FILENAME_MAX_LENGTH))))
 {
  return(fsfUmlErrorNo);
 } 
 
 if((fsfUmlErrorNo = (FsfUmlFilenameValidation(fsfUmlPath,FSF_VALID_FILEPATH_,1,FSF_UML_FILEPATH_MAX_LENGTH))))
 {
  return(fsfUmlErrorNo);
 } 

 snprintf(&fsfUmlPath[strlen(fsfUmlPath)],sizeof(fsfUmlFilename),"%s",fsfUmlFilename);

 return(fsfUmlOk);  
}
 

/* $RCSFiles */
