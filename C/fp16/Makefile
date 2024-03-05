

OBJSC = main.o \

LIBBASE = ./a.out
LDLIBS   = -lrt -lm -mfp16-format=ieee

override CC=mpicc

all: a.out

# Note the implicit rule to compile '.c' files into '.o' files is
# %.o : %.c
# 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

a.out: $(OBJSC)
	$(CC) -o $(LIBBASE) $^ $(LDLIBS)

.PHONY: clean
clean:
	rm -f  $(OBJSC) $(LIBBASE)
