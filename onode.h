#ifndef __ONODE_H__
#define __ONODE_H__
#include <stddef.h>

struct _Onode{
    struct _Onode *next;
    struct _Onode *prev;
    size_t size;
};
typedef struct _Onode Onode;
/**
 * @brief 创建一个节点
 * @param data 用户数据
 * @param size 用户数据大小
 * @return 返回一个指向被创建的节点的指针
 */
Onode *oCreateNode(const void *data, size_t size);
/**
 * @brief 返回一个节点的用户数据
 * @param n 节点
 * @return 返回的用户数据
 */
void * oGetData(Onode *n);
/**
 * @brief 销毁一个节点
 * @param node 被销毁节点的指针
 */
void oDestoryNode(Onode *node);
#endif