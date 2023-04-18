CC = g++
SRC = src/*.cpp
APP_NAME = app.exe
INC = -Iinclude
LIB = -Llib-mingw-w64
TAG = -lopengl32 -lglfw3 -lgdi32 -lglew32

windows:
	@echo --== COMPILING ARSENIC ==--
	g++ -o $(APP_NAME) $(SRC) $(INC) $(LIB) $(TAG)
	@echo --== RUNNING ARSENIC ==--
	@$(APP_NAME)   
