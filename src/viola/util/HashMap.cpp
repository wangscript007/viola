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
	object p = table[index];
	if (p == NULL) {
		table[index] = std::make_shared<Entry>(key, value);
		return NULL;
	} else {
		object e = NULL;
		object k = ((Entry*) p.get())->getKey();
		int phash = hash(k->hashCode());
		if (phash == h && key->equals(k.get())) {
			e = p;
		} else {
			for (int binCount = 0;; ++binCount) {
				object e = ((Entry*) p.get())->getNext();
				if (e == NULL) {
					entry ent = std::make_shared<Entry>(key, value);
					printf("collision. <%s>\n", ent->toString().c_str());
					printf("before: <%s>\n", this->toString().c_str());
					((Entry*) p.get())->setNext(ent);
					printf("after: <%s>\n", this->toString().c_str());
					break;
				}
				Entry* tmp = (Entry*) e.get();
				int ehash = hash(tmp->getKey()->hashCode());
				if (ehash == h && key->equals(tmp->getKey().get())) {
					break;
				}
				p = e;
			}
		}
		if (e != NULL) {
			object oldValue = ((Entry*) e.get())->getValue();
			((Entry*) p.get())->setValue(value);
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
	object first = table[index];
	if (first == NULL) {
		return NULL;
	}
	int fHash = hash(((Entry*) first.get())->getKey()->hashCode());
	if (fHash == h && key->equals(((Entry*) first.get())->getKey().get())) {
		return ((Entry*) first.get())->getValue();
	}
	object e = ((Entry*) first.get())->getNext();
	if (e == NULL) {
		return NULL;
	}
	do {
		int eHash = hash(((Entry*) e.get())->getKey()->hashCode());
		if (eHash == h && key->equals(((Entry*) e.get())->getKey().get())) {
			return ((Entry*) e.get())->getValue();
		}
	} while ((e = ((Entry*) e.get())->getNext()) != NULL);

	return NULL;
}
object HashMap::remove(object key) {
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
	object first = table[index];
	if (first == NULL) {
		return NULL;
	}

	object node = NULL;
	object e = NULL;
	int fHash = hash(((Entry*) first.get())->getKey()->hashCode());
	if (fHash == h && key->equals(((Entry*) first.get())->getKey().get())) {
		node = first;
	} else if ((e = ((Entry*) first.get())->getNext()) != NULL) {
		Entry* ent = NULL;
		do {
			ent = ((Entry*) first.get());
			int eHash = hash(ent->getKey()->hashCode());
			if (eHash == h && key->equals(ent->getKey().get())) {
				node = std::make_shared<Entry>(ent->getKey(), ent->getValue());
				break;
			}
			first = std::make_shared<Entry>(ent->getKey(), ent->getValue());

		} while ((ent = (Entry*) ent->getNext().get()) != NULL);
	}
	if (node == NULL) {
		return NULL;
	}
	if (node->equals(first.get())) {
		Entry* n = (Entry*) ((Entry*) node.get())->getNext().get();
		table[index] = std::make_shared<Entry>(n->getKey(), n->getValue());
	} else {
		Entry* fp = ((Entry*) first.get());
		Entry* np = ((Entry*) node.get());
		fp->setNext(np->getNext());
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
		} while ((p = ((Entry*) p->getNext().get())) != NULL);
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
		} while ((p = ((Entry*) p->getNext().get())) != NULL);

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
