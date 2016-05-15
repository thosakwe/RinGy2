#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <chrono>
#include "RinGyVM.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    cout << "RinGy VM - Tobe O." << endl;
    cout << "------------------" << endl << endl;

    if (argc == 1) {
        cerr << "fatal error: no input file" << endl;
        return 1;
    }

    ifstream ifs(argv[1], ifstream::in);
    if (!ifs) {
        cerr << "fatal error: could not open file" << endl;
        cerr << "error(" << errno << "): " << strerror(errno) << endl;
        return 1;
    }

    stringstream ss;
    ss << ifs.rdbuf();
    string program = ss.str();

    RinGyVM *vm = new RinGyVM();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int result = vm->exec(program.c_str(), program.length());
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << endl << "Execution time: " << duration << "ms" << endl;
    return result;
}