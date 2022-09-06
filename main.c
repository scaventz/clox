#include "common.h"
#include "chunk.h"
#include "debug.h"

int main() {
    Chunk chunk;
    initChunk(&chunk);

    int constantIndex = addConstant(&chunk, 1.23346563423);
    writeChunk(&chunk, OP_CONSTANT, 11);
    writeChunk(&chunk, constantIndex, 11);

    writeChunk(&chunk, OP_CONSTANT, 22);
    writeChunk(&chunk, constantIndex, 22);

    writeChunk(&chunk, OP_RETURN,23);
    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}
