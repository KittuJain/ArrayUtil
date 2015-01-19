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
