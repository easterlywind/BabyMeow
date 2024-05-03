# OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

# CC specifies which compiler we're using
CC = g++

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Iinclude\SDL2  -Iinclude\headers

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -Llib

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# OBJ_NAME specifies the name of our executable
OBJ_NAME = main

# This is the target that compiles our executable
all : 
	$(CC) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o $(OBJ_NAME) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

# This is the target that runs our executable
run : all
	./$(OBJ_NAME)

# Usage (Windows): `mingw32-make` then `mingw32-make run`