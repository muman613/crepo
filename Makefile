###############################################################################
#	FILE		:	Makefile
#	PROJECT		:	crepo
#	DATE		:	May 5, 2016
#	LAST MOD	:	May 5, 2016
#	PROGRAMMER	:	Michael Uman
###############################################################################

TARGET_EXE=crepo
TARGET_TYPE=exe
CPP_SOURCES=main.cpp functions.cpp repoObject.cpp utils.cpp actions.cpp

ARCH?=$(shell arch)

#include ../build/sqlite3_env.mk

include ../build/Build/libxml2_env.mk
include ../build/Build/libpopt_env.mk

#ARCH_CFLAGS=-m32
#ARCH_LDFLAGS=-m32
#DEBUG_CFLAGS=-g3 -D_DEBUG

CFLAGS=-std=c++11 $(LIBXML_CFLAGS) $(LIBPOPT_CFLAGS)
LDFLAGS=$(LIBXML_LIBS) $(LIBPOPT_LIBS)


include ../build/Build/buildsys.mk

-include $(DEPS)


