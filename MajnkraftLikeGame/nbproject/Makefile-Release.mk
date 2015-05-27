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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Graphic/Camera.o \
	${OBJECTDIR}/Graphic/GObject.o \
	${OBJECTDIR}/Graphic/Mesh.o \
	${OBJECTDIR}/Graphic/Shader.o \
	${OBJECTDIR}/Graphic/Texture.o \
	${OBJECTDIR}/Graphic/Transformation.o \
	${OBJECTDIR}/Graphic/Window.o \
	${OBJECTDIR}/Input.o \
	${OBJECTDIR}/Kocky/KockaKamena.o \
	${OBJECTDIR}/Kocky/KockaTravy.o \
	${OBJECTDIR}/Kocky/KockaVzduchu.o \
	${OBJECTDIR}/Kocky/KockaZeme.o \
	${OBJECTDIR}/Svet/Chunk.o \
	${OBJECTDIR}/Svet/GeneratorSveta.o \
	${OBJECTDIR}/Svet/InfoKocka.o \
	${OBJECTDIR}/Svet/Svet.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraft ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Graphic/Camera.o: Graphic/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Camera.o Graphic/Camera.cpp

${OBJECTDIR}/Graphic/GObject.o: Graphic/GObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/GObject.o Graphic/GObject.cpp

${OBJECTDIR}/Graphic/Mesh.o: Graphic/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Mesh.o Graphic/Mesh.cpp

${OBJECTDIR}/Graphic/Shader.o: Graphic/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Shader.o Graphic/Shader.cpp

${OBJECTDIR}/Graphic/Texture.o: Graphic/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Texture.o Graphic/Texture.cpp

${OBJECTDIR}/Graphic/Transformation.o: Graphic/Transformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Transformation.o Graphic/Transformation.cpp

${OBJECTDIR}/Graphic/Window.o: Graphic/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Window.o Graphic/Window.cpp

${OBJECTDIR}/Input.o: Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Input.o Input.cpp

${OBJECTDIR}/Kocky/KockaKamena.o: Kocky/KockaKamena.cpp 
	${MKDIR} -p ${OBJECTDIR}/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Kocky/KockaKamena.o Kocky/KockaKamena.cpp

${OBJECTDIR}/Kocky/KockaTravy.o: Kocky/KockaTravy.cpp 
	${MKDIR} -p ${OBJECTDIR}/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Kocky/KockaTravy.o Kocky/KockaTravy.cpp

${OBJECTDIR}/Kocky/KockaVzduchu.o: Kocky/KockaVzduchu.cpp 
	${MKDIR} -p ${OBJECTDIR}/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Kocky/KockaVzduchu.o Kocky/KockaVzduchu.cpp

${OBJECTDIR}/Kocky/KockaZeme.o: Kocky/KockaZeme.cpp 
	${MKDIR} -p ${OBJECTDIR}/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Kocky/KockaZeme.o Kocky/KockaZeme.cpp

${OBJECTDIR}/Svet/Chunk.o: Svet/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/Chunk.o Svet/Chunk.cpp

${OBJECTDIR}/Svet/GeneratorSveta.o: Svet/GeneratorSveta.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/GeneratorSveta.o Svet/GeneratorSveta.cpp

${OBJECTDIR}/Svet/InfoKocka.o: Svet/InfoKocka.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/InfoKocka.o Svet/InfoKocka.cpp

${OBJECTDIR}/Svet/Svet.o: Svet/Svet.cpp 
	${MKDIR} -p ${OBJECTDIR}/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Svet/Svet.o Svet/Svet.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
