##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Progettino
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/hulk/2/fr2032442/Workspace
ProjectPath            :=/home/hulk/2/fr2032442/Workspace/Progettino
IntermediateDirectory  :=../build-$(ConfigurationName)/Progettino
OutDir                 :=../build-$(ConfigurationName)/Progettino
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=FRANCESCO RONCOLATO
Date                   :=16/11/22
CodeLitePath           :=/home/hulk/2/fr2032442/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Progettino/Date.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Progettino/tester.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Progettino/Book.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Progettino/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Progettino"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Progettino"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Progettino/.d:
	@mkdir -p "../build-$(ConfigurationName)/Progettino"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Progettino/Date.cpp$(ObjectSuffix): Date.cpp ../build-$(ConfigurationName)/Progettino/Date.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hulk/2/fr2032442/Workspace/Progettino/Date.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Date.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Progettino/Date.cpp$(DependSuffix): Date.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Progettino/Date.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Progettino/Date.cpp$(DependSuffix) -MM Date.cpp

../build-$(ConfigurationName)/Progettino/Date.cpp$(PreprocessSuffix): Date.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Progettino/Date.cpp$(PreprocessSuffix) Date.cpp

../build-$(ConfigurationName)/Progettino/tester.cpp$(ObjectSuffix): tester.cpp ../build-$(ConfigurationName)/Progettino/tester.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hulk/2/fr2032442/Workspace/Progettino/tester.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tester.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Progettino/tester.cpp$(DependSuffix): tester.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Progettino/tester.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Progettino/tester.cpp$(DependSuffix) -MM tester.cpp

../build-$(ConfigurationName)/Progettino/tester.cpp$(PreprocessSuffix): tester.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Progettino/tester.cpp$(PreprocessSuffix) tester.cpp

../build-$(ConfigurationName)/Progettino/Book.cpp$(ObjectSuffix): Book.cpp ../build-$(ConfigurationName)/Progettino/Book.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hulk/2/fr2032442/Workspace/Progettino/Book.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Book.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Progettino/Book.cpp$(DependSuffix): Book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Progettino/Book.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Progettino/Book.cpp$(DependSuffix) -MM Book.cpp

../build-$(ConfigurationName)/Progettino/Book.cpp$(PreprocessSuffix): Book.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Progettino/Book.cpp$(PreprocessSuffix) Book.cpp


-include ../build-$(ConfigurationName)/Progettino//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


