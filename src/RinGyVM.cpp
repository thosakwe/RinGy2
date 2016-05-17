//
// Created by tobe on 5/15/2016.
//

#include "RinGyVM.h"
#include <iostream>
#include <cstdio>

using namespace std;

int RinGyVM::exec(const char *opcodes, int length) {
    for (char i = 0; i < length; i++) {
        if (opcodes[i] == '<') {
            if (memoryPointer_ > 0)
                memoryPointer_--;
        } else if (opcodes[i] == '>') {
            if (memoryPointer_ < MEMORY_SIZE - 1)
                memoryPointer_++;
        } else if (opcodes[i] == '\'') {
            if (++i < length - 1) {
                memory_[memoryPointer_] = opcodes[i];
            } else {
                cerr << "Invalid memory offset: " << i << " (must be < " << MEMORY_SIZE << ")" << endl;
                return 1;
            }
        } else if (opcodes[i] == '+') {
            memory_[memoryPointer_]++;
        } else if (opcodes[i] == '-') {
            memory_[memoryPointer_]--;
        } else if (opcodes[i] == '_') {
            memory_[memoryPointer_] = 0;
            for (int j = memoryPointer_ + 1; j < MEMORY_SIZE - 1; j++) {
                memory_[j] = memory_[j] >> 1;
            }
        } else if (opcodes[i] == ':') {
            if (memory_[memoryPointer_] != 0) {
                char until = opcodes[++i];
                cout << "until " << until << endl;
                while (opcodes[i + 1] != until) {
                    //skip
                    cout << "skip " << opcodes[++i] << endl;
                    if (opcodes[i + 1] == until) {
                        cout << "last: " << opcodes[i] << endl;
                    }
                }
            }
        } else if (opcodes[i] == 'q') {
            return 0;
        } else if (opcodes[i] == '.') {
            cout << memory_[memoryPointer_];
        } else if (opcodes[i] == ',') {
            printf("%c", memory_[memoryPointer_]);
        } else if (opcodes[i] == '[') {
            stack.push_back(memory_[memoryPointer_]);
        } else if (opcodes[i] == ']') {
            memory_[memoryPointer_] = stack.back();
            stack.pop_back();
        } else if (opcodes[i] == '~') {
            //continue;
            char old = i;
            i = memory_[memoryPointer_];
            memory_[memoryPointer_] = old;
        } else if (opcodes[i] == '#') {
            memory_[memoryPointer_] = i;
        } else if (opcodes[i] == '$') {
            char first = stack.back();
            stack.pop_back();
            char second = stack.back();
            stack.pop_back();

            if (first == second) {
                stack.push_back(1);
            } else {
                stack.push_back(0);
            }
        } else if (opcodes[i] == '(') {
            if (memory_[memoryPointer_] == 0) {
                i = stack.back();
                stack.pop_back();
            }
        } else if (opcodes[i] == ')') {
            if (memory_[memoryPointer_] != 0) {
                i = stack.back();
                stack.pop_back();
            }
        } else if (opcodes[i] == '^') {
            memory_[memoryPointer_] = '\n';
            do {
                memory_[memoryPointer_] = (char) getchar();
            } while (memory_[memoryPointer_] == '\n');
            memoryPointer_++;
            flush(cout);
        } else if (opcodes[i] == '@') {
            memory_[memoryPointer_] = 0;
        } else if (opcodes[i] == '!') {
            memoryPointer_ = 0;
        } else {
            cerr << "Invalid command: " << opcodes[i] << endl;
            return 1;
        }
    }

    return 0;
}

