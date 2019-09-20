# TODO detect if on windows or not
#Windows
EXE_EXT :=.exe
#About the rest of the world.
EXE_EXT :=

TARGET := blakely$(EXE_EXT)

GIF := test.gif
# TODO don't prepend "./" on windows
TEST_CMD := ./$(TARGET) "xx*yy*" 32 > $(GIF)

# FIXME Windows only
# SEE_GIF := start $(GIF)
SEE_GIF := xdg-open $(GIF)


CFLAGS := -O3 -Wall
SRC := ioccc-blakely.c v3.c parser.c
OBJ := $(SRC:.c=.o)

all: test

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -O3 -lm

$(GIF): $(TARGET)
	$(TEST_CMD)

.PHONY:
test: $(GIF)
	$(SEE_GIF)

.PHONY:
clean:
	rm $(OBJ)
	rm $(GIF)

.PHONY:
deepclean: clean
	rm $(TARGET)

.PHONY:
nuke: deepclean


.PHONY:
love:
	@echo not war

#------ Dependencies -----

parser.c: parser.h
v3.c: v3.h
