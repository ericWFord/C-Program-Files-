/*
Programmer: Eric Ford
Program: A1 CSC 150 Review

Program will take a number from the user and generate n random numbers (between 1 to 1000), sum the numbers, give the average of the numbers, identify the lowest and highest numbers, and list all the numbers in table formate.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// function to calculate sum of an array
int arrSum(int arr[], int n)
{
	int sum = 0;
	int i;

	for (i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}


int main()
{
	int userNum;


	// Input
	/* Ask user to input a number, if number is less than 1 or greater than 1000 ask
	user to inout another number
	*/
	printf("%s", "\nHow many? ");
	scanf("%d", &userNum);


	// Processing
	// Number determines the size of array

	int arr[1001];
	srand(time(0));

	for (size_t i = 0; i < userNum; ++i) {
		arr[i] = (rand() % 1001);
	}

	// Highest and lowest numbers are identified

	int minimum;
	int max;
	int i;
	
	minimum = arr[0];

	for (i = 1; i < userNum; i++) {
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}

	max = arr[0];

	for (i = 1; i < userNum; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	
	// Output
	// Minimum number is disaplayed
	printf("\nmin:\t%d", minimum);

	// Max number is displayed
	printf("\nmax:\t%d", max);

	// Sum of the array is displayed
	printf("\nSum is:\t%d", arrSum(arr, userNum));

	// Avg of the array is calculated and displayed
	printf("\navg:\t%d\n", arrSum(arr, userNum) / userNum);

	// Random numbers are displayed in table format
	puts("\nPos\t|\tVal");
	puts("--------------------");

	for (size_t i = 0; i < userNum; ++i) {
		printf("%u\t|\t%d\n", i, arr[i]);
	}

}