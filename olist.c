#include <assert.h>
#include "omalloc.h"
#include "olist.h"
#include "onode.h"

Olist *oCreateList(){
    Olist *ptr = omalloc(sizeof(Olist));
    ptr->count = 0;
    ptr->head.next = &(ptr->tail);
    ptr->head.prev = NULL;
    ptr->tail.next = NULL;
    ptr->tail.prev = &(ptr->head);
    ptr->head.size = 0;
    ptr->tail.size = 0;
    return ptr;
}
void oDestoryList(Olist *l){
    assert(l != NULL);
    size_t count = l->count;
    for (int i = 0; i < count; i++){
        oDestoryNode(oDeleteNodeInList(l, l->head.next));
    }
    ofree(l);
}


int oInsertNodeToList(Olist *l, Onode *n){
    assert(l != NULL && n != NULL);
    size_t c = l->count;
    if (c > (c + 1)) return -1;
    Onode *tmp_n = l->head.next;

    l->head.next = n;
    n->prev = &(l->head);
    n->next = tmp_n;
    tmp_n->prev = n; 
    l->count += 1;
}

Onode *oInquireNodeInList(const Olist *l, bool (*cmp)(const void *args, void *node), const void *args){
    assert(l != NULL && cmp != NULL && args != NULL);
    //size_t count = l->count;
    Onode **ptr = (Onode **const)&(l->head.next);
    bool flag = 0;

    while ((*ptr)->size != 0){
        flag = cmp(args, *ptr);
        if (flag == true){
            return *ptr;
        }
        *ptr = (*ptr)->next;
    }
    return NULL;
}
Onode *oAtList(const Olist *l, size_t index){
    assert(l != NULL);
    size_t count = l->count;
    if (index == -1 && count != 0){
        return l->tail.prev;
    }
    if (index >= count || index < 0) return NULL;

    Onode **ptr = (Onode **const)&(l->head.next);
    for (int i = 0; i != index; i++){
        *ptr = (*ptr)->next;
    }

    return *ptr;
}
Onode *oDeleteNodeInList(Olist *l, Onode *n){
    assert(l != NULL && n != NULL);
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->prev = NULL;
    n->next = NULL;
    l->count -= 1;
    return n;
}

size_t oGetListLength(Olist *l){
    assert(l != NULL);
    return l->count;
}






