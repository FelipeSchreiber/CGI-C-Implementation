/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2017/1
 
$Author$
$Date$
$Log$
*/

#include "fsfUmlTypes.h"
#include "fsfUmlUserInterface.h" 
#include "fsfUmlErrors.h"
#include <stdio.h>


char *fsfUmlCliUserInterfaceMessages [fsfUmlLanguagesAmount][fsfUmlTotalInterfaceMessages]=
{
 {
  "Please select an option.Use arrow keys to move up and down.Press Enter when done",
  "Selected option:",
  "Please, insert nickname.\nOnly non capital letters from a-z are allowed.\nIt must contain a dot and 5-65 characters.\nPress ESC before writing anything if you want to leave this window",
  "Please, insert password.\nIt must contain at least 8 characters.\nOnly the following characters are allowed:\na-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPress ESC before writing anything if you want to leave this window",
  "Enter",
  "Help", 
  "Exit",
  "Show configuration values",
  "Require Registration",
  "Accept Invitation",
  "Reject Invitation",
  "Add User",
  "Get Pending Registration Requests Per User",  
  "Get Pending Registration Requests",
  "Approve Registration Request ",
  "Disapprove Registration Request", 
  "Get unlocking Requests",
  "Lock user account",
  "Unlock user account",
  "Change user password",
  "Reset user password",
  "Change user name",
  "Change user email",
  "Confirm email change",
  "Change user profile",
  "Get users",
  "Search users",
  "Nickname:",
  "Password:",
  "User Id:",
  "Private root directory:", 
  "Data directory:",
  "Cookies directory:",
  "Users data filename:",
  "Invited users data filename:",
  "Requesting users data filename:",
  "Locked users data filename:"
 },

 {
  "Escolha uma dessas opcoes.Pressione seta para cima ou para baixo para nevegar.Aperte Enter para selecionar",
  "Opcao selecionada:",
  "Insira um apelido.\nApenas letras minusculas a-z sao permitidas\nPrecisa conter um ponto e 5-65 caracteres para validar seu apelido.\nPressione ESC se voce quiser sair dessa janela",
  "Por favor, insira a senha.\nDeve conter no minimo 8 caracteres.\nSomente os seguintes caracteres sao permitidos:\n a-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPressione ESC se voce quiser sair dessa janela",
  "Entrar",
  "Ajuda",
  "Sair",
  "Mostrar valores de configuracao",
  "Requisitar Registro",
  "Aceitar Convite",
  "Rejeitar Convite",
  "Adcionar usurario",
  "Obter pedidos de registro pendentes por usuario",  
  "Obter pedidos de registro pendentes",
  "Aprovar pedido de registro",
  "Rejeitar pedido de registro", 
  "Obter solicitacao de desbloqueio",
  "Bloquear conta do usuario",
  "Desbloquear conta do usuario",
  "Mudar senha do usuario",
  "Resetar senha do usuario",
  "Mudar nome do usuario",
  "Mudar email do usuario",
  "Confirmar alteracao de email",
  "Mudar de perfil",
  "Obter usarios",
  "Buscar usuarios",
  "Apelido:",
  "Senha:",
  "Id do usuario:",
  "Raiz do diretorio privado:",
  "Diretorio de dados:",
  "Diretorio de cookies",
  "Nome do arquivo de dados dos usuarios",
  "Nome do arquivo de dados dos usuarios convidados:",
  "Nome do arquivo de dados dos usuarios em espera:",
  "Nome do arquivo de dados dos usuarios bloqueados:"
 }
};

