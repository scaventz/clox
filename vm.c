#include "vm.h"

VM vm;

void initVM() {

}

void freeVM() {

}

InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    for (;;) {
        uint8_t byte = READ_BYTE();
        switch (byte) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printf("%f\n", constant);
                break;
            }

            case OP_RETURN:
                return INTERPRET_OK;

        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk *chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}