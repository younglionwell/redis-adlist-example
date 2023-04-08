#include "adlist.h"
#include <stdio.h>

void printList(list *mylist) {
    listIter *iter = listGetIterator(mylist, AL_START_HEAD);
    listNode *node = NULL;
    while (node = listNext(iter)) {
        printf("%d ", (int)node->value);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    list * mylist = listCreate();
    
    for (int i = 0; i < 10; i++) {
        listAddNodeTail(mylist, (void *)i); // 数据直接存放在 value 指针中
    }

    printf("原链表: ");
    printList(mylist);

    printf("将链表尾部节点移到首部: ");
    listRotateTailToHead(mylist);
    printList(mylist);

    list * newlist = listCreate();
    for (int i = 0; i < 10; i++) {
        listAddNodeTail(newlist, (void *)(i*10)); // 数据直接存放在 value 指针中
    }
    printf("新链表: ");
    printList(newlist);

    printf("将新链表连接到旧链表: ");
    listJoin(mylist, newlist);
    printList(mylist);

    printf("将链表首部节点移到尾部: ");
    listRotateHeadToTail(mylist);
    printList(mylist);

    printf("将链表首部节点删除: ");
    listDelNode(mylist, listFirst(mylist));
    printList(mylist);

    printf("查询链表中值为 50 的节点: ");
    listNode *  node = listSearchKey(mylist, (void *)50);
    if (node) {
        printf("找到了(%d)\n", (int)node->value);
    } else {
        printf("没找到\n");
    }

    printf("查询链表中索引为 2 的节点: ");
    node = listIndex(mylist, 2);
    if (node) {
        printf("找到了(%d)\n", (int)node->value);
    } else {
        printf("没找到\n");
    }

    printf("查询链表中索引为 -2 的节点: ");
    node = listIndex(mylist, -2);
    if (node) {
        printf("找到了(%d)\n", (int)node->value);
    } else {
        printf("没找到\n");
    }

    listRelease(mylist);

    return 0;
}