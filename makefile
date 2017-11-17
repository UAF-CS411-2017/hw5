CPP=g++
CPPFLAGS=--std=c++17

build:
	read -p "Username: " USERNAME; \
	mkdir "test/$$USERNAME" -p; \
	cp solutions/$$USERNAME/build.* test/$$USERNAME/; \
	cp test.cpp test/$$USERNAME/; \
	clear; \
	$(CPP) $(CPPFLAGS) test/$$USERNAME/test.cpp test/$$USERNAME/build.cpp -o test/$$USERNAME/build; \
	test/$$USERNAME/build;

clean:
	rm -Rf test
	clear

test: clean build	
