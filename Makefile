final: bbn.o hash.o crypthash.o 
	cc bbn.o hash.o crypthash.o -o final

bloom.o: bbn.c hash.h crypthash.h
	cc -c bbn.c

hash.o: hash.c hash.h
	cc -c hash.c

crypthash.o: crypthash.c crypthash.h
	cc -c crypthash.c
	
clean:
	rm *.o final
