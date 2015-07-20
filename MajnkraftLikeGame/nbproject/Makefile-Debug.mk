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
	${OBJECTDIR}/source/Core/Engine.o \
	${OBJECTDIR}/source/Core/Input.o \
	${OBJECTDIR}/source/Core/Transformation.o \
	${OBJECTDIR}/source/Game/Game.o \
	${OBJECTDIR}/source/Game/Kocky/KockaKamena.o \
	${OBJECTDIR}/source/Game/Kocky/KockaTravy.o \
	${OBJECTDIR}/source/Game/Kocky/KockaVzduchu.o \
	${OBJECTDIR}/source/Game/Kocky/KockaZeme.o \
	${OBJECTDIR}/source/Game/Svet/Chunk.o \
	${OBJECTDIR}/source/Game/Svet/GeneratorSveta.o \
	${OBJECTDIR}/source/Game/Svet/InfoKocka.o \
	${OBJECTDIR}/source/Game/Svet/Svet.o \
	${OBJECTDIR}/source/Graphic/Camera.o \
	${OBJECTDIR}/source/Graphic/GObject.o \
	${OBJECTDIR}/source/Graphic/Lights/Attenuation.o \
	${OBJECTDIR}/source/Graphic/Lights/BaseLight.o \
	${OBJECTDIR}/source/Graphic/Lights/DirectionalLight.o \
	${OBJECTDIR}/source/Graphic/Lights/PointLight.o \
	${OBJECTDIR}/source/Graphic/Lights/SpotLight.o \
	${OBJECTDIR}/source/Graphic/Material.o \
	${OBJECTDIR}/source/Graphic/Mesh.o \
	${OBJECTDIR}/source/Graphic/MeshCube.o \
	${OBJECTDIR}/source/Graphic/PhongShader.o \
	${OBJECTDIR}/source/Graphic/Shader.o \
	${OBJECTDIR}/source/Graphic/Texture.o \
	${OBJECTDIR}/source/Graphic/TextureBasicShader.o \
	${OBJECTDIR}/source/Graphic/Vertex.o \
	${OBJECTDIR}/source/Graphic/Window.o \
	${OBJECTDIR}/source/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_CONF}/Minekraft.exe

${CND_CONF}/Minekraft.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_CONF}
	${LINK.cc} -o ${CND_CONF}/Minekraft ${OBJECTFILES} ${LDLIBSOPTIONS} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32

${OBJECTDIR}/source/Core/Engine.o: source/Core/Engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Core/Engine.o source/Core/Engine.cpp

${OBJECTDIR}/source/Core/Input.o: source/Core/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Core/Input.o source/Core/Input.cpp

${OBJECTDIR}/source/Core/Transformation.o: source/Core/Transformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Core/Transformation.o source/Core/Transformation.cpp

${OBJECTDIR}/source/Game/Game.o: source/Game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Game.o source/Game/Game.cpp

${OBJECTDIR}/source/Game/Kocky/KockaKamena.o: source/Game/Kocky/KockaKamena.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Kocky/KockaKamena.o source/Game/Kocky/KockaKamena.cpp

${OBJECTDIR}/source/Game/Kocky/KockaTravy.o: source/Game/Kocky/KockaTravy.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Kocky/KockaTravy.o source/Game/Kocky/KockaTravy.cpp

${OBJECTDIR}/source/Game/Kocky/KockaVzduchu.o: source/Game/Kocky/KockaVzduchu.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Kocky/KockaVzduchu.o source/Game/Kocky/KockaVzduchu.cpp

${OBJECTDIR}/source/Game/Kocky/KockaZeme.o: source/Game/Kocky/KockaZeme.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Kocky
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Kocky/KockaZeme.o source/Game/Kocky/KockaZeme.cpp

${OBJECTDIR}/source/Game/Svet/Chunk.o: source/Game/Svet/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Svet/Chunk.o source/Game/Svet/Chunk.cpp

${OBJECTDIR}/source/Game/Svet/GeneratorSveta.o: source/Game/Svet/GeneratorSveta.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Svet/GeneratorSveta.o source/Game/Svet/GeneratorSveta.cpp

${OBJECTDIR}/source/Game/Svet/InfoKocka.o: source/Game/Svet/InfoKocka.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Svet/InfoKocka.o source/Game/Svet/InfoKocka.cpp

${OBJECTDIR}/source/Game/Svet/Svet.o: source/Game/Svet/Svet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Game/Svet
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Game/Svet/Svet.o source/Game/Svet/Svet.cpp

${OBJECTDIR}/source/Graphic/Camera.o: source/Graphic/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Camera.o source/Graphic/Camera.cpp

${OBJECTDIR}/source/Graphic/GObject.o: source/Graphic/GObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/GObject.o source/Graphic/GObject.cpp

${OBJECTDIR}/source/Graphic/Lights/Attenuation.o: source/Graphic/Lights/Attenuation.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic/Lights
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Lights/Attenuation.o source/Graphic/Lights/Attenuation.cpp

${OBJECTDIR}/source/Graphic/Lights/BaseLight.o: source/Graphic/Lights/BaseLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic/Lights
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Lights/BaseLight.o source/Graphic/Lights/BaseLight.cpp

${OBJECTDIR}/source/Graphic/Lights/DirectionalLight.o: source/Graphic/Lights/DirectionalLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic/Lights
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Lights/DirectionalLight.o source/Graphic/Lights/DirectionalLight.cpp

${OBJECTDIR}/source/Graphic/Lights/PointLight.o: source/Graphic/Lights/PointLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic/Lights
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Lights/PointLight.o source/Graphic/Lights/PointLight.cpp

${OBJECTDIR}/source/Graphic/Lights/SpotLight.o: source/Graphic/Lights/SpotLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic/Lights
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Lights/SpotLight.o source/Graphic/Lights/SpotLight.cpp

${OBJECTDIR}/source/Graphic/Material.o: source/Graphic/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Material.o source/Graphic/Material.cpp

${OBJECTDIR}/source/Graphic/Mesh.o: source/Graphic/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Mesh.o source/Graphic/Mesh.cpp

${OBJECTDIR}/source/Graphic/MeshCube.o: source/Graphic/MeshCube.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/MeshCube.o source/Graphic/MeshCube.cpp

${OBJECTDIR}/source/Graphic/PhongShader.o: source/Graphic/PhongShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/PhongShader.o source/Graphic/PhongShader.cpp

${OBJECTDIR}/source/Graphic/Shader.o: source/Graphic/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Shader.o source/Graphic/Shader.cpp

${OBJECTDIR}/source/Graphic/Texture.o: source/Graphic/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Texture.o source/Graphic/Texture.cpp

${OBJECTDIR}/source/Graphic/TextureBasicShader.o: source/Graphic/TextureBasicShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/TextureBasicShader.o source/Graphic/TextureBasicShader.cpp

${OBJECTDIR}/source/Graphic/Vertex.o: source/Graphic/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Vertex.o source/Graphic/Vertex.cpp

${OBJECTDIR}/source/Graphic/Window.o: source/Graphic/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Graphic
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Graphic/Window.o source/Graphic/Window.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_CONF}/Minekraft.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
