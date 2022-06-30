#include "dijkstra.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Введіть кількість вершин графа\n");

    printf("  --> ");
    int size;
    scanf("%d", &size);

    printf("\n");

    printf("Оберіть тип вводу графу\n");
    printf("1. Заданням матриці\n");
    printf("2. Заданням весів сусідів графу\n");

    printf("  --> ");
    int choose;
    scanf("%d", &choose);
    printf("\n\n");



    dijkstra d1;

    dijkstra_init(&d1, size, choose);

    printf("Введіть початкову вершину\n");

    printf("  --> ");
    int id;
    scanf("%d", &id);
    printf("\n");
    dijkstra_calculate(&d1, size, id-1, 5);

  return 0;
}