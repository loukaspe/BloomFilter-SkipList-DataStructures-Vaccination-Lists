#include "VirusLinkedList.h"

VirusLinkedList::VirusLinkedList() {
    this->head = NULL;
    this->size = 0;
}


void VirusLinkedList::addAtStart(Virus* Virus) {
    VirusLinkedListNode* newNode = new VirusLinkedListNode(Virus);

    newNode->next = this->head;
    this->head = newNode;
    this->size++;
}

void VirusLinkedList::deleteNodeWithId(char* id) {
    if( isEmpty() ) {
        return;
    }

    VirusLinkedListNode* current = head;
    VirusLinkedListNode* previous = NULL;

    while( strcmp( current->Virus->getCitizenId(), id ) != 0 ) {

        if(current->next == NULL) {
            return;
        }

        previous = current;
        current = current->next;
    }

    if(current == head) {
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

VirusLinkedListNode *VirusLinkedList::findByName(char* virusName) {
    VirusLinkedListNode* current = this->head;
    while (current != NULL)
    {
        if (current->getVirus()->getVirusName() == virusName) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

