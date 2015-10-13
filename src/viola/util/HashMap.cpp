/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "HashMap.h"

//#include "Strings.h"
//typedef std::shared_ptr<Strings> strings;

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
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
	entry entry = table[index];
	if (entry == NULL) {
		return false;
	}
	return true;

}

object HashMap::put(object key, object value) {
	int h = hash(key->hashCode());
	int index = (capacity - 1) & h;
//	printf("index:<%d>\n", index);
	entry p = table[index];
	if (p == NULL) {
		table[index] = std::make_shared<Entry>(key, value);
		return NULL;
	} else {
		//	printf("not null. index:<%d>\n", index);
		Entry* e = NULL;
		object k = p.get()->getKey();
		int phash = hash(k->hashCode());
		if (phash == h && key->equals(k.get())) {
			e = p.get();
			//		printf("find at first. index:<%d>\n", index);
		} else {
			Entry* pp = p.get();
			for (int binCount = 0;; binCount++) {
				if (pp->getNext() == NULL) {
//					printf("next is null. index:<%d>\n", index);
					entry ent = std::make_shared<Entry>(key, value);
					pp->setNext(ent.get());
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
			//	printf("updated. :<%d>\n", index);
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
	entry entry = table[(capacity - 1) & h];
	if (entry != NULL) {
		return entry->getValue();
	}
	return NULL;

}
object HashMap::remove(object key) {
	int h = hash(key->hashCode());
	entry entry = table[(capacity - 1) & h];
	if (entry == NULL) {
		return NULL;
	}
	table[(capacity - 1) & h] = NULL;
	return entry->getValue();

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
		if (table[i] != NULL) {
			size++;
		}
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
	/*
	 for (int i = 0; i < capacity; i++) {
	 std::vector<entry>::iterator it = table[i].begin();
	 for (int i = 0; i < size(); i++) {
	 entry entry = *it;
	 Entry* entryp = entry.get();
	 int tmp = 0;
	 if (entryp != NULL) {
	 tmp = entryp->hashCode();
	 }
	 hashCode = 31 * hashCode + tmp;
	 i++;
	 }
	 }
	 */
	return hashCode;
}

bool HashMap::equals(Object* obj) {
	HashMap* map = (HashMap*) obj;
	if (hashCode() == map->hashCode()) {
		return true;
	}
	return false;
}

string HashMap::getClassName() {
	return "HashMap";
}

int HashMap::hash(int keyHashCode) {
	return keyHashCode ^ (keyHashCode >> 16);
}
