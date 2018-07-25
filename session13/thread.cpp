#include <iostream>
#include <thread>
#include <vector>

std::vector<std::thread> threads;
const size_t number_of_threads=3;

void task() { std::cout<<"Alive\n";}

void spawn() {
	for(int i=0; i<number_of_threads; ++i){
		threads.emplace_back(task);
	}
	for(int i=0; i<threads.size(); ++i){
		threads[i].join();
	}
}

int main() {
	threads.reserve(number_of_threads);
//	spawn();
	threads.emplace_back(task);
	threads[0].join();

}
