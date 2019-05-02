#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE          := $(wildcard *.c) $(wildcard *.cpp) 
OBJS            := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE))) 


#目标文件名，输入任意你想要的执行文件名
TARGET          := mytgt

#编译参数
CC              := g++ 
#LIBS            :=  -lpthread -lm -ldl
LIBS            :=  
LIB_DIR		    := 
LDFLAGS         :=
DEFINES         := 
INCLUDE         := -I. 
CFLAGS          := -g -Wall $(DEFINES) $(INCLUDE)
CXXFLAGS        := $(CFLAGS) 

.PHONY : everything objs clean veryclean rebuild install 
everything      : $(TARGET)
all             : $(TARGET)
objs            : $(OBJS)



rebuild:        veryclean everything 
clean :
	rm -fr *.o
	rm -fr $(TARGET)
veryclean       : clean 
install:
	cp $(TARGET) ../bin
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -static $(LIB_DIR) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
