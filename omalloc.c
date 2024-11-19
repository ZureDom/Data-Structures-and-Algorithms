#include "omalloc.h"



void *omalloc(size_t size){
    void *ptr = malloc(size + sizeof(size_t));
    if (ptr == NULL){
        //log(LOG_WARNING, "<omalloc>%s", strerror_r(errno, "", sizeof("")));
        exit(EXIT_FAILURE);
    }
    *(size_t *)ptr = size;
    ptr += sizeof(size_t);

    
    return ptr;
}

void ofree(void *ptr){
    ptr -= sizeof(size_t);
    free(ptr);
}