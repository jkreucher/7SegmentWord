pname=segment_words

all:
	gcc src/main.c src/segment.c -o $(pname)

clean:
	rm -rf *.o $(pname)

run: all
	./$(pname)

