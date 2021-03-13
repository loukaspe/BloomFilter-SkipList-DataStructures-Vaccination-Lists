#include "SkipListNode.h"

SkipListNode::SkipListNode()
{
    key = DEFAULT_KEY;
    value = DEFAULT_VALUE;
    this->next = new SkipListNode*[MAX_LEVEL];
    for (int i = 0; i < MAX_LEVEL; i++) {
        next[i] = NULL;
    }
}

SkipListNode::SkipListNode(int key) : key(key)
{
    this->value = 0;
    this->next = new SkipListNode*[MAX_LEVEL];
    for (int i = 0; i < MAX_LEVEL; i++) {
        next[i] = NULL;
    }
}

SkipListNode::~SkipListNode()
{
    delete next;
}

int SkipListNode::getValue() const {
    return value;
}

void SkipListNode::setValue(int value) {
    SkipListNode::value = value;
}

int SkipListNode::getKey() const {
    return key;
}

void SkipListNode::setKey(int key) {
    SkipListNode::key = key;
}

SkipListNode *SkipListNode::getNextNodeWithKey(int key) const {
    return next[key];
}

void SkipListNode::setNextNodeWithKeyTo(int key, SkipListNode *givenNode)
{
    this->next[key] = givenNode;
}
