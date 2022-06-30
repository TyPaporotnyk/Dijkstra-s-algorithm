#include "dijkstra.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input_matrix(int** arr, int size)
{
    // Заполнение массива ребер и их связей
    printf("Якщо вершина I не має звʼязку з сусідом Y\n");
    printf("Записуйте 0\n");

    for(int i = 0; i < size; i++){
        arr[i][i] = 0;
        for(int j = 0; j < size; j++){

            if(i == j || arr[i][j] != -1) continue;

            int weight;
            printf("Воджина вершини %d к вершині %d => ", i+1, j+1);
            scanf("%d", &weight);
            arr[i][j] = arr[j][i] = weight;
        }
    }
    printf("\n\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%5d ", arr[j][i]);
        printf("\n");
    }
    printf("\n\n");
}

void input_matrix2(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[j][i]);
        }
    }

    printf("\n\n");

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //         printf("%5d ", arr[j][i]);
    //     printf("\n");
    // }
    // printf("\n\n");

}

void dijkstra_init(dijkstra* n, int size, int choose)
{
    // matix init
    n->matrix = (int**)malloc(size*sizeof(int*));
    for(int i = 0; i < size; i++)
    {
        n->matrix[i] = (int *) malloc(size * sizeof(int));
        for(int j = 0; j < size; j++)
        {
            n->matrix[i][j] = -1;
        }
    }

    switch (choose)
    {
    case 1:
        input_matrix2(n->matrix, size);
      break;

    case 2:
        input_matrix(n->matrix, size);
      break;

    default:
      break;
    }


    //init min
    n->min = (int*)calloc(size, sizeof(int));

    // init n->visited
    n->visited = (int*)calloc(size, sizeof(int));

    //init res
    n->ver = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; i++){
        n->min[i]     = INFINITY;
        n->visited[i] = 1;
    }
}

void dijkstra_calculate(dijkstra* n, int size, int start, int end)
{
    int cost[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (n->matrix[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = n->matrix[i][j];

    for (int i = 0; i < size; i++)
    {
        n->min[i] = cost[start][i];
        n->ver[i] = start;
        n->visited[i] = 0;
    }

    int mindistance;
    int nextnode;

    n->min[start] = 0;
    n->visited[start] = 1;
    int count = 1;

    while (count < size - 1)
    {
        mindistance = INFINITY;

        for (int i = 0; i < size; i++)
        {
            if (n->min[i] < mindistance && !n->visited[i])
            {
                mindistance = n->min[i];
                nextnode = i;
            }
        }

        n->visited[nextnode] = 1;
        for (int i = 0; i < size; i++)
        {
            if (!n->visited[i])
            {
                if (mindistance + cost[nextnode][i] < n->min[i])
                {
                    n->min[i] = mindistance + cost[nextnode][i];
                    n->ver[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (int i = 0; i < size; i++){
        if (i != start)
        {
            printf("\nДовжина до вершини %d = %d", i+1, n->min[i]);
            printf("\nШлях = %d", i+1);

            int j = i;
            do
            {
                j = n->ver[j];
                printf("<--%d", j+1);
            } while (j != start);
        }

        printf("\n");
    }
    printf("\n\n");
}

