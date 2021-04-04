#include "PersonLinkedList.h"

PersonLinkedList::PersonLinkedList() {
    this->head = NULL;
    this->size = 0;
}


void PersonLinkedList::addAtStart(Person* person) {
    PersonLinkedListNode* newNode = new PersonLinkedListNode(person);

    newNode->next = this->head;
    this->head = newNode;
    this->size++;
}

void PersonLinkedList::deleteNodeWithId(char* id) {
    if( isEmpty() ) {
        return;
    }

    PersonLinkedListNode* current = head;
    PersonLinkedListNode* previous = NULL;

    while( strcmp( current->person->getCitizenId(), id ) != 0 ) {

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

int PersonLinkedList::getSize() {
    return this->size;
}

bool PersonLinkedList::isEmpty() {
    return this->size == 0;
}

PersonLinkedListNode *PersonLinkedList::findByCitizenId(char * citizenId) {
    PersonLinkedListNode* current = this->head;
    while (current != NULL)
    {
        if (current->person->getCitizenId() == citizenId) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

