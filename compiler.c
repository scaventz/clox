#include "common.h"
#include "compiler.h"
#include "scanner.h"

void compile(const char* source) {
    initScanner(source);
    int line = -1;
    for(;;) {
        Token token = scanToken(source);
        printf("%4d %2d '%.*s'\n", token.line, token.type, token.length, token.start);
        if(token.type == TOKEN_EOF) break;
    }
}