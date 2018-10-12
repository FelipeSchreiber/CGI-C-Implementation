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

#ifndef _FSF_UML_ADD_USER_H
#define _FSF_UML_ADD_USER_H "@(#)fsfUmlAddUser.h $Revision:$"

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
FsfUmlAddUser (fsfUmlConfigurationOptionsType *fsfUmlConfiguration, fsfUmlUserDataType *fsfUmlUserData);

#endif

/* $RCSfile:$ */