char *fsfUmlNcursesUserInterfaceMessages[fsfUmlLanguagesAmount][fsfUmlTotalInterfaceMessages]=
{
 {
  "Please select an option.Use arrow keys to move up and down.Press Enter when done",
  "Selected option:",
  "Please, insert nickname.\nOnly non capital letters from a-z are allowed.\nIt must contain a dot and 5-65 characters.\nPress ESC before writing anything if you want to leave this window",
  "Please, insert password.\nIt must contain at least 8 characters.\nOnly the following characters are allowed:\na-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPress ESC before writing anything if you want to leave this window",
  "Enter",
  "Help", 
  "Exit",
  "Show configuration values",
  "Require Registration",
  "Accept Invitation",
  "Reject Invitation",
  "Add User",
  "Get Pending Registration Requests Per User",  
  "Get Pending Registration Requests",
  "Approve Registration Request ",
  "Disapprove Registration Request", 
  "Get unlocking Requests",
  "Lock user account",
  "Unlock user account",
  "Change user password",
  "Reset user password",
  "Change user name",
  "Change user email",
  "Confirm email change",
  "Change user profile",
  "Get users",
  "Search users",
  "Nickname:",
  "Password:",
  "User Id:",
  "Private root directory:", 
  "Data directory:",
  "Cookies directory:",
  "Users data filename:",
  "Invited users data filename:",
  "Requesting users data filename:",
  "Locked users data filename:"
 },

 {
  "Escolha uma dessas opcoes.Pressione seta para cima ou para baixo para nevegar.Aperte Enter para selecionar",
  "Opcao selecionada:",
  "Insira um apelido.\nApenas letras minusculas a-z sao permitidas\nPrecisa conter um ponto e 5-65 caracteres para validar seu apelido.\nPressione ESC se voce quiser sair dessa janela",
  "Por favor, insira a senha.\nDeve conter no minimo 8 caracteres.\nSomente os seguintes caracteres sao permitidos:\n a-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPressione ESC se voce quiser sair dessa janela",
  "Entrar",
  "Ajuda",
  "Sair",
  "Mostrar valores de configuracao",
  "Requisitar Registro",
  "Aceitar Convite",
  "Rejeitar Convite",
  "Adcionar usurario",
  "Obter pedidos de registro pendentes por usuario",  
  "Obter pedidos de registro pendentes",
  "Aprovar pedido de registro",
  "Rejeitar pedido de registro", 
  "Obter solicitacao de desbloqueio",
  "Bloquear conta do usuario",
  "Desbloquear conta do usuario",
  "Mudar senha do usuario",
  "Resetar senha do usuario",
  "Mudar nome do usuario",
  "Mudar email do usuario",
  "Confirmar alteracao de email",
  "Mudar de perfil",
  "Obter usarios",
  "Buscar usuarios",
  "Apelido:",
  "Senha:",
  "Id do usuario:",
  "Raiz do diretorio privado:",
  "Diretorio de dados:",
  "Diretorio de cookies",
  "Nome do arquivo de dados dos usuarios",
  "Nome do arquivo de dados dos usuarios convidados:",
  "Nome do arquivo de dados dos usuarios em espera:",
  "Nome do arquivo de dados dos usuarios bloqueados:"
  
 }
};

