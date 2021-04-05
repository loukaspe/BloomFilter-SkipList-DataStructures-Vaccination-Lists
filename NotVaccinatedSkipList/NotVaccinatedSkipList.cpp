#include "NotVaccinatedSkipList.h"

NotVaccinatedSkipList::NotVaccinatedSkipList() :
        currentHighestLevel(STARTING_NOT_VACCINATED_LIST_LEVEL),
        numberOfNodesExceptFirstAndLast(STARTING_NOT_VACCINATED_LIST_SIZE) {
    firstNode = new NotVaccinatedPersonSkipListNode();
    lastNode = new NotVaccinatedPersonSkipListNode(MAX_SKIP_LIST_SIZE);

    for (int tempKey = 0; tempKey < MAX_SKIP_LIST_SIZE; tempKey++) {
        firstNode->setNextNodeWithKeyTo(tempKey, lastNode);
    }
}

NotVaccinatedSkipList::~NotVaccinatedSkipList() {
    NotVaccinatedPersonSkipListNode *tempNode;
    NotVaccinatedPersonSkipListNode *tempNode2;

    tempNode = firstNode->getNextNodeWithKey(0);
    while (tempNode != NULL) {
        tempNode2 = tempNode;
        tempNode = tempNode->getNextNodeWithKey(0);
        delete tempNode2;
    }

    delete firstNode;
}

NotVaccinatedPersonSkipListNode *NotVaccinatedSkipList::getFirstNode() const {
    return firstNode;
}

void NotVaccinatedSkipList::setFirstNode(NotVaccinatedPersonSkipListNode *firstNode) {
    NotVaccinatedSkipList::firstNode = firstNode;
}

NotVaccinatedPersonSkipListNode *NotVaccinatedSkipList::getLastNode() const {
    return lastNode;
}

void NotVaccinatedSkipList::setLastNode(NotVaccinatedPersonSkipListNode *lastNode) {
    NotVaccinatedSkipList::lastNode = lastNode;
}

int NotVaccinatedSkipList::getCurrentHighestLevel() const {
    return currentHighestLevel;
}

void NotVaccinatedSkipList::setCurrentHighestLevel(int currentHighestLevel) {
    NotVaccinatedSkipList::currentHighestLevel = currentHighestLevel;
}

int NotVaccinatedSkipList::getNumberOfNodesExceptFirstAndLast() const {
    return numberOfNodesExceptFirstAndLast;
}

void NotVaccinatedSkipList::setNumberOfNodesExceptFirstAndLast(int numberOfNodesExceptFirstAndLast) {
    NotVaccinatedSkipList::numberOfNodesExceptFirstAndLast = numberOfNodesExceptFirstAndLast;
}

Person* NotVaccinatedSkipList::search(int searchKey) {
    NotVaccinatedPersonSkipListNode *tempNode = firstNode;

    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while ((tempNode->getNextNodeWithKey(i))->getKey() < searchKey) {
            tempNode = tempNode->getNextNodeWithKey(i);
        }
    }

    tempNode = tempNode->getNextNodeWithKey(0);

    if (tempNode->getKey() == searchKey) {
        return tempNode->getPerson();
    }

    // TODO: return sth else
    return NULL;
}

void NotVaccinatedSkipList::insert(int searchKey, Person* newPerson) {
    NotVaccinatedPersonSkipListNode **nodesThatMayNeedToBeUpdated = new NotVaccinatedPersonSkipListNode *[MAX_LEVEL];
    int newLevel;
    NotVaccinatedPersonSkipListNode *tempNode = firstNode;

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
    tempNode = new NotVaccinatedPersonSkipListNode(newLevel);
    tempNode->setPerson(newPerson);
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

void NotVaccinatedSkipList::deleteNode(int searchKey) {
    NotVaccinatedPersonSkipListNode **nodesThatMayNeedToBeUpdated = new NotVaccinatedPersonSkipListNode *[MAX_LEVEL];
    NotVaccinatedPersonSkipListNode *temp = firstNode;

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

void NotVaccinatedSkipList::print() {
    NotVaccinatedPersonSkipListNode *tempNode = firstNode->getNextNodeWithKey(0);
    if (tempNode == lastNode) {
        //TODO: Empty List
        return;
    }

    while (tempNode != lastNode) {
        tempNode->printPersonInfo();
        tempNode = tempNode->getNextNodeWithKey(0);
    }
}

int NotVaccinatedSkipList::setLevelOfNodeByCalculatingPossibilities() {
    srand(time(NULL));
    int level = STARTING_NOT_VACCINATED_LIST_LEVEL;
    while (
            (rand() % 100) < NOT_VACCINATED_LIST_KEY_POSSIBILITY_LIMIT_FOR_UPDATING_LEVEL
            && level < MAX_LEVEL
            ) {
        level++;
    }

    return level;
}

