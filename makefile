all: all.out
all.out : premiership.o premiershipdatabase.o result.o result_test.o premiershipdbtest.o
	g++ $^ -lgtest -lgtest_main -lpthread -o $@ 
premiershipdbtest.o: premiershipdbtest.cpp result.h premiership.h premiershipdatabase.h
	g++ $< -c
result_test.o: result_test.cpp result.h premiership.h
	g++ $< -c
premiershipdatabase.o : premiershipdatabase.cpp premiershipdatabase.h premiership.h result.h
	g++ $< -c
result.o : result.cpp premiership.h result.h
	g++ $< -c    
premiership.o : premiership.cpp premiership.h
	g++ $< -c
valgrind.o : ./all.out
	valgrind ./all.out
cppcheck: *.cpp
	cppcheck *.cpp
clean:
	rm -rf *.o *.out
