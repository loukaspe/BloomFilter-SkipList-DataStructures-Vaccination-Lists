#include "PersonLinkedListNode.h"

PersonLinkedListNode::PersonLinkedListNode(Person* person) {
    this->person = person;
    this->next = NULL;
//    this->id = Helper::copyString(this->voterNode->voter->getId());
}