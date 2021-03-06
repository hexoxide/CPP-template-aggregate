#include "client.h"

Client::Client() {
	zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");
    zmq::message_t request;

    //  Wait for next request from client
    socket.recv(&request);
    std::cout << "Received Hello" << std::endl;

    //  Send reply back to client
    zmq::message_t reply(5);
    memcpy(reply.data (), "World", 5);
    socket.send(reply);
}