/*
 * HttpResponse.h
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#pragma once
#include <string>
#include "Object.h"
#include "Strings.h"

class HttpResponse: public Object {
private:
	int status;
	std::string message;
public:
	HttpResponse();
	HttpResponse(uint32_t status, std::string message);
	~HttpResponse();

	void setStatusCode(uint32_t status);
	uint32_t getStatusCode();

	void setMessage(std::string message);
	std::string getMessage();

	//Override
	std::string getClassName();
	std::string toString();
};
