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
	table = new std::shared_ptr<Entry>[threshold];
}

HashMap::HashMap(uint32_t capacity) {
	this->capacity = capacity;
	threshold = tableSizeFor(capacity);
	table = new std::shared_ptr<Entry>[threshold];
}

HashMap::~HashMap() {
	this->clear();
	delete[] table;
}

bool HashMap::containsKey(std::shared_ptr<Object> key) {
	std::shared_ptr<Object> val = this->get(key);
	if (val == NULL) {
		return false;
	}
	return true;
}

std::shared_ptr<Object> HashMap::put(std::string key, std::string value) {
	std::shared_ptr<Object> skey = std::make_shared<Strings>(key);
	std::shared_ptr<Object> sval = std::make_shared<Strings>(value);
	return put(skey, sval);
}

std::shared_ptr<Object> HashMap::put(std::shared_ptr<Object> key,
		std::shared_ptr<Object> value) {
	uint32_t h = hash(key->hashCode());
	uint32_t index = (capacity - 1) & h;
	std::shared_ptr<Object> p = table[index];
	if (p == NULL) {
		table[index] = std::make_shared<Entry>(key, value);
		return NULL;
	} else {
		std::shared_ptr<Object> e = NULL;
		std::shared_ptr<Object> k = ((Entry*) p.get())->getKey();
		uint32_t phash = hash(k->hashCode());
		if (phash == h && key->equals(k.get())) {
			e = p;
		} else {
			for (int binCount = 0;; ++binCount) {
				std::shared_ptr<Object> e = ((Entry*) p.get())->getNext();
				if (e == NULL) {
					std::shared_ptr<Entry> ent = std::make_shared<Entry>(key,
							value);
					((Entry*) p.get())->setNext(ent);
					break;
				}
				Entry* ep = (Entry*) e.get();
				uint32_t ehash = hash(ep->getKey()->hashCode());
				if (ehash == h && key->equals(ep->getKey().get())) {
					break;
				}
				p = e;
			}
		}
		if (e != NULL) {
			Entry* ep = (Entry*) e.get();
			std::shared_ptr<Object> oldValue = ep->getValue();
			ep->setValue(value);
			return oldValue;
		}
	}

	if (size() > threshold) {
		resize();
	}
	return NULL;

}

std::shared_ptr<Object> HashMap::putIfAbsent(std::shared_ptr<Object> key,
		std::shared_ptr<Object> value) {
	if (this->containsKey(key)) {
		return this->get(key);
	}
	put(key, value);
	return NULL;
}
std::shared_ptr<Object> HashMap::get(std::string key) {
	std::shared_ptr<Object> skey = std::make_shared<Strings>(key);
	return get(skey);
}

std::shared_ptr<Object> HashMap::get(std::shared_ptr<Object> key) {
	uint32_t h = hash(key->hashCode());
	uint32_t index = (capacity - 1) & h;
	std::shared_ptr<Object> first = table[index];
	if (first == NULL) {
		return NULL;
	}
	Entry* ep = (Entry*) first.get();
	uint32_t fHash = hash(ep->getKey()->hashCode());
	if (fHash == h && key->equals(ep->getKey().get())) {
		return ep->getValue();
	}
	std::shared_ptr<Object> e = ep->getNext();
	if (e == NULL) {
		return NULL;
	}
	do {
		Entry* ep = (Entry*) e.get();
		uint32_t eHash = hash(ep->getKey()->hashCode());
		if (eHash == h && key->equals(ep->getKey().get())) {
			return ep->getValue();
		}
	} while ((e = ep->getNext()) != NULL);

	return NULL;
}

