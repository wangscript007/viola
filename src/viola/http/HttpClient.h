/*
 * HttpClient.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_HTTP_HTTPCLIENT_H_
#define SRC_VIOLA_HTTP_HTTPCLIENT_H_

#include <string>
#include "Object.h"
#include "HttpRequest.h"
#include "HttpProxy.h"
#include "HttpResponse.h"

class HttpClient: public Object {
private:
	std::shared_ptr<HttpProxy> proxy;
public:
	HttpClient();
	~HttpClient();

	void setProxy(std::shared_ptr<HttpProxy> proxy);
	std::shared_ptr<HttpProxy> getProxy();

	std::shared_ptr<HttpResponse> execute(std::shared_ptr<HttpRequest> request);

	//Override
	std::string getClassName();
};

#endif /* SRC_VIOLA_HTTP_HTTPCLIENT_H_ */
