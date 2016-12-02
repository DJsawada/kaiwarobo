CC=g++
CFLAGS=-g -O2

####
#### When using system-installed libraries
####
CPPFLAGS=`libjulius-config --cflags` `libsent-config --cflags`
LDFLAGS=`libjulius-config --libs` `libsent-config --libs`

############################################################

all: julius-simple

julius-simple: julius-simple.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -o julius-simple julius-simple.cpp $(LDFLAGS)

clean:
	$(RM) *.o *.bak *~ core TAGS

distclean:
	$(RM) *.o *.bak *~ core TAGS
	$(RM) julius-simple
