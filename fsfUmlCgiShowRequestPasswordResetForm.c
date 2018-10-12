/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2017/1
 *
 * $Author$
 * $Date$
 * $Log$
 */ 

#define FSF_UML_INVALID_EXECUTION_ENVIRONMENT					1

#include "fsfUmlUserInterface.h"
#include "fsfUmlConst.h"
#include "fsfUmlTypes.h"
#include "Libraries/mlcgi.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main ()
{
 environmentType fsfUmlExecutionEnvironment;
 unsigned fsfUmlErrNo;
 fsfUmlLanguageType fsfUmlLanguageId;
 char fsfUmlConfigurationFileName [FSF_UML_FILENAME_MAX_LENGTH];
 char fsfUmlLanguage [16];
  
 if (mlCgiInitialize (&fsfUmlExecutionEnvironment))
  exit (ML_CGI_OK);

 if (fsfUmlExecutionEnvironment == commandLine)
 {
  printf ("Invalid execution environment\n");
  exit (FSF_UML_INVALID_EXECUTION_ENVIRONMENT);
 }

 mlCgiBeginHttpHeader ("text/html");
 fsfUmlErrNo = mlCgiGetFormStringNoNewLines ("fsfUmlLanguage",fsfUmlLanguage,16);
  
 if (fsfUmlErrNo != ML_CGI_OK)
 {
  mlCgiEndHttpHeader ();
  mlCgiFreeResources ();
  exit (ML_CGI_OK);
 }
 if(!(strcmp(fsfUmlLanguage,"fsfUmlPortuguese")))
  fsfUmlLanguageId = fsfUmlPortuguese;
 else
  fsfUmlLanguageId = fsfUmlEnglish;
	
 fsfUmlErrNo = mlCgiGetFormStringNoNewLines ("fsfUmlConfigurationFileName",fsfUmlConfigurationFileName,FSF_UML_FILENAME_MAX_LENGTH);
 
 if (fsfUmlErrNo != ML_CGI_OK)
 {
  mlCgiEndHttpHeader ();
  mlCgiFreeResources ();
  exit (ML_CGI_OK);
 }

 printf ("<html>\n");
 printf (" <head>\n");
 printf ("  <title>REQUEST PASSWOR FORM</title>\n");
 printf (" </head>\n");
 printf (" <body>\n");
 printf ("  <nav>\n");
 printf ("    <a href=\"./fsfUmlShowRequestRegistrationForm.cgi\">%s|</a>\n",FsfUmlGetWebUserInterfaceMessage(fsfUmlSignInMessage,fsfUmlLanguageId));
 printf ("    <a href=\"./fsfUmlShowLicense.cgi?fsfUmlConfigurationFileName=%s&fsfUmlLanguage=%s\">%s|</a>\n",fsfUmlConfigurationFileName,fsfUmlLanguage,FsfUmlGetWebUserInterfaceMessage(fsfUmlLicenseMessage,fsfUmlLanguageId));
 printf ("    <a href=\"./fsfUmlMain.cgi?fsfUmlConfigurationFileName=%s&fsfUmlLanguage=%s\">%s|</a><br> \n",fsfUmlConfigurationFileName,fsfUmlLanguage,FsfUmlGetWebUserInterfaceMessage(fsfUmlReturnMessage,fsfUmlLanguageId));
 printf ("  </nav>\n");
 printf ("  <footer>\n");
 printf ("    <a href=\"mailto:schreiber.felipe@poli.ufrj.br\"> Felipe Schreiber Fernandes</a>\n"); 
 printf ("  </footer>\n");
 printf ("    <form action=\"fsfRequestPasswordReset.cgi\" method=\"post\"> \n");
 printf ("      <fieldset>\n");
 printf ("       <legend>%s</legend>\n",FsfUmlGetWebUserInterfaceMessage(fsfUmlRequestPasswordMessage,fsfUmlLanguageId));
 printf ("     %s:<br>\n",FsfUmlGetWebUserInterfaceMessage(fsfUmlInsertNickname,fsfUmlLanguageId));
 printf ("     <input type=\"text\" name=\"fsfUmlNickname\" maxlength=\"%i \" <br>\n",FSF_UML_NICKNAME_MAX_LENGTH);
 printf ("       <input type=\"hidden\"  name=\"fsfUmlConfigurationFileName\" value=\"%s\">\n",fsfUmlConfigurationFileName);
 printf ("       <input type=\"hidden\" name=\"fsfUmlLanguage\" value=\"%s\">\n",fsfUmlLanguage);
 printf ("       <input type=\"submit\" value=\"Submit\">\n");
 printf ("      </fieldset>\n");
 printf ("    </form>\n");
 printf (" </body>\n");
 printf ("</html>\n");
 
 mlCgiFreeResources ();
 return ML_CGI_OK;	
}


/*$RCSfile$*/

