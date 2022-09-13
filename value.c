#include <stdio.h>
#include "value.h"
#include "memory.h"

void initValueArray(ValueArray *valueArray) {
    valueArray->capacity = 0;
    valueArray->count = 0;
    valueArray->values = NULL;
}

void writeValueArray(ValueArray *valueArray, Value value) {
    if (valueArray->capacity <= valueArray->count) {
        valueArray->capacity = GROW_CAPACITY(valueArray->capacity);
        valueArray->values = GROW_ARRAY(valueArray->values, Value, valueArray->capacity);
    }
    valueArray->values[valueArray->count++] = value;
}

void freeValueArray(ValueArray *valueArray) {
    FREE_ARRAY(valueArray->values);
    initValueArray(valueArray);
}

void printValue(Value value) {
    switch (value.type) {
        case VAL_BOOL: {
            printf(AS_BOOL(value) ? "true" : "false");
            break;
        }

        case VAL_NIL: {
            printf("nil");
            break;
        }

        case VAL_NUMBER: {
            printf("%g", AS_NUMBER(value));
            break;
        }
    }
}

bool valuesEqual(Value a, Value b) {
    if (a.type != b.type) return false;
    switch (a.type) {
        case VAL_BOOL:   return AS_BOOL(a) == AS_BOOL(b);
        case VAL_NIL:    return true;
        case VAL_NUMBER: return AS_NUMBER(a) == AS_NUMBER(b);
        default:         return false; // Unreachable.
    }
}