#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"

void test_returns_1_for_having_equal_lengths (){
	ArrayUtil a,b;
	a.length = 10;
	b.length = 10;
	assertEqual(areLengthEqual(a,b), 1);
}

void test_returns_1_for_having_same_typeSize (){
	ArrayUtil a,b;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(int);
	assertEqual(isTypeSizeSame(a,b), 1);
}

void test_returns_0_for_having_different_types_of_same_typeSize (){
	ArrayUtil a,b;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(char);
	assertEqual(isTypeSizeSame(a,b), 0);
}

void test_returns_1_for_having_same_values_in_base (){
	int *base;
	ArrayUtil a,b;
	a.length=2;
	b.length=2;
	base = calloc(a.length,sizeof(int));
	
	((int*)a.base)[0] = 12;
	((int*)a.base)[1] = 13;

	((int*)b.base)[0] = 12;
	((int*)b.base)[1] = 13;
	assertEqual(areBaseValuesSame (a, b),1);	
}

void test_returns_0_for_having_different_values_in_base (){
	int *base;
	ArrayUtil a,b;
	a.length=3;
	b.length=3;
	a.base = calloc(a.length,sizeof(int));
	b.base = calloc(b.length,sizeof(int));

	((int*)a.base)[0] = 12;
	((int*)a.base)[1] = 13;
	((int*)a.base)[2] = 14;

	((int*)b.base)[0] = 12;
	((int*)b.base)[1] = 15;
	((int*)b.base)[2] = 14;
	assertEqual(areBaseValuesSame (a, b),0);	
}

void test_returns_1_for_same_array_utils (){
	int *base;
	ArrayUtil a,b;
	a.length = 3;
	b.length = 3;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(int);
	a.base = calloc(a.length,sizeof(int));
	b.base = calloc(b.length,sizeof(int));

	((int*)a.base)[0] = 12;
	((int*)a.base)[1] = 13;
	((int*)a.base)[2] = 14;

	((int*)b.base)[0] = 12;
	((int*)b.base)[1] = 13;
	((int*)b.base)[2] = 14;
	
	assertEqual(areEqual(a, b), 1);	
}

void test_creates_new_array_containing_all_elements_0 (){
	int typeSize = sizeof(int);
	int length = 5;
	ArrayUtil a,b;
	a = create(typeSize, length);
	b = create(typeSize, length);
	assertEqual(areEqual(a, b), 1);
}

void test_creates_new_array_containing_all_elements_0_and_gives_0_for_different_lengths (){
	int typeSize = sizeof(int);
	int length_of_a = 5;
	int length_of_b = 15;
	ArrayUtil a,b;
	a = create(typeSize, length_of_a);
	b = create(typeSize, length_of_b);
	assertEqual(areEqual(a, b), 0);
}

