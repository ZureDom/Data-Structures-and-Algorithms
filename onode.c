#include <string.h>
#include <assert.h>
#include "omalloc.h"
#include "onode.h"

#include <stdio.h>

Onode *oCreateNode(const void *data, size_t size){
    Onode *ptr = omalloc(size + sizeof(Onode));
    memcpy((void *)ptr + sizeof(Onode), data, size);
    ptr->size = size;
    return ptr;
}
void oDestoryNode(Onode *node){
    ofree(node);
}
void *oGetData(Onode *n){
    assert(n != NULL);
    return (n + sizeof(Onode));
}