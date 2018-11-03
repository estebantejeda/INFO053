//Importar Librerias

#include <iostream>
#include <queue>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    if(argc != 2 || atoi(argv[1]) < 1000 || atoi(argv[1]) > 1000000){
        printf("ejecutar como ./prog N (N = [1k, 1M])\n");
        exit(EXIT_FAILURE);
    }

    //Definir Variables

    int N = atoi(argv[1]);
    double tiempoA = 0;
    double tiempoB = 0;
    double tiempoC = 0;
    int b = 0;
    srand(time(NULL));

    //Creando vector de tamaño N

    std::queue<int> Q;

    //Insertando Variables

    for (int i = 0; i < N/1000; i++){
        for(int j = i*1000; j < i*1000+950; j++){
            Q.push(1+rand()%(1000001-1));
        }
        double t_1 = omp_get_wtime();
        for (int j = i*1000+950; j < i*1000+1000; j++){
            Q.push(1+rand()%(1000001-1));
        }
        double t_2 = omp_get_wtime();
        tiempoA = tiempoA + (t_2-t_1);
    }
    tiempoA = tiempoA/(N/1000);

    //Buscar Variable Aleatoria

    for (int i = 0; i < N/1000; i++) {
        double t_1 = omp_get_wtime();
        while(b != N-1 && Q.front() != 1+rand()%(1000001-1)){
            b++;
        }
        double t_2 = omp_get_wtime();
        tiempoB = tiempoB + (t_2-t_1);
    }
    tiempoB = tiempoB/(N/1000);

    //Eliminar Variables

    for (int i = 0; i < N/1000; i++){
        double t_1 = omp_get_wtime();
        for (int j = i*1000+950; j < i*1000+1000; j++){
            Q.push(j);
        }
        double t_2 = omp_get_wtime();
        tiempoC = tiempoC + (t_2-t_1);
    }
    tiempoC = tiempoC/(N/1000);

    //Imprimir tiempo utilizado

    std::cout << "\nTiempo promedio de Inserción: " << tiempoA << "\n";
    std::cout << "\nTiempo promedio de Búsqueda: " << tiempoB << "\n";
    std::cout << "\nTiempo promedio de Eliminación: " << tiempoC << "\n";

}
