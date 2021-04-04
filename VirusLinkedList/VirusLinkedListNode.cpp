#include "VirusLinkedListNode.h"

VirusLinkedListNode::VirusLinkedListNode(Virus* Virus) {
    this->virus = Virus;
    this->next = NULL;
//    this->id = Helper::copyString(this->voterNode->voter->getId());
}

Virus *VirusLinkedListNode::getVirus() const {
    return virus;
}
