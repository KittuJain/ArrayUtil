#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)

#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"

ArrayUtil util1, util2;
void setup(){
	util1 = create(INT_SIZE,2);
	util2 = create(INT_SIZE,2);
}

void teardown(){
	dispose(util1);
	dispose(util2);
}

void test_areLengthEqual_returns_1_for_having_equal_lengths (){
	ArrayUtil a,b;
	a.length = 10;
	b.length = 10;
	assertEqual(areLengthEqual(a,b), 1);
}

void test_isTypeSizeSame_returns_1_for_having_same_typeSize (){
	ArrayUtil a,b;
	a.typeSize = INT_SIZE;
	b.typeSize = INT_SIZE;
	assertEqual(isTypeSizeSame(a,b), 1);
}

void test_isTypeSizeSame_returns_0_for_having_different_types_of_same_typeSize (){
	ArrayUtil a,b;
	a.typeSize = INT_SIZE;
	b.typeSize = CHAR_SIZE;
	assertEqual(isTypeSizeSame(a,b), 0);
}

void test_areBaseValuesSame_returns_1_for_having_same_values_in_base (){
	ArrayUtil util1 = { (int[]){2,5,3},INT_SIZE,2 };
	ArrayUtil util2 = { (int[]){2,5,3},INT_SIZE,2 };	
	assertEqual(areBaseValuesSame(util1, util2), 1);	
}

void test_areBaseValuesSame_returns_0_for_having_different_values_in_base (){	
	ArrayUtil util1 = { (int[]){2,5,3},INT_SIZE,2 };
	ArrayUtil util2 = { (int[]){2,9,5},INT_SIZE,2 };	
	assertEqual(areBaseValuesSame(util1, util2), 0);	
}

void test_areEqual_returns_1_for_same_array_utils_of_int_type (){
	ArrayUtil util1 = { (int[]){2,5},INT_SIZE,2 };
	ArrayUtil util2 = { (int[]){2,5},INT_SIZE,2 };	
	assertEqual(areEqual(util1, util2), 1);	
}

void test_areEqual_returns_1_for_same_array_utils_of_char_type (){
	ArrayUtil util1 = { (char[]){'k','r','a'},CHAR_SIZE,3 };
	ArrayUtil util2 = { (char[]){'k','r','a'},CHAR_SIZE,3 };
	assertEqual(areEqual(util1, util2), 1);	
}

void test_areEqual_returns_1_for_same_array_utils_of_float_type (){
	ArrayUtil util1 = { (float[]){1.4,2.5,7.8,8.3},FLOAT_SIZE,4 };
	ArrayUtil util2 = { (float[]){1.4,2.5,7.8,8.3},FLOAT_SIZE,4 };
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_returns_0_for_different_array_utils_of_int_type (){
	ArrayUtil util1 = { (int[]){2,5,3},INT_SIZE,3 };
	ArrayUtil util2 = { (int[]){2,5,1},INT_SIZE,3 };	
	assertEqual(areEqual(util1, util2), 0);	
}

void test_areEqual_returns_0_for_different_array_utils_of_char_type (){
	ArrayUtil util1 = { (char[]){'k','r','a','t','i'},CHAR_SIZE,5 };
	ArrayUtil util2 = { (char[]){'k','r','a','t','j'},CHAR_SIZE,5 };
	assertEqual(areEqual(util1, util2), 0);	
}

void test_areEqual_returns_0_for_different_array_utils_of_float_type (){
	ArrayUtil util1 = { (float[]){1.4,2.5,7.8,5.3},FLOAT_SIZE,4 };
	ArrayUtil util2 = { (float[]){1.4,2.5,7.8,8.3},FLOAT_SIZE,4 };
	assertEqual(areEqual(util1, util2), 0);
}

void test_Create_creates_new_array_of_int_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},INT_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(INT_SIZE, 2)), 1);
}

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},FLOAT_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(FLOAT_SIZE, 2)), 1);
}

void test_Create_creates_new_array_of_char_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},CHAR_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(CHAR_SIZE, 2)), 1);
}

void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	assertEqual(areEqual(expectedUtil, create(INT_SIZE, 2)), 0);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(FLOAT_SIZE, 3)), 0);
}

void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	assertEqual(areEqual(expectedUtil, create(CHAR_SIZE, 2)), 0);
}

void test_resizeUtil_resizes_already_created_util (){
	ArrayUtil util1 = create(INT_SIZE, 3);
	ArrayUtil expectedUtil = {(int[]){0,0,0,0},INT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util1, 4)), 1);
}

void test_resize_sets_new_elements_to_0 (){
	ArrayUtil util = {(int[]){4,2,1},INT_SIZE,3};
	ArrayUtil expectedUtil = {(int[]){0,0,0,0},INT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util1, 4)), 1);
}

