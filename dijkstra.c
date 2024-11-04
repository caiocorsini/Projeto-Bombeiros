/*


*/

#include <stdio.h>
#include <stdlib.h>

void initializeTempMatrix(int **mapa, int n)
{
    // Temporary static array with predefined values
    int temp[6][6] = {
        {0, 0, 8, 2, 4, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 3},
        {0, 4, 0, 0, 0, 1},
        {0, 2, 0, 0, 0, 0}};

    // Copy values from temp array to the dynamically allocated `mapa`
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mapa[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int n = 6;

    // Allocate dynamic matrix
    int **mapa = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mapa[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the dynamic matrix with predefined values
    initializeTempMatrix(mapa, n);

    // Print matrix to verify
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}
