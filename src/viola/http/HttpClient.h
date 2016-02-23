/*
 * HttpClient.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#pragma once
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
