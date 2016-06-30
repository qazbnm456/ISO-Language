TARGET = ISO
PP = clang++
FLAGS = -O3 -g -w -lcurses -lz -ldl -lpthread
LLVM = llvm-config
LLVM_ARGS = --cxxflags --ldflags --libs core mcjit native

all: $(TARGET)

$(TARGET): iso_main.cpp lex.yy.c y.tab.c iso_ast.cpp iso_codeGenerator.cpp iso_vm.cpp iso_gc.cpp iso_msghandler.cpp iso_variable.cpp iso_stdlib.cpp iso_hashvalue.cpp MurmurHash3.cpp
	$(PP) -o $@ iso_main.cpp lex.yy.c y.tab.c iso_ast.cpp iso_codeGenerator.cpp iso_vm.cpp iso_gc.cpp iso_msghandler.cpp iso_variable.cpp iso_stdlib.cpp iso_hashvalue.cpp MurmurHash3.cpp `$(LLVM) $(LLVM_ARGS)` $(FLAGS)

lex.yy.c: ISO.l
	lex $<

y.tab.c: ISO.y
	yacc -d $<

clean:
	@echo "Clean all created files."
	rm -f *.o lex.yy.c y.tab.c y.tab.h $(TARGET)
	rm -fR ISO.dSYM
