#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

int areLengthEqual(ArrayUtil a, ArrayUtil b){
	if(a.length==b.length)
		return 1;
	return 0;
}	

int isTypeSizeSame (ArrayUtil a, ArrayUtil b){
	if(a.typeSize == b.typeSize)
		return 1;
	return 0;
}

int areBaseValuesSame (ArrayUtil a, ArrayUtil b){
	int i;
	char *util1 = ((char*)a.base);
	char *util2 = ((char*)b.base);

	if(areLengthEqual(a, b) == 0)
		return 0;
	for(i = 0; i < (a.length*a.typeSize); i++){
		if(util1[i] != util2[i])
			return 0;
	}
	return 1;
}

int arrayEqual (int *array1, int *array2){
	int i;
	if((sizeof(array1))!=(sizeof(array2)))
		return 0;
	
	for(i = 0; i < sizeof(array1); i++){
		if(array1[i] != array2[i])
			return 0;
	}
	return 1;
}

int areEqual(ArrayUtil a, ArrayUtil b){
	if(isTypeSizeSame(a, b) && areBaseValuesSame(a, b))
		return 1;
	return 0;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil util1 = {calloc(length,typeSize), typeSize, length};
	return util1;
}

ArrayUtil resize(ArrayUtil util, int length) {
	int count;
	int size = util.typeSize;
	int len = util.length > length ? length : util.length;
	ArrayUtil new_util = {calloc(length, size), size, length};

	for(count = 0; count < len*size; count++){
		((char*)new_util.base)[count] = ((char*)util.base)[count];
	}

	return new_util;
}

int findIndex(ArrayUtil util, void* element){
	int count;
	void *base;
	for(count = 0; count < (util.length*util.typeSize); count++){
		base = &(util.base)[count*util.typeSize];
		if(!memcmp(base, element, util.typeSize))
			return count;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
	util.length = 0;
}

void* findFirst(ArrayUtil util, MatchFunc *match, void* hint){
	int i;
	char* base = (char*)util.base;

	for(i = 0; i < util.length; i++){
		if(match(hint, (void*)(&base[i*util.typeSize])))
			return (void*)&base[i*util.typeSize];
	}
	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc *match, void* hint){
	int i;
	char* base = (char*)util.base;
	for(i = (util.length)-1; i >= 0; i--){
		if(match(hint, (void*)&base[i*util.typeSize]))
			return (void*)&base[i*util.typeSize];
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int i, count = 0;
	char* base = (char*)util.base;
	for(i = 0; i < util.length; i++){
		if(match(hint, (void*)&base[i*util.typeSize]))
			count++;
	}
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int count;
	int len = 0;
	char** _destination =(char**) destination;
	char* base = (char*) util.base;
	void* item ;
	
	for (count = 0; count < util.length;count++){
		
		item = &(base[(count * util.typeSize)]);
		if(match(hint,(void*)item) && len < maxItems){
			memcpy(&((*_destination)[len * util.typeSize]), item, util.typeSize);
			len++;
		}
	}
	return len;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int counter;
	void *sourceItem;
	void *destinationItem;
	for(counter = 0; counter < source.length; counter++){
		sourceItem = (void*)&(source.base[counter*source.typeSize]);
		destinationItem = (void*)&(destination.base[counter*source.typeSize]);
		convert(hint, sourceItem, destinationItem);
	}
}

void forEach(ArrayUtil source, OperationFunc* operation, void* hint){
	int counter;
	void *sourceItem;
	for(counter = 0; counter < source.length; counter++){
		sourceItem = (void*)&(source.base[counter*source.typeSize]);
		operation(hint, sourceItem);
	}
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint , void* initialValue){
	int counter;
	void* sourceItem, *result;
	for(counter = 0; counter < util.length; counter++){
		sourceItem = (void*)&(util.base[counter*util.typeSize]);
		result = reducer(hint, initialValue, sourceItem);
		initialValue = result;
	}
	return result;
}