#!/usr/bin/python
## makegen.sh for gnerating makefile
## 
## Made by Jeremy Cochoy
##

import os, sys, re

#Nom du projet
proj = "mlc"
args = sys.argv
if len(args) > 1:
    proj = args[1]
print "Generating makefile for %s..." % proj

#Verification des repertoires

if os.path.isdir('src') == False:
    print "Can't find dirrectory ./src"
    exit (0)
if os.path.isdir('out') == False:
    print "Creating dirrectory ./out"
    os.mkdir("out");

#List des headers et sources

src = os.listdir('src');
include = []
if os.path.isdir('include'):
	include = os.listdir('include')
else:
    print "Warning: Your headers file have to be in ./include/"

f = open("Makefile", "w")

f.write("##\n")
f.write("## Makefile for %s in /home/cochoy_j/rendu/%s\n" % (proj, proj))
f.write("## \n")
f.write("## Made by Jeremy Cochoy\n")
f.write("##\n\n")

f.write("NAME	=	lib%s_${MACHTYPE}-${OSTYPE}-${HOSTTYPE}.a\n\n" % proj);
f.write("NDBG	=	lib%s_${MACHTYPE}-${OSTYPE}-${HOSTTYPE}-d.a\n\n" % proj);
f.write("OBJS	=	\\\n");

for name in src:
    if os.path.splitext(os.path.basename(name))[1] == ".c":
	file_name = os.path.splitext(os.path.basename(name))[0]
	f.write("		out/%s.o \\\n" % file_name)

f.write("\n#####################################################\n");
f.write("CC	=	gcc\n");
f.write("RM	=	rm -f\n");
f.write("AR	=	ar -crs\n");
f.write("CP	=	cp\n");
f.write("\n");
f.write("INCS	=	-I./include -I. \n");
f.write("\n");
f.write("CFLAGS	=	-W -Wall -Wstrict-prototypes -ansi\n");
f.write("CFLAGS	+=	-pedantic -fomit-frame-pointer -O2 -O3\n");
f.write("CFLAGS	+=	$(INCS)");
f.write("\n");
f.write("DBGF	=	-W -Wall -Wstrict-prototypes -DDEBUG\n");
f.write("DBGF	+=	-ansi -pedantic -O0 -ggdb3 -I../include -I.. \n");
f.write("\n");
f.write("LIBFS	=	\n");
f.write("LIBNS	+=	\n");
f.write("\n");
f.write("LFLAGS	=	$(LIBFS) $(LIBNS)\n");
f.write("\n");

f.write("#####################################################\n");
f.write("$(NAME):	$(OBJS)\n");
f.write("	@printf \"[%-9s]\\t%s\\n\" \"Linking\" $@\n");
f.write("	@$(AR) $(NAME) $(OBJS)\n");
f.write("	@$(CP) $(NAME) ../\n");
f.write("	@$(CP) %s.h ../\n" % proj);

f.write("#####################################################\n");
for name in src:
    if os.path.splitext(os.path.basename(name))[1] == ".c":
	file_name = "out/%s.o" % os.path.splitext(os.path.basename(name))[0]
	name = "src/%s" % name
	if os.path.isfile(name):
	    print "\nAdding %s" % name
	    #Parcour du fichier
            dep = []
            r = open(name, "r")
            for line in r:
		elms = re.findall("^#include \"([-a-zA-Z0-9._]+)\"", line)
		if len(elms) > 0:
                    dep.append(elms[0])
            #Regle de compilation
            f.write("\n%s:\t%s \\\n" % (file_name, name))
            for id in range(len(dep)):
		print "\tDepend on %s" % dep[id]
		if os.path.isfile("include/%s" % dep[id]):
                    f.write("\t\tinclude/%s\\\n" % dep[id])
                if os.path.isfile("lib/%s" % dep[id]):
                    f.write("\t\tlib/%s\\\n" % dep[id])
            f.write("\n\t@printf \"[Compiling]\\t%%-65s -> %%s\\n\" %s %s\n" % (name, file_name))
            f.write("\t@$(CC) $(CFLAGS) -c %s -o %s\n" % (name, file_name))

#End of makefile

f.write("""
all:	$(NAME)

re:	fclean all

debug:  fclean
	@printf \"[Making Debug] . . .\\n\"
	@cd src && $(CC) $(DBGF) *.c -c && mv *.o ../
	@$(AR) $(NAME) *.o
	@$(CP) $(NAME) ../
	@$(CP) $(NAME) $(NDBG)
	@$(CP) $(NDBG) ../
	@$(CP) mlc.h ../
	@$(RM) src/*.o
	@$(RM) *.o
	@printf \"[Done]\\n\"

clean:
	@printf \"[%-9s]\\n\" \"Clean\"
	@$(RM) $(OBJS)
	@$(RM) *~
	@$(RM) \#*#

fclean: clean
	@printf \"[%-9s]\\n\" \"Fclean\"
	@$(RM) $(NAME)

.PHONY: all clean fclean debug re
""");
