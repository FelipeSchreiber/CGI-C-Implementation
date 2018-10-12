/* Universidade Federal do Rio de Janeiro
*  Escola Politecnica
*  Departamento de Eletronica e de Computacao
*  Prof. Marcelo Luiz Drumond Lanza
*  EEL 270 - Computacao II - Turma 2017/1
* 
*  $Author: $
*  $Date: $
*  $Log: $
*
*/

#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fsfUmlTypes.h"
#include "fsfUmlErrors.h"
#include "fsfUmlFunctions.h"
#include "fsfUmlConst.h"

/*
 fsfUmlErrorType
 FsfUmlAddUser (fsfUmlConfigurationOptionsType *, fsfUmlUserDataType *)
 
   
 Arguments:
  
 fsfUmlConfigurationOptionsType * - The structure containing the configuration options (I)
 
 fsfUmlUserDataType * - The structure containing user's information (I)
  
  
  Returned code:
 
  fsfUmlMemmoryAllocationError - Case an problem occured while allocating memmory 
   
  fsfUmlFileOpeningError - Case an problem occured while  opening a file
  
  fsfUmlNullUserData - Pointer to struct < fsfUmlUserDataType > is NULL

  fsfUmlInvalidProfile - The profile no. is zero

  fsfUmlOk - No problems occured
  
   Description:

   Adds a user to the users file or user abeyances file
 */
