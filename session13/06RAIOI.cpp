class MyStinkyObject {
	private:
		int* a;
		int* b;
	public:
		MyStinkyObject() {
			a = new int[1000];
			if (a == nullptr)
				throw "No memory, getting out";
			b = new int[1000000000];
			if (b == nullptr) {
				delete []a;
				throw "No Memory, getting out2";
			}
		}

};

//先为a开辟1000的空间，如果满了没开辟成功，throw一个异常
//再如果a开辟成功了，又开辟b，b很大没开辟成功，为了程序结束都正常，要先delete A，再throw一个异常。
