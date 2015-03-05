TARGET = ISO
PP = g++
FLAGS = -O3 -g -w -lcurses
LLVM = llvm-config-mp-3.7
LLVM_ARGS = --cxxflags --ldflags --libs all

all: $(TARGET)

$(TARGET): iso_main.cpp lex.yy.c y.tab.c iso_ast.cpp iso_codeGenerator.cpp
	$(PP) -o $@ iso_main.cpp lex.yy.c y.tab.c iso_ast.cpp iso_codeGenerator.cpp `$(LLVM) $(LLVM_ARGS)` $(FLAGS)

lex.yy.c: ISO.l
	lex $<

y.tab.c: ISO.y
	yacc -d $<

clean:
	@echo "Clean all created files."
	rm -f *.o lex.yy.c y.tab.c y.tab.h $(TARGET)
	rm -fR ISO.dSYM