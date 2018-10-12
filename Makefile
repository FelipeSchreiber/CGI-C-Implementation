#Universidade Federal do Rio de Janeiro 
#Escola Politecnica Departamento de Eletronica e de Computacao Prof. Marcelo Luiz Drumond Lanza EEL 270 - Computacao II - Turma 2017/1 
#$Author$ 
#$Date$
#$Log$


LFLAGS= -ansi -Wall 
CFLAGS= -ansi -Wall -std=c99
LD= gcc
CC= gcc

ROOT = /users/felipe.schreiber/private/EEL270/2017-1/FSF_TOP
ROOTTEST = /users/felipe.schreiber/public/html/EEL270/2017-1/FSF_TOP

MAKEDIRECTORIES = $(ROOT)/Binaries\
	$(ROOT)/Data/Cookies\
	$(ROOT)/CGIs\
	$(ROOT)/Html\
	$(ROOTTEST)/CGIs\
	$(ROOTTEST)/HTML\

CGIOBJS = fsfUmlUserInterface.o fsfUmlErrors.o
CGIMAINOBJS = fsfUmlCgiMain.o $(CGIOBJS)
CGIHELPOBJS = fsfUmlShowWebHelp.o $(CGIOBJS)
CGIREGISTEROBJS = fsfUmlShowRequestRegistrationForm.o $(CGIOBJS)
CGIPASSWORDOBJS = fsfUmlShowRequestPasswordResetForm.o $(CGIOBJS)
CGILICENSEOBJS = fsfUmlShowLicense.o $(CGIOBJS)
CGILOGINOBJS = fsfUmlCgiLogin.o $(CGIOBJS)

ALLCGIOBJS = $(CGIMAINOBJS)\
	$(CGIREGISTEROBJS)\
	$(CGIPWDOBJS)\
	$(CGILICENSEOBJS)

fsfUmlObjs= fsfUml.o fsfUmlFunctions.o fsfUmlUserInterface.o fsfUmlErrors.o fsfUmlGetPendingRegistrationRequests.o fsfUmlRunNcursesInterface.o fsfUmlGetPendingRegistrationRequestsPerUser.o 

CGIs= *.cgi

EXECS= fsfUml

.c.o:
	$(CC) $(CFLAGS) -c $<

all:$(EXECS) $(CGIs)

fsfUml: $(fsfUmlObjs) 
	$(CC) -o fsfUml $(fsfUmlObjs) -lcrypt -lcurses

install:$(EXECS) $(CGIs) MAKEDIRs
	cp fsfUml $(ROOT)/Binaries/
	cp ./../HTML/index* $(ROOT)/Html/
	cp ./../HTML/index* $(ROOTTEST)/HTML/
	cp $(ROOT)/CGIs/*.cgi $(ROOTTEST)/CGIs/
	rm -f /users/felipe.schreiber/public/html/index.html

MAKEDIRs:
	mkdir -p $(MAKEDIRECTORIES)

deinstall:
	rm -rf $(ROOT)
	rm -rf $(ROOTTEST)
	rmdir $(ROOT)
	rmdir $(ROOTTEST)

fsfUmlMain.cgi: $(CGIMAINOBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGIMAINOBJS) -LLibraries -lmlcgi

fsfUmlShowWebHelp.cgi: $(CGIHELPOBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGIHELPOBJS) -LLibraries -lmlcgi

fsfUmlShowRequestRegistrationForm.cgi: $(CGIREGISTEROBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGIREGISTEROBJS) -LLibraries -lmlcgi

fsfUmlShowRequestPasswordResetForm.cgi: $(CGIPASSWORDOBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGIPWDOBJS) -LLibraries -lmlcgi

fsfUmlShowLicense.cgi: $(CGILICENSEOBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGILICENSEOBJS) -LLibraries -lmlcgi	

fsfUmlCgiLogin.cgi: $(CGILOGINOBJS)
	$(LD) $(LFLAGS) -o $(ROOT)/CGIs/$@ $(CGILOGINOBJS) -LLibraries -lmlcgi				

clean:
	rm -f *.o $(EXECS) 
	
#$RCSFile$













