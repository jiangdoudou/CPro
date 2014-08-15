#include <stdio.h>
#include <stdlib.h>

int MaxSubSequenceSum(const int A[], int N)
{
	int ThisSum, result = 0, i, j;
	
	for(i = 0; i < N; i++) {
		ThisSum = 0;
		for(j = i; j < N; j++) {
			ThisSum += A[j];
			if(ThisSum > result)
				result = ThisSum;
		}
	}

	return result;
}

int main(void)
{
	int array[11] = {1, 2, 3, -1, 3, -10, 2, 4, 2, -2222, 12};
	int result = MaxSubSequenceSum(array, 11);
	printf("%d\n", result);
	exit(EXIT_SUCCESS);
}