std::shared_ptr<Object> HashMap::remove(std::shared_ptr<Object> key) {
	uint32_t h = hash(key->hashCode());
	uint32_t index = (capacity - 1) & h;
	std::shared_ptr<Object> first = table[index];
	if (first == NULL) {
		return NULL;
	}

	std::shared_ptr<Object> node = NULL;
	std::shared_ptr<Object> e = NULL;
	Entry* fp = (Entry*) first.get();
	uint32_t fHash = hash(fp->getKey()->hashCode());
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

uint32_t HashMap::getThreshold() {
	return threshold;
}

uint32_t HashMap::getCapacity() {
	return capacity;
}

uint32_t HashMap::size() {
	uint32_t size = 0;
	for (uint32_t i = 0; i < capacity; i++) {
		std::shared_ptr<Entry> e = table[i];
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

uint32_t HashMap::hashCode() {
	uint32_t hashCode = 1;
	for (uint32_t i = 0; i < capacity; i++) {
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

std::string HashMap::toString(std::shared_ptr<Entry>* e, uint32_t capa) {
	Strings str;
	str.append("{");
	for (uint32_t i = 0; i < capa; i++) {
		std::shared_ptr<Entry> n = e[i];

		if (n == NULL) {
			continue;
		}
		Entry* p = n.get();
		do {
			str.append(p->toString());
			str.append(", ");
		} while ((p = ((Entry*) p->getNext().get())) != NULL);

		if (i < size() - 1) {
			str.append(", ");
		}
	}
	str.append("}");
	str.replace(", , ", ", ");
	str.replace(", }", "}");
	return str.toString();
}

std::string HashMap::toString() {
	Strings str;
	str.append("{");
	for (uint32_t i = 0; i < capacity; i++) {
		std::shared_ptr<Entry> e = table[i];

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
	str.append("}");
	str.replace(", , ", ", ");
	str.replace(", }", "}");
	return str.toString();
}

std::string HashMap::getClassName() {
	return "HashMap";
}

uint32_t HashMap::hash(uint32_t keyHashCode) {
	return keyHashCode ^ (keyHashCode >> 16);
}

/*
 uint32_t n = cap - 1;
 n |= n >>> 1;
 n |= n >>> 2;
 n |= n >>> 4;
 n |= n >>> 8;
 n |= n >>> 16;
 return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
 */
uint32_t HashMap::tableSizeFor(uint32_t capacity) {
	uint32_t n = capacity - 1;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;

	//always false
//	if (n < 0) {
//		return 1;
//	}
	if (n >= maxCapacity) {
		return maxCapacity;
	}
	return n + 1;
}

std::shared_ptr<Entry>* HashMap::resize() {
	std::shared_ptr<Entry> * oldTable = table;
	uint32_t oldCapacity = capacity;
	uint32_t oldThreshold = threshold;

	uint32_t newCapacity = 0;
	uint32_t newThreshold = 0;
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
	capacity = newCapacity;
	std::shared_ptr<Entry>* newTable = new std::shared_ptr<Entry>[newCapacity];
	table = newTable;

	if (oldTable == NULL) {
		return newTable;
	}
	for (uint32_t i = 0; i < oldCapacity; i++) {
		std::shared_ptr<Entry> e = oldTable[i];
		if (e == NULL) {
			continue;
		}
		oldTable[i] = NULL;
		if (e->getNext() == NULL) {
			uint32_t ehash = hash(e->getKey()->hashCode());
			newTable[ehash & (newCapacity - 1)] = e;
		} else {
			Entry* ent = (Entry*) e.get();
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
						std::shared_ptr<Entry> tmp = std::make_shared<Entry>(
								ent);
						loTail->setNext(tmp);
					}
					loTail = ent;
				} else {
					if (hiTail == NULL) {
						hiHead = ent;
					} else {
						std::shared_ptr<Entry> tmp = std::make_shared<Entry>(
								ent);
						hiTail->setNext(tmp);
					}
					hiTail = ent;
				}

			} while ((ent = next) != NULL);
			if (loTail != NULL) {
				loTail->setNext(NULL);
				std::shared_ptr<Entry> tmp = std::make_shared<Entry>(loHead);
				newTable[i] = tmp;
			}
			if (hiTail != NULL) {
				hiTail->setNext(NULL);
				std::shared_ptr<Entry> tmp = std::make_shared<Entry>(hiHead);
				newTable[i + oldCapacity] = tmp;
			}
		}
	}

	delete[] oldTable;
	return newTable;

}
