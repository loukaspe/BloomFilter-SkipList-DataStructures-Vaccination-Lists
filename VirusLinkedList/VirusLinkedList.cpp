#include "VirusLinkedList.h"

VirusLinkedList::VirusLinkedList() {
    this->head = NULL;
    this->size = 0;
}


void VirusLinkedList::addAtStart(Virus *Virus) {
    VirusLinkedListNode *newNode = new VirusLinkedListNode(Virus);

    newNode->next = this->head;
    this->head = newNode;
    this->size++;
}

void VirusLinkedList::deleteNodeWithName(char *name) {
    if (isEmpty()) {
        return;
    }

    VirusLinkedListNode *current = head;
    VirusLinkedListNode *previous = NULL;

    while (strcmp(current->getVirus()->getVirusName(), name) != 0) {

        if (current->next == NULL) {
            return;
        }

        previous = current;
        current = current->next;
    }

    if (current == head) {
        head = head->next;
        free(current);
        this->size--;
        return;
    }

    previous->next = current->next;
    free(current);
    this->size--;
}

int VirusLinkedList::getSize() {
    return this->size;
}

bool VirusLinkedList::isEmpty() {
    return this->size == 0;
}

VirusLinkedListNode *VirusLinkedList::findByName(char *virusName) {
    VirusLinkedListNode *current = this->head;
    while (current != NULL) {
        if (strcmp(current->getVirus()->getVirusName(), virusName) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void VirusLinkedList::traverseAndCheckIfVaccinated(
        VirusLinkedListNode *initialRecursiveNode,
        char *citizenId
) {
    if (initialRecursiveNode == NULL) {
        return;
    }

    Virus *tempVirus = initialRecursiveNode->getVirus();
    bool shouldPrintVirusName = true;
    tempVirus->printIfPersonIsVaccinated(citizenId, true);

    this->traverseAndCheckIfVaccinated(initialRecursiveNode->next, citizenId);
}

void VirusLinkedList::checkIfVaccinatedForAllViruses(char *citizenId) {
    this->traverseAndCheckIfVaccinated(this->head, citizenId);
}
