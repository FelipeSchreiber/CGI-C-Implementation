/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$ 
*/ 

#include <stdio.h>
#include "fsfUmlErrors.h"

char *fsfUmlCliErrorMessages [fsfUmlLanguagesAmount] [fsfUmlErrorsAmount]=
{
  {
    "Ok",
    "Invalid error number",
    "File error",
    "Memory alocation error",
    "Invalid password",
    "Got NULL pointer in name",
    "Got NULL pointer in valid characters",
    "Got an invalid character",
    "String length exceeds maximum length",
    "String length does not reach the minimum length",
    "Got null path",
    "Got null filename",
    "Absolut file path surpass the maximum length allowed",
    "Number of dots exceeds the maximum allowed",
    "Got null email",
    "Number of at signs '@' surpass the maximum allowed",
    "Got null random string",
    "Random string got zero length",
    "Got NULL pointer in String Field",
    "No surname found.Impossible to create a nickname",
    "Invalid Crypt.There is an error in the password, a missing '$' character or unmatched crypting algorithm",
    "The encrypted password length is invalid",
    "The crypting algorithm Id is invalid",
    "The \"salt\" contains invalid characters or wrong length",
    "The encrypted part of password contains invalid charaters or length out of the following range: 22 - 86",
    "The password contains invalid characters or invalid length",
    "The passwords are diferent",
    "The encrypted string got NULL value",
    "The Id got NULL value",
    "The salt got NULL value",
    "The pointer to struct fsfUmlConfigurationsType got NULL value",
    "An error occurred while opening a file",
    "An error occurred while reading a file or the error indicator is set to this file ",
    "Unrecognized configuration option", 
    "An error occured while closing a window",
    "Keypad Unabled",
    "An error occured while writing at window",
    "An error occured while reloading a window",
    "An error occured while moving the cursor",
    "Wborder error: could not set the window border",
    "An error occured while you were digiting",
    "Unknown Message",
    "The pointer to WINDOW type is NULL",
    "The pointer to WINDOW(border) is NULL",
    "The pointer to boolean type(fsfUmlExit) is NULL", 
    "The nickname contains no dots",
    "Pointer to struct < fsfUmlUserDataType > is NULL",
    "Nickname not found in the user's file",
    "Invalid User Id",
    "Id and nickname dont match",
    "Profile does not contain only numbers or is zero",
    "Id not found in request file",
    "No valid requests",
    "It is missing an at sign in email",
    "Invalid language",
    "Token already processed"
  },
  {
    "Sucesso",
    "Numero de erro invalido",
    "Erro relacionado com arquivo",
    "Erro alocando memória",
    "Senha incorreta",
    "Nickname possui valor nulo",
    "A string de caracteres validos comeca com ponteiro de valor NULL",
    "Existe(m) caracter(es) invalido(s)",
    "String muito longa",
    "String muito curta",
    "Caminho para o arquivo eh NULL",
    "Nome do arquivo eh NULL",
    "Caminho absoluto para o arquivo eh muito longo",
    "Numero de pontos supera o valor maximo permitido",
    "Email nulo",
    "Numero de arrobas '@' supera o valor maximo permitido",
    "Random string foi passada com valor nulo",
    "Random string foi passada com tamanho zero",
    "Campo da string recebeu ponteiro com valor nulo",
    "Sobrenome nao encontrado. Impossivel de criar um apelido",
    "A senha encriptada esta incorreta. Falta o caracter '$' ou o algoritimo de encriptacao eh invalido ",
    "O tamanho da senha encriptada eh invalido"
    "A identificacao do algoritimo para criptografia eh invalido",
    "O \"salt\" contem caracteres invalidos ou tamanho incorreto",
    "A senha criptografada contem caracteres invalidos ou esta fora do tamanho: 22 - 86",
    "A senha plana contem contem caracteres invalidos ou tamanho inapropriado",
    "As senhas sao diferentes",
    "O ponteiro para a string encriptada eh nulo",
    "O ponteiro para Id tem valor nulo",
    "O ponteiro para o Salt tem valor nulo",
    "O ponteiro para a estrutura fsfUmlConfigurationsType tem valor nulo",
    "Um erro ocorreu durante a abertura do arquivo",
    "Um erro ocorreu durante a leitura do arquivo, ou o indicador de erro esta setado para o arquivo em questao",
    "Op&ccedil&atildeo de configura&ccedil&atildeo n&atildeo achada",
    "Um erro ocorreu fechando a janela",
    "Teclado desabilitado",
    "Um erro ocorreu enquanto escrevia na tela",
    "Um erro ocorreu enquanto atualizava a tela",
    "Um erro ocorreu enquanto movia o cursor",
    "Erro na funcao wborder: nao foi possivel desenhar a borda da janela",
    "Um erro ocorreu enquanto voce digitava",
    "Mensagem desconhecida",
    "O ponteiro para o tipo WINDOW eh NULL",
    "O ponteiro para o tipo WINDOW(borda) eh NULL",
    "O ponteiro para o tipo boolean (fsfUmlExit) eh NULL",
    "O apelido nao contem ponto",
    "Ponteiro para struct < fsfUmlUserDataType > eh NULL",
    "Apelido nao encontrado no arquivo de usuarios",
    "Id do usuario invalido",
    "Id e apelido nao tem correspondencia",
    "Profile nao contem apenas numeros ou eh zero",
    "Id nao encontrado no arquivo de solicitacoes",
    "Nenhuma solicitacao valida",
    "Falta o arroba no email",
    "Idioma invalido",
    "Token ja foi processado anteriormente"
  }
};

