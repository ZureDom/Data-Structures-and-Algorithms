/**
 * 通用数据类型非线程安全的链表
 * 使用说明：
 *      
 */


#ifndef __OLIST_H__
#define __OLIST_H__
#include <stdbool.h>
#include <stddef.h>
#include "onode.h"

struct _Olist{
    struct _Onode head, tail;
    size_t count;
};

typedef struct _Olist Olist;
/**
 * @brief 创建一个空链表
 * 
 * @return 返回指向链表的指针
 */
Olist *oCreateList();
/**
 * @brief 销毁一个链表
 * @param l 被销毁链表的指针
 */
void oDestoryList(Olist *l);

/**
 * @brief 向链表插入节点
 * @param l 被插入的链表的指针
 * @param n 插入节点
 * @return 如果链表长度达到最大时，则插入失败
 */
int oInsertNodeToList(Olist *l, Onode *n);
/**
 * @brief 查询并返回一个节点，该节点满足cmp的返回值为true
 * @param l 需要查询的链表的指针
 * @param cmp 函数指针，函数原型为：bool cmp(const void *args, void *node); 
 * @param args 函数指针cmp原型的第一个参数
 * @return 如果查询成功就返回该节点的指针，否则返回NULL
 */
Onode *oInquireNodeInList(const Olist *l, bool (*cmp)(const void *args, void *node), const void *args);
/**
 * @brief 根据索引index返回链表l中的节点
 * @param l 被查询的链表的指针
 * @param index 索引
 * @return 1、当index = -1，返回链表倒数第一个节点；2、当 0 <= index < 链表长度,返回对应的节点；3、其它，返回NULL
 */
Onode *oAtList(const Olist *l, size_t index);
/**
 * @brief 在链表l中删除n节点
 * @param l 
 * @param n 被删除的节点
 * @return 返回被删除的节点
 */
Onode *oDeleteNodeInList(Olist *l, Onode *n);
/**
 * @brief 获取链表长度（节点数）
 * @param l 
 * @return 返回链表长度
 */
size_t oGetListLength(Olist *l);

#endif