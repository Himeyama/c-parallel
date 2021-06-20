CC      = cc
LIBS    = -lpthread
PROGRAM = main
SRC     = main.c

$(PROGRAM): $(SRC)
	$(CC) -o $@ $^ $(LIBS)
