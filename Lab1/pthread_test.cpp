//Author: Xinrea
//Date: 2018/7/5
//Basic sample of using pthread

#include <pthread.h>
#include <unistd.h>
#include <cstdio>

void *TestThread1(void*){
    for(int i = 0; i < 10; i++){
        printf("Thread1: %d\n",i);
        sleep(1);
    }
}

void *TestThread2(void*){
    for(int i = 0; i < 10; i++){
        printf("Thread2: %d\n",i);
        sleep(1);
    }
}


int main(int argc, char const *argv[])
{
    pthread_t thread_id1, thread_id2;
    int ret = 0;
    ret = pthread_create(&thread_id1,NULL,TestThread1,NULL);
    if(ret){
        printf("Create TestThread1 Error\n");
        return -1;
    }
    ret = pthread_create(&thread_id2,NULL,TestThread2,NULL);
    if(ret){
        printf("Create TestThread2 Error\n");
        return -1;
    }
    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
    return 0;
}
