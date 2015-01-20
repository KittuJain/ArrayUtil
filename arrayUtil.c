#include <stdio.h>
#include <stdlib.h>
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
	if(a.length != b.length)
		return 0;
	for(i = 0; i < (a.length*a.typeSize); i++){
		if(((char*)a.base)[i] != ((char*)b.base)[i])
			return 0;
	}
	return 1;

}

int areEqual(ArrayUtil a, ArrayUtil b){
	if(areLengthEqual(a, b) && isTypeSizeSame(a, b) && areBaseValuesSame(a, b))
		return 1;
	return 0;
}

ArrayUtil create(int typeSize, int length){
	void *base;
	ArrayUtil a;
	a.base = calloc(length,typeSize);
	a.length = length;
	a.typeSize = typeSize;
	return a;
}

ArrayUtil resize(ArrayUtil util, int length) {
	int count;
	ArrayUtil arr;
	int util_new_length = (util.typeSize)*length;
	arr.base = calloc(length, util.typeSize);
	arr.length = length;
	for(count = 0; count < util_new_length; count++){
		((char*)arr.base)[count] = ((char*)util.base)[count];
	}
	return arr;
}

int findIndex(ArrayUtil util, void* element){
	int count;
	int length = sizeof(element);
	
	for(count = 0; count < (util.length*util.typeSize); count++){
		if(length == sizeof(int)){
			if(((int*)util.base)[count] == *((int*)element))
				return count;
		}
		if(length == sizeof(float)){
			if(((float*)util.base)[count] == *((float*)element))
				return count;
		}
	}
	for(count = 0; count < (util.length*util.typeSize); count++){
		if(((char*)util.base)[count] == *((char*)element))
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
	int* base = (int*)util.base;
	for(i = 0; i < util.length; i++){
		if(match(hint,(void*)&base[i])==1)
			return (void*)&base[i];
	}
	return 0;
}