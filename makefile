#Windows
EXE_EXT :=.exe
#About the rest of the world.
#EXE_EXT :=.exe

TARGET := blakely$(EXE_EXT)

GIF := test.gif
TEST_CMD := $(TARGET) "xx*yy*" 32 > $(GIF)

#Windows only
SEE_GIF := start $(GIF)


all: test
	
$(TARGET): ioccc-blakely.c
	$(CC) -o $@ $^ -O3 -lm

$(GIF): $(TARGET)
	$(TEST_CMD)
	
.PHONY:
test: $(GIF)
	$(SEE_GIF)
	
clean:
	rm $(GIF)
	rm $(TARGET)