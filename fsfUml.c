/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$
  
*/

#define _XOPEN_SOURCE 500
#include <assert.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fsfUmlAddUser.h"
#include "fsfUmlFunctions.h"
#include "fsfUmlErrors.h"
#include "fsfUmlConst.h"
#include "fsfUmlTypes.h"
#include "fsfUmlRunNcursesInterface.h"
#include "fsfUmlGetPendingRegistrationRequestsPerUser.h"
#include "fsfUmlGetPendingRegistrationRequests.h"
#include <unistd.h>
#include <sys/types.h>

typedef enum
{
 fsfUmlConfigurationFileArgument,
 fsfUmlUserArgument,
 fsfUmlUserNameArgument,
 fsfUmlUserNameConfirmationArgument,
 fsfUmlEmailArgument,
 fsfUmlEmailConfirmationArgument,
 fsfUmlFriendEmailArgument,
 fsfUmlNicknameArgument,
 fsfUmlProfileArgument,
 fsfUmlLanguageArgument,
 fsfUmlPasswdArgument,
}fsfUmlArgumentIndexType;

int
main (int argc, char **argv)
{
opterr = 0;
const char *fsfUmlShortOptions = "hNCaitjnoqQvdUluprmecgsS";
struct option fsfUmlLongOptions [ ] = 
{
 {"help",no_argument, NULL, 'h'},
 {"Ncurses", no_argument, NULL, 'N'},
 {"Configure", no_argument, NULL, 'C'},
 {"add", no_argument, NULL, 'a'},
 {"invite", no_argument, NULL, 'i'}, 
 {"accept", no_argument, NULL, 't'},
 {"reject", no_argument, NULL, 'j'},
 {"new", no_argument, NULL, 'n'},
 {"options", no_argument, NULL, 'o'},
 {"request", no_argument, NULL, 'q'},
 {"Request", no_argument, NULL, 'Q'},
 {"approve", no_argument, NULL, 'v'},
 {"disapprove", no_argument, NULL, 'd'},
 {"Unlocking", no_argument, NULL, 'U'},
 {"lock", no_argument, NULL, 'l'},
 {"unlock", no_argument, NULL, 'u'},
 {"password", no_argument, NULL, 'p'},
 {"reset", no_argument, NULL, 'r'},
 {"modify", no_argument, NULL, 'm'},
 {"edit", no_argument, NULL, 'e'},
 {"confirm", no_argument, NULL, 'c'},
 {"group", no_argument, NULL, 'g'},
 {"show", no_argument, NULL, 's'},
 {"Search", no_argument, NULL, 'S'},
 {NULL, 0, NULL, 0}
};

char *fsfUmlArgumentNames [ ] =
{
 "configuration\0",
 "user\0",
 "username\0",
 "confirm-username\0",
 "email\0",
 "confirm-email\0",
 "friend-email\0",
 "nickname\0",
 "profile\0",
 "language\0",
 "key\0",
 NULL
};

int fsfUmlShortOption,fsfUmlLongOption,fsfUmlArgumentIndex,fsfUmlErrNo;
char *fsfUmlArguments, *fsfUmlArgumentValue;
char fsfUmlConfigurationFileValue [FSF_UML_FILENAME_MAX_LENGTH + 1];	
char fsfUmlUserValue [FSF_UML_NICKNAME_MAX_LENGTH + 1];
char fsfUmlUserNameValue [FSF_UML_FULLNAME_MAX_LENGTH + 1];
char fsfUmlUserNameConfirmationValue [FSF_UML_FULLNAME_MAX_LENGTH + 1];
char fsfUmlEmailValue [FSF_UML_EMAIL_MAX_LENGTH + 1];
char fsfUmlEmailConfirmationValue [FSF_UML_EMAIL_MAX_LENGTH + 1];
char fsfUmlFriendEmailValue [FSF_UML_EMAIL_MAX_LENGTH + 1];
char fsfUmlNicknameValue [FSF_UML_NICKNAME_MAX_LENGTH + 1];
char fsfUmlProfileValue [20];
char fsfUmlPasswdValue [FSF_UML_PASSWORD_MAX_LENGTH + 1];
char fsfUmlPasswdConfirmationValue [FSF_UML_PASSWORD_MAX_LENGTH + 1];
char *fsfUmlPtr;

fsfUmlConfigurationOptionsType fsfUmlConfigurations;
fsfUmlUserDataType *fsfUmlFirstData,fsfUmlData;
fsfUmlLanguageType fsfUmlLanguageValue;
boolean fsfUmlCheck,fsfUmlUserTokenProcessed,fsfUmlUserNameTokenProcessed,fsfUmlUserNameConfirmationTokenProcessed,fsfUmlEmailTokenProcessed,fsfUmlEmailConfirmationTokenProcessed,fsfUmlLanguageTokenProcessed,fsfUmlConfigurationTokenProcessed;

 fsfUmlUserTokenProcessed = fsfUmlUserNameTokenProcessed = fsfUmlUserNameConfirmationTokenProcessed = fsfUmlEmailTokenProcessed = fsfUmlEmailConfirmationTokenProcessed = fsfUmlLanguageTokenProcessed = fsfUmlConfigurationTokenProcessed = fsfUmlCheck = fsfUmlFalse;
fsfUmlLanguageValue = fsfUmlEnglish;

while (((fsfUmlShortOption = getopt_long (argc, argv, fsfUmlShortOptions, fsfUmlLongOptions, &fsfUmlLongOption)) != -1 ))
{
 switch (fsfUmlShortOption)
 {

 case 'h':
 {
  printf ("FsfUmlShowCliHelp\n");

  while(optind < argc)
  {
   fsfUmlArguments = argv [optind];
   fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);

  switch (fsfUmlArgumentIndex)
  {
   case fsfUmlConfigurationFileArgument:
   {  
    if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
    {
     printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
     exit (fsfUmlErrNo);
    }
    strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
    printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
   }
   break;

   case fsfUmlUserArgument:
   {
    if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
    {
     printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
     printf ("Invalid user\n");
     exit (fsfUmlErrNo);
    }
    fsfUmlCheck = fsfUmlTrue;
   }
   break;
   
   case fsfUmlLanguageArgument:
   {
    if((!strcmp(fsfUmlArgumentValue,"portuguese")))
     fsfUmlLanguageValue = fsfUmlPortuguese;
    else
     fsfUmlLanguageValue = fsfUmlEnglish;
   }
   break;
   
   default:
    printf ("Invalid argument\n");
   }/* switch fsfUmlArgumentIndex */
   optind++;
  } /* while optind < argc */
  if(fsfUmlCheck == fsfUmlFalse)
   printf("\nUser is an required argument\n");
 }
 break; /* break 'h' */

  case 'o':
  {
   printf ("FsfUmlShowConfigurationValues\n");
   while (optind < argc)
   {
    fsfUmlArguments = argv [optind];
    fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
    switch (fsfUmlArgumentIndex)
    {
     case fsfUmlConfigurationFileArgument:
     {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
      {
       exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
      printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);  
     }
     break;
  
     case fsfUmlLanguageArgument:
     { 
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
     }
     break;

     default:
      printf ("Invalid argument\n");
    } /* switch fsfUmlArgumentIndex */
    optind++;
   } /* while optind < argc */
  }
  break; /* break 'o' */
	
  case 'N':
  {
   printf ("FsfUmlRunNcursesInterface\n");
   while (optind < argc)
   {
    if(argv[optind][(strlen(argv[optind]) - 1)] == '\n')
     argv[optind][(strlen(argv[optind]) - 1)] = '\0';
    fsfUmlArguments = argv [optind];
    #ifdef _MY_DEBUG_
     printf("\nOptind :%i\n,argc:%i\n,*fsfUmlArguments:%c\n",optind,argc,*fsfUmlArguments);
    #endif
    fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
    #ifdef _MY_DEBUG_
     printf("\nfsfUmlArgumentIndex: %s\n",fsfUmlArgumentNames[fsfUmlArgumentIndex]);
    #endif
    switch (fsfUmlArgumentIndex)
    {
     case fsfUmlConfigurationFileArgument:
     {
      if(!fsfUmlConfigurationTokenProcessed)
      {
       if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
       {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
        printf ("Invalid configuration file\n");
        exit (fsfUmlErrNo);
       }
       fsfUmlConfigurationTokenProcessed = fsfUmlTrue;
       strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
       printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;
     case fsfUmlUserArgument:
     {
      if(!fsfUmlUserTokenProcessed)
      {
       strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
       fsfUmlUserTokenProcessed = fsfUmlTrue;
       printf ("User: \"%s\"\n", fsfUmlUserValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;
     case fsfUmlLanguageArgument:
     {
      if(!fsfUmlLanguageTokenProcessed)
      {
       fsfUmlLanguageTokenProcessed = fsfUmlTrue;
       #ifdef _MY_DEBUG_
        printf("\nLanguage :%s\n",fsfUmlArgumentValue);
       #endif
       if((!strcmp(fsfUmlArgumentValue,"portuguese")))
        fsfUmlLanguageValue = fsfUmlPortuguese;
       else
        fsfUmlLanguageValue = fsfUmlEnglish;
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;
  
     default:
     {
      printf ("Invalid argument\n");
      exit(1);
     }
     break;
    } /* switch fsfUmlArgumentIndex */
    optind++;
   }/* while optind < argc */
   FsfUmlRunNcursesInterface(&fsfUmlConfigurations,fsfUmlUserValue,fsfUmlLanguageValue);
  }
  break; /* break N */
		
  case 'C':
  {
   printf ("FsfUmlAddUser\n");
   if(FSF_UML_ADMINISTRATOR_USER_IDENTIFIER != (int) getuid())
    exit(fsfUmlNotAdmin);
   while (optind < argc)
   {
    fsfUmlArguments = argv [optind];
    fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
    switch (fsfUmlArgumentIndex)
    {
     case fsfUmlConfigurationFileArgument:
     {
      if(!fsfUmlConfigurationTokenProcessed)
      {
       if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
       {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
        printf ("Invalid configuration file\n");
        exit (fsfUmlErrNo);
       }
       fsfUmlConfigurationTokenProcessed = fsfUmlTrue;
       strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
       printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     } 	
     break;
     
     case fsfUmlUserNameArgument:
     {
      if(!fsfUmlUserNameTokenProcessed)
      {
       strcpy (fsfUmlUserNameValue, fsfUmlArgumentValue);
       fsfUmlUserNameTokenProcessed = fsfUmlTrue;
       printf ("User: \"%s\"\n", fsfUmlUserValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;	

     case fsfUmlLanguageArgument:
     {
      if(!fsfUmlLanguageTokenProcessed)
      {
       fsfUmlLanguageTokenProcessed = fsfUmlTrue;
       #ifdef _MY_DEBUG_
        printf("\nLanguage :%s\n",fsfUmlArgumentValue);
       #endif
       if((!strcmp(fsfUmlArgumentValue,"portuguese")))
        fsfUmlLanguageValue = fsfUmlPortuguese;
       else
        fsfUmlLanguageValue = fsfUmlEnglish;
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;
      
     case fsfUmlUserNameConfirmationArgument:
     {
      if(!fsfUmlUserNameConfirmationTokenProcessed)
      {
       strcpy (fsfUmlUserNameConfirmationValue, fsfUmlArgumentValue);
       fsfUmlUserNameTokenProcessed = fsfUmlTrue;
       printf ("User: \"%s\"\n", fsfUmlUserValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     }
     break;
     
     case fsfUmlEmailArgument:
     {
      if(!fsfUmlEmailTokenProcessed)
      {
       fsfUmlEmailTokenProcessed = fsfUmlTrue;
       if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
       {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
        printf ("Invalid email\n");
  	     exit (fsfUmlErrNo);
       }
       strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
       printf ("Email: \"%s\"\n", fsfUmlEmailValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
      break;

     case fsfUmlEmailConfirmationArgument:
     {
      if(!fsfUmlEmailConfirmationTokenProcessed)
      {
       fsfUmlEmailConfirmationTokenProcessed = fsfUmlTrue;
       if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
       {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
        printf ("Invalid email\n");
  	     exit (fsfUmlErrNo);
       }
       strcpy (fsfUmlEmailConfirmationValue, fsfUmlArgumentValue);
       printf ("Email: \"%s\"\n", fsfUmlEmailValue);
      }
      else
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlTokenAlreadyProcessed,fsfUmlLanguageValue));
       exit(fsfUmlTokenAlreadyProcessed);
      }
     } 	
     break;
     default:
      printf ("Invalid argument\n");
    } /* switch fsfUmlArgumentIndex */
    optind++;
   }/* while optind < argc */
   if(strcmp(fsfUmlUserNameValue,fsfUmlUserNameConfirmationValue))
    exit(fsfUmlDifferentUsers);
   if(strcmp(fsfUmlEmailValue,fsfUmlEmailConfirmationValue))
    exit(fsfUmlDifferentEmails);
   
   fsfUmlPtr = getpass(FsfUmlGetCliUserInterfaceMessage(fsfUmlInsertPassword,fsfUmlLanguageValue));
   strcpy(fsfUmlPasswdValue,fsfUmlPtr);  
   fsfUmlPtr = getpass("Confirm.");
   strcpy(fsfUmlPasswdConfirmationValue,fsfUmlPtr);

   if(strcmp(fsfUmlPasswdConfirmationValue,fsfUmlPasswdValue))
    exit(fsfUmlDifferentPasswords);

   fsfUmlData.fsfUmlId = 0;
   fsfUmlData.fsfUmlNickname[0] = '\0';
   strcpy(fsfUmlData.fsfUmlPassword,fsfUmlPasswdValue);
   strcpy(fsfUmlData.fsfUmlPasswordVerification,fsfUmlPasswdConfirmationValue);
   fsfUmlData.fsfUmlProfile = 0;
   strcpy(fsfUmlData.fsfUmlName,fsfUmlUserNameValue);
   strcpy(fsfUmlData.fsfUmlNameVerification,fsfUmlUserNameConfirmationValue);
   strcpy(fsfUmlData.fsfUmlEmail,fsfUmlEmailValue);
   
   FsfUmlGetConfigurationOptionsValues(fsfUmlConfigurationFileValue,&fsfUmlConfigurations);

   FsfUmlAddUser(&fsfUmlConfigurations,&fsfUmlData);
  }/* case 'C'*/
  break;
   
  case 'a':
  case 'i':
  {
   printf ("FsfUmlAddUser\n");
   while (optind < argc)
   {
    fsfUmlArguments = argv [optind];
    fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
    switch (fsfUmlArgumentIndex)
    {
     case fsfUmlConfigurationFileArgument:
     {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
       printf ("Invalid configuration file\n");
       exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
      printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
     }
     break;
     			
     case fsfUmlUserArgument:
     {	
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
      {	
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
       printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
      printf ("User: \"%s\"\n", fsfUmlUserValue);
     } 
     break;
      
     case fsfUmlUserNameArgument:
     {
      if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
       printf ("Invalid user name\n");
	    exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlUserNameValue, fsfUmlArgumentValue);
      printf ("User name: \"%s\"\n", fsfUmlUserNameValue);
     }
     break;	

     case fsfUmlUserNameConfirmationArgument:
     {
      if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user name confirmation\n");
	    exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlUserNameConfirmationValue, fsfUmlArgumentValue);
      printf ("User name confirmation: \"%s\"\n", fsfUmlUserNameConfirmationValue);
     }
     break;	

     case fsfUmlEmailArgument:
     {
      if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
       printf ("Invalid email\n");
  	    exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
      printf ("Email: \"%s\"\n", fsfUmlEmailValue);
     }
     break;

     case fsfUmlEmailConfirmationArgument:
     {
      if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid email confirmation\n");
	    exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlEmailConfirmationValue, fsfUmlArgumentValue);
      printf ("Email confirmation: \"%s\"\n", fsfUmlEmailConfirmationValue);
     } 	
     break;

     case fsfUmlProfileArgument:
     {
      if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
       printf ("Invalid profile\n");
       exit (fsfUmlErrNo);
      }
      strcpy (fsfUmlProfileValue, fsfUmlArgumentValue);
      printf ("Profile: \"%s\"\n", fsfUmlProfileValue);
     }
     break;
						
     case fsfUmlLanguageArgument:
     {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
 	  }
     break;
								
     default:
	   printf ("Invalid argument\n");
    } /* switch fsfUmlArgumentIndex */
    optind++;
   }	 /* while optind < argc */
  }
  break; /* break 'C' */

  case 't':
  {
   printf ("FsfUmlAcceptInvite\n");
   while (optind < argc)
   {
    fsfUmlArguments = argv [optind];
    fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
    switch (fsfUmlArgumentIndex)
    {
	  case fsfUmlConfigurationFileArgument:
     {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
	  break;

	  case fsfUmlUserArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
	   printf ("User: \"%s\"\n", fsfUmlUserValue);
	  }
     break;

	  case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
     }
  	  break;

 	  default:
	   printf ("Invalid argument\n");
    } /* switch fsfUmlArgumentIndex */
    optind++;
   } /* while optind < argc */
  }
  break; /* break 't' */

  case 'j':
  {
   printf ("FsfUmlRejectInvite\n");
   while (optind < argc)
   {
	 fsfUmlArguments = argv [optind];
	 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	 switch (fsfUmlArgumentIndex)
	 {
	  case fsfUmlConfigurationFileArgument:
	  {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
     break;

	  case fsfUmlUserArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
	   printf ("User: \"%s\"\n", fsfUmlUserValue);
	  }
     break;

	  case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
 	  }
     break;

	  default:
	   printf ("Invalid argument\n");
    } /* switch fsfUmlArgumentIndex */
    optind++;
   } /* while optind < argc */
  } 
  break; /* break 'j' */

  case 'n':
  {   
   printf ("FsfUmlRequestRegistration\n");
   while (optind < argc)
   {
	 fsfUmlArguments = argv [optind];
	 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	 switch (fsfUmlArgumentIndex)
	 {
	  case fsfUmlConfigurationFileArgument:
	  { 
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
     break;
   
  	  case fsfUmlUserNameArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
   	 printf ("Invalid user name\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserNameValue, fsfUmlArgumentValue);
	   printf ("User name: \"%s\"\n", fsfUmlUserNameValue);
	  }
     break;	

     case fsfUmlUserNameConfirmationArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user name confirmation\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserNameConfirmationValue, fsfUmlArgumentValue);
	   printf ("User name confirmation: \"%s\"\n", fsfUmlUserNameConfirmationValue);
	  }
     break;	

	  case fsfUmlEmailArgument:
	  {
      if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid email\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
	   printf ("Email: \"%s\"\n", fsfUmlEmailValue);
	  }
     break;

	  case fsfUmlEmailConfirmationArgument:
	  {		
      if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid email confirmation\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlEmailConfirmationValue, fsfUmlArgumentValue);
	   printf ("Email confirmation: \"%s\"\n", fsfUmlEmailConfirmationValue);
	  }
     break;

	  case fsfUmlFriendEmailArgument:
	  {
      if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid friend email\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlFriendEmailValue, fsfUmlArgumentValue);
	   printf ("Friend email: \"%s\"\n", fsfUmlFriendEmailValue);
	  }
     break;

     case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
 	  }
     break;

	  default:
	   printf ("Invalid argument\n");
     break;
	 }/* switch fsfUmlArgumentIndex */
	 optind++;
   } /* while optind < argc */
  } 
  break; /* break 'n' */
		
  case 'q':
  {
   printf ("FsfUmlGetPendingRegistrationRequestPerUser\n");
	while (optind < argc)
	{
	 fsfUmlArguments = argv [optind];
	 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	 switch (fsfUmlArgumentIndex)
	 {
	  case fsfUmlConfigurationFileArgument:
	  {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
 	   }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
     break;

	  case fsfUmlUserArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
	   printf ("User: \"%s\"\n", fsfUmlUserValue);
	  }
     break;

	  case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
     }
  	  break;

     default:
	   printf ("Invalid argument\n");
	 }/* switch fsfUmlArgumentIndex */
	 optind++;
   } /* while optind < argc */
   printf("\nFsfUmlGetConfigurationOptionsValues\n");
   FsfUmlGetConfigurationOptionsValues(fsfUmlConfigurationFileValue,&fsfUmlConfigurations);
   printf("\nFsfUmlGetPendingRegistrationRequestsPerUser\n");
   FsfUmlGetPendingRegistrationRequestsPerUser(&fsfUmlConfigurations,fsfUmlUserValue,&fsfUmlFirstData);
  }
  break; /* break 'q' */

  case 'Q':
  {
   printf ("FsfUmlGetPendingRegistrationRequests\n");
	while (optind < argc)
	{
	 fsfUmlArguments = argv [optind];
	 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	 switch (fsfUmlArgumentIndex)
	 {
	  case fsfUmlConfigurationFileArgument:
	  {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
     break;

	  case fsfUmlUserArgument:
	  {
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
	   printf ("User: \"%s\"\n", fsfUmlUserValue);
	  }
     break;

     case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
     }
     break;
  
     default:
      printf ("Invalid argument\n");
 	 } /* switch fsfUmlArgumentIndex */
	 optind++;
   } /* while optind < argc */
   FsfUmlGetConfigurationOptionsValues(fsfUmlConfigurationFileValue,&fsfUmlConfigurations);
   FsfUmlGetPendingRegistrationRequests(&fsfUmlConfigurations,&fsfUmlFirstData);
  }		
  break; /* break 'Q' */

  case 'v':	
  {
   printf ("FsfUmlApproveRegistrationRequest\n");
	while (optind < argc)
	{
	 fsfUmlArguments = argv [optind];
	 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	 switch (fsfUmlArgumentIndex)
	 {
	  case fsfUmlConfigurationFileArgument:
	  {
      if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid configuration file\n");
	    exit (fsfUmlErrNo);
      }
	   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	  }
     break;

	  case fsfUmlUserArgument:
	  { 
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
	   {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid user\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
	   printf ("User: \"%s\"\n", fsfUmlUserValue);
	  }
     break;
 
     case fsfUmlNicknameArgument:
     {
      if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
      {
       printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	    printf ("Invalid nickname\n");
	    exit (fsfUmlErrNo);
	   }
	   strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
	   printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
	  }
     break;

	  case fsfUmlLanguageArgument:
	  {
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
     }
     break;

	  default:
	   printf ("Invalid argument\n");
	 } /* switch fsfUmlArgumentIndex */
	   optind++;
   } /* while optind < argc */
  }
  break; /* break 'v' */
 	
   case 'd':
	{
    printf ("FsfUmlDisapproveRegistrationRequest\n");
	 while (optind < argc)
	 {
	  fsfUmlArguments = argv [optind];
	  fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	  switch (fsfUmlArgumentIndex)
	  {
	   case fsfUmlConfigurationFileArgument:
	   {
       if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
	    {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	     printf ("Invalid configuration file\n");
        exit (fsfUmlErrNo);
	    }
	    strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
	    printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	   }
      break;
   
   	case fsfUmlUserArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid user\n");
		  exit (fsfUmlErrNo);
		 }
		  strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		  printf ("User: \"%s\"\n", fsfUmlUserValue);
	   }
      break;

		case fsfUmlNicknameArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid nickname\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		}	
      break;

		case fsfUmlLanguageArgument:
		{
      if((!strcmp(fsfUmlArgumentValue,"portuguese")))
       fsfUmlLanguageValue = fsfUmlPortuguese;
      else
       fsfUmlLanguageValue = fsfUmlEnglish;
      }
      break;

		default:
		 printf ("Invalid argument\n");
      break;
	  } /* switch fsfUmlArgumentIndex */
	  optind++;
	 } /* while optind < argc */
	}
   break; /* break 'd' */

	 case 'U':
	 {
     printf ("FsfUmlGetUnlockingRequests\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
	   fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
		 case fsfUmlConfigurationFileArgument:
		 { 
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid configuration file\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		  printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		 }
       break;

		 case fsfUmlUserArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid user\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		  printf ("User: \"%s\"\n", fsfUmlUserValue);
		 }
       break;

		 case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;

		default:
		 printf ("Invalid argument\n");
      break;
	  } /* switch fsfUmlArgumentIndex */
	  optind++;
    } /* while optind < argc */
   }
	break; /* break 'U' */
 
   case 'l':
	{
    printf ("FsfUmlLockUserAccount\n");
 	 while (optind < argc)
	 {
	  fsfUmlArguments = argv [optind];
	  fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
	  switch (fsfUmlArgumentIndex)
	  {
		case fsfUmlConfigurationFileArgument:
	   {
       if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
	     printf ("Invalid configuration file\n");
		  exit (fsfUmlErrNo);
		 }
	    strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		 printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		}
      break;

		case fsfUmlUserArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid user\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		 printf ("User: \"%s\"\n", fsfUmlUserValue);
		}
      break;

      case fsfUmlNicknameArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid nickname\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		}
      break;

		case fsfUmlLanguageArgument:
		{
       if((!strcmp(fsfUmlArgumentValue,"portuguese")))
        fsfUmlLanguageValue = fsfUmlPortuguese;
       else
        fsfUmlLanguageValue = fsfUmlEnglish;
      }
      break;

		default:
		 printf ("Invalid argument\n");
      break;
	  } /* switch fsfUmlArgumentIndex */
	  optind++;
	 } /* while optind < argc */
	}
	  break; /* break 'l' */
		
		case 'u':
		{
       printf ("FsfUmlUnlockUserAccount\n");
		 while (optind < argc)
		 {
		  fsfUmlArguments = argv [optind];
		  fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		  switch (fsfUmlArgumentIndex)
		  {
		   case fsfUmlConfigurationFileArgument:
			{
          if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid configuration file\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
			 printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
			}
         break;

			case fsfUmlUserArgument:
			{
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid user\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
			 printf ("User: \"%s\"\n", fsfUmlUserValue);
			}
         break;

			case fsfUmlNicknameArgument:
			{
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid nickname\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
			 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		   }
         break;

			case fsfUmlLanguageArgument:
			{
          if((!strcmp(fsfUmlArgumentValue,"portuguese")))
           fsfUmlLanguageValue = fsfUmlPortuguese;
          else
           fsfUmlLanguageValue = fsfUmlEnglish;
         }
         break;

			default:
			 printf ("Invalid argument\n");
         break;
		  } /* switch fsfUmlArgumentIndex */
		  optind++;
		 } /* while optind < argc */
		}
		break; /* break 'u' */

		case 'p':
		{
    	 printf ("FsfUmlChangeUserPassword\n");
		 while (optind < argc)
		 {
		  fsfUmlArguments = argv [optind];
		  fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		  switch (fsfUmlArgumentIndex)
		  {
		   case fsfUmlConfigurationFileArgument:
			{
          if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid configuration file\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
			 printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		   }
         break;

		   case fsfUmlUserArgument:
		   {
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		    {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		 	  printf ("Invalid user\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
			 printf ("User: \"%s\"\n", fsfUmlUserValue);
		   }
         break;

		   case fsfUmlNicknameArgument:
		   {
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		    {
     printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid nickname\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
			 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		   }
         break;

		   case fsfUmlLanguageArgument:
		   {
          if((!strcmp(fsfUmlArgumentValue,"portuguese")))
           fsfUmlLanguageValue = fsfUmlPortuguese;
          else
           fsfUmlLanguageValue = fsfUmlEnglish;
         }
         break;

		   default:
		    printf ("Invalid argument\n");
         break;
	  	  } /* switch fsfUmlArgumentIndex */
		  optind++;
		 } /* while optind < argc */
		}
		break; /* break 'p' */

		case 'r':
		{
       printf ("FsfUmlResetUserPassword\n");
		 while (optind < argc)
		 {
		  fsfUmlArguments = argv [optind];
		  fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		  switch (fsfUmlArgumentIndex)
		  {
		   case fsfUmlConfigurationFileArgument:
			{
          if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid configuration file\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
			 printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		   }
       	break;
      
		   case fsfUmlUserArgument:
			{
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid user\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
			 printf ("User: \"%s\"\n", fsfUmlUserValue);
			}
         break;

			case fsfUmlNicknameArgument:
			{
          if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
			 {
           printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
			  printf ("Invalid nickname\n");
			  exit (fsfUmlErrNo);
			 }
			 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
			 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
			}
         break;

			case fsfUmlLanguageArgument:
			{
          if((!strcmp(fsfUmlArgumentValue,"portuguese")))
           fsfUmlLanguageValue = fsfUmlPortuguese;
          else
           fsfUmlLanguageValue = fsfUmlEnglish;
         }
         break;

         default:
			 printf ("Invalid argument\n");
         break;
		  } /* switch fsfUmlArgumentIndex */
		 optind++;
		} /* while optind < argc */
	  }  	
	  break; /* break 'r' */

	  case 'm':
	  {
      printf ("FsfUmlChangeUserName\n");
	 	while (optind < argc)
	   {
		 fsfUmlArguments = argv [optind];
		 fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		 switch (fsfUmlArgumentIndex)
		 {
		  case fsfUmlConfigurationFileArgument:
		  {
         if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		   {
          printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		    printf ("Invalid configuration file\n");
		  	 exit (fsfUmlErrNo);
		   }
		   strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		   printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		  }
        break;

		  case fsfUmlUserArgument:
		  {
         if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		   {
          printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		    printf ("Invalid user\n");
		    exit (fsfUmlErrNo);
   	   }
		   strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		   printf ("User: \"%s\"\n", fsfUmlUserValue);
		  }
        break;

		 case fsfUmlNicknameArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid nickname\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		  printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		 }
       break;

		 case fsfUmlEmailArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid email\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
		  printf ("Email: \"%s\"\n", fsfUmlEmailValue);
		 }
       break;

		 case fsfUmlEmailConfirmationArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid email confirmation\n");
		  	exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlEmailConfirmationValue, fsfUmlArgumentValue);
		  printf ("Email confirmation: \"%s\"\n", fsfUmlEmailConfirmationValue);
		 }
       break;
 
       case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;
 
       default:
		  printf ("Invalid argument\n");
       break;
		} /* switch fsfUmlArgumentIndex */
		optind++;
 	  } /* while optind < argc */
    }
  	 break; /* break 'm' */
  
	 case 'e':
	 {
     printf ("FsfUmlChangeUserEmail\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
		fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
       case fsfUmlConfigurationFileArgument:
		 {
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid configuration file\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		  printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
	    }
       break;

		 case fsfUmlUserArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid user\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		  printf ("User: \"%s\"\n", fsfUmlUserValue);
		 }
       break;
 
       case fsfUmlNicknameArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid nickname\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		  printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		 }
       break;
	
       case fsfUmlEmailArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid email\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
		  printf ("Email: \"%s\"\n", fsfUmlEmailValue);
		 }
       break;

		 case fsfUmlEmailConfirmationArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid email confirmation\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlEmailConfirmationValue, fsfUmlArgumentValue);
		  printf ("Email confirmation: \"%s\"\n", fsfUmlEmailConfirmationValue);
		 }
       break;

		 case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;
 
       default:
		  printf ("Invalid argument\n");
       break;
		} /* switch fsfUmlArgumentIndex */
		optind++;
	  } /* while optind < argc */
	 }
	 break; /* break 'e' */
 
    case 'c':
	 {
     printf ("FsfUmlConfirmEmailChange\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
		fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
       case fsfUmlConfigurationFileArgument:
		 { 
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid configuration file\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		  printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		 }
       break;

		 case fsfUmlUserArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid user\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		  printf ("User: \"%s\"\n", fsfUmlUserValue);
		 }
       break;
 
       case fsfUmlNicknameArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid nickname\n");
		 	exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		  printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		 }
       break;
	
		 case fsfUmlPasswdArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_PASSWORD_,FSF_UML_PASSWORD_MIN_LENGTH,FSF_UML_PASSWORD_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid key\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlPasswdValue, fsfUmlArgumentValue);
		  printf ("Passwd: \"%s\"\n", fsfUmlPasswdValue);
		 }
       break;
	
		 case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;
  
       default:
		  printf ("Invalid argument\n");
       break;
		} /* switch fsfUmlArgumentIndex */
		optind++;
	  } /* while optind < argc */
	 }	
	 break; /* break 'c' */

	 case 'g':
	 {
     printf ("FsfUmlChangeUserProfile\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
		fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
		 case fsfUmlConfigurationFileArgument:
		 {
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid configuration file\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		 printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		}
    	break;

		case fsfUmlUserArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid user\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlUserValue, fsfUmlArgumentValue);
		 printf ("User: \"%s\"\n", fsfUmlUserValue);
		}
      break;

		case fsfUmlNicknameArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckNickname(fsfUmlArgumentValue,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid nickname\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlNicknameValue, fsfUmlArgumentValue);
		 printf ("Nickname: \"%s\"\n", fsfUmlNicknameValue);
		}
      break;
		
    	case fsfUmlProfileArgument:
		{
       if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
		 {
        printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		  printf ("Invalid profile\n");
		  exit (fsfUmlErrNo);
		 }
		 strcpy (fsfUmlProfileValue, fsfUmlArgumentValue);
		 printf ("Profile: \"%s\"\n", fsfUmlProfileValue);
		}
      break;
						
		case fsfUmlLanguageArgument:
		{
       if((!strcmp(fsfUmlArgumentValue,"portuguese")))
        fsfUmlLanguageValue = fsfUmlPortuguese;
       else
        fsfUmlLanguageValue = fsfUmlEnglish;
      }
     	break;

	   default:
		 printf ("Invalid argument\n");
      break;
		} /* switch fsfUmlArgumentIndex */
		optind++;
	  } /* while optind < argc */
	 }	
	 break; /* break 'g' */

	 case 's':
	 {
     printf ("FsfUmlGetUsers\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
		fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
		 case fsfUmlConfigurationFileArgument:
	    {	
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid configuration file\n");
		   exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		  printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		 }
 		 break;

       case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;
 
       default:
		  printf ("Invalid argument\n");
       break;
	   } /* switch fsfUmlArgumentIndex */
	   optind++;
	  }  /* while optind < argc */
	 }
    break; /* break 's' */

	 case 'S':
	 {
     printf ("FsfUmlSearchUsers\n");
	  while (optind < argc)
	  {
	   fsfUmlArguments = argv [optind];
		fsfUmlArgumentIndex = getsubopt (&fsfUmlArguments, fsfUmlArgumentNames, &fsfUmlArgumentValue);
		switch (fsfUmlArgumentIndex)
		{
		 case fsfUmlConfigurationFileArgument:
		 {
        if((fsfUmlErrNo = FsfUmlFilenameValidation(fsfUmlArgumentValue,FSF_UML_VALID_FILENAME_,FSF_UML_FILENAME_MIN_LENGTH,FSF_UML_FILENAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid configuration file\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlConfigurationFileValue, fsfUmlArgumentValue);
		  printf ("Configuration file: \"%s\"\n", fsfUmlConfigurationFileValue);
		 }
       break;
 
       case fsfUmlUserNameArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid user name\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlUserNameValue, fsfUmlArgumentValue);
		  printf ("User name: \"%s\"\n", fsfUmlUserNameValue);
		 }
       break;	

		 case fsfUmlEmailArgument:
		 {
        if((fsfUmlErrNo =FsfUmlCheckEmail(fsfUmlArgumentValue,FSF_VALID_EMAIL_,FSF_UML_EMAIL_MIN_LENGTH,FSF_UML_EMAIL_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlEmailValue, fsfUmlArgumentValue);
		  printf ("Email: \"%s\"\n", fsfUmlEmailValue);
		 }
       break;
 
       case fsfUmlProfileArgument:
		 {
        if((fsfUmlErrNo = FsfUmlCheckStringField(fsfUmlArgumentValue,FSF_UML_USERNAME_,FSF_UML_FULLNAME_MIN_LENGTH,FSF_UML_FULLNAME_MAX_LENGTH)))
		  {
         printf("\n%s\n",FsfUmlGetCliErrorMessage (fsfUmlErrNo, fsfUmlEnglish));
		   printf ("Invalid profile\n");
			exit (fsfUmlErrNo);
		  }
		  strcpy (fsfUmlProfileValue, fsfUmlArgumentValue);
		  printf ("Profile: \"%s\"\n", fsfUmlProfileValue);
		 }
       break;
						
		 case fsfUmlLanguageArgument:
		 {
        if((!strcmp(fsfUmlArgumentValue,"portuguese")))
         fsfUmlLanguageValue = fsfUmlPortuguese;
        else
         fsfUmlLanguageValue = fsfUmlEnglish;
       }
       break;

		 default:
		  printf ("Invalid argument\n");
	   } /* switch fsfUmlArgumentIndex */
		optind++;
	  } /* while optind < argc */
	 }	
	 break; /* break 'S' */
	
	 /*default:
	  printf ("Invalid option\n");
    break;*/
	} 	/* switch fsfUmlShortOption */
  } /* while fsfUmlShortOption */
 }
 return fsfUmlOk;
}