char *fsfUmlNcursesErrorMessages [fsfUmlLanguagesAmount] [fsfUmlErrorsAmount]=
{
  {
   "Ok",
    "Invalid error number",
    "File error",
    "Memory alocation error",
    "Invalid password",
    "Got NULL pointer in name",
    "Got NULL pointer in valid characters",
    "Got an invalid character",
    "String length exceeds maximum length",
    "String length does not reach the minimum length",
    "Got null path",
    "Got null filename",
    "Absolut file path surpass the maximum length allowed",
    "Number of dots exceeds the maximum allowed",
    "Got null email",
    "Number of at signs '@' surpass the maximum allowed",
    "Got null random string",
    "Random string got zero length",
    "Got NULL pointer in String Field",
    "No surname found.Impossible to create a nickname",
    "Invalid Crypt.There is an error in the password, a missing '$' character or unmatched crypting algorithm",
    "The encrypted password length is invalid",
    "The crypting algorithm Id is invalid",
    "The \"salt\" contains invalid characters or wrong length",
    "The encrypted part of password contains invalid charaters or length out of the following range: 22 - 86",
    "The password contains invalid characters or invalid length",
    "The passwords are diferent",
    "The encrypted string got NULL value",
    "The Id got NULL value",
    "The salt got NULL value",
    "The pointer to struct fsfUmlConfigurationsType got NULL value",
    "An error occurred while opening a file",
    "An error occurred while reading a file or the error indicator is set to this file ",
    "Unrecognized configuration option", 
    "An error occured while closing a window",
    "Keypad Unabled",
    "An error occured while writing at window",
    "An error occured while reloading a window",
    "An error occured while moving the cursor",
    "Wborder error: could not set the window border",
    "An error occured while you were digiting",
    "Unknown Message",
    "The pointer to WINDOW type is NULL",
    "The pointer to WINDOW(border) is NULL",
    "The pointer to boolean type(fsfUmlExit) is NULL", 
    "The nickname contains no dots",
    "Pointer to struct < fsfUmlUserDataType > is NULL",
    "Nickname not found in the user's file",
    "Invalid User Id",
    "Id and nickname dont match",
    "Profile does not contain only numbers or is zero",
    "Id not found in request file",
    "No valid requests",
    "It is missing an at sign in email",
    "Invalid language" 
   },
  {
    "Sucesso",
    "Numero de erro invalido",
    "Erro relacionado com arquivo",
    "Erro alocando memória",
    "Senha incorreta",
    "Nickname possui valor nulo",
    "A string de caracteres validos comeca com ponteiro de valor NULL",
    "Existe(m) caracter(es) invalido(s)",
    "String muito longa",
    "String muito curta",
    "Caminho para o arquivo eh NULL",
    "Nome do arquivo eh NULL",
    "Caminho absoluto para o arquivo eh muito longo",
    "Numero de pontos supera o valor maximo permitido",
    "Email nulo",
    "Numero de arrobas '@' supera o valor maximo permitido",
    "Random string foi passada com valor nulo",
    "Random string foi passada com tamanho zero",
    "Campo da string recebeu ponteiro com valor nulo",
    "Sobrenome nao encontrado. Impossivel de criar um apelido",
    "A senha encriptada esta incorreta. Falta o caracter '$' ou o algoritimo de encriptacao eh invalido ",
    "O tamanho da senha encriptada eh invalido"
    "A identificacao do algoritimo para criptografia eh invalido",
    "O \"salt\" contem caracteres invalidos ou tamanho incorreto",
    "A senha criptografada contem caracteres invalidos ou esta fora do tamanho: 22 - 86",
    "A senha plana contem contem caracteres invalidos ou tamanho inapropriado",
    "As senhas sao diferentes",
    "O ponteiro para a string encriptada eh nulo",
    "O ponteiro para Id tem valor nulo",
    "O ponteiro para o Salt tem valor nulo",
    "O ponteiro para a estrutura fsfUmlConfigurationsType tem valor nulo",
    "Um erro ocorreu durante a abertura do arquivo",
    "Um erro ocorreu durante a leitura do arquivo, ou o indicador de erro esta setado para o arquivo em questao",
    "Op&ccedil&atildeo de configura&ccedil&atildeo n&atildeo achada",
    "Um erro ocorreu fechando a janela",
    "Teclado desabilitado",
    "Um erro ocorreu enquanto escrevia na tela",
    "Um erro ocorreu enquanto atualizava a tela",
    "Um erro ocorreu enquanto movia o cursor",
    "Erro na funcao wborder: nao foi possivel desenhar a borda da janela",
    "Um erro ocorreu enquanto voce digitava",
    "Mensagem desconhecida",
    "O ponteiro para o tipo WINDOW eh NULL",
    "O ponteiro para o tipo WINDOW(borda) eh NULL",
    "O ponteiro para o tipo boolean (fsfUmlExit) eh NULL",
    "O apelido nao contem ponto",
    "Ponteiro para struct < fsfUmlUserDataType > eh NULL",
    "Apelido nao encontrado no arquivo de usuarios",
    "Id do usuario invalido",
    "Id e apelido nao tem correspondencia",
    "Profile nao contem apenas numeros ou eh zero",
    "Id nao encontrado no arquivo de solicitacoes",
    "Nenhuma solicitacao valida",
    "Falta o arroba no email",
    "Idioma invalido"
  }
};

