ifeq ($(DEBUG),yes)
  OPTIMIZE_FLAG = -O0 -g -DDEBUG
else
  OPTIMIZE_FLAG = -O3
endif

OBJS = finding_buddhism.o \
		hash_tables.o \
		read.o \
		classifier.o\
		thread.o
DEPS = $(OBJS:.o=.d)
CC = clang
CFLAGS = -std=gnu99 -Wall -MMD -MP -I. $(OPTIMIZE_FLAG)
LDLIBS = -lpthread
BIN = buddhism

all: buddhism

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(BIN) $(LDLIBS)

%.d: %.c

clean:
	-rm -f $(OBJS) $(BIN) *.d

-include $(DEPS)
