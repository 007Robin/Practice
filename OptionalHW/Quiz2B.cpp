//
// Created by Jizhou.Sun on 2017/10/19.
//
#include <iostream>
using namespace std;

class Image {
private:
    uint32_t *rgba;
    int rows, cols;
public:
    //constructor
    Image(int rows, int cols, uint32_t init=0):rgba(new uint32_t[rows*cols]),rows(rows),cols(cols)
    {
        for (int i = 0; i < rows*cols; i++) {
            rgba[i]=init;
        }
    }

    //destructor
    ~Image()
    {
        delete [] rgba;
    }

    //copy constructor
    Image(const Image& orig) : rgba(new uint32_t[orig.rows*orig.cols]),rows(orig.rows),cols(orig.cols){
        //in session05 08MoveConstructor.cc why??????????
//        uint32_t *rgba1 = rgba;
//        const uint32_t* rgba2 = orig.rgba;
//        for (int i = 0; i < orig.rows*orig.cols; i++) {
//            *rgba++ = *rgba++;
//        }
        for (int i = 0; i < orig.rows*orig.cols; i++) {
            rgba[i]=orig.rgba[i];
        }
    }


    //operator =
    Image& operator =(const Image& orig)
    {
        Image copy(orig);
        swap(rgba, copy.rgba);
        rows = copy.rows;
        cols = copy.cols;
        return *this;
    }

    uint32_t& operator ()(int r, int c)
    {
        return rgba[r * cols +c ];
    }
    uint32_t operator ()(int r, int c) const {
        return rgba[r * cols + c];
    }

    //operator <<
    friend ostream& operator <<(ostream& s, Image& p)
    {
        for (int i = 0; i < p.rows*p.cols; i++) {
            s<<p.rgba[i]<<" ";
            if((i+1)%p.cols==0)
            {s<<endl;}
        }
        return s;
    }

};

int main() {
    Image a(20,30); // 20 rows 30 columns each, all pixels rgba =0
    a(1,1)=1;
    cout<<a<<endl;

    Image b = a; // copy the image
    b(2,2)=2;
    cout<<'b'<<endl;
    cout<<b<<endl;
    cout<<'a'<<endl;
    cout<<a<<endl;

    Image c(a); // also a copy
    c(3,3)=3;
    cout<<'c'<<endl;
    cout<<c<<endl;
    cout<<'a'<<endl;
    cout<<a<<endl;


    b(5,5) = 0xFF00FF; // extra credit 3 points, write the operator
    c = b; // wipe out whatever was in c, overwrite with b
    cout<<'c'<<endl;
    cout<<c<<endl;
    c(3,3)=3;
    cout<<'b'<<endl;
    cout<<b<<endl;
}