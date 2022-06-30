#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INFINITY 99999

typedef struct dijkstra dijkstra;

struct dijkstra{
    int** matrix;
    int*  min;
    int*  visited;
    int*  ver;
};

void dijkstra_init(dijkstra* n, int size, int choose);
void input_matrix2(int** arr, int size);
void input_matrix(int** arr, int size);
void dijkstra_calculate(dijkstra* n, int size, int strart, int end);
void dijkstra_print(dijkstra* n, int size);

#endif