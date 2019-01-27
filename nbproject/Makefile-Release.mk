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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ASM_DYNAMIC.o \
	${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o \
	${OBJECTDIR}/ASM_MYERS.o \
	${OBJECTDIR}/ASM_READ_FILE.o \
	${OBJECTDIR}/ASM_STRING.o \
	${OBJECTDIR}/ASM_UKKONEN.o \
	${OBJECTDIR}/MIN.o \
	${OBJECTDIR}/Tests/PRECOMPUTED.o \
	${OBJECTDIR}/Tests/RANDOM_TEST.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/precomputed.o

# C Compiler Flags
CFLAGS=-m64 -pedantic -Wextra -march=native

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=--64

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asm

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asm: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asm ${OBJECTFILES} ${LDLIBSOPTIONS} -s

${OBJECTDIR}/ASM_DYNAMIC.o: ASM_DYNAMIC.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_DYNAMIC.o ASM_DYNAMIC.c

${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o: ASM_LEVENSHTEIN_OUTPUT.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o ASM_LEVENSHTEIN_OUTPUT.c

${OBJECTDIR}/ASM_MYERS.o: ASM_MYERS.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_MYERS.o ASM_MYERS.c

${OBJECTDIR}/ASM_READ_FILE.o: ASM_READ_FILE.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_READ_FILE.o ASM_READ_FILE.c

${OBJECTDIR}/ASM_STRING.o: ASM_STRING.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_STRING.o ASM_STRING.c

${OBJECTDIR}/ASM_UKKONEN.o: ASM_UKKONEN.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_UKKONEN.o ASM_UKKONEN.c

${OBJECTDIR}/MIN.o: MIN.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MIN.o MIN.c

${OBJECTDIR}/Tests/PRECOMPUTED.o: Tests/PRECOMPUTED.c
	${MKDIR} -p ${OBJECTDIR}/Tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tests/PRECOMPUTED.o Tests/PRECOMPUTED.c

${OBJECTDIR}/Tests/RANDOM_TEST.o: Tests/RANDOM_TEST.c
	${MKDIR} -p ${OBJECTDIR}/Tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tests/RANDOM_TEST.o Tests/RANDOM_TEST.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/precomputed.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/precomputed.o: tests/precomputed.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Wall -s -I. -std=c99 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/precomputed.o tests/precomputed.c


${OBJECTDIR}/ASM_DYNAMIC_nomain.o: ${OBJECTDIR}/ASM_DYNAMIC.o ASM_DYNAMIC.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_DYNAMIC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_DYNAMIC_nomain.o ASM_DYNAMIC.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_DYNAMIC.o ${OBJECTDIR}/ASM_DYNAMIC_nomain.o;\
	fi

${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT_nomain.o: ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o ASM_LEVENSHTEIN_OUTPUT.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT_nomain.o ASM_LEVENSHTEIN_OUTPUT.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT.o ${OBJECTDIR}/ASM_LEVENSHTEIN_OUTPUT_nomain.o;\
	fi

${OBJECTDIR}/ASM_MYERS_nomain.o: ${OBJECTDIR}/ASM_MYERS.o ASM_MYERS.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_MYERS.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_MYERS_nomain.o ASM_MYERS.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_MYERS.o ${OBJECTDIR}/ASM_MYERS_nomain.o;\
	fi

${OBJECTDIR}/ASM_READ_FILE_nomain.o: ${OBJECTDIR}/ASM_READ_FILE.o ASM_READ_FILE.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_READ_FILE.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_READ_FILE_nomain.o ASM_READ_FILE.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_READ_FILE.o ${OBJECTDIR}/ASM_READ_FILE_nomain.o;\
	fi

${OBJECTDIR}/ASM_STRING_nomain.o: ${OBJECTDIR}/ASM_STRING.o ASM_STRING.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_STRING.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_STRING_nomain.o ASM_STRING.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_STRING.o ${OBJECTDIR}/ASM_STRING_nomain.o;\
	fi

${OBJECTDIR}/ASM_UKKONEN_nomain.o: ${OBJECTDIR}/ASM_UKKONEN.o ASM_UKKONEN.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ASM_UKKONEN.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ASM_UKKONEN_nomain.o ASM_UKKONEN.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ASM_UKKONEN.o ${OBJECTDIR}/ASM_UKKONEN_nomain.o;\
	fi

${OBJECTDIR}/MIN_nomain.o: ${OBJECTDIR}/MIN.o MIN.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MIN.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MIN_nomain.o MIN.c;\
	else  \
	    ${CP} ${OBJECTDIR}/MIN.o ${OBJECTDIR}/MIN_nomain.o;\
	fi

${OBJECTDIR}/Tests/PRECOMPUTED_nomain.o: ${OBJECTDIR}/Tests/PRECOMPUTED.o Tests/PRECOMPUTED.c 
	${MKDIR} -p ${OBJECTDIR}/Tests
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Tests/PRECOMPUTED.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tests/PRECOMPUTED_nomain.o Tests/PRECOMPUTED.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Tests/PRECOMPUTED.o ${OBJECTDIR}/Tests/PRECOMPUTED_nomain.o;\
	fi

${OBJECTDIR}/Tests/RANDOM_TEST_nomain.o: ${OBJECTDIR}/Tests/RANDOM_TEST.o Tests/RANDOM_TEST.c 
	${MKDIR} -p ${OBJECTDIR}/Tests
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Tests/RANDOM_TEST.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tests/RANDOM_TEST_nomain.o Tests/RANDOM_TEST.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Tests/RANDOM_TEST.o ${OBJECTDIR}/Tests/RANDOM_TEST_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Wall -s -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
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

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
