#include "VaccinatedSkipList.h"

VaccinatedSkipList::VaccinatedSkipList() :
        currentHighestLevel(STARTING_VACCINATED_LIST_LEVEL),
        numberOfNodesExceptFirstAndLast(STARTING_VACCINATED_LIST_SIZE) {
    firstNode = new VaccinatedPersonSkipListNode();
    lastNode = new VaccinatedPersonSkipListNode(MAX_SKIP_LIST_SIZE);

    for (int tempKey = 0; tempKey < MAX_SKIP_LIST_SIZE; tempKey++) {
        firstNode->setNextNodeWithKeyTo(tempKey, lastNode);
    }
}

VaccinatedSkipList::~VaccinatedSkipList() {
    VaccinatedPersonSkipListNode *tempNode;
    VaccinatedPersonSkipListNode *tempNode2;

    tempNode = firstNode->getNextNodeWithKey(0);
    while (tempNode != NULL) {
        tempNode2 = tempNode;
        tempNode = tempNode->getNextNodeWithKey(0);
        delete tempNode2;
    }

    delete firstNode;
}

VaccinatedPersonSkipListNode *VaccinatedSkipList::getFirstNode() const {
    return firstNode;
}

void VaccinatedSkipList::setFirstNode(VaccinatedPersonSkipListNode *firstNode) {
    VaccinatedSkipList::firstNode = firstNode;
}

VaccinatedPersonSkipListNode *VaccinatedSkipList::getLastNode() const {
    return lastNode;
}

void VaccinatedSkipList::setLastNode(VaccinatedPersonSkipListNode *lastNode) {
    VaccinatedSkipList::lastNode = lastNode;
}

int VaccinatedSkipList::getCurrentHighestLevel() const {
    return currentHighestLevel;
}

void VaccinatedSkipList::setCurrentHighestLevel(int currentHighestLevel) {
    this->currentHighestLevel = currentHighestLevel;
}

int VaccinatedSkipList::getNumberOfNodesExceptFirstAndLast() const {
    return numberOfNodesExceptFirstAndLast;
}

void VaccinatedSkipList::setNumberOfNodesExceptFirstAndLast(int numberOfNodesExceptFirstAndLast) {
    this->numberOfNodesExceptFirstAndLast = numberOfNodesExceptFirstAndLast;
}

Vaccination* VaccinatedSkipList::search(int searchKey) {
    VaccinatedPersonSkipListNode *tempNode = firstNode;

    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while ((tempNode->getNextNodeWithKey(i))->getKey() < searchKey) {
            tempNode = tempNode->getNextNodeWithKey(i);
        }
    }

    tempNode = tempNode->getNextNodeWithKey(0);

    if (tempNode->getKey() == searchKey) {
        return tempNode->getVaccination();
    }

    // TODO: return sth else
    return NULL;
}

void VaccinatedSkipList::insert(int searchKey, Vaccination* newVaccination) {
    VaccinatedPersonSkipListNode **nodesThatMayNeedToBeUpdated = new VaccinatedPersonSkipListNode *[MAX_LEVEL];
    int newLevel;
    VaccinatedPersonSkipListNode *tempNode = firstNode;

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
    tempNode = new VaccinatedPersonSkipListNode(newLevel);
    tempNode->setVaccination(newVaccination);
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

void VaccinatedSkipList::deleteNode(int searchKey) {
    VaccinatedPersonSkipListNode **nodesThatMayNeedToBeUpdated = new VaccinatedPersonSkipListNode *[MAX_LEVEL];
    VaccinatedPersonSkipListNode *temp = firstNode;

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

void VaccinatedSkipList::print() {
    VaccinatedPersonSkipListNode *tempNode = firstNode->getNextNodeWithKey(0);
    if (tempNode == lastNode) {
        //TODO: Empty List
        return;
    }

    while (tempNode != lastNode) {
        tempNode->printVaccinationInfo();
        tempNode = tempNode->getNextNodeWithKey(0);
    }
}

int VaccinatedSkipList::setLevelOfNodeByCalculatingPossibilities() {
    srand(time(NULL));
    int level = STARTING_VACCINATED_LIST_LEVEL;
    while (
            (rand() % 100) < VACCINATED_LIST_KEY_POSSIBILITY_LIMIT_FOR_UPDATING_LEVEL
            && level < MAX_LEVEL
            ) {
        level++;
    }

    return level;
}

