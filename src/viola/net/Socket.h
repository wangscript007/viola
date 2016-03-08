/*
 * Socket.h
 *
 *  Created on: 2016/03/05
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "InputStream.h"
#include "OutputStream.h"

class Socket: public Object {
private:
	std::string host;
	uint32_t port;
	bool closed;
public:
	Socket(std::string host, uint32_t port);
	virtual ~Socket();

	std::shared_ptr<InputStream> getInputStream();
	std::shared_ptr<OutputStream> getOutputStream();

	void close() throw (IOException);
	bool isClosed();
};
