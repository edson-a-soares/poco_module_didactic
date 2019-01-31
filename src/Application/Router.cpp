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
        return getResource(request.getURI());
    }

    Poco::Net::HTTPRequestHandler * Router::getResource(const std::string & route)
    {

        Poco::URI uri        = Poco::URI(route);
        auto routeIndex      = routingTable.find(uri.getPath());

        auto resourceFactory = Resource::Factory::AbstractFactory::createResourceFactory(routeIndex->second);
        return resourceFactory->createResource();

    }

    void Router::addRoute(const std::string & route, const std::string & factory)
    {
        routingTable[route] = factory;
    }


}

// add support to Poco ApacheConnector
POCO_BEGIN_MANIFEST(Poco::Net::HTTPRequestHandlerFactory)
    POCO_EXPORT_CLASS(Application::Router)
POCO_END_MANIFEST
