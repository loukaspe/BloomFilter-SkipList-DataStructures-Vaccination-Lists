/* A simple Linked List to hold the Viruses. Don't care about it's complexity since
 * the viruses' number is limited */

#ifndef ERGASIA1_VIRUSLINKEDLIST_H
#define ERGASIA1_VIRUSLINKEDLIST_H

#include "./VirusLinkedListNode.h"

class VirusLinkedList {
public:
    VirusLinkedList();
    void addAtStart(Virus*);
    void deleteNodeWithId(char*);
    int getSize();
    bool isEmpty();
    VirusLinkedListNode* findByName(char*);
private:
    VirusLinkedListNode* head;
    int size;
};


#endif //ERGASIA1_VIRUSLINKEDLIST_H