char * fsfUmlWebErrorMessages [fsfUmlLanguagesAmount] [fsfUmlErrorsAmount]=
{
  {
    "Ok",
    "Invalid error number",
    "File error",
    "Memory alocation error",
    "Invalid password",
    "Got NULL pointer in name",
    "Got NULL pointer in valid characters",
    "Got an invalid character",
    "String length exceeds maximum length",
    "String length does not reach the minimum length",
    "Got null path",
    "Got null filename",
    "Absolut file path surpass the maximum length allowed",
    "Number of dots exceeds the maximum allowed",
    "Got null email",
    "Number of at signs '@' surpass the maximum allowed",
    "Got null random string",
    "Random string got zero length",
    "Got NULL pointer in String Field",
    "No surname found.Impossible to create a nickname",
    "Invalid Crypt.There is an error in the password, a missing '$' character or unmatched crypting algorithm",
    "The encrypted password length is invalid",
    "The crypting algorithm Id is invalid",
    "The \"salt\" contains invalid characters or wrong length",
    "The encrypted part of password contains invalid charaters or length out of the following range: 22 - 86",
    "The password contains invalid characters or invalid length",
    "The passwords are diferent",
    "The encrypted string got NULL value",
    "The Id got NULL value",
    "The salt got NULL value",
    "The pointer to struct fsfUmlConfigurationsType got NULL value",
    "An error occurred while opening a file",
    "An error occurred while reading a file or the error indicator is set to this file ",
    "Unrecognized configuration option", 
    "An error occured while closing a window",
    "Keypad Unabled",
    "An error occured while writing at window",
    "An error occured while reloading a window",
    "An error occured while moving the cursor",
    "Wborder error: could not set the window border",
    "An error occured while you were digiting",
    "Unknown Message",
    "The pointer to WINDOW type is NULL",
    "The pointer to WINDOW(border) is NULL",
    "The pointer to boolean type(fsfUmlExit) is NULL", 
    "The nickname contains no dots",
    "Pointer to struct < fsfUmlUserDataType > is NULL",
    "Nickname not found in the user's file",
    "Invalid User Id",
    "Id and nickname dont match",
    "Profile does not contain only numbers or is zero",
    "Id not found in request file",
    "No valid requests",
    "It is missing an at sign in email",
    "Invalid language"
   },
  {
    "Sucesso",
    "Numero de erro invalido",
    "Erro relacionado com arquivo",
    "Erro alocando memória",
    "Senha incorreta",
    "Nickname possui valor nulo",
    "A string de caracteres validos comeca com ponteiro de valor NULL",
    "Existe(m) caracter(es) invalido(s)",
    "String muito longa",
    "String muito curta",
    "Caminho para o arquivo eh NULL",
    "Nome do arquivo eh NULL",
    "Caminho absoluto para o arquivo eh muito longo",
    "Numero de pontos supera o valor maximo permitido",
    "Email nulo",
    "Numero de arrobas '@' supera o valor maximo permitido",
    "Random string foi passada com valor nulo",
    "Random string foi passada com tamanho zero",
    "Campo da string recebeu ponteiro com valor nulo",
    "Sobrenome nao encontrado. Impossivel de criar um apelido",
    "A senha encriptada esta incorreta. Falta o caracter '$' ou o algoritimo de encriptacao eh invalido ",
    "O tamanho da senha encriptada eh invalido"
    "A identificacao do algoritimo para criptografia eh invalido",
    "O \"salt\" contem caracteres invalidos ou tamanho incorreto",
    "A senha criptografada contem caracteres invalidos ou esta fora do tamanho: 22 - 86",
    "A senha plana contem contem caracteres invalidos ou tamanho inapropriado",
    "As senhas sao diferentes",
    "O ponteiro para a string encriptada eh nulo",
    "O ponteiro para Id tem valor nulo",
    "O ponteiro para o Salt tem valor nulo",
    "O ponteiro para a estrutura fsfUmlConfigurationsType tem valor nulo",
    "Um erro ocorreu durante a abertura do arquivo",
    "Um erro ocorreu durante a leitura do arquivo, ou o indicador de erro esta setado para o arquivo em questao",
    "Op&ccedil&atildeo de configura&ccedil&atildeo n&atildeo achada",
    "Um erro ocorreu fechando a janela",
    "Teclado desabilitado",
    "Um erro ocorreu enquanto escrevia na tela",
    "Um erro ocorreu enquanto atualizava a tela",
    "Um erro ocorreu enquanto movia o cursor",
    "Erro na funcao wborder: nao foi possivel desenhar a borda da janela",
    "Um erro ocorreu enquanto voce digitava",
    "Mensagem desconhecida",
    "O ponteiro para o tipo WINDOW eh NULL",
    "O ponteiro para o tipo WINDOW(borda) eh NULL",
    "O ponteiro para o tipo boolean (fsfUmlExit) eh NULL",
    "O apelido nao contem ponto",
    "Ponteiro para struct < fsfUmlUserDataType > eh NULL",
    "Apelido nao encontrado no arquivo de usuarios",
    "Id do usuario invalido",
    "Id e apelido nao tem correspondencia",
    "Profile nao contem apenas numeros ou eh zero",
    "Id nao encontrado no arquivo de solicitacoes",
    "Nenhuma solicitacao valida",
    "Falta o arroba no email",
    "Idioma invalido"
  }
};

