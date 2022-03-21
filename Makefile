.SUFFIXES: .cpp .o .x .hpp .txt

DIR = `$(CURDIR)`

NAME1 = KDTree
NAME2 = in
NAME3 = Generator

INPUT1 = $(NAME2).txt

OBJS1 = $(NAME1).o
OBJS2 = $(NAME3).o

EXEC1 = $(NAME1).x
EXEC2 = $(NAME3).x

HEADS1 = $(NAME1).hpp

CFLAFS = -std=c++17 -Wall -O
LFLAGS = -std=c++17 -Wall -O

CO = g++
LD = $(CO)

%.o: %.cpp
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1) $(HEADS1)
	$(LD) -o $@ $(LFLAGS) $(OBJS1) $(HEADS1)
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $(OBJS2)



.PHONY: run runGen
run: $(EXEC1)
	./$(EXEC1) < $(INPUT1)
runGen: $(EXEC2)
	./$(EXEC2)


.PHONY: clean
clean:
	rm -f *.o *.x result.txt;


