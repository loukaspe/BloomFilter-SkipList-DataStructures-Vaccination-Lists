#ifndef ERGASIA1_VIRUSLINKEDLISTNODE_H
#define ERGASIA1_VIRUSLINKEDLISTNODE_H

#include "../Virus/Virus.h"

class VirusLinkedListNode {
public:
    VirusLinkedListNode *next;
    VirusLinkedListNode(Virus*);
private:
    Virus* virus;
public:
    Virus *getVirus() const;
};


#endif //ERGASIA1_VirusLINKEDLISTNODE_H
