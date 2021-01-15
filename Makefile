EXENAME = naive_bayes

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test stest clean

all : $(EXENAME)

$(EXENAME): driver.o classifier.o image.o model.o
	$(LD) driver.o classifier.o image.o model.o $(LDFLAGS) -o $(EXENAME)

driver.o : src/driver.cc includes/classifier.h includes/image.h includes/model.h
	$(CXX) $(CXXFLAGS) src/driver.cc

image.o: src/image.cc includes/image.h
	$(CXX) $(CXXFLAGS) src/image.cc

model.o : src/model.cc includes/model.h
	$(CXX) $(CXXFLAGS) src/model.cc

classifier.o : src/classifier.cc includes/classifier.h
	$(CXX) $(CXXFLAGS) src/classifier.cc

test: tests.o classifier.o image.o model.o
	$(LD) tests.o classifier.o image.o model.o $(LDFLAGS) -o test

stest: catchmain.o separatetest.o Person.o Analyzer.o PersonCollector.o
	$(LD) catchmain.o separatetest.o Person.o Analyzer.o PersonCollector.o $(LDFLAGS) -o stest

catchmain.o : tests/catchmain.cc tests/catch.hpp
	$(CXX) $(CXXFLAGS) tests/catchmain.cc

tests.o : tests/tests.cc tests/catch.hpp 
	$(CXX) $(CXXFLAGS) tests/tests.cc

separatetest.o : tests/separatetest.cc tests/catch.hpp src/main.cc
	$(CXX) $(CXXFLAGS) tests/separatetest.cc

clean:
	rm -f *.o $(EXENAME) test