fsfUmlErrorType
FsfUmlAddUser (fsfUmlConfigurationOptionsType *fsfUmlConfiguration, fsfUmlUserDataType *fsfUmlUserData)
{
 size_t fsfUmlColonCounter = 0, fsfUmlLength;
 FILE *fsfUmlUserFile, *fsfUmlAbeyances;
 unsigned fsfUmlErrNo;
 char fsfUmlBuffer[2], fsfUmlPassword[17];
 boolean fsfUmlFound = fsfUmlFalse;
 fsfUmlUserDataType *fsfUmlFirst, *fsfUmlLast, *fsfUmlNew, *fsfUmlAux;

 if(!fsfUmlUserData)
  return fsfUmlNullUserData;

 if(!fsfUmlConfiguration)
 {	
  fsfUmlErrNo = FsfUmlGetConfigurationOptionsValues(NULL,fsfUmlConfiguration);
  if (fsfUmlErrNo)
   return fsfUmlErrNo;
 }
 
 if(!(fsfUmlUserFile = fopen(fsfUmlConfiguration->fsfUmlUsersDataFilename, "r")))
  return fsfUmlFileOpeningError ;
 else
 {
  fclose(fsfUmlUserFile);
  if(fsfUmlUserData->fsfUmlProfile == 0)
  return fsfUmlInvalidProfile ;
 }
 	
 if(!(fsfUmlUserFile = fopen(fsfUmlConfiguration->fsfUmlUsersDataFilename, "a")))
  return fsfUmlFileOpeningError;

 fclose(fsfUmlUserFile);

 if(!(fsfUmlUserFile = fopen(fsfUmlConfiguration->fsfUmlUsersDataFilename, "r")))
  return fsfUmlFileOpeningError;


 fsfUmlFirst = NULL;
 if (!(fsfUmlFirst = (fsfUmlUserDataType *) malloc (sizeof (fsfUmlUserDataType))))
 {
  fclose (fsfUmlUserFile);
  return fsfUmlMemoryAllocationError;			  
 }

 memset (fsfUmlFirst, 0x00, sizeof (fsfUmlUserDataType));
 
 fsfUmlFirst->fsfUmlNext = NULL;
 fsfUmlFirst->fsfUmlPrevious = NULL;

 fsfUmlNew  = fsfUmlFirst;
 
 fsfUmlUserData->fsfUmlId = 0;

 fsfUmlLast = NULL;
 
 while ((fgets (fsfUmlBuffer, 2, fsfUmlUserFile)) != NULL) 
 {
  if(fsfUmlBuffer[0] == ':')
   fsfUmlColonCounter++;
  else
  {
   switch (fsfUmlColonCounter)
 	{
	 case 0:
	  fsfUmlNew->fsfUmlId = (fsfUmlNew->fsfUmlId * 10) + (fsfUmlBuffer[0] - '0');
	 break;

	 case 1:
	  fsfUmlLength = strlen(fsfUmlNew->fsfUmlNickname);
	  fsfUmlNew->fsfUmlNickname[fsfUmlLength] = fsfUmlBuffer[0];
	  fsfUmlNew->fsfUmlNickname[fsfUmlLength + 1] = '\0';
	 break;
					
	 case 2:
	  fsfUmlLength = strlen(fsfUmlNew->fsfUmlPassword);
	  fsfUmlNew->fsfUmlPassword[fsfUmlLength] = fsfUmlBuffer[0];
	  fsfUmlNew->fsfUmlPassword[fsfUmlLength + 1] = '\0';
    break;
					
  	 case 3:
 	  fsfUmlNew->fsfUmlProfile = (fsfUmlNew->fsfUmlProfile * 10) + (fsfUmlBuffer[0] - '0');
	 break;
					
	 case 4:
	  fsfUmlLength = strlen(fsfUmlNew->fsfUmlName);
	  fsfUmlNew->fsfUmlName[fsfUmlLength]=fsfUmlBuffer[0];
	  fsfUmlNew->fsfUmlName[fsfUmlLength + 1] = '\0';
	 break;

	 case 5:
	  fsfUmlLength = strlen(fsfUmlNew->fsfUmlEmail);
	  fsfUmlNew->fsfUmlEmail[fsfUmlLength] = fsfUmlBuffer[0];
	  fsfUmlNew->fsfUmlEmail[fsfUmlLength + 1] = '\0';
	 break;			
   }
  }

  if(fsfUmlBuffer[0] == '\n')
  {
   fsfUmlNew->fsfUmlEmail[strlen(fsfUmlNew->fsfUmlEmail) - 1] = '\0';
  
   fsfUmlColonCounter = 0;

   if(fsfUmlLast)
   {	
    fsfUmlNew->fsfUmlPrevious = fsfUmlLast;
	 fsfUmlLast->fsfUmlNext = fsfUmlNew;
	 fsfUmlNew->fsfUmlNext = NULL;
   }

   fsfUmlLast = fsfUmlNew;
   if (!(fsfUmlNew = (fsfUmlUserDataType *) malloc (sizeof (fsfUmlUserDataType))))
   {
    while (fsfUmlFirst)
	 {
	  fsfUmlAux = fsfUmlFirst;
	  fsfUmlFirst = fsfUmlFirst->fsfUmlNext;
	  free (fsfUmlAux);
	 }
	 fclose (fsfUmlUserFile);
	 return fsfUmlMemoryAllocationError;			  
   }
   memset (fsfUmlNew, 0x00, sizeof (fsfUmlUserDataType));

   if(fsfUmlLast->fsfUmlPrevious)
   {	
    fsfUmlAux = fsfUmlLast->fsfUmlPrevious;
	 if(((fsfUmlLast->fsfUmlId - fsfUmlAux->fsfUmlId) >=2) && !fsfUmlFound)
	 {	
	  fsfUmlFound = fsfUmlTrue;			
	  fsfUmlUserData->fsfUmlId = fsfUmlAux->fsfUmlId + 1;
	  fsfUmlUserData->fsfUmlPrevious = fsfUmlAux;
	  fsfUmlUserData->fsfUmlNext = fsfUmlLast;
	  fsfUmlAux->fsfUmlNext = fsfUmlUserData;
	  fsfUmlLast->fsfUmlPrevious = fsfUmlUserData;
	  fsfUmlLast = fsfUmlUserData;
	 }
   }		
  }
 }
 if(fsfUmlNew)	
 free(fsfUmlNew);

 if(fsfUmlLast)
 {	
  if(!fsfUmlFound)
  {
   fsfUmlUserData->fsfUmlId = fsfUmlLast->fsfUmlId + 1;
	fsfUmlUserData->fsfUmlPrevious = fsfUmlLast;
	fsfUmlUserData->fsfUmlNext = NULL;
	fsfUmlLast->fsfUmlNext = fsfUmlUserData;
  }
 }
 else
 {
  fsfUmlFirst = fsfUmlUserData;
  fsfUmlUserData->fsfUmlPrevious = NULL;
  fsfUmlUserData->fsfUmlNext = NULL;
 }		

 fclose(fsfUmlUserFile);

 if(!strlen(fsfUmlUserData->fsfUmlPassword))
 {	
  FsfUmlCreateRandomString(FSF_UML_PASSWORD_,16, fsfUmlPassword);
  		
  if(!(fsfUmlAbeyances = fopen(fsfUmlConfiguration->fsfUmlInvitedUsersDataFilename, "a")))
   return fsfUmlFileOpeningError;
		
  fprintf(fsfUmlAbeyances, "%Lu:", fsfUmlUserData->fsfUmlId);
  fprintf(fsfUmlAbeyances, "%s:", fsfUmlPassword);
  fprintf(fsfUmlAbeyances, "%s\n", "time + 72hrs");
  fclose(fsfUmlAbeyances);

 }

 if (!(fsfUmlUserFile = fopen(fsfUmlConfiguration->fsfUmlUsersDataFilename, "w"))) 
 {
  return fsfUmlFileOpeningError;
 }

 while (fsfUmlFirst)
 {
  fprintf(fsfUmlUserFile, "%Lu:", fsfUmlFirst->fsfUmlId);
  fprintf(fsfUmlUserFile, "%s:", fsfUmlFirst->fsfUmlNickname);
  fprintf(fsfUmlUserFile, "%s:", fsfUmlFirst->fsfUmlPassword);
  fprintf(fsfUmlUserFile, "%Lu:", fsfUmlFirst->fsfUmlProfile);
  fprintf(fsfUmlUserFile, "%s:", fsfUmlFirst->fsfUmlName);
  fprintf(fsfUmlUserFile, "%s\n", fsfUmlFirst->fsfUmlEmail);
  
  fsfUmlAux = fsfUmlFirst;
  fsfUmlFirst = fsfUmlFirst->fsfUmlNext;
  if(fsfUmlAux != fsfUmlUserData)
   free (fsfUmlAux);
 }	

 fclose(fsfUmlUserFile);	

 return fsfUmlOk;
}

/* $RCSfile:$ */