char *fsfUmlWebUserInterfaceMessages [fsfUmlLanguagesAmount][fsfUmlTotalInterfaceMessages]=
{
 {
  "Please select an option.Use arrow keys to move up and down.Press Enter when done",
  "Selected option:",
  "Please, insert nickname.\nOnly non capital letters from a-z are allowed.\nIt must contain a dot and 5-65 characters.\nPress ESC before writing anything if you want to leave this window",
  "Please, insert password.\nIt must contain at least 8 characters.\nOnly the following characters are allowed:\na-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPress ESC before writing anything if you want to leave this window",
  "Enter",
  "Help", 
  "Exit",
  "Show configuration values",
  "Require Registration",
  "Accept Invitation",
  "Reject Invitation",
  "Add User",
  "Get Pending Registration Requests Per User",  
  "Get Pending Registration Requests",
  "Approve Registration Request ",
  "Disapprove Registration Request", 
  "Get unlocking Requests",
  "Lock user account",
  "Unlock user account",
  "Change user password",
  "Reset user password",
  "Change user name",
  "Change user email",
  "Confirm email change",
  "Change user profile",
  "Get users",
  "Search users",
  "Nickname:",
  "Password:",
  "User Id:",
  "Private root directory:", 
  "Data directory:",
  "Cookies directory:",
  "Users data filename:",
  "Invited users data filename:",
  "Requesting users data filename:",
  "Locked users data filename:",
  "Sign In",
  "License",
  "Prev.Page",
  "Friend Email:",
  "Full name:",
  "Name confirmation:",
  "Email:",
  "Email confirmation:",
  "Require a temporary password",
  "Show Help",
  "Show License"
 },

 {
  "Escolha uma dessas opcoes.Pressione seta para cima ou para baixo para nevegar.Aperte Enter para selecionar",
  "Opcao selecionada:",
  "Insira um apelido.\nApenas letras minusculas a-z sao permitidas\nPrecisa conter um ponto e 5-65 caracteres para validar seu apelido.\nPressione ESC se voce quiser sair dessa janela",
  "Por favor, insira a senha.\nDeve conter no minimo 8 caracteres.\nSomente os seguintes caracteres sao permitidos:\n a-z,A-Z,0-9,_-'\"()[]{}!?.@#$%&\\/+=,;:\nPressione ESC se voce quiser sair dessa janela",
  "Entrar",
  "Ajuda",
  "Sair",
  "Mostrar valores de configuracao",
  "Requisitar Registro",
  "Aceitar Convite",
  "Rejeitar Convite",
  "Adcionar usurario",
  "Obter pedidos de registro pendentes por usuario",  
  "Obter pedidos de registro pendentes",
  "Aprovar pedido de registro",
  "Rejeitar pedido de registro", 
  "Obter solicitacao de desbloqueio",
  "Bloquear conta do usuario",
  "Desbloquear conta do usuario",
  "Mudar senha do usuario",
  "Resetar senha do usuario",
  "Mudar nome do usuario",
  "Mudar email do usuario",
  "Confirmar alteracao de email",
  "Mudar de perfil",
  "Obter usarios",
  "Buscar usuarios",
  "Apelido:",
  "Senha:",
  "Id do usuario:",
  "Raiz do diretorio privado:",
  "Diretorio de dados:",
  "Diretorio de cookies",
  "Nome do arquivo de dados dos usuarios",
  "Nome do arquivo de dados dos usuarios convidados:",
  "Nome do arquivo de dados dos usuarios em espera:",
  "Nome do arquivo de dados dos usuarios bloqueados:"
  "Cadastrar-se",
  "Licensa",
  "P.Anter.",
  "Email do amigo:",
  "Nome completo:",
  "Confirmacao do nome:",
  "Email:",
  "Confirmacao do email:",
  "Requerir senha temporaria",
  "Mostrar ajuda",
  "Mostrar Licensa"
 }
};

/*
FsfUmlGetCliUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetCliUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType fsfUmlMessage, fsfUmlLanguageType fsfUmlLanguage)
{
 if(fsfUmlMessage < 0 || fsfUmlMessage > fsfUmlTotalInterfaceMessages)
  return FsfUmlGetCliErrorMessage(fsfUmlUnknownMessage,fsfUmlLanguage);
 return(fsfUmlCliUserInterfaceMessages[fsfUmlLanguage][fsfUmlMessage]);
};

/*
FsfUmlGetUserNcursesInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetNcursesUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType fsfUmlMessage, fsfUmlLanguageType fsfUmlLanguage)
{
 if(fsfUmlMessage < 0 || fsfUmlMessage > fsfUmlTotalInterfaceMessages)
  return FsfUmlGetNcursesErrorMessage(fsfUmlUnknownMessage,fsfUmlLanguage);
 return(fsfUmlNcursesUserInterfaceMessages[fsfUmlLanguage][fsfUmlMessage]);
};
/*
FsfUmlGetWebUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType, fsfUmlLanguageType);

Arguments:

fsfUmlUserInterfaceMessageNumberType - This argument indicates the message which will be displayed to user (I)
fsfUmlLanguageType - This argument indicates in which language the message will be displayed (I)

Returned Code: 
char * - This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

Description:
This function returns a pointer that points to the begining of a string. This string contains the message that will be displayed.

*/
char *
FsfUmlGetWebUserInterfaceMessage (fsfUmlUserInterfaceMessageNumberType fsfUmlMessage, fsfUmlLanguageType fsfUmlLanguage) 
{
 if(fsfUmlMessage < 0 || fsfUmlMessage > fsfUmlTotalInterfaceMessages)
  return FsfUmlGetWebErrorMessage(fsfUmlUnknownMessage,fsfUmlLanguage);
 return(fsfUmlWebUserInterfaceMessages[fsfUmlLanguage][fsfUmlMessage]);
};

/*RCSFile*/  
