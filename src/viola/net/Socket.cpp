/*
 * Socket.cpp
 *
 *  Created on: 2016/03/05
 *      Author: tsubaki
 */

#include "Socket.h"

Socket::Socket(std::string host, uint32_t port) {
	this->host = host;
	this->port = port;
	closed = false;
}

Socket::~Socket() {

}

void Socket::close() throw (IOException) {
	closed = true;
}

bool Socket::isClosed() {
	return closed;
}
