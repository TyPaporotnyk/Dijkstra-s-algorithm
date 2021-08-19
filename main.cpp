/*
 * Реализачия Алгоритма Дейксты для поиска кратчайшего пути
 *
 * Свадковский Даниил
 * @TyPaporotnyk
 **/

#include <iostream>
#include <iomanip>

#define TEST

// const int edgesVar;
int edgesVar = 6;
int **weights;
int *edges;
bool *steped;
int maxValue = INT_MAX;
int start = 0, end;

bool run = true;


/// <#Description#>
int main(){
    setlocale(LC_ALL, "Rus");
    
    // Инициализация массива верщин и ребер
#ifdef TEST
    std::cout << "Введите количество вершин: ";
    std::cin >> edgesVar;
    
    std::cout << "Введите последнюю вершину: ";
    std::cin >> end;
    
    // Помеченые вершины
    steped = new bool[edgesVar];
    
    
    // Создаем массив ребер и их связей
    weights = new int*[edgesVar];
    for(int i = 0; i < edgesVar; i++){
        weights[i] = new int[edgesVar];
    }
    
    // Заполняем массив отрицательными числами
    for(int i = 0; i < edgesVar; i++){
        for(int j = 0; j < edgesVar; j++){
            weights[i][j] = -1;
        }
    }
    edges = new int[edgesVar];
    edges[1] = 0;
    for(int i = 1; i < edgesVar; i++){
        edges[i] = maxValue;
    }
    
#endif
    // Заполнение массива ребер и их связей
    std::cout << "Если вершина I не имеет связи с соседом Y\n";
    std::cout << "Записывайте 0\n";
    for(int i = 0; i < edgesVar; i++){
        weights[i][i] = 0;
        for(int j = 0; j < edgesVar; j++){
#ifdef TEST
            if(i == j || weights[i][j] != -1) continue;
#endif
            int weight;
            std::cout << "Длина ребра вершини " << i+1 << " к вершине " << j+1 << " => ";
            std::cin >> weight;
            weights[i][j] = weights[j][i] = weight;
        }
    }
    
    // Выводим массив связей ребер
    std::cout << "\n";
    for(int i = 0; i < edgesVar; i++){
        for(int j = 0; j < edgesVar; j++){
            std::cout << std::setw(3) << weights[i][j] << " ";
        }
        std::cout <<"\n\n";
    }
    
    for(int i = 1; i < edgesVar; i++){
        for(int j = 0; j < edgesVar; j++){
            if(weights[i-1][j] == 0 ) continue;
            // || steped[j])
            int temp = edges[i-1] + weights[i-1][j];
            if(temp < edges[j]) {
                edges[j] = temp;
                steped[i-1] = true;
            }
        }
    }
        
    for(int i = 0; i < edgesVar; i++){
        std::cout << edges[i] << " ";
    }
    std::cout << "\n";
    
#ifdef TEST
    // Delete
    for(int i = 0; i < edgesVar; i++){
        delete[] weights[i];
    }
    delete[] weights;
#endif
    return 0;
}

// Test 1: 7 9 0 0 14 10 15 0 0 11 0 2 6 0 9
// Input 1:
