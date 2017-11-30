#include "Poco/URI.h"
#include "Poco/ClassLibrary.h"
#include "Application/Router.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Application/Resource/RouteNotFound.h"
#include "Application/Resource/Factory/Factory.h"
#include "Application/Configuration/WebCORSConfiguration.h"

#include <iostream>

namespace Application
{

    Router::Router()
    {
        init();
    }

    void Router::init()
    {
        addRoute("/", "Application::Resource::Factory::ApplicationFactory");
    }

    Poco::Net::HTTPRequestHandler * Router::createRequestHandler(const Poco::Net::HTTPServerRequest & request)
    {
        return getResource(request.getURI());
    }

    Poco::Net::HTTPRequestHandler * Router::getResource(const std::string & route)
    {

        Poco::URI uri = Poco::URI(route);
        auto factoryIndex = routingTable.find(uri.getPath());
        Application::Resource::Factory::IFactory * factory =
            Application::Resource::Factory::Factory::createResourceFactory(
                "Application::Resource::Factory::RouteNotFoundFactory"
            );

        if ( factoryIndex != routingTable.end() ) {
            delete factory;
            factory = Application::Resource::Factory::Factory::createResourceFactory(factoryIndex->second);
        }

        return factory->createResource();

    }

    void Router::addRoute(const std::string & route, const std::string & factory)
    {
        routingTable[route] = factory;
    }

}

POCO_BEGIN_MANIFEST(Poco::Net::HTTPRequestHandlerFactory)
    POCO_EXPORT_CLASS(Application::Router)
POCO_END_MANIFEST
