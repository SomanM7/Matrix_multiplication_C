#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char print_help_and_exit(){
	printf("Please enter: <filename> <N> <M> <Seed>\n");
	exit(-1);
}

void* MultiplyMatrix(int rows,int columns,int **matrix1, int **matrix2, int seed){

    int i, j;
    srand(seed);

	//Matrix 1
    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++){
         matrix1[i] = (int *)malloc(columns * sizeof(int));
    }
    printf("Matrix 1:\n");
   for (i = 0; i <  rows; i++){
    	for (j = 0; j < columns; j++){
			matrix1[i][j] = rand()%100;
			printf("%d\t",matrix1[i][j]);
	  	}
	  	printf("\n");
	}
	//Matrix 2
	matrix2 = (int **)malloc(columns * sizeof(int *));
    for (i=0; i<columns; i++){
         matrix2[i] = (int *)malloc(rows * sizeof(int));
	}
    printf("\nMatrix 2:\n");
    for (i = 0; i <  columns; i++)
    {
    	for (j = 0; j < rows; j++){
			matrix2[i][j] = rand()%100;
			printf("%d\t",matrix2[i][j]);
	  	}
	  	printf("\n");
	}
//Result of multiplication
	int **resultingMatrix;
	resultingMatrix = (int **)malloc(rows * sizeof(int *));
	for (i=0; i<rows; i++)
         resultingMatrix[i] = (int *)malloc(rows * sizeof(int));
         printf("\nResult:\n");
    for (i = 0; i <  rows; i++){ //Iterate rows of matrix1
    	for (j = 0; j < rows; j++){
			resultingMatrix[i][j] = 0;
			for(int k = 0; k < columns; k++){ //iterate columns of m1
				resultingMatrix[i][j] = resultingMatrix[i][j] + matrix1[i][k] * matrix2[k][j];
			}
			printf("%d\t", resultingMatrix[i][j]);
    	}printf("\n");
    }

	//Memory deallocation for 2D arrays
	for(i = 0; i < rows; i++){
		free(matrix1[i]);
	}
	for(i = 0; i < rows; i++){
		free(matrix2[i]);
	}
	for(i = 0; i < rows; i++){
		free(resultingMatrix[i]);
	}
	free(matrix1);
	free(matrix2);
    free(resultingMatrix);
}

int main(int argc, char *argv[] ){

	clock_t begin = clock(); //starts clock

	int **mat1,**mat2;
	int N,M, seed;
	if( argc != 4 ) //Checks there is atleast 4 arguemnts entered
	{
		printf("invalid number of arguments.\n");
		print_help_and_exit();
	}
	long args[3]; 
	for(int i = 0; i < 3; i++){ //Check arguments are integers
		char* ptr;
		args[i] =  strtol(argv[i+1], &ptr, 10);
		if (ptr == argv[i+1] || ptr[0] != '\0') {
			printf("Invalid argument \n");
			print_help_and_exit();

		}
	}
	N = atoi(argv[1]);
    M = atoi(argv[2]);
    seed = atoi(argv[3]);

	MultiplyMatrix(N,M,mat1,mat2,seed);

	begin = clock() - begin;
	double time_spent = (double)(begin) / CLOCKS_PER_SEC; //Caculates execution time
	printf("Execution Time: %f seconds\n", time_spent);

}	