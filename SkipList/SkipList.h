#ifndef ERGASIA1_SKIPLIST_H
#define ERGASIA1_SKIPLIST_H

#ifndef MAX_SKIP_LIST_SIZE
#define MAX_SKIP_LIST_SIZE 100000000
#endif

#include "../SkipListNode/SkipListNode.h"

static const int STARTING_LEVEL = 1;
static const int STARTING_SIZE = 0;
static const int POSSIBILITY_LIMIT_FOR_UPDATING_LEVEL = 25;

class SkipList {
private:
    SkipListNode* firstNode;
    SkipListNode* lastNode;
    int currentHighestLevel;
    int numberOfNodesExceptFirstAndLast;
    int setLevelOfNodeByCalculatingPossibilities();

public:
    SkipList();
    virtual ~SkipList();

    int* search(int searchKey);
    void insert(int searchKey, int *newValue);
    int deleteNode(int searchKey);
    void print();

    SkipListNode *getFirstNode() const;
    void setFirstNode(SkipListNode *firstNode);

    SkipListNode *getLastNode() const;
    void setLastNode(SkipListNode *lastNode);

    int getCurrentHighestLevel() const;
    void setCurrentHighestLevel(int currentHighestLevel);

    int getNumberOfNodesExceptFirstAndLast() const;
    void setNumberOfNodesExceptFirstAndLast(int numberOfNodesExceptFirstAndLast);
};


#endif //ERGASIA1_SKIPLIST_H
