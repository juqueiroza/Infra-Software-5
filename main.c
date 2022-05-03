#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int matrixSize, matrix[10][10], sums[10];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* rowSum(void* pointer) {
        pthread_mutex_lock(&mutex);
        int y = *((int*) pointer);
        for (int i = 0; i < matrixSize; i++) {
                sums[y] += matrix[y][i];
        }
        pthread_mutex_unlock(&mutex);
        return NULL;
}

void *main_thread(){
        int *pointer, a;
        int matrixSum = 0;
        pthread_t threads[10];

        scanf("%d", &matrixSize);

        for (int i = 0; i < matrixSize; i++) {
                for (int j = 0; j < matrixSize; j++) {
                        scanf("%d", &matrix[i][j]);
                }
        }

        /*
        for(int i = 0; i < matrixSize; i++) {
                for(int j = 0; j < matrixSize; j++) {
                        printf("%d ", matrix[i][j]);   
                }               
                printf("\n");
        }
        */

        for (int i = 0; i < matrixSize; i++) {
                pointer = malloc(sizeof(int));
                *pointer = i;
                a = pthread_create(&threads[i], NULL, rowSum, pointer);
                pthread_join(threads[i], NULL);
                if (a != 0) {
                        printf("Thread creation failed\n");
                        break;
                } /*else {
                        printf("Thread created succefully\n");
                }*/
        }

        for (int i = 0; i < matrixSize; i++) {
                pthread_join(threads[i], NULL);
        }
        
        for (int i = 0; i < matrixSize; i++) {
                matrixSum += sums[i];
        }
        printf("%d\n", matrixSum);

        return 0;

}

int main() {
        pthread_t t1;
        pthread_create(&t1, NULL, &main_thread, NULL);
        pthread_join(t1, NULL);
}
