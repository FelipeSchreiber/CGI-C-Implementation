/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2016/2
Prof. Marcelo Luiz Drumond Lanza

$Author$
$Date$
$Log$
*/ 

#include "fsfUmlRunNcursesInterface.h"
#include "fsfUmlFunctions.h"
#include "fsfUmlShowConfigurationValues.h"
#include "fsfUmlGetPendingRegistrationRequestsPerUser.h"
#include "fsfUmlGetPendingRegistrationRequests.h"
#include "fsfUmlAddUser.h"
/*
fsfUmlErrorType
FsfUmlRunNcursesInterface(fsfUmlConfigurationOptionsType *fsfUmlConfigurations, char *fsfUmlNickname,fsfUmlLanguageType fsfUmlLanguage);


Arguments:

fsfUmlConfigurations - This struct contains the filenames that will be used at the current program

fsfUmlNickname - This is the user's nickname

fsfUmlLanguage - The language in which the messages will be shown at screen


Returned code:

fsfUmlNullConfigurationData - Case the pointer to struct fsfUmlConfigurations is NULL

fsfUmlKeypadUnabled - Case de keypad() function returned an error

fsfUmlErrNo - This equals to the returned value by the following functions: FsfUmlNcursesLogin,FsfUmlPrintWindow or FsfUmlPrintWindowMoveCursor

fsfUmlErrorClosingWindow - Case an problem occured while closing a window


Description:

This function runs the ncurses interface.Only login and password are required for a while.A menu is shown to the user, althought it's missing 
the primary functions and forms for each option available.
*/

