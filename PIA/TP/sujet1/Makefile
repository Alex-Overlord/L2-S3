#################################################################################

#	- Quelques informations :
	
#	Nom Prénom :
#	Date :
#	Intitulé du projet :
#	Matière / Encadrant :

	
#	- Utilisation :

#	make clean (supprime les fichiers issus de la programmation)
#	make archive (crée une archive contenant les sources de l’application)
#	make arch (crée une archive pour la diffusion de l’application)
#	make save (crée une sauvegarde dans un répertoire au format JJ_MM_AAAA/)
#	make dep (Calcul des dépendances des fichiers sources)

#################################################################################

#				- Variables -

#	- La Compilation :
CC 		= $(MSQ)gcc
FLAGS		= -Wall
LIBS		=
DEP_FLAG = -MM

#	- Les Fichiers :
PROGNAME = prog # Nom de l’application
ARCH 		= $(PROGNAME).tar.gz
ARCH SRC = $(PROGNAME) src.tar.gz
SOURCE 	= 1.cpp 2.cpp 3.cpp 4.cpp
HEADERS 	= 
THIS 		= Makefile
VERSION 	= `eval\ date\ +%d_%m_%Y`
DEP_FILE = .depend

#	- Le Shell :
MSQ 		= @
RM 		= $(MSQ)rm -f
LS 		= $(MSQ)ls -a --color
MV 		= $(MSQ)mv
MKDIR 	= $(MSQ)mkdir -p
CLEAR 	= $(MSQ)clear
MAKE 		= $(MSQ)make
TAR 		= $(MSQ)tar -czf

#	- La VF :
MSG 		= $(MSQ)echo -e
MSG1 		= $(MSG) "Compilation de $<\t==>\t$@"
MSG2 		= $(MSG) "Edition de lien de $^\t==>\t$@"
MSG_OK 	= $(MSG) "\t\t\t......................Ok"

#				- Cibles -

#	- Cibles Usuelles :
ifeq ($(wildcard $(DEP_FILE)),)
all : $(DEP_FILE)
		$(MAKE) --no-print -directory
else
all : $(PROGNAME)
endif
dep : $(DEP_FILE)
arch : $(ARCH)
archive : $(ARCH_SRC)
save : $(VERSION)

#	- Les Archives :
$(ARCH) : $(THIS) $(PROGNAME) $(HEADERS) $(SOURCE:.c=.h) $(SOURCE:.c=.o)
		$(MSG) "Création de l’archive $@\n\tAjout des fichiers : $ˆ"
		$(TAR) $@ $ˆ
		$(MSG_OK)

$(ARCH_SRC) : $(THIS) $(SOURCE) $(SOURCE:.c=.h) $(HEADERS)
		$(MSG) ” C ré a t i o n de l ’ a r c h i v e $@\n\ t A j o u t d e s f i c h i e r s : $ ˆ ”
		$(TAR)$@ $ˆ
		$(MSG_OK)

$(VERSION) : $(ARCH_SRC)
		$(MSG) "Création du répertoire de sauvegarde : $@" 
		$(RM) -rf $@
		$(MKDIR) $@
		$(MSG) "Sauvegarde de l'Archive $<"
		$(MV) $< $@
		$(MSG_OK)

#	- Le Nettoyage :
cls :
		$(MSG) "On fait le ménage"
		$(RM) \#∗
		$(RM) ∗~
		$(RM) core
		$(RM) ∗.o
		$(RM) $(PROGNAME)
		$(RM) $(ARCH)
		$(RM) $(ARCH_SRC)
		$(RM) $(DEP_FILE)
		$(MSG_OK)

clean : cls
		$(CLEAR)
		$(LS)

#	- La Compilation :
.SUFFIXES : .c .h .o
$(DEP_FILE) : $(SOURCE)
		$(MSG) "Recherche des dépendances des fichiers..."
		$(RM) $(DEP_FILE)
		$(CC) $(DEP_FLAG) $ˆ >> $@
		$(MSG_OK)

.c.o :
		$(MSG1)
		$(CC) -c $(FLAGS) $(LIBS) $<
		$(MSG_OK)

$(PROGNAME) : $(SOURCE :.c=.o)
$(MSG2)
$(CC) $(FLAGS) $(LIBS) $ˆ -o $@
$(MSG_OK)