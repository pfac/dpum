CXXFLAGS ?= -Wall -Wextra -pedantic

EXECS = flood dijkstra

.PHONY: default debug clean

%.opp: %.cpp
	$(COMPILE.cpp) $< -o $@

%: %.opp
	$(LINK.cpp) $^ -o $@

default: $(EXECS)

debug: CPPFLAGS+=-DDEBUG
debug: CXXFLAGS+=-g
debug: $(EXECS)

flood: flood.opp

dijkstra: dijkstra.opp

clean:
	$(RM) *.opp
	$(RM) $(EXECS)
