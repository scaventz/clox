#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
    char line[1024];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret(line);
    }
}

static char* readFile(const char* path) {
    FILE* file = fopen(path, "rb");

    if(file == NULL) {
        fprintf(stderr,"Could not open file %s. \n", path);
        exit(74);
    }

    fseek(file,0,SEEK_END);
    int fileSize = ftell(file);
    char* buffer = malloc(fileSize + 1);
    if(buffer == NULL) {
        fprintf(stderr,"No enough memory to read %s", path);
        exit(74);
    }

    size_t bytesRead =  fread(buffer, sizeof(char), fileSize, file);
    if(bytesRead < fileSize) {
        fprintf(stderr,"Could not read file %s. \n", path);
        exit(74);
    }

    buffer[fileSize] = '\0';

    fclose(file);
    return buffer;
}

static void runFile(const char* path) {
    char* source = readFile(path);
    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR) exit(65);
    if (result == INTERPRET_RUNTIME_ERROR) exit(70);

}

int main(int argc, const char *argv[]) {
#ifdef DEBUG_PRINT_CODE
    setbuf(stdout, 0);
#endif
    initVM();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: clox [path]\n");
        exit(64);
    }
    printf("%s", argv[0]);

    return 0;
}
