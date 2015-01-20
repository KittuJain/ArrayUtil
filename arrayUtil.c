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
	int util_new_length = (util.typeSize)*length;
	util.base = realloc(util.base, util_new_length);
	util.length = length;
	return util;
}

int findIndex(ArrayUtil util, void* element){
	int count;
	float* _element = element;
	float* base_ptr = util.base;
	for(count = 0; count < util.length; count++){
		if(base_ptr[count] == *_element)
			return count;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
	util.length = 0;
}
