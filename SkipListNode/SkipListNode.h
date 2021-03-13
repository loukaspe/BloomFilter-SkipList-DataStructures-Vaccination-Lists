#ifndef ERGASIA1_SKIPLISTNODE_H
#define ERGASIA1_SKIPLISTNODE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef MAX_LEVEL
#define MAX_LEVEL 16
#endif

static const int DEFAULT_KEY = -1;
static const int DEFAULT_VALUE = 0;

class SkipListNode {
private:
    int value;
    int key;
    SkipListNode **next;
public:
    SkipListNode();
    SkipListNode(int value);
    ~SkipListNode();

    int getValue() const;
    void setValue(int value);

    int getKey() const;
    void setKey(int key);

    SkipListNode *getNextNodeWithKey(int key) const;
    void setNextNodeWithKeyTo(int key, SkipListNode* givenNode);
};


#endif //ERGASIA1_SKIPLISTNODE_H
