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
    printf("%g", value);
}