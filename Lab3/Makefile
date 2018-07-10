all: MIP_OpenMP SEcreator

MIP_OpenMP: MIP_OpenMP.cpp pngfunc.cpp mipop.cpp
	g++ -o MIP_OpenMP MIP_OpenMP.cpp pngfunc.cpp mipop.cpp -fopenmp

SEcreator: SEcreator.cpp pngfunc.cpp
	g++ -o SEcreator SEcreator.cpp pngfunc.cpp

clean:
	rm MIP_OpenMP SEcreator