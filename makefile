BIN_DIR = bin
GXX = g++
CPPFLAGS = -Wall -g
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

all: bin/alistint.o alisttest stackint.o stackinttest llist_tester llistint llistint.o

bin/alistint.o: alistint.o
	$(CXX) $(CPPFLAGS) alistint.o -c -o $@

alistint.cpp: alistint.cpp
	$(CXX) $(CPPFLAGS) alistint.cpp -c -o $@

alisttest: $(BIN_DIR)/alistint.o alisttest.cpp
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

stackint.o: bin/alistint.o stackint.cpp
	$(CXX) $(CPPFLAGS) stackint.cpp -c -o $@

stackinttest: $(BIN_DIR)/alistint.o stackint.h stackint.cpp stackinttest.cpp
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

llist_tester: llist_tester
	$(CXX) $(CPPFLAGS) llist_tester.cpp -c -o $@

llistint: llistint.cpp
	$(CXX) $(CPPFLAGS) llistint.cpp -c -o $@

llistint.o: llistint.cpp
	$(CXX) $(CPPFLAGS) llistint.cpp -c -o $@


# Make a $(BIN_DIR) directoy if it doesn't exist:
$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)