/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "HashMap.h"

HashMap::HashMap() {
	capacity = 16;
	threshold = tableSizeFor(capacity);
	table = new entry[threshold];
}

HashMap::HashMap(int capacity) {
	this->capacity = capacity;
	threshold = tableSizeFor(capacity);
	table = new entry[threshold];
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
					((Entry*) p.get())->setNext(ent);
					break;
				}
				Entry* ep = (Entry*) e.get();
				int ehash = hash(ep->getKey()->hashCode());
				if (ehash == h && key->equals(ep->getKey().get())) {
					break;
				}
				p = e;
			}
		}
		if (e != NULL) {
			Entry* ep = (Entry*) e.get();
			object oldValue = ep->getValue();
			ep->setValue(value);
			return oldValue;
		}
	}

	if (size() > threshold) {
		printf("resize\n");
		resize();
		printf("resized\n");
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
	Entry* ep = (Entry*) first.get();
	int fHash = hash(ep->getKey()->hashCode());
	if (fHash == h && key->equals(ep->getKey().get())) {
		return ep->getValue();
	}
	object e = ep->getNext();
	if (e == NULL) {
		return NULL;
	}
	do {
		Entry* ep = (Entry*) e.get();
		int eHash = hash(ep->getKey()->hashCode());
		if (eHash == h && key->equals(ep->getKey().get())) {
			return ep->getValue();
		}
	} while ((e = ep->getNext()) != NULL);

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
	Entry* fp = (Entry*) first.get();
	int fHash = hash(fp->getKey()->hashCode());
	if (fHash == h && key->equals(fp->getKey().get())) {
		node = first;
	} else if ((e = fp->getNext()) != NULL) {
		Entry* ent = NULL;
		do {
			ent = fp;
			int eHash = hash(ent->getKey()->hashCode());
			if (eHash == h && key->equals(ent->getKey().get())) {
				node = std::make_shared<Entry>(ent);
				break;
			}
			first = std::make_shared<Entry>(ent);

		} while ((ent = (Entry*) ent->getNext().get()) != NULL);
	}
	if (node == NULL) {
		return NULL;
	}
	if (node->equals(first.get())) {
		Entry* np = (Entry*) node.get();
		Entry* n = (Entry*) np->getNext().get();
		if (n == NULL) {
			table[index] = NULL;
		} else {
			table[index] = std::make_shared<Entry>(n);
		}
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

int HashMap::getThreshold() {
	return threshold;
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
	Strings str;
	str.append("HashMap[");
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
	str.replace(", , ", ", ");
	str.replace(", ]", "]");
	return str.toString();
}

string HashMap::getClassName() {
	return "HashMap";
}

int HashMap::hash(int keyHashCode) {
	return keyHashCode ^ (keyHashCode >> 16);
}

/*
 int n = cap - 1;
 n |= n >>> 1;
 n |= n >>> 2;
 n |= n >>> 4;
 n |= n >>> 8;
 n |= n >>> 16;
 return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
 */
int HashMap::tableSizeFor(int capacity) {
	int n = capacity - 1;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	if (n < 0) {
		return 1;
	}
	if (n >= maxCapacity) {
		return maxCapacity;
	}
	return n + 1;
}
entry* HashMap::resize() {
	entry* oldTable = table;
	int oldCapacity = capacity;
	int oldThreshold = threshold;

	int newCapacity = 0;
	int newThreshold = 0;
	if (oldCapacity > 0) {
		if (oldCapacity >= maxCapacity) {
			threshold = INT_MAX;
			return oldTable;
		} else if ((newCapacity = oldThreshold << 1) < maxCapacity
				&& oldCapacity >= 16) {
			newThreshold = oldThreshold << 1;
		}
	} else if (oldThreshold > 0) {
		newCapacity = oldThreshold;
	} else {
		newCapacity = 16;
		newThreshold = (int) (16 * 0.75);
	}
	if (newThreshold == 0) {
		float ft = (float) (newCapacity * 0.75);
		bool tmp = newCapacity < maxCapacity && ft < (float) maxCapacity;
		if (tmp) {
			newThreshold = (int) ft;
		} else {
			newThreshold = INT_MAX;
		}
	}
	threshold = newThreshold;
	entry* newTable = new entry[newCapacity];
	table = newTable;

	if (oldTable == NULL) {
		return newTable;
	}
	for (int i = 0; i < oldCapacity; i++) {
		entry e = oldTable[i];
		if (e == NULL) {
			continue;
		}
		oldTable[i] = NULL;
		if (e->getNext() == NULL) {
			int ehash = hash(e->getKey()->hashCode());
			newTable[ehash & (newCapacity - 1)] = e;
		} else {
			Entry* ent = (Entry*) e->getNext().get();
			Entry* loHead = NULL;
			Entry* loTail = NULL;
			Entry* hiHead = NULL;
			Entry* hiTail = NULL;
			Entry* next;
			do {
				next = (Entry*) ent->getNext().get();
				int ehash = hash(ent->getKey()->hashCode());
				if ((ehash & oldCapacity) == 0) {
					if (loTail == NULL) {
						loHead = ent;
					} else {
						entry tmp = std::make_shared<Entry>(ent);
						loTail->setNext(tmp);
					}
					loTail = ent;
				} else {
					if (hiTail == NULL) {
						hiHead = ent;
					} else {
						entry tmp = std::make_shared<Entry>(ent);
						hiTail->setNext(tmp);
					}
					hiTail = ent;
				}

			} while ((ent = next) != NULL);
			if (loTail != NULL) {
				loTail->setNext(NULL);
				entry tmp = std::make_shared<Entry>(loHead);
				newTable[i] = tmp;
			}
			if (hiTail != NULL) {
				hiTail->setNext(NULL);
				entry tmp = std::make_shared<Entry>(hiHead);
				newTable[i + oldCapacity] = tmp;
			}
		}
	}

	return newTable;

}
