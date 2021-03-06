#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void test_areEqual_returns_1_for_same_array_utils_of_string_type(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, STRING_SIZE, 1};
	ArrayUtil array2 = {b, STRING_SIZE, 1};

	assertEqual(areEqual(array1,array2),1);
}

void test_areEqual_returns_1_for_different_strings_in_array_utils_of_string_type(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, STRING_SIZE, 1};
	ArrayUtil array2 = {b, STRING_SIZE, 1};

	assertEqual(areEqual(array1,array2),0);
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

void test_areEqual_returns_1_for_Student_when_data_of_structure_is_same () {
	ArrayUtil util1 = { (students[]){{1, 50}, {2, 100}}, sizeof(students), 2};
	ArrayUtil util2 = { (students[]){{1, 50}, {2, 100}}, sizeof(students), 2};
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_returns_0_for_Student_when_data_structure_are_different () {
	ArrayUtil util1 = { (students[]){{1, 50}, {2, 100}}, sizeof(students), 2};
	ArrayUtil util2 = { (students[]){{1, 500}, {2, 200}}, sizeof(students), 2};
	assertEqual(areEqual(util1, util2), 0);
}

void test_Create_creates_new_array_of_int_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},INT_SIZE,2};
	ArrayUtil newUtil = create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 1);
	dispose(newUtil);
}

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil = create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 1);
	dispose(newUtil);
}

void test_Create_creates_new_array_of_char_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(int[]){0,0},CHAR_SIZE,2};
	ArrayUtil newUtil = create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 1);
	dispose(newUtil);
}

void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	ArrayUtil newUtil = create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil = create(FLOAT_SIZE, 3);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}

void test_Create_creates_new_doubleArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(double[]){0,0},DOUBLE_SIZE,2};
	ArrayUtil util = create(DOUBLE_SIZE, 3);
	assertEqual(areEqual(expectedUtil, util), 0);
	dispose(util);
}

void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	ArrayUtil util = create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, util), 0);
	dispose(util);
}

void test_areEqual_should_return_1_when_two_students_type_of_array_are_created_whose_length_are_same () {
	ArrayUtil expectedUtil = { (students[]){{0, 0}, {0, 0}}, sizeof(students), 2};
	ArrayUtil util = create(sizeof(students), 2);
    assertEqual(areEqual(expectedUtil, util), 1);
    dispose(util);
}

void test_areEqual_should_return_0_when_two_students_type_of_array_are_created_whose_length_are_different () {
	ArrayUtil expectedUtil = { (students[]){{0, 0}, {0, 0}}, sizeof(students), 3};
	ArrayUtil util = create(sizeof(students), 2);
    assertEqual(areEqual(expectedUtil, util), 0);
    dispose(util);
}

void test_areEqual_should_return_0_when_two_students_type_of_array_are_created_whose_baseValues_are_different () {
	ArrayUtil expectedUtil = { (students[]){{1, 500}, {2, 100}}, sizeof(students), 2};
   ArrayUtil util = create(sizeof(students), 2);
    assertEqual(areEqual(expectedUtil, util), 0);
    dispose(util);
}

void test_resizeUtil_resizes_already_created_util_of_int_type (){
	ArrayUtil util1 = create(INT_SIZE, 3);
	ArrayUtil expectedUtil = {(int[]){0,0,0,0},INT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util1, 4)), 1);
}

void test_resize_trims_int_array_by_length (){
	ArrayUtil util = {(int[]){4,2,1,4,1,9},INT_SIZE,6};
	ArrayUtil expectedUtil = {(int[]){4,2,1},INT_SIZE,3};
	assertEqual(areEqual(expectedUtil, resize(util, 3)), 1);
}

void test_resize_sets_new_elements_of_int_array_to_0 (){
	ArrayUtil util = {(int[]){400000000,200000000,100000000},INT_SIZE,3};
	ArrayUtil expectedUtil = {(int[]){400000000,200000000,100000000,0},INT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util, 4)), 1);
}

void test_resize_sets_new_elements_of_float_array_to_0 (){
	ArrayUtil util = {(float[]){4.0,2.0,1.0},FLOAT_SIZE,3};
	ArrayUtil expectedUtil = {(float[]){4.0,2.0,1.0,0},FLOAT_SIZE,4};
	assertEqual(areEqual(expectedUtil, resize(util, 4)), 1);
}

void test_resize_sets_new_elements_of_char_array_to_0 (){
	ArrayUtil util = {(char[]){'k','r','a'},CHAR_SIZE,3};
	ArrayUtil expectedUtil = {(char[]){'k','r','a',0,0},CHAR_SIZE,5};
	assertEqual(areEqual(expectedUtil, resize(util, 5)), 1);
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    String array1[] = {"Krati","Ambuj","Jain"}, array2[] = {"Krati","Ambuj"};
    ArrayUtil util1 = {array1,STRING_SIZE,3};
    ArrayUtil util2 = {array2,STRING_SIZE,2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);
}

