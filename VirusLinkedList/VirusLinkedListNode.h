#ifndef ERGASIA1_VIRUSLINKEDLISTNODE_H
#define ERGASIA1_VIRUSLINKEDLISTNODE_H

#include "../Virus/Virus.h"

class VirusLinkedListNode {
public:
    VirusLinkedListNode *next;
    Virus *Virus;

    VirusLinkedListNode(Virus *);
};


#endif //ERGASIA1_VirusLINKEDLISTNODE_H
