#ifndef __OMALLOC_H__
#define __OMALLOC_H__
#include <stdlib.h>
#include <stdint.h>
//#include "log.h"

void *omalloc(size_t size);

void ofree(void *ptr);


#endif