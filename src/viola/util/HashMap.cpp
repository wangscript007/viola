/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "HashMap.h"

HashMap::HashMap() {
	capacity = 16;
	table = new entry[capacity];
	threshold = tableSizeFor(capacity);
}

HashMap::HashMap(int capacity) {
	this->capacity = capacity;
	table = new entry[capacity];
	threshold = tableSizeFor(capacity);
}

HashMap::~HashMap() {
	this->clear();
	delete[] table;
}

bool HashMap::containsKey(object key) {
	object val = this->get(key);
	if (val == NULL) {
		return false;
	}
	return true;
}

object HashMap::put(object key, object value) {
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
	entry p = table[index];
	if (p == NULL) {
		table[index] = std::make_shared<Entry>(key, value);
		return NULL;
	} else {
		Entry* e = NULL;
		object k = p->getKey();
		int phash = hash(k->hashCode());
		if (phash == h && key->equals(k.get())) {
			e = p.get();
		} else {
			Entry* pp = p.get();
			for (int binCount = 0;; ++binCount) {
				if (pp->getNext() == NULL) {
					entry ent = std::make_shared<Entry>(key, value);
					Entry* ep = ent.get();
					printf("collision. <%s>\n", ep->toString().c_str());
					printf("before: <%s>\n",this->toString().c_str());
					pp->setNext(ep);
					printf("after: <%s>\n",this->toString().c_str());
					break;
				}
				e = pp->getNext();
				int ehash = hash(e->getKey()->hashCode());
				if (ehash == h && key->equals(e->getKey().get())) {
					break;
				}
				pp = e;
			}
		}
		if (e != NULL) {
			object oldValue = e->getValue();
			e->setValue(value);
			return oldValue;
		}
	}

	if (size() > threshold) {
		resize();
	}
	return NULL;

}

object HashMap::putIfAbsent(object key, object value) {
	if (this->containsKey(key)) {
		return this->get(key);
	}
	put(key, value);
	return NULL;
}

object HashMap::get(object key) {
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
	entry first = table[index];
	if (first == NULL) {
		return NULL;
	}
	int fHash = hash(first->getKey()->hashCode());
	if (fHash == h && key->equals(first->getKey().get())) {
		return first->getValue();
	}
	Entry* e = first->getNext();
	if (e == NULL) {
		return NULL;
	}
	do {
		int eHash = hash(e->getKey()->hashCode());
		if (eHash == h && key->equals(e->getKey().get())) {
			return e->getValue();
		}
	} while ((e = e->getNext()) != NULL);

	return NULL;
}
object HashMap::remove(object key) {
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
	entry first = table[index];
	if (first == NULL) {
		return NULL;
	}

	entry node = NULL;
	Entry* e = NULL;
	int fHash = hash(first->getKey()->hashCode());
	if (fHash == h && key->equals(first->getKey().get())) {
		node = first;
	} else if ((e = first->getNext()) != NULL) {
		do {
			int eHash = hash(e->getKey()->hashCode());
			if (eHash == h && key->equals(e->getKey().get())) {
				node = std::make_shared<Entry>(e->getKey(), e->getValue());
				break;
			}
			first = std::make_shared<Entry>(e->getKey(), e->getValue());
		} while ((e = e->getNext()) != NULL);
	}
	if (node == NULL) {
		return NULL;
	}
	if (node->equals(first.get())) {
		Entry* n = node->getNext();
		table[index] = std::make_shared<Entry>(n->getKey(), n->getValue());
	} else {
		first->setNext(node->getNext());
	}
	return node;
}

void HashMap::clear() {
	for (int i = 0; i < capacity; i++) {
		table[i] = NULL;
	}
}

int HashMap::getCapacity() {
	return capacity;
}

int HashMap::size() {
	int size = 0;
	for (int i = 0; i < capacity; i++) {
		entry e = table[i];
		if (e == NULL) {
			continue;
		}
		Entry* p = e.get();
		do {
			size++;
		} while ((p = p->getNext()) != NULL);
	}
	return size;
}
bool HashMap::isEmpty() {
	return size() == 0;
}

int HashMap::hashCode() {
	int hashCode = 1;
	for (int i = 0; i < capacity; i++) {
		int tmp = 0;
		if (table[i] != NULL) {
			tmp = table[i].get()->hashCode();
		}
		hashCode = 31 * hashCode + tmp;
	}

	return hashCode;
}

bool HashMap::equals(Object* obj) {
	HashMap* map = (HashMap*) obj;
	if (hashCode() == map->hashCode()) {
		return true;
	}
	return false;
}

string HashMap::toString() {
	string str("HashMap[");
	for (int i = 0; i < capacity; i++) {
		entry e = table[i];

		if (e == NULL) {
			continue;
		}
		Entry* p = e.get();
		do {
			str.append(p->toString());
			str.append(", ");
		} while ((p = p->getNext()) != NULL);

		if (i < size() - 1) {
			str.append(", ");
		}
	}
	str.append("]");
	return str;
}

string HashMap::getClassName() {
	return "HashMap";
}

int HashMap::hash(int keyHashCode) {
	return keyHashCode ^ (keyHashCode >> 16);
}

int HashMap::tableSizeFor(int capacity) {
	return 0;
}
void HashMap::resize() {

}