void test_findIndex_returns_3_if_search_element_is_at_3rd_location_of_int_array (){
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

void test_findFirst_gives_NULL_for_no_element_is_GreaterThanHint5 (){
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

void test_findFirst_gives_occurence_of_first_h_in_charArray_ (){
	char hint = 'h';
	char *result;
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'m','a','h','a','v','i','r'},CHAR_SIZE,6};
	result = (char*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,'h');
}

void test_findLast_gives_occurence_of_last_element_greaterThan5 (){
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

void test_findLast_gives_occurence_of_last_element_in_charArray_equal_to_h (){
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

void test_filter_filters_the_util_intArray_which_matches_the_criteria (){
	int hint = 4;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,6,3,8,9},INT_SIZE,6};
	int *destination;
	destination = malloc(INT_SIZE*4);
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),4);
	assertEqual(destination[0], 7);
	assertEqual(destination[1], 6);
	assertEqual(destination[2], 8);
	assertEqual(destination[3], 9);
	free(destination);
}

void test_filter_filters_the_util_floatArray_which_matches_the_criteria (){
	float hint = 5.1;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	float *destination;
	destination = malloc(FLOAT_SIZE*2);
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),2);
	assertEqual(destination[0], (float)7.1);
	assertEqual(destination[1], (float)8.3);
	free(destination);
}

void test_filter_filters_the_util_charArray_which_matches_the_criteria (){
	char hint = 'h';
	char *result;
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'k','h','u','h','g','h'},CHAR_SIZE,6};
	char *destination;
	destination = malloc(CHAR_SIZE*3);
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),3);
	assertEqual(destination[0], 'h');
	assertEqual(destination[1], 'h');
	assertEqual(destination[2], 'h');
	free(destination);
}

void test_filter_returns_0_when_the_criteria_is_not_matched_in_int_array (){
	int hint = 34;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,6,3,8,9},INT_SIZE,6};
	int *destination;
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 0),0);
}

void test_filter_returns_0_when_the_criteria_is_not_matched_in_float_array (){
	float hint = 85.1;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	float *destination;
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 0),0);
}

void test_filter_returns_0_when_the_criteria_is_not_matched_in_char_array (){
	char hint = 'a';
	MatchFunc *match = &isElementM;
	ArrayUtil util = {(char[]){'k','h','u','h','g','h'},CHAR_SIZE,6};
	char *destination;
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 0),0);
}

int isElementHello (void *hint, void *element){
	if(strcmp((char*)element,(char*)hint) == 0)
		return 1;
	return 0;
}

void test_filter_of_string_array_filters_array (){
	char* hint = "hello";
	MatchFunc *match = &isElementHello;
	ArrayUtil util = {(char*[]){"hello","world"},STRING_SIZE,2};
 	char **destination;
 	destination = malloc(STRING_SIZE*1);
 	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 1), 1);
 	free(destination);
}

void test_filter_of_string_array_filters_array_and_returns_0 (){
	char* hint = "hello";
	MatchFunc *match = &isElementHello;
	ArrayUtil util = {(char*[]){"hi","world"},STRING_SIZE,2};
 	char **destination;
 	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 0), 0);
}

void addHintInElement(void* hint, void* sourceItem, void* destinationItem){
	*((float*)destinationItem) = *((float*)sourceItem) + *((float*)hint);
}

void test_map_is_performed_for_int_array_of_eight_elements () {
	int hint = 2;
	ConvertFunc *convert = &addHintInElement;
	ArrayUtil source = {(int[]){7,2,6,3,8,9,5,4},INT_SIZE,8};
	ArrayUtil expectedUtil = {(int[]){9,4,8,5,10,11,7,6},INT_SIZE,8};
	ArrayUtil destination = create(INT_SIZE,8);
	map(source, destination, convert, (void*)&hint);
	assertEqual(areEqual(destination, expectedUtil), 1);
	dispose(destination);
}

void test_map_is_performed_for_float_array_of_eight_elements () {
	float hint = 2.0;
	ConvertFunc *convert = &addHintInElement;
	ArrayUtil source = {(float[]){7.0, 2.0, 6.0, 3.0, 8.0, 9.0, 5.0, 4.0},FLOAT_SIZE,8};
	ArrayUtil expectedUtil = {(float[]){9.0, 4.0, 8.0, 5.0, 10.0, 11.0, 7.0, 6.0},FLOAT_SIZE,8};
	ArrayUtil destination = create(FLOAT_SIZE,8);
	map(source, destination, convert, (void*)&hint);
	assertEqual(areEqual(destination, expectedUtil), 1);
	dispose(destination);
}

