#ifndef ERGASIA1_SKIPLISTNODE_H
#define ERGASIA1_SKIPLISTNODE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef MAX_LEVEL
#define MAX_LEVEL 16
#endif

using namespace std;

static int DEFAULT_KEY = -1;
static char* DEFAULT_VALUE = "";

class SkipListNode {
private:
    char* value;
    int key;
    SkipListNode **next;
public:
    SkipListNode();

    SkipListNode(int key);

    ~SkipListNode();

    char* getValue() const;

    void setValue(char* value);

    int getKey() const;

    void setKey(int key);

    SkipListNode *getNextNodeWithKey(int key) const;

    void setNextNodeWithKeyTo(int key, SkipListNode *givenNode);

    void printValue();
};


#endif //ERGASIA1_SKIPLISTNODE_H
