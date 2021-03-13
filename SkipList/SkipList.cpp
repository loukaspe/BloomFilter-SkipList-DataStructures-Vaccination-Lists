#include "SkipList.h"

SkipList::SkipList():
    currentHighestLevel(STARTING_LEVEL),
    numberOfNodesExceptFirstAndLast(STARTING_SIZE)
{
    firstNode = new SkipListNode();
    lastNode = new SkipListNode(MAX_SKIP_LIST_SIZE);

    for(int tempKey = 0; tempKey < MAX_SKIP_LIST_SIZE; tempKey++) {
        firstNode->setNextNodeWithKeyTo(tempKey, lastNode);
    }
}

SkipList::~SkipList()
{
    SkipListNode* tempNode;
    SkipListNode* tempNode2;

    tempNode = firstNode->getNextNodeWithKey(0);
    while(tempNode != NULL) {
        tempNode2 = tempNode;
        tempNode = tempNode->getNextNodeWithKey(0);
        delete tempNode2;
    }
    
    delete firstNode;
}

SkipListNode *SkipList::getFirstNode() const
{
    return firstNode;
}

void SkipList::setFirstNode(SkipListNode *firstNode)
{
    SkipList::firstNode = firstNode;
}

SkipListNode *SkipList::getLastNode() const
{
    return lastNode;
}

void SkipList::setLastNode(SkipListNode *lastNode)
{
    SkipList::lastNode = lastNode;
}

int SkipList::getCurrentHighestLevel() const
{
    return currentHighestLevel;
}

void SkipList::setCurrentHighestLevel(int currentHighestLevel)
{
    SkipList::currentHighestLevel = currentHighestLevel;
}

int SkipList::getNumberOfNodesExceptFirstAndLast() const
{
    return numberOfNodesExceptFirstAndLast;
}

void SkipList::setNumberOfNodesExceptFirstAndLast(int numberOfNodesExceptFirstAndLast)
{
    SkipList::numberOfNodesExceptFirstAndLast = numberOfNodesExceptFirstAndLast;
}

int* SkipList::search(int searchKey)
{

}

void SkipList::insert(int searchKey, int *newValue)
{

}

int SkipList::deleteNode(int searchKey)
{

}

void SkipList::print()
{

}

int SkipList::setLevelOfNodeByCalculatingPossibilities() {
    srand(time(NULL));
    int level = STARTING_LEVEL;
    while(
            (rand() % 100) < POSSIBILITY_LIMIT_FOR_UPDATING_LEVEL
        && level < MAX_LEVEL
    ) {
        level++;
    }
    
    return level;
}

