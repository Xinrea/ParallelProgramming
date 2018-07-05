//Author: Xinrea
//Date: 2018/7/5
//Basic sample of openMP
//Before run the program, use `export OMP_NUM_THREADS = x` to set threads number 

#include <omp.h>
#include <cstdio>

int main(int argc, char const *argv[])
{
    int nthreads, tid;
    /* Fork a team of threads with each thread having a private tid variable */
    #pragma omp parallel private(tid)
    {
       /* Obtain and print thread id */
       tid = omp_get_thread_num();
       printf("Hello World from thread = %d\n", tid);

       /* Only master thread does this */
       if (tid == 0) {
           nthreads = omp_get_num_threads();
           printf("Number of threads = %d\n", nthreads);
       }
    }  /* All threads join master thread and terminate */
    return 0;
}
