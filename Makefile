omploop: opmloop.cpp
	g++-4.9 -fopenmp $< -o omploop -lpthread	#  libomp.a 
