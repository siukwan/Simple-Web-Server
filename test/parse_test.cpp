<<<<<<< HEAD
#include "server_http.hpp"
#include "client_http.hpp"
=======
#include "server_ws.hpp"
#include "client_ws.hpp"
>>>>>>> upstream/master
#include <iostream>

using namespace std;
using namespace SimpleWeb;

<<<<<<< HEAD
class ServerTest : public ServerBase<HTTP> {
public:
    ServerTest() : 
            ServerBase<HTTP>::ServerBase(8080, 1, 5, 300) {}
=======
class SocketServerTest : public SocketServerBase<WS> {
public:
    SocketServerTest() : 
            SocketServerBase<WS>::SocketServerBase(8080, 1, 5, 300) {}
>>>>>>> upstream/master
            
    void accept() {}
    
    bool parse_request_test() {
<<<<<<< HEAD
        std::shared_ptr<Request> request(new Request(io_service));
=======
        std::shared_ptr<Connection> connection(new Connection(new WS(io_service)));
>>>>>>> upstream/master
        
        stringstream ss;
        ss << "GET /test/ HTTP/1.1\r\n";
        ss << "TestHeader: test\r\n";
        ss << "TestHeader2:test2\r\n";
        ss << "\r\n";
        
<<<<<<< HEAD
        parse_request(request, ss);
        
        if(request->method!="GET")
            return 0;
        if(request->path!="/test/")
            return 0;
        if(request->http_version!="1.1")
            return 0;
        
        if(request->header.size()!=2)
            return 0;
        auto header_it=request->header.find("TestHeader");
        if(header_it==request->header.end() || header_it->second!="test")
            return 0;
        header_it=request->header.find("TestHeader2");
        if(header_it==request->header.end() || header_it->second!="test2")
=======
        parse_handshake(connection, ss);
        
        if(connection->method!="GET")
            return 0;
        if(connection->path!="/test/")
            return 0;
        if(connection->http_version!="1.1")
            return 0;
        
        if(connection->header.size()!=2)
            return 0;
        if(connection->header.count("TestHeader")==0)
            return 0;
        if(connection->header["TestHeader"]!="test")
            return 0;

        if(connection->header.count("TestHeader2")==0)
            return 0;
        if(connection->header["TestHeader2"]!="test2")
>>>>>>> upstream/master
            return 0;
        
        return 1;
    }
};

<<<<<<< HEAD
class ClientTest : public ClientBase<HTTP> {
public:
    ClientTest(const std::string& server_port_path) : ClientBase<HTTP>::ClientBase(server_port_path, 80) {}
=======
class SocketClientTest : public SocketClientBase<WS> {
public:
    SocketClientTest(const std::string& server_port_path) : SocketClientBase<WS>::SocketClientBase(server_port_path, 80) {}
>>>>>>> upstream/master
    
    void connect() {}
    
    bool constructor_parse_test1() {
<<<<<<< HEAD
=======
        if(path!="/test")
            return 0;
>>>>>>> upstream/master
        if(host!="test.org")
            return 0;
        if(port!=8080)
            return 0;
        
        return 1;
    }
    
    bool constructor_parse_test2() {
<<<<<<< HEAD
=======
        if(path!="/test")
            return 0;
>>>>>>> upstream/master
        if(host!="test.org")
            return 0;
        if(port!=80)
            return 0;
        
        return 1;
    }
    
<<<<<<< HEAD
    bool parse_response_header_test() {
        std::shared_ptr<Response> response(new Response());
=======
    bool constructor_parse_test3() {
        if(path!="/")
            return 0;
        if(host!="test.org")
            return 0;
        if(port!=80)
            return 0;
        
        return 1;
    }
    
    bool constructor_parse_test4() {
        if(path!="/")
            return 0;
        if(host!="test.org")
            return 0;
        if(port!=8080)
            return 0;
        
        return 1;
    }
    
    bool parse_response_header_test() {
        connection=std::unique_ptr<Connection>(new Connection(new WS(io_service)));
>>>>>>> upstream/master
        
        stringstream ss;
        ss << "HTTP/1.1 200 OK\r\n";
        ss << "TestHeader: test\r\n";
        ss << "TestHeader2:test2\r\n";
        ss << "\r\n";
        
<<<<<<< HEAD
        parse_response_header(response, ss);
        
        if(response->http_version!="1.1")
            return 0;
        if(response->status_code!="200 OK")
            return 0;
        
        if(response->header.size()!=2)
            return 0;

        auto header_it=response->header.find("TestHeader");
        if(header_it==response->header.end() || header_it->second!="test")
          return 0;
        header_it=response->header.find("TestHeader2");
        if(header_it==response->header.end() || header_it->second!="test2")
          return 0;
        
=======
        parse_handshake(ss);
                
        if(connection->header.size()!=2)
            return 0;
        if(connection->header.count("TestHeader")==0)
            return 0;
        if(connection->header["TestHeader"]!="test")
            return 0;

        if(connection->header.count("TestHeader2")==0)
            return 0;
        if(connection->header["TestHeader2"]!="test2")
            return 0;
        
        connection.reset();
>>>>>>> upstream/master
        return 1;
    }
};

int main(int argc, char** argv) {
<<<<<<< HEAD
    ServerTest serverTest;
    
    if(!serverTest.parse_request_test()) {
        cerr << "FAIL Server::parse_request" << endl;
        return 1;
    }
    
    ClientTest clientTest("test.org:8080");
    if(!clientTest.constructor_parse_test1()) {
        cerr << "FAIL Client::Client" << endl;
        return 1;
    }
    
    ClientTest clientTest2("test.org");
    if(!clientTest2.constructor_parse_test2()) {
        cerr << "FAIL Client::Client" << endl;
        return 1;
    }
    
    if(!clientTest2.parse_response_header_test()) {
        cerr << "FAIL Client::parse_response_header" << endl;
=======
    SocketServerTest serverTest;
    if(!serverTest.parse_request_test()) {
        cerr << "FAIL SocketServer::parse_request" << endl;
        return 1;
    }
    
    SocketClientTest clientTest("test.org:8080/test");
    if(!clientTest.constructor_parse_test1()) {
        cerr << "FAIL SocketClient::SocketClient" << endl;
        return 1;
    }
    
    SocketClientTest clientTest2("test.org/test");
    if(!clientTest2.constructor_parse_test2()) {
        cerr << "FAIL SocketClient::SocketClient" << endl;
        return 1;
    }
    
    SocketClientTest clientTest3("test.org");
    if(!clientTest3.constructor_parse_test3()) {
        cerr << "FAIL SocketClient::SocketClient" << endl;
        return 1;
    }
    
    SocketClientTest clientTest4("test.org:8080");
    if(!clientTest4.constructor_parse_test4()) {
        cerr << "FAIL SocketClient::SocketClient" << endl;
        return 1;
    }
    
    if(!clientTest4.parse_response_header_test()) {
        cerr << "FAIL SocketClient::parse_response_header" << endl;
>>>>>>> upstream/master
        return 1;
    }
    
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> upstream/master
