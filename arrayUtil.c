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
	for(i = 0; i < a.length; i++){
		if(((int*)a.base)[i] != ((int*)b.base)[i])
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
	int *base;
	ArrayUtil a;
	a.base = calloc(length,typeSize);
	a.length = length;
	a.typeSize = typeSize;
	return a;
}

