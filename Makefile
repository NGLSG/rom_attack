obj=$(wildcard *.cpp)
cmd=g++ 
flag=-std=c++2a -pthread -time -O3 -Wall -Wunreachable-code -o
main:$(obj)
	$(cmd) $(flag) $@ $^
clean:
	rm -rf *.o main
