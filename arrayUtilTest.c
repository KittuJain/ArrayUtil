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
	int *baseTempOfA;
	int *baseTempOfB;

	a.length=2;
	b.length=2;
	base = calloc(a.length,sizeof(int));

	baseTempOfA = ((int*)a.base);
	baseTempOfB = ((int*)b.base);

	baseTempOfA[0] = 12;
	baseTempOfA[1] = 13;

	baseTempOfB[0] = 12;
	baseTempOfB[1] = 13;
	assertEqual(areBaseValuesSame (a, b),1);	
}

void test_returns_0_for_having_different_values_in_base (){
	int *base;
	ArrayUtil a,b;
	int *baseTempOfA;
	int *baseTempOfB;
	a.length=3;
	b.length=3;
	a.base = calloc(a.length,sizeof(int));
	b.base = calloc(b.length,sizeof(int));

	baseTempOfA = ((int*)a.base);
	baseTempOfB = ((int*)b.base);

	baseTempOfA[0] = 12;
	baseTempOfA[1] = 13;
	baseTempOfA[2] = 14;

	baseTempOfB[0] = 12;
	baseTempOfB[1] = 15;
	baseTempOfB[2] = 14;
	assertEqual(areBaseValuesSame (a, b),0);	
}

void test_returns_1_for_same_array_utils (){
	int *base;
	ArrayUtil a,b;
	int *baseTempOfA;
	int *baseTempOfB;
	a.length = 3;
	b.length = 3;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(int);
	a.base = calloc(a.length,sizeof(int));
	b.base = calloc(b.length,sizeof(int));

	baseTempOfA = ((int*)a.base);
	baseTempOfB = ((int*)b.base);

	baseTempOfA[0] = 12;
	baseTempOfA[1] = 13;
	baseTempOfA[2] = 14;

	baseTempOfB[0] = 12;
	baseTempOfB[1] = 13;
	baseTempOfB[2] = 14;
	
	assertEqual(areEqual(a, b), 1);	
}

void test_returns_1_for_same_array_utils_of_char_type (){
	char *base;
	ArrayUtil a,b;
	char *baseTempOfA;
	char *baseTempOfB;
	a.length = 3;
	b.length = 3;
	a.typeSize = sizeof(char);
	b.typeSize = sizeof(char);
	a.base = calloc(a.length,sizeof(char));
	b.base = calloc(b.length,sizeof(char));

	baseTempOfA = ((char*)a.base);
	baseTempOfB = ((char*)b.base);

	baseTempOfA[0] = 'k';
	baseTempOfA[1] = 'r';
	baseTempOfA[2] = 'a';

	baseTempOfB[0] = 'k';
	baseTempOfB[1] = 'r';
	baseTempOfB[2] = 'a';
	
	assertEqual(areEqual(a, b), 1);	
}

void test_creates_new_array_containing_all_elements_0 (){
	int typeSize = sizeof(int);
	int length = 5;
	ArrayUtil a,b;
	a = create(typeSize, length);
	b = create(typeSize, length);
	assertEqual(areEqual(a, b), 1);
	free(a.base);
	free(b.base);
}

void test_creates_new_array_containing_all_elements_0_and_gives_0_for_different_lengths (){
	int typeSize = sizeof(int);
	int length_of_a = 5;
	int length_of_b = 15;
	ArrayUtil a,b;
	a = create(typeSize, length_of_a);
	b = create(typeSize, length_of_b);
	assertEqual(areEqual(a, b), 0);
	free(a.base);
	free(b.base);
}

void test_resizes_already_created_array (){
	int length = 5;
	ArrayUtil util, new_util;
	util = create(sizeof(int), length);
	new_util = resize(util, 10);
	assertEqual(areEqual(util, new_util), 0);
}

void test_findIndex_returns_3_if_search_element_is_at_3rd_location (){
	ArrayUtil util;
	int length = 6;
	int typeSize = sizeof(int);
	int *baseTempOfA;
	int element = 3;
	util = create(typeSize,length);
	baseTempOfA = ((int*)util.base); 

	baseTempOfA[0] = 4;
	baseTempOfA[1] = 2;
	baseTempOfA[2] = 1;
	baseTempOfA[3] = 3;
	baseTempOfA[4] = 6;
	baseTempOfA[5] = 0;
	assertEqual(findIndex(util, &element),3);
}

void test_findIndex_returns_neg_1_if_the_search_element_not_found (){
	ArrayUtil util;
	int length = 6;
	int typeSize = sizeof(int);
	int *baseTempOfA;
	int element = 34;
	util = create(typeSize,length);
	baseTempOfA = ((int*)util.base); 

	baseTempOfA[0] = 4;
	baseTempOfA[1] = 2;
	baseTempOfA[2] = 1;
	baseTempOfA[3] = 5;
	baseTempOfA[4] = 6;
	baseTempOfA[5] = 0;
	assertEqual(findIndex(util, &element),-1);
}

void test_findIndex_returns_4_if_search_element_is_at_4th_location (){
	ArrayUtil util;
	int length = 6;
	int typeSize = sizeof(float);
	float *baseTempOfA;
	float element = 7.8;
	util = create(typeSize,length);
	baseTempOfA = ((float*)util.base); 

	baseTempOfA[0] = 4.2;
	baseTempOfA[1] = 2.9;
	baseTempOfA[2] = 1.4;
	baseTempOfA[3] = 3.1;
	baseTempOfA[4] = 7.8;
	baseTempOfA[5] = .90;
	assertEqual(findIndex(util, &element),4);
}