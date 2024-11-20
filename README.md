# 概述

这是一个关于通用数据结构和算法实现的库

# 有哪些数据结构和算法呢？

- [x] [链表](#链表)
- [ ] 可变长数组
- [ ] 红黑树
- [ ] 图

### 链表

这个通用链表是怎么使用的呢？

```c
//test.c
#include "olist.h"//0
struct mystruct{
  int i;
};
int main(void){
    Olist *l = oCreateList();
    struct mystruct a = {0};
    Onode *n = oCreateNode(&a, sizeof(struct mystruct));
    oInsertNodeToList(l, n);
    oDeleteNodeInList(l, n);
    struct mystruct data = oGetData(n);
    oDestoryNode(n);
}
```

