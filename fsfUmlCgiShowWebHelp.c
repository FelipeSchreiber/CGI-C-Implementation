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
 fsfUmlErrNo = mlCgiGetFormStringNoNewLines ("fsfUmlLanguage", fsfUmlLanguage, 16);
  
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
 printf ("  <title> HELP </title>\n");
 printf (" </head>\n");
 printf (" <body>\n");
 printf (" <abbr title=\"Tranca Ou Puxa\"> TOP </abbr><br>\n");
 printf ("<nav>\n");
 printf (" <div>\n<p>\n");
 printf ("  <a href=\"./fsfUmlMain.cgi?fsfUmlConfigurationFileName=\"%s\"&fsfUmlLanguage=\"portuguese\">Pt-Br</a>\n",fsfUmlConfigurationFileName);
 printf ("  <a href=\"./fsfUmlMain.cgi?fsfUmlConfigurationFileName=\"%s\"&fsfUmlLanguage=\"english\">En-Us</a>\n",fsfUmlConfigurationFileName);
 printf (" </p>\n</div>\n");
 printf ("  <a href=\"./fsfUmlShowRequestRegistrationForm.cgi?fsfUmlConfigurationFileName=%s&fsfUmlLanguage=%s\">%s</a>\n",fsfUmlConfigurationFileName,fsfUmlLanguage,FsfUmlGetWebUserInterfaceMessage(fsfUmlSignInMessage,fsfUmlLanguageId));
 printf ("  <a href=\"./fsfUmlShowRequestPasswordResetForm.cgi\">%s</a>\n",FsfUmlGetWebUserInterfaceMessage(fsfUmlRequestPasswordMessage,fsfUmlLanguageId));
 printf ("  <a href=\"./fsfUmlShowLicense.cgi?fsfUmlConfigurationFileName=%s&fsfUmlLanguage=%s\">%s</a>\n",fsfUmlConfigurationFileName, fsfUmlLanguage, FsfUmlGetWebUserInterfaceMessage(fsfUmlLicenseMessage, fsfUmlLanguageId));
 printf ("</nav>\n");
 printf ("<footer>\n");
 printf ("  <a href=\"mailto:schreiber.felipe@poli.ufrj.br\"> Felipe Schreiber Fernandes</a>\n"); 
 printf ("</footer>\n");
 printf (" %s<br>\n",fsfUmlShowHelp);
 printf (" </body>\n");
 printf ("</html>\n");
 
 mlCgiFreeResources ();
 return ML_CGI_OK;	
}


/*$RCSfile$*/

