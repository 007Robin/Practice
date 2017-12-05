#include<thread>
#include<iostream>
#include<unistd.h>

using namespace std;

void f() {
//	for(;;) {
	for(int i = 0;; i++){
		cout << " hello" << i << flush;
//		cout << "hello" << i;
		sleep(1);
	}
}

void g() {
	while(true) {
		cout << " bye " << flush;
//		cout << "bye";
		sleep(2);
	}
}

int main() {
	thread t1(f);
	thread t2(g);
	t1.join();
	t2.join();
}

/*
flush endl 都是刷新了缓冲区输出, 如果不加就会只往buffer里写东西但没有输出。
join 是两个线程一个完了以后 再执行另一个
mutex 是锁。使用的话就是mutex.lock()  mutex.unlock()
   */
