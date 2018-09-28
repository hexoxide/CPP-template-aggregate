#include <iostream>
#include <zmq.hpp>

int main(int argc, const char* argv[]) {
	zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");
    zmq::message_t request;

    //  Wait for next request from client
    socket.recv(&request);
    std::cout << "Received Hello" << std::endl;
}
