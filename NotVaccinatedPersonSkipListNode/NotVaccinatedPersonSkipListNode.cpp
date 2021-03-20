#include "NotVaccinatedPersonSkipListNode.h"

NotVaccinatedPersonSkipListNode::NotVaccinatedPersonSkipListNode() {
    key = DEFAULT_KEY;
    person = NULL;
    this->next = new NotVaccinatedPersonSkipListNode *[MAX_LEVEL];
    for (int i = 0; i < MAX_LEVEL; i++) {
        next[i] = NULL;
    }
}

NotVaccinatedPersonSkipListNode::NotVaccinatedPersonSkipListNode(int key) : key(key) {
    this->person = NULL;
    this->next = new NotVaccinatedPersonSkipListNode *[MAX_LEVEL];
    for (int i = 0; i < MAX_LEVEL; i++) {
        next[i] = NULL;
    }
}

NotVaccinatedPersonSkipListNode::~NotVaccinatedPersonSkipListNode() {
    delete next;
}

Person* NotVaccinatedPersonSkipListNode::getPerson() const {
    return person;
}

void NotVaccinatedPersonSkipListNode::setPerson(Person* person) {
    NotVaccinatedPersonSkipListNode::person = person;
}

int NotVaccinatedPersonSkipListNode::getKey() const {
    return key;
}

void NotVaccinatedPersonSkipListNode::setKey(int key) {
    NotVaccinatedPersonSkipListNode::key = key;
}

NotVaccinatedPersonSkipListNode *NotVaccinatedPersonSkipListNode::getNextNodeWithKey(int key) const {
    return next[key];
}

void NotVaccinatedPersonSkipListNode::setNextNodeWithKeyTo(int key, NotVaccinatedPersonSkipListNode *givenNode) {
    this->next[key] = givenNode;
}

void NotVaccinatedPersonSkipListNode::printPersonInfo() {
    cout << "Info of Person ID: " << this->person->getCitizenId() << endl <<
    "\t" << this->person->getFirstName() << endl <<
    "\t" << this->person->getLastName() << endl <<
    "\t" << this->person->getAge() << endl <<
    "\t" << this->person->getCountry() << endl;
}