void test_map_is_performed_for_float_array_of_eight_elements_with_values_after_decimalPoint () {
	float hint = 2.1;
	ConvertFunc *convert = &addHintInElement;
	ArrayUtil source = {(float[]){7.6, 2.9, 6.5, 3.7, 7.0, 9.0, 5.0, 4.0},FLOAT_SIZE,8};
	ArrayUtil destination = create(FLOAT_SIZE,8);
	ArrayUtil expectedUtil = {(float[]){9.7, 5.0, 8.6, 5.8, 9.1, 11.1, 7.1, 6.1},FLOAT_SIZE,8};
	map(source, destination, convert, (void*)&hint);
	assertEqual(areEqual(destination, expectedUtil), 1);
	dispose(destination);
}

void makeCapital(void* hint, void* sourceItem, void* destinationItem){
	*((char*)destinationItem) = *((char*)sourceItem) + 32;
}

void test_map_converts_a_b_c_d_e_to_A_B_C_D_E_in_charArray(){
	char hint = 32;
	ArrayUtil source = {(char[]){'A','B','C','D','E'},CHAR_SIZE,5};
	ArrayUtil destination = create(CHAR_SIZE,5);
	ArrayUtil expected = {(char[]){'a','b','c','d','e'},CHAR_SIZE,5};
	map(source,destination,makeCapital,(void*)&hint);
	assertEqual(areEqual(destination,expected),1);
	dispose(destination);
}

void addTwiceHintInElement(void* hint, void* item){
	*((float *)item)= *((float *)item) + (2*(*((float *)hint)));
}

void test_forEach_is_performed_for_int_array_of_eight_elements () {
	int hint = 2;
	int array[]={7,2,6,3,8,9,5,4};
	int incremented[]={11,6,10,7,12,13,9,8};
	ArrayUtil util={array,INT_SIZE,8};
	ArrayUtil expected={incremented,INT_SIZE,8};
	forEach(util,addTwiceHintInElement,(void*)&hint);
	assert(areEqual(util,expected));
}

void test_forEach_is_performed_for_float_array_of_eight_elements () {
	float hint = 2.0;
	float array[]={7.6, 2.9, 6.5, 3.7, 7.0, 9.0, 5.0, 4.0};
	float incremented[]={11.6, 6.90, 10.5, 7.70, 11.0, 13.0, 9.00, 8.00};
	ArrayUtil util={array,FLOAT_SIZE,8};
	ArrayUtil expected={incremented,FLOAT_SIZE,8};
	forEach(util,addTwiceHintInElement,(void*)&hint);
	assert(areEqual(util,expected));
}

void makeCursive(void* hint, void* sourceItem){
	*((char*)sourceItem) = *((char*)sourceItem) - 32;
}

void test_forEach_converts_A_B_C_D_E_to_a_b_c_d_e_in_charArray(){
	char hint = 32;
	char sourceArray[] = {'a','b','c','d','e'};
	char expectedArray[] = {'A','B','C','D','E'};
	ArrayUtil source = {sourceArray,CHAR_SIZE,5};
	ArrayUtil expected = {expectedArray,CHAR_SIZE,5};
	forEach(source,makeCursive,(void*)&hint);
	assertEqual(areEqual(source,expected),1);
}

void* addTwoValues (void* hint, void* previousItem, void* item){
	 *((float*)item) = *((float*)previousItem) + *((float*)item);
	 return ((float*)item);
}

void test_reduce_of_1_2_3_4_gives_12 () {
	int hint = 2, initialValue = 2;
	int array[]={1,2,3,4};
	ArrayUtil util={array,INT_SIZE,4};
	void* return_value = reduce(util,addTwoValues,(void*)&hint,(void*)&initialValue);
	assertEqual(*((int*)return_value),12);
}

void test_reduce_of_floating_point_values_can_also_be_conducted () {
	float hint = 2, initialValue = 2.0;
	float array[6] = {1.2,2.2,3.5,4.3,5.1};
	ArrayUtil util={array,FLOAT_SIZE,5};
	void* return_value = reduce(util,addTwoValues,(void*)&hint,(void*)&initialValue);
	assertEqual(*((float*)return_value),(float)18.29);
}

void* giveCharOfGreatestAsciiValue (void* hint, void* previousItem, void* item){
	return (*(char*)previousItem > *(char*)item) ? previousItem : item;
}

void test_reduce_can_be_performed_for_charArray () {
	char hint = 'm', initialValue = 'm';
	char array[5] = {'h','e','l','l','o'};
	ArrayUtil util={array,FLOAT_SIZE,5};
	void* return_value = reduce(util,giveCharOfGreatestAsciiValue,(void*)&hint,(void*)&initialValue);
	assertEqual(*((char*)return_value),'o');
}