#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

typedef int (MatchFunc)(void*,void*);
typedef struct util ArrayUtil;

struct util {
	void *base;
	int typeSize;
	int length;
};

typedef struct Student {
	int roll;
	int marks;
} students;

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
