adlist:
	mkdir -p output
	gcc main.c adlist.c -o output/adlist
	./output/adlist
clean:
	rm -rf output