											# ---/ TODO: ALLOW COMPILING FOR WINDOWS \--- #
PROGRAM_NAME = MyProgram
PROGRAM_VERSION = 0.0.1
MAIN_C = main.c
HAZRD_DIR = Hazrd
EXPORT_DIR = export
LINUX_EXPORT_DIR = linux
WINDOWS_EXPORT_DIR = windows

FULL_EXPORT_DIR_LINUX = $(EXPORT_DIR)/$(LINUX_EXPORT_DIR)/$(PROGRAM_NAME)_$(PROGRAM_VERSION)
FULL_EXPORT_DIR_WINDOWS = $(EXPORT_DIR)/$(WINDOWS_EXPORT_DIR)/$(PROGRAM_NAME)_$(PROGRAM_VERSION)

COMPILER = gcc
LINUX_FLAGS = -lglfw
WINDOWS_FLAGS = -Lpath/to/glfw/install/lib -lglfw

project_export_linux:
ifeq ($(OS), Windows_NT)
	@if not exists "$(EXPORT_DIR)\$(LINUX_EXPORT_DIR)\$(PROGRAM_NAME)_$(PROGRAM_VERSION)\data" ^
	   mkdir "$(EXPORT_DIR)\$(LINUX_EXPORT_DIR)\$(PROGRAM_NAME)_$(PROGRAM_VERSION)\data"
	xcopy /E /I "$(HAZRD_DIR)\shaders" "$(FULL_EXPORT_DIR_LINUX)\data\"
	del /Q "$(FULL_EXPORT_DIR_LINUX)\data\shaders\SimpeShader.frag"
	del /Q "$(FULL_EXPORT_DIR_LINUX)\data\shaders\SimpeShader.vert"
else
	mkdir -p $(EXPORT_DIR)/$(LINUX_EXPORT_DIR)/$(PROGRAM_NAME)_$(PROGRAM_VERSION)/data
	cp -r $(HAZRD_DIR)/shaders $(FULL_EXPORT_DIR_LINUX)/data/
	rm -f $(FULL_EXPORT_DIR_LINUX)/data/shaders/SimpleShader.frag
	rm -f $(FULL_EXPORT_DIR_LINUX)/data/shaders/SimpleShader.vert
endif


project_export_windows:
ifeq ($(OS), Windows_NT)
	@if not exists "$(EXPORT_DIR)\$(WINDOWS_EXPORT_DIR)\$(PROGRAM_NAME)_$(PROGRAM_VERSION)\data" ^
	   mkdir "$(EXPORT_DIR)\$(WINDOWS_EXPORT_DIR)\$(PROGRAM_NAME)_$(PROGRAM_VERSION)\data"
	xcopy /E /I "$(HAZRD_DIR)\shaders" "$(FULL_EXPORT_DIR_WINDOWS)\data\"
	del /Q "$(FULL_EXPORT_DIR_WINDOWS)\data\shaders\SimpeShader.frag"
	del /Q "$(FULL_EXPORT_DIR_WINDOWS)\data\shaders\SimpeShader.vert"
else
	mkdir -p $(EXPORT_DIR)/$(WINDOWS_EXPORT_DIR)/$(PROGRAM_NAME)_$(PROGRAM_VERSION)/data
	cp -r $(HAZRD_DIR)/shaders $(FULL_EXPORT_DIR_WINDOWS)/data/
	rm -f $(FULL_EXPORT_DIR_WINDOWS)/data/shaders/SimpleShader.frag
	rm -f $(FULL_EXPORT_DIR_WINDOWS)/data/shaders/SimpleShader.vert
endif

compile_linux: project_export_linux
ifeq ($(OS), Windows_NT)
	$(COMPILER) $(MAIN_C) $(HAZRD_DIR)/hazrd_src/*.c -o $(FULL_EXPORT_DIR_LINUX)/$(PROGRAM_NAME).x86_64 $(WINDOWS_FLAGS)
else
	$(COMPILER) $(MAIN_C) $(HAZRD_DIR)/hazrd_src/*.c -o $(FULL_EXPORT_DIR_LINUX)/$(PROGRAM_NAME).x86_64 $(LINUX_FLAGS)
endif


compile_windows: project_export_windows
	$(COMPILER) $(MAIN_C) $(HAZRD_DIR)/hazrd_src/*.c -o $(FULL_EXPORT_DIR_WINDOWS)/$(PROGRAM_NAME).exe $(WINDOWS_FLAGS)
