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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Core/Engine.o \
	${OBJECTDIR}/Core/Input.o \
	${OBJECTDIR}/Core/Transformation.o \
	${OBJECTDIR}/Game/Game.o \
	${OBJECTDIR}/Game/Kocky/KockaKamena.o \
	${OBJECTDIR}/Game/Kocky/KockaTravy.o \
	${OBJECTDIR}/Game/Kocky/KockaVzduchu.o \
	${OBJECTDIR}/Game/Kocky/KockaZeme.o \
	${OBJECTDIR}/Game/Svet/Chunk.o \
	${OBJECTDIR}/Game/Svet/GeneratorSveta.o \
	${OBJECTDIR}/Game/Svet/InfoKocka.o \
	${OBJECTDIR}/Game/Svet/Svet.o \
	${OBJECTDIR}/Graphic/Attenuation.o \
	${OBJECTDIR}/Graphic/BaseLight.o \
	${OBJECTDIR}/Graphic/Camera.o \
	${OBJECTDIR}/Graphic/DirectionalLight.o \
	${OBJECTDIR}/Graphic/GObject.o \
	${OBJECTDIR}/Graphic/Material.o \
	${OBJECTDIR}/Graphic/Mesh.o \
	${OBJECTDIR}/Graphic/PhongShader.o \
	${OBJECTDIR}/Graphic/PointLight.o \
	${OBJECTDIR}/Graphic/Shader.o \
	${OBJECTDIR}/Graphic/Texture.o \
	${OBJECTDIR}/Graphic/TextureBasicShader.o \
	${OBJECTDIR}/Graphic/Window.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraftlikegame.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraftlikegame.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraftlikegame ${OBJECTFILES} ${LDLIBSOPTIONS} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32

${OBJECTDIR}/Core/Engine.o: Core/Engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Core/Engine.o Core/Engine.cpp

${OBJECTDIR}/Core/Input.o: Core/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Core/Input.o Core/Input.cpp

${OBJECTDIR}/Core/Transformation.o: Core/Transformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Core/Transformation.o Core/Transformation.cpp

${OBJECTDIR}/Game/Game.o: Game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Game.o Game/Game.cpp

${OBJECTDIR}/Game/Kocky/KockaKamena.o: Game/Kocky/KockaKamena.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Kocky/KockaKamena.o Game/Kocky/KockaKamena.cpp

${OBJECTDIR}/Game/Kocky/KockaTravy.o: Game/Kocky/KockaTravy.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Kocky/KockaTravy.o Game/Kocky/KockaTravy.cpp

${OBJECTDIR}/Game/Kocky/KockaVzduchu.o: Game/Kocky/KockaVzduchu.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Kocky/KockaVzduchu.o Game/Kocky/KockaVzduchu.cpp

${OBJECTDIR}/Game/Kocky/KockaZeme.o: Game/Kocky/KockaZeme.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Kocky/KockaZeme.o Game/Kocky/KockaZeme.cpp

${OBJECTDIR}/Game/Svet/Chunk.o: Game/Svet/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Svet/Chunk.o Game/Svet/Chunk.cpp

${OBJECTDIR}/Game/Svet/GeneratorSveta.o: Game/Svet/GeneratorSveta.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Svet/GeneratorSveta.o Game/Svet/GeneratorSveta.cpp

${OBJECTDIR}/Game/Svet/InfoKocka.o: Game/Svet/InfoKocka.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Svet/InfoKocka.o Game/Svet/InfoKocka.cpp

${OBJECTDIR}/Game/Svet/Svet.o: Game/Svet/Svet.cpp 
	${MKDIR} -p ${OBJECTDIR}/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game/Svet/Svet.o Game/Svet/Svet.cpp

${OBJECTDIR}/Graphic/Attenuation.o: Graphic/Attenuation.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Attenuation.o Graphic/Attenuation.cpp

${OBJECTDIR}/Graphic/BaseLight.o: Graphic/BaseLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/BaseLight.o Graphic/BaseLight.cpp

${OBJECTDIR}/Graphic/Camera.o: Graphic/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Camera.o Graphic/Camera.cpp

${OBJECTDIR}/Graphic/DirectionalLight.o: Graphic/DirectionalLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/DirectionalLight.o Graphic/DirectionalLight.cpp

${OBJECTDIR}/Graphic/GObject.o: Graphic/GObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/GObject.o Graphic/GObject.cpp

${OBJECTDIR}/Graphic/Material.o: Graphic/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Material.o Graphic/Material.cpp

${OBJECTDIR}/Graphic/Mesh.o: Graphic/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Mesh.o Graphic/Mesh.cpp

${OBJECTDIR}/Graphic/PhongShader.o: Graphic/PhongShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/PhongShader.o Graphic/PhongShader.cpp

${OBJECTDIR}/Graphic/PointLight.o: Graphic/PointLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/PointLight.o Graphic/PointLight.cpp

${OBJECTDIR}/Graphic/Shader.o: Graphic/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Shader.o Graphic/Shader.cpp

${OBJECTDIR}/Graphic/Texture.o: Graphic/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Texture.o Graphic/Texture.cpp

${OBJECTDIR}/Graphic/TextureBasicShader.o: Graphic/TextureBasicShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/TextureBasicShader.o Graphic/TextureBasicShader.cpp

${OBJECTDIR}/Graphic/Window.o: Graphic/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graphic/Window.o Graphic/Window.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/majnkraftlikegame.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
