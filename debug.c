#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name) {
    printf("== %s ==\n", name);
    for (int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int constantInstruction(char *name, Chunk *chunk, int offset) {
    int constantIndex = chunk->code[offset+1];
    Value value = chunk->constants.values[constantIndex];
    printf("%-18s %f\n", name, value);
    return offset + 2;
}

static int simpleInstruction(char *name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

int disassembleInstruction(Chunk *chunk, int offset) {
    printf("%04d Line:%-4d", offset, chunk->lines[offset]);
    int instruction = chunk->code[offset];
    switch (instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_ADD:
            return simpleInstruction("OP_ADD", offset);
        case OP_SUBTRACT:
            return simpleInstruction("OP_SUBTRACT", offset);
        case OP_MULTIPLY:
            return simpleInstruction("OP_MULTIPLY", offset);
        case OP_DIVIDE:
            return simpleInstruction("OP_DIVIDE", offset);
        case OP_NEGATE:
            return simpleInstruction("OP_NEGATE", offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d ", instruction);
            return offset + 1;
    }
}