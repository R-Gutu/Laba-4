#include <iostream>
#include <stdio.h>

#define N 4
#define M 4
int main(){
    int temp = 0;


    int** array = new int* [N];
    for (int i = 0; i < N; i++){
        array[i] = new int[M];
    }


    std::cout << "Vvedite elementi masiva:\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cin >> array[i][j];
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = rand() * 3;
        }
    }

    //Отсортировать строки массива по возрастанию с помощью метода «пузырька».
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            for (int k = 0; k < N - 1; k++){
                if (array[i][k + 1] < array[i][k]) {
                    temp = array[i][k + 1];
                    array[i][k + 1] = array[i][k];
                    array[i][k] = temp;
                }
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++)
        delete[] array[i];
    delete[] array;

    exit(0);
    return 0;
}