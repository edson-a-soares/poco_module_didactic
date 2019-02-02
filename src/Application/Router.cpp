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
	    auto factory = Resource::Factory::AbstractFactory::createResourceFactory(getRouteFactoryName(request.getURI()));
	    return factory->createResource();
    }

	std::string Router::getRouteFactoryName(const std::string & fragment)
	{

		std::string route;
		Poco::URI uri = Poco::URI(fragment);

		if ( routingTable.find(uri.getPath()) != routingTable.end() ) {
			auto routeIndex = routingTable.find(uri.getPath());
			route = routeIndex->second;
		}

		return route;

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
