all: MIP_pthread SEcreator

MIP_pthread: MIP_pthread.cpp pngfunc.cpp mipop.cpp
	g++ -o MIP_pthread MIP_pthread.cpp pngfunc.cpp mipop.cpp -lpthread

SEcreator: SEcreator.cpp pngfunc.cpp
	g++ -o SEcreator SEcreator.cpp pngfunc.cpp

clean:
	rm MIP_pthread SEcreator