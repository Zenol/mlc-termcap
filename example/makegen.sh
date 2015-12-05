#!/usr/bin/python
##
## Made by Jeremy Cochoy
##

import os, sys, re

#Nom du projet
proj = "termcap_view"
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
f.write("## Makefile generated\n")
f.write("##\n\n")

f.write("NAME	=	%s\n\n" % proj);
f.write("OBJS	=	\\\n");

for name in src:
    if os.path.splitext(os.path.basename(name))[0] != "":
	file_name = os.path.splitext(os.path.basename(name))[0]
	f.write("		out/%s.o \\\n" % file_name)

f.write("\n#####################################################\n");
f.write("CC	=	gcc\n");
f.write("RM	=	@rm -f\n");
f.write("\n");
f.write("INCS	=	-I. -I./include -I../lib\n");
f.write("\n");
f.write("CFLAGS	=	-W -Wall -Wstrict-prototypes -ansi\n");
f.write("CFLAGS	+=	-pedantic -fomit-frame-pointer -O2 -O3\n");
f.write("CFLAGS	+=	$(INCS)");
f.write("\n");
f.write("DBGF	=	-W -Wall -Wstrict-prototypes -DDEBUG\n");
f.write("DBGF	+=	-ansi -pedantic -fomit-frame-pointer -O0 -ggdb3 $(INCS)\n");
f.write("\n");
f.write("LIBFS	=	-L. -L../lib/ -L/usr/lib/ -L/usr/local/lib/\n");
f.write("LIBNS	+=	-lmlc_${MACHTYPE}-${OSTYPE}-${HOSTTYPE} -ltermcap\n");
f.write("\n");
f.write("LFLAGS	=	$(LIBFS) $(LIBNS)\n");
f.write("\n");

f.write("#####################################################\n");
f.write("$(NAME):	$(OBJS)\n");
f.write("	@printf \"[%-9s]\\t%s\\n\" \"Linking\" $@\n");
f.write("	@$(CC) $(OBJS) $(LFLAGS) -o $(NAME)\n\n");

f.write("#####################################################\n");
for name in src:
    if os.path.splitext(os.path.basename(name))[0] != "":
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

debug:
	@printf \"[Making Debug] . . .\\n\"
	@$(CC) $(DBGF) src/*.c -o $(NAME) $(LFLAGS) -pipe
	@rm -rf *.o
	@printf \"[Done]\\n\"

clean:
	@printf \"[%-9s]\\n\" \"Clean\"
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) \#*#

fclean: clean
	@printf \"[%-9s]\\n\" \"Fclean\"
	$(RM) $(NAME)

.PHONY: all clean fclean debug re
""");
