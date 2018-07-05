all: pthread_test openMP_test MPI_test CUDA_test

pthread_test: pthread_test.cpp
	g++ -o pthread_test pthread_test.cpp -lpthread

openMP_test: openMP_test.cpp
	g++ -o openMP_test openMP_test.cpp -fopenmp

MPI_test: MPI_test.cpp
	g++ -o MPI_test MPI_test.cpp -lmpi

CUDA_test: CUDA_test.cu
	nvcc -o CUDA_test CUDA_test.cu

clean:
	rm pthread_test openMP_test MPI_test CUDA_test