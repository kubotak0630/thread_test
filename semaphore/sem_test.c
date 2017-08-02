#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <semaphore.h>
#include <pthread.h>

typedef struct {

    int func_num;

} tagTHDATA;


sem_t g_sem_0;

void *thread_func1(void* pData)
{

    tagTHDATA* pThdata = (tagTHDATA*)pData;


    while (1) {

        printf("--func%d --wait sem-----\n", pThdata->func_num);
        sem_wait(&g_sem_0);

        printf("--func%d-- get sem -----\n", pThdata->func_num);
        
        //do function
        printf("** func%d-- do function -----\n", pThdata->func_num);
        usleep(2*1000*1000);
        printf("--func%d-- finish function -----\n", pThdata->func_num);

        printf("--func%d-- sem_post  -----\n", pThdata->func_num);
        
        //sem_post(&g_sem_0);
        //usleep(1);
    }

}

void *thread_func2(void* pData)
{

    tagTHDATA* pThdata = (tagTHDATA*)pData;


    while (1) {

        printf("--func%d --wait sem-----\n", pThdata->func_num);
        sem_wait(&g_sem_0);

        printf("--func%d-- get sem -----\n", pThdata->func_num);
        
        //do function
        printf("** func%d-- do function -----\n", pThdata->func_num);
        usleep(2*1000*1000);
        printf("--func%d-- finish function -----\n", pThdata->func_num);

        //sem_post(&g_sem_0);
        //usleep(1);

    }

}


void *thread_func3(void* pData)
{

    tagTHDATA* pThdata = (tagTHDATA*)pData;


    while (1) {

        printf("--func%d --wait sem-----\n", pThdata->func_num);
        sem_wait(&g_sem_0);

        printf("--func%d-- get sem -----\n", pThdata->func_num);
        
        //do function
        printf("** func%d-- do function -----\n", pThdata->func_num);
        usleep(2*1000*1000);
        printf("--func%d-- finish function -----\n", pThdata->func_num);

        //sem_post(&g_sem_0);
        //usleep(1);

    }

}

void *thread_func4(void* pData)
{

    tagTHDATA* pThdata = (tagTHDATA*)pData;


    while (1) {

        printf("--func%d --wait sem-----\n", pThdata->func_num);
        sem_wait(&g_sem_0);

        printf("--func%d-- get sem -----\n", pThdata->func_num);
        
        //do function
        printf("** func%d-- do function -----\n", pThdata->func_num);
        usleep(2*1000*1000);
        printf("--func%d-- finish function -----\n", pThdata->func_num);

        //sem_post(&g_sem_0);
        //usleep(1);

    }

}

int main()
{

    int i;
    const int THREAD_NUM = 4;

    tagTHDATA thdata[THREAD_NUM];

    for (i = 0; i < THREAD_NUM; i++) {
        thdata[i].func_num = i;
    }

    pthread_t th[4];

    sem_init(&g_sem_0, 0, 0);


    pthread_create(&th[0], NULL, thread_func1, (void*)&thdata[0]);
    usleep(1000);
    pthread_create(&th[1], NULL, thread_func2, (void*)&thdata[1]);
    usleep(1000);
    pthread_create(&th[2], NULL, thread_func3, (void*)&thdata[2]);
    usleep(1000);
    pthread_create(&th[3], NULL, thread_func4, (void*)&thdata[3]);



    usleep(1*1000*1000);  //wait 1s

    sem_post(&g_sem_0);

    for (i = 0; i < THREAD_NUM; i++){
        pthread_join(th[i], NULL);
    }


    return 0;


}
