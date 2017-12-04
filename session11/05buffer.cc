//#include<fstream>
#include<unistd.h> //level 2 I/O kernel calls to unix
#include<sys/types.h>
#include<fcntl.h>
class Buffer {
	public:
	//enum {SIZE = 32768};   old 
	//#definde SIZE 32768  old
	constexpr static int SIZE = 32768; //2^15
	private:
		int fh;
		char buffer[SIZE];
		char* current; //where you up to
		uint32_t avail;
		void flush(){
			//new begin
			uint32_t bytesWrittern = write(fh, buffer, current-buffer);	
			//if(bytesWritten <  current - buffer)  ????failed
			current = buffer;
			avail = SIZE;
		}
		void internalWrite(float v) {
			*(float*)current = v; //little-endian on Intel
			current += sizeof(float);
			avail -= sizeof(float);
		}
	public:
		Buffer(const char* const filename[]) : current(buffer), avail(SIZE) {
			//creat() //kernal call GOOGLE: man 2 open
			/*
				RWX
				000
				001
				010
				011
				.
				111
			   */
			fh = open(filename, O_WRONLY, 0600);
			if(fh < 0) {
				throw "file can't open";
			}
		}
		~Buffer(){
			int stat = close(fh);
			if(stat < 0)
				throw "AAAAAGH";
		}
		void write(uint32_t v){
			if(avail < sizeof(uint32_t)){
				flush();
			}
			*(uint32_t*)current = v; //consider current as a pointer to uint32_t, copy
			current += sizeof(uint32_t); //advance by 4 bytes
			avail -= sizeof(uint32_t);
		}
		void write(const char m[], uint32_t LEN) {
			if(avail < LEN) {
				flush();
			};
			uint32_t i;
			for(i = 0; m[i] != '\0' && i < LEN; i++) {
				*current++ = m[i]; //copy one letter and advance current;
			}
			for( ; i< LEN; ++i) {
				*current++ 0;
			}
		}
		void write(float v) {
			if(avail < sizeof(float)) {
				flush();
			}
			*(float*)current = v; //little-endian on Intel
			current += sizeof(float);
			avail -= sizeof(float);

		}
		void writeAsFloats(const Vector3d& v){
			if(avail < sizeof(float)*3)
				flush();

		}
		void writeAsFloats(const Triangle& t){
			if(avail < 4*3*sizeof(float)
				flush();

		//	writeAsFloats(t.p1);
			internalWrite(t.p1.x);
			internalWrite(t.p1.y);
			internalWrite(t.p1.z);
		}

};
int main() {
	Buffer b;
	b.write("hello", 80);
}

//--rw--r-- r w execute
