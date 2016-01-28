/*
 * HttpProxy.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_HTTP_HTTPPROXY_H_
#define SRC_VIOLA_HTTP_HTTPPROXY_H_

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

#endif /* SRC_VIOLA_HTTP_HTTPPROXY_H_ */
