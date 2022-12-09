#pragma once

#include <string>
using namespace std;

#include <frame/Server.h>
#include <rpc/FunctionHandler.h>

namespace yazi {
namespace rpc {

class Server : public yazi::frame::Server
{
public:
    Server();
    ~Server();

    template <typename F>
    void bind(const string & name, F func)
    {
        m_handler.bind(name, func);
    }

    void call(const string & name, DataStream & in, DataStream & out)
    {
        m_handler.call(name, in, out);
    }

private:
    FunctionHandler m_handler;
};

}}