fsfUmlErrorType
FsfUmlRunNcursesInterface(fsfUmlConfigurationOptionsType *fsfUmlConfigurations, char *fsfUmlNickname,fsfUmlLanguageType fsfUmlLanguage)
{
 WINDOW *fsfUmlWindow;
 fsfUmlWindow = initscr();
 raw();
 echo();
 
 if(!fsfUmlConfigurations)
  return fsfUmlNullConfigurationData;

 if((keypad(fsfUmlWindow,TRUE) != OK))
  return(fsfUmlKeypadUnabled);
 
 int fsfUmlUserInput,fsfUmlUnderline,fsfUmlMaxRow,fsfUmlMaxColumn,fsfUmlCounterMinValue,fsfUmlCounterMaxValue,fsfUmlErrNo;
 char fsfUmlPassword[FSF_UML_PASSWORD_MAX_LENGTH + 1];
 char fsfUmlGetNickname[FSF_UML_NICKNAME_MAX_LENGTH + 1];
 /*fsfUmlLanguageType fsfUmlLanguage;*/
 boolean fsfUmlExit;
 WINDOW *fsfUmlSecondaryWindow,*fsfUmlBorder;
 fsfUmlUserDataType *fsfUmlFirst = NULL;

 fsfUmlUnderline = 0;
 /*fsfUmlCounter = 0;*/
 wrefresh(fsfUmlWindow);
 fsfUmlExit = fsfUmlFalse;
 getmaxyx(fsfUmlSecondaryWindow,fsfUmlMaxRow,fsfUmlMaxColumn);

 /*fsfUmlLanguage = FsfUmlGetLanguageIndex (fsfUmlLanguages);*/
 if(FsfUmlCheckNickname(fsfUmlNickname,FSF_UML_NICKNAME_,FSF_UML_NICKNAME_MIN_LENGTH,FSF_UML_NICKNAME_MAX_LENGTH))/*The nickname was invalid*/
 {
  fsfUmlGetNickname[0] = '\0';
  fsfUmlPassword[0] ='\0';

  wprintw(fsfUmlWindow,"%s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlHelp,fsfUmlLanguage));
  wrefresh(fsfUmlWindow);
  fsfUmlBorder = newwin(16,FSF_UML_NICKNAME_MAX_LENGTH + 4,4,4);
  wborder(fsfUmlBorder,'|','|','=','=','*','*','*','*');
  wrefresh(fsfUmlBorder);
  
  fsfUmlSecondaryWindow = newwin(14,FSF_UML_NICKNAME_MAX_LENGTH + 2,5,5);
  if((fsfUmlErrNo = FsfUmlNcursesLogin(fsfUmlLanguage,fsfUmlSecondaryWindow,fsfUmlBorder,fsfUmlGetNickname,fsfUmlPassword,&fsfUmlExit)))
   return fsfUmlErrNo;
 
  if(fsfUmlExit == fsfUmlFalse)
  {    
   wclear(fsfUmlSecondaryWindow);
   if((fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlInsertNickname,fsfUmlSecondaryWindow,fsfUmlGetNickname)))
    return fsfUmlErrNo;

   if((fsfUmlErrNo = FsfUmlPrintWindow(fsfUmlLanguage,fsfUmlInsertPassword,fsfUmlSecondaryWindow,fsfUmlPassword)))
    return fsfUmlErrNo;
   
   mvwprintw(fsfUmlSecondaryWindow,fsfUmlMaxRow,fsfUmlMaxColumn - 7,"%s",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlEnter,fsfUmlLanguage));
   wattroff(fsfUmlSecondaryWindow,A_BOLD|A_UNDERLINE);
   getch();
  }/*the other else ends*/
  wclear(fsfUmlWindow);
  wrefresh(fsfUmlWindow);/*Clear the help message from the main window*/
 }/*if ends*/  
 else/*The user has a valid nickname before calling this function*/ 
 {
  #ifdef _MY_DEBUG_
   wprintw(fsfUmlWindow,"\nThe user already has a valid nickname\n"); 
   wrefresh(fsfUmlWindow);
  #endif

  strcpy(fsfUmlGetNickname,fsfUmlNickname);
 
  FsfUmlInitializeWindows(&fsfUmlBorder,&fsfUmlSecondaryWindow);
 
  FsfUmlNcursesLogin(fsfUmlLanguage,fsfUmlSecondaryWindow,fsfUmlBorder,fsfUmlGetNickname,fsfUmlPassword,&fsfUmlExit);
  
  if(fsfUmlExit == fsfUmlFalse)
  {
   wclear(fsfUmlSecondaryWindow);
   wclear(fsfUmlBorder);
   wrefresh(fsfUmlSecondaryWindow);
   wrefresh(fsfUmlBorder);
   
   if(delwin(fsfUmlSecondaryWindow) != OK)
    return(fsfUmlErrorClosingWindow);
   if(delwin(fsfUmlBorder) != OK)
    return(fsfUmlErrorClosingWindow);
  }/*Close the secondary window in order to show up the menu from the main window*/
 } 
   
 while(fsfUmlUnderline != fsfUmlLeave)/*This creates a loop condition: the programm will only close when the user decides to leave*/
 {

 if(fsfUmlExit)
 {
  wclear(fsfUmlWindow);
  
  #ifdef _MY_DEBUG_
  wprintw(fsfUmlWindow,"\nfsfUmlExit --> setting values");
  wrefresh(fsfUmlWindow);
  delay_output(3000);
  #endif 
  
  fsfUmlCounterMaxValue = fsfUmlLeave;/*The menu ends with the Exit option*/
  fsfUmlCounterMinValue = fsfUmlEnter;/*The menu begins with the Enter option*/
  fsfUmlUnderline = fsfUmlEnter;/*The underline shows up the selected option.It begins with the first option from menu*/
 }/*It means that the user has not entered with nickname and password, so all other options must be disabled*/
 else
 {
  fsfUmlCounterMaxValue = fsfUmlSearchUsers ;/*The menu ends with the Search Users option*/
  fsfUmlCounterMinValue = fsfUmlHelp;/*The menu begins with the Help option*/
  fsfUmlUnderline = fsfUmlHelp;/*The underline shows up the selected option.It begins with the first option from menu*/
 }/*The user has already entered with nickname and password, so all the options will be available, except the login one*/

 FsfUmlNcursesMenu(&fsfUmlWindow,fsfUmlCounterMinValue,fsfUmlCounterMaxValue,&fsfUmlUnderline,fsfUmlUserInput,fsfUmlLanguage);
 wclear(fsfUmlWindow); 
 wprintw(fsfUmlWindow,"\n%s < %s > ...",FsfUmlGetNcursesUserInterfaceMessage(fsfUmlSelectedOption,fsfUmlLanguage),
         FsfUmlGetNcursesUserInterfaceMessage(fsfUmlUnderline,fsfUmlLanguage));
 wrefresh(fsfUmlWindow);
 delay_output(3000);
 wclear(fsfUmlWindow);
 wrefresh(fsfUmlWindow);
 
 FsfUmlInitializeWindows(&fsfUmlBorder,&fsfUmlSecondaryWindow);
 wrefresh(fsfUmlSecondaryWindow);
 wrefresh(fsfUmlBorder);
  
 switch(fsfUmlUnderline)
 {
  case(fsfUmlEnter):
  {
   if((fsfUmlErrNo = FsfUmlNcursesLogin(fsfUmlLanguage,fsfUmlSecondaryWindow,fsfUmlBorder,fsfUmlGetNickname,fsfUmlPassword,&fsfUmlExit)))
    return fsfUmlErrNo;
  
   #ifdef _MY_DEBUG_
   wprintw(fsfUmlWindow,"\nfsfUmlExit :%i\n",fsfUmlExit);
   wrefresh(fsfUmlWindow);
   delay_output(3000);
   #endif
  }
  break;
  
  case(fsfUmlHelp):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlHelp");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
  break;
  
  case(fsfUmlLeave):
   wprintw(fsfUmlSecondaryWindow,"Leaving");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlShowConfigurationValues):
  {
   /*fsfUmlBorder = newwin(16,FSF_UML_NICKNAME_MAX_LENGTH + 4,4,4);
   wborder(fsfUmlBorder,'|','|','=','=','*','*','*','*');
   wrefresh(fsfUmlBorder);
   fsfUmlSecondaryWindow = newwin(14,FSF_UML_NICKNAME_MAX_LENGTH + 2,5,5);
   wrefresh(fsfUmlSecondaryWindow);
   wrefresh(fsfUmlBorder);
   
   wprintw(fsfUmlSecondaryWindow,"\nComeca\n");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   wclear(fsfUmlBorder);
   wrefresh(fsfUmlSecondaryWindow);
   wrefresh(fsfUmlBorder);
   
   if(delwin(fsfUmlSecondaryWindow) != OK)
    return(fsfUmlErrorClosingWindow);
   if(delwin(fsfUmlBorder) != OK)
    return(fsfUmlErrorClosingWindow);
  
   wgetch(fsfUmlWindow); 
     
   if(fsfUmlErrNo = FsfUmlShowConfigurationValues(fsfUmlConfigurations,fsfUmlLanguage))
   {
    wprintw(fsfUmlWindow,"\nfsfUmlShowErr :%i\n",fsfUmlErrNo);
    wrefresh(fsfUmlWindow);
    delay_output(3000);
    return fsfUmlErrNo;
   }
   wprintw(fsfUmlWindow,"\nTermina\n");
   wrefresh(fsfUmlWindow);
   delay_output(3000);*/
  } 
  break;
 
  case(fsfUmlRequireRegistration):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlRequireRegistration");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
  break;

  case(fsfUmlAcceptInvitation):
  {
   wprintw(fsfUmlSecondaryWindow,"fsfUmlAcceptInvitation");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   
  } 
  break;
 
  case(fsfUmlRejectInvitation):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlRejectInvitation");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;

  case(fsfUmlAddUser):
   wprintw(fsfUmlSecondaryWindow,"RunNcurses nao recebe xyzUserDataType* ,impossivel executar xyzAddUser");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   /*FsfUmlAddUser(&fsfUmlConfigurations,&fsfUmlUserData);*/
  break;
 
  case(fsfUmlGetPendingRegistrationRequestsPerUser):
   FsfUmlGetPendingRegistrationRequestsPerUser(fsfUmlConfigurations,fsfUmlGetNickname,&fsfUmlFirst);
  break;
  
  case(fsfUmlGetPendingRegistrationRequests):
   FsfUmlGetPendingRegistrationRequests(fsfUmlConfigurations,&fsfUmlFirst);
  break;
 
  case(fsfUmlApproveRegistrationRequest):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlApproveRegistrationRequest");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlDisapproveRegistrationRequest):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlDisapproveRegistrationRequest");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlGetUnlockingRequests):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlGetUnlockingRequests");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlLockUserAccount):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlLockUserAccount");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlUnlockUserAccount):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlUnlockUserAccount");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlChangeUserPassword):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlChangeUserPassword");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlResetUserPassword):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlResetUserPassword");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlChangeUserName):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlChangeUserName");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlChangeUserEmail):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlChangeUserEmail");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlConfirmEmailChange):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlConfirmEmailChange");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlChangeUserProfile):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlChangeUserProfile");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;

  case(fsfUmlGetUsers):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlGetUsers");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  case(fsfUmlSearchUsers):
   wprintw(fsfUmlSecondaryWindow,"fsfUmlSearchUsers");
   wrefresh(fsfUmlSecondaryWindow);
   delay_output(3000);
   wclear(fsfUmlSecondaryWindow);
   break;
  
  default:
   break;
 }
 if(delwin(fsfUmlSecondaryWindow) != OK)
  return(fsfUmlErrorClosingWindow);
 if(delwin(fsfUmlBorder) != OK)
  return(fsfUmlErrorClosingWindow);
}
 endwin();
 return 0;
}  


/* $RCSfile$ */