void test_resize_trims_array_by_length (){
	ArrayUtil util = {(int[]){4,2,1,4,1,9},INT_SIZE,6};
	ArrayUtil expectedUtil = {(int[]){0,0,0,0},INT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util1, 4)), 1);
}

void test_resize_sets_new_elements_of_char_array_to_0 (){
	ArrayUtil util1 = {(char[]){4,2,1},CHAR_SIZE,3};
	assertEqual(areEqual(util1, resize(util1, 4)), 0);
}

void test_findIndex_returns_3_if_search_element_is_at_3rd_location (){
	int element = 3;
	ArrayUtil util = {(int[]){4,2,1,3,6,0},INT_SIZE,6};
	assertEqual(findIndex(util, &element),3);
}

void test_findIndex_returns_neg_1_if_the_search_element_not_found (){
	int element = 9;
	ArrayUtil util = {(int[]){4,2,1,3,6,0},INT_SIZE,6};
	assertEqual(findIndex(util, &element),-1);
}

void test_findIndex_returns_4_for_float_array_if_search_element_is_at_4th_location (){
	float element = 7.8;
	ArrayUtil util = {(float[]){4.2,2.9,1.4,3.1,7.8,8.7},FLOAT_SIZE,6};
	assertEqual(findIndex(util, &element),4);
}

void test_findIndex_returns_2_for_char_array_if_search_element_is_at_2nd_location (){
	char element = 'h';
	ArrayUtil util = {(char[]){'t','a','h'},CHAR_SIZE,3};
	assertEqual(findIndex(util, &element),2);
}

void test_dispose_frees_memory_allocated_for_arrayUtil (){
	ArrayUtil util1 = create(INT_SIZE, 3);
	dispose(util1);
}

int isGreaterThanHint (void* hint, void* element) {
	return (*((float*)element) > *((float*)hint)) ? 1 : 0;
}

void test_findFirst_gives_occurence_of_first_element_greaterThan5 (){
	int hint = 5;
	int *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){1,2,1,3,8,0},INT_SIZE,6};
	result = (int*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,8);
}

void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}

void test_findFirst_gives_NULL_for_no_elementGreaterThanHint5 (){
	int hint = 5;
	int result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){1,2,1,3,4,0},INT_SIZE,6};
	result = (int)findFirst(util,match,(void*)&hint);
	assertEqual(result,0);
}

int isElementM (void* hint, void* element) {
	return (*((char*)element) == *((char*)hint)) ? 1 : 0;
}

void test_findFirst_gives_occurence_of_first_element_in_charArray_greaterThan5 (){
	char hint = 'h';
	char *result;
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'m','a','h','a','v','i','r'},CHAR_SIZE,6};
	result = (char*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,'h');
}

void test_findLast_gives_occurence_of_first_element_greaterThan5 (){
	int hint = 5;
	int *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,1,3,8,0},INT_SIZE,6};
	result = (int*)findLast(util,match,(void*)&hint);
	assertEqual(*result,8);
}

void test_findLast_gives_NULL_for_no_elementGreaterThanHint (){
	int hint = 85;
	int result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,1,3,8,0},INT_SIZE,6};
	result = (int)findLast(util,match,(void*)&hint);
	assertEqual(result,0);
}

void test_findLast_gives_occurence_of_last_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findLast(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}

void test_findLast_gives_occurence_of_last_element_in_charArray_greaterThan5 (){
	char hint = 'h';
	char *result;
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'m','a','h','a','v','i','r'},CHAR_SIZE,6};
	result = (char*)findLast(util,match,(void*)&hint);
	assertEqual(*result,'h');
}

void test_count_counts_the_number_of_elements_greaterThanHint (){
	int hint = 5;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,6,3,8,0},INT_SIZE,6};
	assertEqual(count(util, match, (void*)&hint),3);
}

void test_count_counts_the_number_of_elements_of_float_that_are_greaterThanHint (){
	float hint = 5.1;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,9.7,8.3,0.1},FLOAT_SIZE,6};
	assertEqual(count(util, match, (void*)&hint),3);
}

void test_count_counts_the_number_of_elements_of_char_that_are_equal_to_hint (){
	char hint = 'h';
	char *result;
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'k','h','u','h','g','h'},CHAR_SIZE,6};
	assertEqual(count(util, match, (void*)&hint),3);
}

// void test_filter_filters_the_util_array_which_matches_the_criteria (){
// 	int hint = 4;
// 	MatchFunc *match = &isGreaterThanHint;
// 	ArrayUtil util = {(int[]){7,2,6,3,8,9},INT_SIZE,6};
// 	int *destination;
// 	ArrayUtil expectedUtil = {(int[]){7,6,8,9},INT_SIZE,4};
// 	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),1);
	// assertEqual(areEqual(expectedUtil, *(int*)destination), 1);
// }