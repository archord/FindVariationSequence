#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/CircleList.o \
	${OBJECTDIR}/src/FindVariationSequence.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/utils.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L. -L../../../software/cfitsio/cfitsio -L../../../software/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findvariationsequence

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findvariationsequence: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findvariationsequence ${OBJECTFILES} ${LDLIBSOPTIONS} -lm -lCrossMatchLibrary -lcfitsio

${OBJECTDIR}/src/CircleList.o: src/CircleList.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CircleList.o src/CircleList.cpp

${OBJECTDIR}/src/FindVariationSequence.o: src/FindVariationSequence.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/FindVariationSequence.o src/FindVariationSequence.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/utils.o: src/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils.o src/utils.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TestCircleList.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -lm -lCrossMatchLibrary -lcfitsio -lm -lCrossMatchLibrary -lcfitsio -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -L../../../software/cfitsio/cfitsio -L../../../software/lib -L../../../software/cfitsio/cfitsio 


${TESTDIR}/tests/TestCircleList.o: tests/TestCircleList.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -Isrc -I. -I. -std=c++0x -std=c++0x -MMD -MP -MF $@.d -o ${TESTDIR}/tests/TestCircleList.o tests/TestCircleList.cpp


${OBJECTDIR}/src/CircleList_nomain.o: ${OBJECTDIR}/src/CircleList.o src/CircleList.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CircleList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CircleList_nomain.o src/CircleList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CircleList.o ${OBJECTDIR}/src/CircleList_nomain.o;\
	fi

${OBJECTDIR}/src/FindVariationSequence_nomain.o: ${OBJECTDIR}/src/FindVariationSequence.o src/FindVariationSequence.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/FindVariationSequence.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/FindVariationSequence_nomain.o src/FindVariationSequence.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/FindVariationSequence.o ${OBJECTDIR}/src/FindVariationSequence_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

${OBJECTDIR}/src/utils_nomain.o: ${OBJECTDIR}/src/utils.o src/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/utils.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I../CrossMatchLibrary/src -I../../../software/cfitsio/cfitsio -std=c++0x -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils_nomain.o src/utils.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/utils.o ${OBJECTDIR}/src/utils_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findvariationsequence

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
