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
  
result: hello bye 0 hello1 bye hello2 hello3 bye  hello4 hello5 bye  hello6 hello7 bye  hello8 hello9 bye  hello10 hello11 bye  hello12c hello13 bye 
  */
