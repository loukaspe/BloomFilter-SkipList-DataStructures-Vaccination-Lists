#include "SkipList.h"

SkipList::SkipList() :
        currentHighestLevel(STARTING_LEVEL),
        numberOfNodesExceptFirstAndLast(STARTING_SIZE) {
    firstNode = new SkipListNode();
    lastNode = new SkipListNode(MAX_SKIP_LIST_SIZE);

    for (int tempKey = 0; tempKey < MAX_SKIP_LIST_SIZE; tempKey++) {
        firstNode->setNextNodeWithKeyTo(tempKey, lastNode);
    }
}

SkipList::~SkipList() {
    SkipListNode *tempNode;
    SkipListNode *tempNode2;

    tempNode = firstNode->getNextNodeWithKey(0);
    while (tempNode != NULL) {
        tempNode2 = tempNode;
        tempNode = tempNode->getNextNodeWithKey(0);
        delete tempNode2;
    }

    delete firstNode;
}

SkipListNode *SkipList::getFirstNode() const {
    return firstNode;
}

void SkipList::setFirstNode(SkipListNode *firstNode) {
    SkipList::firstNode = firstNode;
}

SkipListNode *SkipList::getLastNode() const {
    return lastNode;
}

void SkipList::setLastNode(SkipListNode *lastNode) {
    SkipList::lastNode = lastNode;
}

int SkipList::getCurrentHighestLevel() const {
    return currentHighestLevel;
}

void SkipList::setCurrentHighestLevel(int currentHighestLevel) {
    SkipList::currentHighestLevel = currentHighestLevel;
}

int SkipList::getNumberOfNodesExceptFirstAndLast() const {
    return numberOfNodesExceptFirstAndLast;
}

void SkipList::setNumberOfNodesExceptFirstAndLast(int numberOfNodesExceptFirstAndLast) {
    SkipList::numberOfNodesExceptFirstAndLast = numberOfNodesExceptFirstAndLast;
}

int SkipList::search(int searchKey) {
    SkipListNode *tempNode = firstNode;

    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while ((tempNode->getNextNodeWithKey(i))->getKey() < searchKey) {
            tempNode = tempNode->getNextNodeWithKey(i);
        }
    }

    tempNode = tempNode->getNextNodeWithKey(0);

    if (tempNode->getKey() == searchKey) {
        return tempNode->getValue();
    }

    // TODO: return sth else
    return NULL;
}

void SkipList::insert(int searchKey, int newValue) {
    SkipListNode **nodesThatMayNeedToBeUpdated = new SkipListNode *[MAX_LEVEL];
    int newLevel;
    SkipListNode *tempNode = firstNode;

    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while ((tempNode->getNextNodeWithKey(i))->getKey() < searchKey) {
            tempNode = tempNode->getNextNodeWithKey(i);
        }

        nodesThatMayNeedToBeUpdated[i] = tempNode;
    }

    tempNode = tempNode->getNextNodeWithKey(0);
    if (tempNode->getKey() == searchKey) {
        //TODO: throw exception of insertedKey
        return;
    }

    newLevel = setLevelOfNodeByCalculatingPossibilities();
    if (newLevel > currentHighestLevel) {
        currentHighestLevel = newLevel;
    }
    tempNode = new SkipListNode(newLevel);
    tempNode->setValue(newValue);
    for (int i = 0; i <= newLevel; ++i) {
        tempNode->setNextNodeWithKeyTo(
                i,
                nodesThatMayNeedToBeUpdated[i]->getNextNodeWithKey(i)
        );
        nodesThatMayNeedToBeUpdated[i]->setNextNodeWithKeyTo(i, tempNode);
    }

    numberOfNodesExceptFirstAndLast++;

    delete nodesThatMayNeedToBeUpdated;
}

void SkipList::deleteNode(int searchKey) {
    SkipListNode **nodesThatMayNeedToBeUpdated = new SkipListNode *[MAX_LEVEL];
    SkipListNode *temp = firstNode;

    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while ((temp->getNextNodeWithKey(i))->getKey() < searchKey) {
            temp = temp->getNextNodeWithKey(i);
        }

        nodesThatMayNeedToBeUpdated[i] = temp;
    }

    temp = temp->getNextNodeWithKey(0);
    if (temp->getKey() == searchKey) {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            if (nodesThatMayNeedToBeUpdated[i]->getNextNodeWithKey(i) != temp) {
                break;
            }
            nodesThatMayNeedToBeUpdated[i]->setNextNodeWithKeyTo(i, temp->getNextNodeWithKey(i));
        }

        numberOfNodesExceptFirstAndLast--;
        delete temp;
    }
}

void SkipList::print() {
    SkipListNode *tempNode = firstNode->getNextNodeWithKey(0);
    if (tempNode == lastNode) {
        //TODO: Empty List
        return;
    }

    while (tempNode != lastNode) {
        tempNode->printValue();
        tempNode = tempNode->getNextNodeWithKey(0);
    }
}

int SkipList::setLevelOfNodeByCalculatingPossibilities() {
    srand(time(NULL));
    int level = STARTING_LEVEL;
    while (
            (rand() % 100) < POSSIBILITY_LIMIT_FOR_UPDATING_LEVEL
            && level < MAX_LEVEL
            ) {
        level++;
    }

    return level;
}

