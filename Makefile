wiegand_c:
	gcc -o wiegand_c test_wiegand.c wiegand.c -lpigpio -lrt

clean:
	rm -f wiegand_c *.o
