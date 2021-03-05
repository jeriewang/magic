#include "magicWrapper.h"
#include <stdio.h>

int main(int argc, char** argv){
    if (argc!=2){
        printf("Usage: %s path\n",argv[0]);
        return 1;
    }
    const char * content=check(argv[1],MAGIC_CONTINUE|MAGIC_PRESERVE_ATIME);
    if (content==NULL){
        printf("Cannot open file\n");
        return 1;
    }
    printf("%s\n",content);
    free((void *)content);
}