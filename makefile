#Place this makefile in the same directory as your all .cpp and .h files
#at the command prompt
#make ./turnerFinal  (or whatever you call the TARGET)

# for use with C++ files
.SUFFIXES: .cpp

SOURCES = main.cpp Computer.cpp Grid.cpp Human.cpp Player.cpp Point.cpp Ship.cpp

######Change from matrix to (for example hw1) .#######
TARGET = turnerFinal

#-------Do Not Change below this line-------------
#Compile with g++
CC = g++

#use -g for gnu debugger and -std= for c++14 compiling
CXXFLAGS = -g -std=c++14

OBJS:= ${SOURCES:.cpp=.o}

######Do NOT change this...Tabs Matter!#########
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

#In order to get rid of all .o files create, at the command prompt
#make clean

clean:
	rm -f $(OBJS) $(TARGET) core
