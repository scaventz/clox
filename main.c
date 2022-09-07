#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main() {
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    int constantIndex = addConstant(&chunk, 1.23346563423);
    writeChunk(&chunk, OP_CONSTANT, 11);
    writeChunk(&chunk, constantIndex, 11);

    writeChunk(&chunk, OP_NEGATE, 12);

    writeChunk(&chunk, OP_RETURN,23);
    disassembleChunk(&chunk, "test chunk");

    printf("== running vm ==\n");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

    return 0;
}
