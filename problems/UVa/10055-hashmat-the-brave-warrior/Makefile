CXXFLAGS = -Wall -Wextra -pedantic -lm -O2 -pipe -ansi -DONLINE_JUDGE

EXECS = hashmat

.PHONY: default debug clean

default: $(EXECS)

debug: CPPFLAGS+=-DDEBUG
debug: default

clean:
	$(RM) $(EXECS)
