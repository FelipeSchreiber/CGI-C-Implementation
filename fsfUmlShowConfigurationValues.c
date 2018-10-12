/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$
  
*/
/*check environment*/

/*#include <ncurses.h>*/
#include <stdio.h>
#include <string.h>
#include "fsfUmlConfig.h"
/*#include "fsfUmlConst.h"*/
#include "fsfUmlTypes.h"
#include "fsfUmlErrors.h"
#include "fsfUmlUserInterface.h"
#include "fsfUmlShowConfigurationValues.h" 
/*#include "fsfUmlNcursesFunctions.h"*/

fsfUmlErrorType
FsfUmlShowConfigurationValues(fsfUmlConfigurationOptionsType *fsfUmlConfigurations,fsfUmlLanguageType fsfUmlLanguage)
{
 /*WINDOW* fsfUmlNewWindow;
 fsfUmlNewWindow = newwin(12,200,5,5);*/
 char fsfUmlBuffer[100]; 
 int fsfUmlErrNo = 0;

 /*wprintw(fsfUmlNewWindow,"\nEh hora do show\n");
 wrefresh(fsfUmlNewWindow);
 if(!fsfUmlConfigurations)
  return fsfUmlNullConfigurationData;
 
 sprintf(fsfUmlBuffer,"%llu",fsfUmlConfigurations->fsfUmlUserId);
 fsfUmlBuffer[strlen(fsfUmlBuffer)] = '\0';
  
 fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlUserIdentifier,fsfUmlNewWindow,fsfUmlBuffer);
 
 wprintw(fsfUmlNewWindow,"\n#Erro: %i // #Funcao: %i \n",fsfUmlErrNo,FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlUserIdentifier,fsfUmlNewWindow,fsfUmlBuffer));
 wrefresh(fsfUmlNewWindow);
 delay_output(3000);
 
 if(fsfUmlErrNo)
  return fsfUmlErrNo;
 
 wprintw(fsfUmlNewWindow,"\nSUCESSO \n");
 wrefresh(fsfUmlNewWindow);
 delay_output(3000);

 fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlPrivateRoot,fsfUmlNewWindow, fsfUmlConfigurations->fsfUmlPrivateRootDirectory);
 
 if(fsfUmlErrNo)
 {
  wprintw(fsfUmlNewWindow,"\n%i,<%s>\n",fsfUmlErrNo,fsfUmlConfigurations->fsfUmlPrivateRootDirectory);
  wrefresh(fsfUmlNewWindow);
  delay_output(3000); 
  return fsfUmlErrNo;
 }
 if(fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlData,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlDataDirectory))
  return fsfUmlErrNo;
 
 if(fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlCookies,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlCookiesDirectory))
  return fsfUmlErrNo;
 
 if(fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlUsersDataFile,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlUsersDataFilename))
  return fsfUmlErrNo;
 
 if(fsfUmlErrNo =FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlInvitedUsersDataFile,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlInvitedUsersDataFilename))
  return fsfUmlErrNo;
 
 if(fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlRequestingUsersDataFile,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename))
  return fsfUmlErrNo;
 
 if(fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlLockedUsersDataFile,fsfUmlNewWindow,
    fsfUmlConfigurations->fsfUmlLockedUsersDataFilename))
  return fsfUmlErrNo;  
 
  wrefresh(fsfUmlNewWindow);
  wgetch(fsfUmlNewWindow);
  wclear(fsfUmlNewWindow);
  wrefresh(fsfUmlNewWindow);
  if(delwin(fsfUmlNewWindow) != OK)
   return(fsfUmlErrorClosingWindow);
 */

 if(!fsfUmlConfigurations)
  return fsfUmlNullConfigurationData;
 
 printf("\n%s %llu\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlUserIdentifier,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlUserId);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlPrivateRoot,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlPrivateRootDirectory);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlData,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlDataDirectory);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlCookies,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlCookiesDirectory);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlUsersDataFile,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlUsersDataFilename);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlInvitedUsersDataFile,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlInvitedUsersDataFilename);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlRequestingUsersDataFile,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlRequestingUsersDataFilename);
 printf("\n%s %s\n",FsfUmlGetCliUserInterfaceMessage(fsfUmlLockedUsersDataFile,fsfUmlLanguage),fsfUmlConfigurations->fsfUmlLockedUsersDataFilename);

 return fsfUmlOk; 
}

/*$RCSFile$*/

