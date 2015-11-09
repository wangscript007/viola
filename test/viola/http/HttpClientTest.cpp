/*
 * HttpClientTest.cpp
 *
 *  Created on: 2015/11/09
 *      Author: tsubaki
 */

#include "viola.h"

int main() {

	HttpClient client;

	_HttpRequest request = std::make_shared<HttpRequest>();
	_HttpResponse response = client.execute(request);

	return 0;
}
