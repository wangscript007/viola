/*
 * HttpProxy.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class HttpProxy: public Object {
private:
	std::string host;
	int port;
public:
	HttpProxy();
	~HttpProxy();

	void setHost(std::string host);
	std::string getHost();

	void setPort(int port);
	int getPort();
};

