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
	${OBJECTDIR}/src/Synapsis/Core/SynapsisBase.o \
	${OBJECTDIR}/src/Synapsis/Log/Log.o \
	${OBJECTDIR}/src/Synapsis/Sensor/Sensor.o \
	${OBJECTDIR}/src/Synapsis/Sensor/SimpleSwitch.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-I src
CXXFLAGS=-I src

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/domalgoserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/domalgoserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/domalgoserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Synapsis/Core/SynapsisBase.o: src/Synapsis/Core/SynapsisBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Synapsis/Core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Synapsis/Core/SynapsisBase.o src/Synapsis/Core/SynapsisBase.cpp

${OBJECTDIR}/src/Synapsis/Log/Log.o: src/Synapsis/Log/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Synapsis/Log
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Synapsis/Log/Log.o src/Synapsis/Log/Log.cpp

${OBJECTDIR}/src/Synapsis/Sensor/Sensor.o: src/Synapsis/Sensor/Sensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Synapsis/Sensor
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Synapsis/Sensor/Sensor.o src/Synapsis/Sensor/Sensor.cpp

${OBJECTDIR}/src/Synapsis/Sensor/SimpleSwitch.o: src/Synapsis/Sensor/SimpleSwitch.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Synapsis/Sensor
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Synapsis/Sensor/SimpleSwitch.o src/Synapsis/Sensor/SimpleSwitch.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/domalgoserver

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