/*
 * char *
 * FsfUmlGetCliErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);
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
   fsfUmlCliErrorMessages [fsfUmlLanguage] [fsfUmlErrors]
 * 
   This function returns a pointer which points to the begining of a string
 *
 * 
   Description:
 * 
   Returns an error message corresponding to the error number in the language specified
 * */
char *
FsfUmlGetCliErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage)
{
 return(fsfUmlCliErrorMessages [fsfUmlLanguage] [fsfUmlError]);
};

/*
 * char *
 * FsfUmlGetNcursesErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);
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
   fsfUmlNcursesErrorMessages [fsfUmlLanguage] [fsfUmlErrors]
 * 
   This function returns a pointer which points to the begining of a string
 *
 * 
   Description:
 * 
   Returns an error message corresponding to the error number in the language specified
 * */
char*
FsfUmlGetNcursesErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage)
{
 return(fsfUmlNcursesErrorMessages [fsfUmlLanguage] [fsfUmlError]);
};
/*
 char *
 FsfUmlGetWebErrorMessage (fsfUmlErrorType fsfUmlError, fsflUmlLanguageType fsfUmlLanguage);
 
 
 Arguments:
 
 fsfUmlErrorType - Equivalent integer to a specific error (I)
 
 fsfLanguageType- Equivalent integer to the language defined (I)
 
 
 Return code:
 
 fsfUmlWebErrorMessages [fsfUmlLanguage] [fsfUmlError]
 
 This function returns a pointer which points to the begining of a string
 
 
 Description:
 
 Returns an error message corresponding to the error number in the language specified
*/

char *
FsfUmlGetWebErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage)
{
 return (fsfUmlWebErrorMessages [fsfUmlLanguage] [fsfUmlError]);
};


/*RErrorMessage (fsfUmlErrorType fsfUmlError, fsfUmlLanguageType fsfUmlLanguage)CSFile*/
