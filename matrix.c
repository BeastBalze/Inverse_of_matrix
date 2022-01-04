#include <stdio.h>

int main()
{
    int order, method;
    printf("What amethod do you want to use?\nChoose 1 for Row Transform\nChoose 2 for Column Transform\n");
    scanf("%d", &method);
    printf("Entre the order of square matrix:");
    scanf("%d", &order);
    float matrix[order][order];

    /* User Input for the matrix*/

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
    printf("\n");

    /*Declaring the identity Matrix*/

    float inverse_matrix[order][order];
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if (i == j)
            {
                inverse_matrix[i][i] = 1;
            }
            else
                inverse_matrix[i][j] = 0;
        }
    }

    /*printing the 1st step*/

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("   ");
        for (int j = 0; j < order; j++)
        {
            printf("%.2f ", inverse_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    /*starting operations*/

    /*Row Transform*/

    if (method == 1)
    {
        for (int i = 0; i < order; i++)
        {
        here1:
            /*checking for singularity of the matrix*/
            for (int z = 0; z < order; z++)
            {
                if (matrix[z][z] == 0)
                {
                    printf("Inverse of the given Matrix dosen't exist!!");
                    goto end;
                }
            }
            if (matrix[i][i] == 1)
            {
                for (int j = 0; j < order; j++)
                {
                    if (i != j)
                    {
                        int a = matrix[j][i];
                        for (int k = 0; k < order; k++)
                        {
                            matrix[j][k] = matrix[j][k] - a * matrix[i][k];
                            inverse_matrix[j][k] = inverse_matrix[j][k] - a * inverse_matrix[i][k];
                        }
                    }
                }
            }
            else
            {
                int b = matrix[i][i];
                for (int j = 0; j < order; j++)
                {
                    matrix[i][j] = matrix[i][j] / b;
                    inverse_matrix[i][j] = inverse_matrix[i][j] / b;
                }
                for (int i = 0; i < order; i++)
                {
                    for (int j = 0; j < order; j++)
                    {
                        printf("%.2f ", matrix[i][j]);
                    }
                    printf("   ");
                    for (int j = 0; j < order; j++)
                    {
                        printf("%.2f ", inverse_matrix[i][j]);
                    }
                    printf("\n");
                }
                printf("\n\n");
                goto here1;
            }

            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    printf("%.2f ", matrix[i][j]);
                }
                printf("   ");
                for (int j = 0; j < order; j++)
                {
                    printf("%.2f ", inverse_matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
    }

    /*column transform*/

    else if (method == 2)
    {
        for (int i = 0; i < order; i++)
        {
        here:
            /*checking for singularity of the matrix*/
            for (int z = 0; z < order; z++)
            {
                if (matrix[z][z] == 0)
                {
                    printf("Inverse of the given Matrix dosen't exist!!");
                    goto end;
                }
            }
            if (matrix[i][i] == 1)
            {
                for (int j = 0; j < order; j++)
                {
                    if (i != j)
                    {
                        int a = matrix[i][j];
                        for (int k = 0; k < order; k++)
                        {
                            matrix[k][j] = matrix[k][j] - a * matrix[k][i];
                            inverse_matrix[k][j] = inverse_matrix[k][j] - a * inverse_matrix[k][i];
                        }
                    }
                }
            }
            else
            {
                int b = matrix[i][i];
                for (int j = 0; j < order; j++)
                {
                    matrix[j][i] = matrix[j][i] / b;
                    inverse_matrix[j][i] = inverse_matrix[j][i] / b;
                }
                for (int i = 0; i < order; i++)
                {
                    for (int j = 0; j < order; j++)
                    {
                        printf("%.2f ", matrix[i][j]);
                    }
                    printf("   ");
                    for (int j = 0; j < order; j++)
                    {
                        printf("%.2f ", inverse_matrix[i][j]);
                    }
                    printf("\n");
                }
                printf("\n\n");
                goto here;
            }

            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    printf("%.2f ", matrix[i][j]);
                }
                printf("   ");
                for (int j = 0; j < order; j++)
                {
                    printf("%.2f ", inverse_matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
    }

end:
    return 0;
}