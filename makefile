CC = g++
SRC = src/*.cpp
OBJ = *.o
INC = -Iinclude -Iheaders
LIB = -Llib-mingw-w64 -Lbin
TAG = -lmingw32 -lopengl32 -lglfw3 -lgdi32 -lglew32 -lglu32
OUT = bin/libarsenic.dll
DLL = -shared -Wl,-rpath='$$ORIGIN'

windows:
	@echo --== COMPILING ARSENIC ==--
	$(CC) $(DLL) $(INC) -c $(SRC)
	$(CC) $(DLL) -o $(OUT) $(OBJ) $(LIB) $(TAG)
	del $(OBJ)
