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
	${OBJECTDIR}/Kocky/KockaTravy.o \
	${OBJECTDIR}/Mesh.o \
	${OBJECTDIR}/Shader.o \
	${OBJECTDIR}/Svet/Chunk.o \
	${OBJECTDIR}/Svet/GeneratorSveta.o \
	${OBJECTDIR}/Svet/InfoKocka.o \
	${OBJECTDIR}/Svet/Svet.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/Transformation.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lSDL2 -lGL -lGLEW -lSDL2_image

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Kocky/KockaTravy.o: Kocky/KockaTravy.cpp 
	${MKDIR} -p ${OBJECTDIR}/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Kocky/KockaTravy.o Kocky/KockaTravy.cpp

${OBJECTDIR}/Mesh.o: Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mesh.o Mesh.cpp

${OBJECTDIR}/Shader.o: Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Shader.o Shader.cpp

${OBJECTDIR}/Svet/Chunk.o: Svet/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/Chunk.o Svet/Chunk.cpp

${OBJECTDIR}/Svet/GeneratorSveta.o: Svet/GeneratorSveta.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/GeneratorSveta.o Svet/GeneratorSveta.cpp

${OBJECTDIR}/Svet/InfoKocka.o: Svet/InfoKocka.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/InfoKocka.o Svet/InfoKocka.cpp

${OBJECTDIR}/Svet/Svet.o: Svet/Svet.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/Svet.o Svet/Svet.cpp

${OBJECTDIR}/Texture.o: Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/Transformation.o: Transformation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Transformation.o Transformation.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
