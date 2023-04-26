CC = g++
APP_SRC = main.cpp
OBJ = *.o
APP_NAME = app.exe
APP_TAG = -lmingw32 -lopengl32 -lglfw3 -lgdi32 -lglew32 -lglu32 -larsenic
LIB = -L../lib-mingw-w64 -L.
INC = -I../include -I../headers


windows:
	@echo --== COMPILING APP ==--
	g++ $(INC) -Wl,-rpath='$$ORIGIN' -c $(APP_SRC)
	g++ -Wl,-rpath='$$ORIGIN' -o  $(APP_NAME) $(OBJ) $(LIB) $(APP_TAG)
	del $(OBJ)
