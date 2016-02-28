/*
 * HttpResponse.cpp
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#include "HttpResponse.h"

HttpResponse::HttpResponse() {
	status = -1;
}

HttpResponse::HttpResponse(uint32_t status, std::string message) {
	this->status = status;
	this->message = message;
}

HttpResponse::~HttpResponse() {
	// TODO Auto-generated destructor stub
}

void HttpResponse::setStatusCode(uint32_t status) {
	this->status = status;
}

uint32_t HttpResponse::getStatusCode() {
	return status;
}

void HttpResponse::setMessage(std::string message) {
	this->message = message;
}

std::string HttpResponse::getMessage() {
	return message;
}

//Override
std::string HttpResponse::getClassName() {
	return "HttpResponse";
}

//Override
std::string HttpResponse::toString() {
	return "status: " + Strings::valueOf(status) + ", message: " + message;
}
