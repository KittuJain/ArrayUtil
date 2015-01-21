typedef int (MatchFunc)(void*,void*);
typedef struct util ArrayUtil;

struct util {
	void *base;
	int typeSize;
	int length;
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
