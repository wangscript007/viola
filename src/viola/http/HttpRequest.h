/*
 * HttpRequest.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_HTTP_HTTPREQUEST_H_
#define SRC_VIOLA_HTTP_HTTPREQUEST_H_

#include <string>
#include "Object.h"

class HttpRequest: public Object {
private:
	std::string url;
	std::string method;
public:
	HttpRequest();
	~HttpRequest();
};

#endif /* SRC_VIOLA_HTTP_HTTPREQUEST_H_ */
