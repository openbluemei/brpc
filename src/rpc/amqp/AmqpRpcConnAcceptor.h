#pragma once
#include "stdafx.h"
#include "RpcServer.h"
#include "RpcSocket.h"
#include "ChannelFactory.h"


namespace brpc{

class AmqpRpcConnection;

class AmqpRpcConnAcceptor : public RpcConnAcceptor
{
public:
	AmqpRpcConnAcceptor(RpcServer* server);
	virtual ~AmqpRpcConnAcceptor(){}
public:
	virtual void run();
	virtual void stop();
	virtual void wait();
protected:
	virtual void waitConnection();
	virtual void addConnection(String id, AMQP::ChannelFactory* factory);
	virtual void removeConnection(String id);
	virtual AmqpRpcConnection* getConnection(String id);
	
	virtual void checkAlive(unsigned int timeout);

private:
	volatile bool running;

private:
	String topic, nodeId;
	String url;
	HashMap<String, AmqpRpcConnection*> connections;
};

}//end of namespace brpc