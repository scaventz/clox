#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main() {
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    int constant1 = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant1, 1); // iload index

    int constant2 = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constant2, 2);

    writeChunk(&chunk, OP_ADD, 3); // 1.2 + 3.4

    int constant3 = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 4);
    writeChunk(&chunk, constant3, 4);

    writeChunk(&chunk, OP_DIVIDE, 5); // 4.6/5.6

    writeChunk(&chunk, OP_NEGATE, 6);

    writeChunk(&chunk, OP_RETURN, 6);
    interpret(&chunk);
    return 0;
}
