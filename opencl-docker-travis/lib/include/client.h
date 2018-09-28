#ifndef CLIENT_H_
#define CLIENT_H_

#include <zmq.hpp>
#include <iostream>
#include <string>

class Client {
	public:
		Client();
		void receive();
	private:
		// zmq::context_t context;
		// zmq::socket_t socket;
};

#endif //  CLIENT_H_