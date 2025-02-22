all: universalCalculator

universalCalculator: driver.o binaryCalculator.o binaryConversion.o hexCalculator.o hexConversion.o
	g++ -o universalCalculator driver.o binaryCalculator.o binaryConversion.o hexCalculator.o hexConversion.o

binaryCalculator.o: binaryCalculator.cpp binaryCalculator.h
	g++ -c binaryCalculator.cpp

binaryConversion.o: binaryConversion.cpp binaryConversion.h
	g++ -c binaryConversion.cpp

hexCalculator.o: hexCalculator.cpp hexCalculator.h hexConversion.h
	g++ -c hexCalculator.cpp

hexConversion.o: hexConversion.cpp hexConversion.h
	g++ -c hexConversion.cpp

driver.o: driver.cpp binaryCalculator.h binaryConversion.h hexCalculator.h hexConversion.h
	g++ -c driver.cpp

run:
	./universalCalculator

clean:
	rm -f universalCalculator driver.o binaryCalculator.o binaryConversion.o hexCalculator.o hexConversion.o