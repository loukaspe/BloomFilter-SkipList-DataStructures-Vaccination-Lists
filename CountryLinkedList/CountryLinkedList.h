/* A simple Linked List to hold the Countries. Don't care about it's complexity since
 * the countries' number is limited */

#ifndef ERGASIA1_COUNTRYLINKEDLIST_H
#define ERGASIA1_COUNTRYLINKEDLIST_H

#include "../CountryLinkedList/CountryLinkedListNode.h"

class CountryLinkedList {
public:
    CountryLinkedList();

    void addAtStart(Country *);

    void deleteNodeWithName(char *);

    int getSize();

    bool isEmpty();

    CountryLinkedListNode *findByName(char *);

    void printStatisticsForDates(char*, Date*, Date*);

    void printStatisticsPerAgeForDates(char*, Date*, Date*);

private:

    void traverseAndPrintStatisticsForDates(CountryLinkedListNode *, char *, Date*, Date*);

    void traverseAndPrintStatisticsPerAgeForDates(CountryLinkedListNode *, char *, Date*, Date*);

    CountryLinkedListNode *head;
    int size;

};

#endif //ERGASIA1_COUNTRYLINKEDLIST_H
