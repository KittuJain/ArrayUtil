#define log(test_description) int log = (printf("\t	%s\n\n", test_description))
#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define STRING_SIZE sizeof(char*)

#define null '\0'
#define YES 1
#define NO 0
typedef char String[256];
typedef int (MatchFunc)(void*,void*);
typedef void (ConvertFunc)(void*, void*, void*); 
typedef void (OperationFunc)(void*, void*);
typedef void* (ReducerFunc)(void*, void*, void*);
typedef struct Student students;
typedef struct StudentDetails student;
typedef struct util ArrayUtil;

struct util {
	void *base;
	int typeSize;
	int length;
};

struct Student {
	int roll;
	int marks;
};

struct StudentDetails{
    int rollno;
    float age;
};
int areLengthEqual(ArrayUtil, ArrayUtil);
int isTypeSizeSame (ArrayUtil, ArrayUtil);
int areBaseValuesSame (ArrayUtil, ArrayUtil);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void*);
void dispose(ArrayUtil);
void* findFirst(ArrayUtil, MatchFunc *, void*);
void* findLast(ArrayUtil, MatchFunc *, void*);
int count(ArrayUtil, MatchFunc* , void*);
int filter(ArrayUtil, MatchFunc*, void*, void**, int);
int arrayEqual(int*, int*);
void map(ArrayUtil, ArrayUtil, ConvertFunc*, void*);
void forEach(ArrayUtil, OperationFunc*, void*);
void* reduce(ArrayUtil, ReducerFunc*, void*, void*);