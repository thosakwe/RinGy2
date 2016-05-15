//
// Created by tobe on 5/15/2016.
//

#ifndef RINGY_RINGYVM_H
#define RINGY_RINGYVM_H
const int MEMORY_SIZE = 255;

class RinGyVM {
public:
    int exec(const char *, int);

private:
    char memory_[MEMORY_SIZE] = {0};
    int memoryPointer_ = 0;
};


#endif //RINGY_RINGYVM_H
