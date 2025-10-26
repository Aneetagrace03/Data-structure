#include <stdio.h>

// Structure for one non-zero element
struct Element {
    int row;
    int col;
    int value;
};

// Structure for sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numNonZero;
    struct Element elements[100]; // Maximum 100 non-zero elements
};

int main() {
    struct SparseMatrix sm1, sm2, smSum;
    sm1.rows = sm2.rows = smSum.rows = 3;
    sm1.cols = sm2.cols = smSum.cols = 3;
    sm1.numNonZero = sm2.numNonZero = smSum.numNonZero = 0;

    // Original 2D matrix 1
    int arr1[3][3] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 0, 0}
    };

    // Original 2D matrix 2
    int arr2[3][3] = {
        {0, 5, 0},
        {0, 0, 7},
        {0, 0, 0}
    };

    // Convert arr1 to sparse matrix
    for(int i = 0; i < sm1.rows; i++) {
        for(int j = 0; j < sm1.cols; j++) {
            if(arr1[i][j] != 0) {
                sm1.elements[sm1.numNonZero].row = i;
                sm1.elements[sm1.numNonZero].col = j;
                sm1.elements[sm1.numNonZero].value = arr1[i][j];
                sm1.numNonZero++;
            }
        }
    }
for(int i=0;i<sm1.numNonZero;i++){
    printf("%d\t%d\t%d\t",sm1.elements[i].row,sm1.elements[i].col,sm1.elements[i].value);
}
    // Convert arr2 to sparse matrix
    for(int i = 0; i < sm2.rows; i++) {
        for(int j = 0; j < sm2.cols; j++) {
            if(arr2[i][j] != 0) {
                sm2.elements[sm2.numNonZero].row = i;
                sm2.elements[sm2.numNonZero].col = j;
                sm2.elements[sm2.numNonZero].value = arr2[i][j];
                sm2.numNonZero++;
            }
        }
    }
int C[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
{
    C[i][j]=arr1[i][j]+arr2[i][j];
}    }
 for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(C[i][j] != 0) {  // Only print non-zero elements
                printf("%d\t%d\t%d\n", i, j, C[i][j]);
            }
        }
    }}