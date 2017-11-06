##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lzw
ConfigurationName      :=Debug
WorkspacePath          := "/home/bcc/lgjr15/c++"
ProjectPath            := "/home/bcc/lgjr15/git/lzw"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=LUIZ GUSTAVO JHON RODRIGUES
Date                   :=06/11/17
CodeLitePath           :="/home/bcc/lgjr15/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="lzw.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_algorithms.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_lzw.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_file.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_dictionary.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_array.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_algorithms.cpp$(ObjectSuffix): src/algorithms.cpp $(IntermediateDirectory)/src_algorithms.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bcc/lgjr15/git/lzw/src/algorithms.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_algorithms.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_algorithms.cpp$(DependSuffix): src/algorithms.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_algorithms.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_algorithms.cpp$(DependSuffix) -MM "src/algorithms.cpp"

$(IntermediateDirectory)/src_algorithms.cpp$(PreprocessSuffix): src/algorithms.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_algorithms.cpp$(PreprocessSuffix) "src/algorithms.cpp"

$(IntermediateDirectory)/src_lzw.cpp$(ObjectSuffix): src/lzw.cpp $(IntermediateDirectory)/src_lzw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bcc/lgjr15/git/lzw/src/lzw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lzw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lzw.cpp$(DependSuffix): src/lzw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lzw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lzw.cpp$(DependSuffix) -MM "src/lzw.cpp"

$(IntermediateDirectory)/src_lzw.cpp$(PreprocessSuffix): src/lzw.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lzw.cpp$(PreprocessSuffix) "src/lzw.cpp"

$(IntermediateDirectory)/src_file.cpp$(ObjectSuffix): src/file.cpp $(IntermediateDirectory)/src_file.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bcc/lgjr15/git/lzw/src/file.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_file.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_file.cpp$(DependSuffix): src/file.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_file.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_file.cpp$(DependSuffix) -MM "src/file.cpp"

$(IntermediateDirectory)/src_file.cpp$(PreprocessSuffix): src/file.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_file.cpp$(PreprocessSuffix) "src/file.cpp"

$(IntermediateDirectory)/src_dictionary.cpp$(ObjectSuffix): src/dictionary.cpp $(IntermediateDirectory)/src_dictionary.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bcc/lgjr15/git/lzw/src/dictionary.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_dictionary.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_dictionary.cpp$(DependSuffix): src/dictionary.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_dictionary.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_dictionary.cpp$(DependSuffix) -MM "src/dictionary.cpp"

$(IntermediateDirectory)/src_dictionary.cpp$(PreprocessSuffix): src/dictionary.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_dictionary.cpp$(PreprocessSuffix) "src/dictionary.cpp"

$(IntermediateDirectory)/src_array.cpp$(ObjectSuffix): src/array.cpp $(IntermediateDirectory)/src_array.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bcc/lgjr15/git/lzw/src/array.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_array.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_array.cpp$(DependSuffix): src/array.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_array.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_array.cpp$(DependSuffix) -MM "src/array.cpp"

$(IntermediateDirectory)/src_array.cpp$(PreprocessSuffix): src/array.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_array.cpp$(PreprocessSuffix) "src/array.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


