ifeq ($(DEBUG),yes)
  OPTIMIZE_FLAG = -O0 -g -DDEBUG
else
  OPTIMIZE_FLAG = -O3
endif


OBJS = read.o \
       finding_buddhism.o \
       TestScripts/hash_tables.o
DEPS = $(OBJS:.o=.d)
CC = clang
CFLAGS = -std=c99 -Wall -MMD -MP -I. $(OPTIMIZE_FLAG)
LDLIBS = -lpthread
BIN = find

all: find

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(BIN) $(LDLIBS)

%.d: %.c

clean:
	-rm -f $(OBJS) $(BIN) *.d

-include $(DEPS)
