#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::srand;
using std::time;
using std::rand;
using std::fstream;
using std::ios;

struct punkt{
    int x, y, z;
};

const int length = 50;

struct array_wrapper {
    punkt tab[length];
};

array_wrapper generate() {

    array_wrapper wrapper;

    srand(time(nullptr));

    for (int i = 0; i < length; i++) {

        wrapper.tab[i].x = rand() % 10;
        wrapper.tab[i].y = rand() % 10;
        wrapper.tab[i].z = rand() % 10;
    }
    return wrapper;
}


#define SIZE 20


int main() {

    fstream file;
    file.open("results.csv", ios::out);

    if (!file.good()) {
        cout << "Error" << endl;
        return 1;
    }

    array_wrapper wrapper = generate();

    for(int i=0; i < length; i++){
        file << wrapper.tab[i].x << " " << wrapper.tab[i].y << " " << wrapper.tab[i].z << endl;
    }

    file.close();
    cout << "Success" << endl;

    return 0;

}