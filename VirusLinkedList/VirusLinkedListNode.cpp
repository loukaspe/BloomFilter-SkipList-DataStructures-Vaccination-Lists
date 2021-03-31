#include "VirusLinkedListNode.h"

VirusLinkedListNode::VirusLinkedListNode(Virus* Virus) {
    this->Virus = Virus;
    this->next = NULL;
//    this->id = Helper::copyString(this->voterNode->voter->getId());
}