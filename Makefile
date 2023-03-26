PROG = pjt
# OBJSに実行に必要なオブジェクトファイルを追加
OBJS = mainPJT.o createNode.o addNode.o printTree.o Sort_Struct.o clearBinSTree.o mystrlen.o mystrcmp.o mystrcpy.o substString.o sortBinSTree.o mystrsubst.o DictStruct.o removeNode.o addque.o createque.o file.o chomp.o uNode.o standard.o
CC = gcc
CFLAGS = -Wall -g -O0
LDFLAGS = -lm
.PHONY: all
all: $(PROG)

.SUFFIXES: .o.c
.c.o:
	$(CC) $(CFLAGS) -c $<
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)
