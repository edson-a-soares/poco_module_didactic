#include "Poco/URI.h"
#include "Poco/ClassLibrary.h"
#include "Application/Router.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Application/Resource/Factory/AbstractFactory.h"

namespace Application {


    Router::Router()
    {
        addRoute("/", "Application::Resource::Application");
    }

    Poco::Net::HTTPRequestHandler * Router::createRequestHandler(const Poco::Net::HTTPServerRequest & request)
    {
        auto factory = Resource::Factory::AbstractFactory::createResourceFactory(getRouteFactoryKey(request.getURI()));
        return factory->createResource();
    }

    std::string Router::getRouteFactoryKey(const std::string & fragment)
    {

    	std::string routeFactoryKey;
        Poco::URI uri = Poco::URI(fragment);

        if ( routingTable.find(uri.getPath()) == routingTable.end() )
            return routeFactoryKey;

        auto routingTableRegister = routingTable.find(uri.getPath());
        routeFactoryKey = routingTableRegister->second;
        return routeFactoryKey;

    }

    void Router::addRoute(const std::string & fragment, const std::string & factory)
    {
        routingTable[fragment] = factory;
    }


}

// add support to Poco ApacheConnector
POCO_BEGIN_MANIFEST(Poco::Net::HTTPRequestHandlerFactory)
    POCO_EXPORT_CLASS(Application::Router)
POCO_END_MANIFEST
