#include "Application/Resource/RouteNotFound.h"
#include "Application/Resource/Factory/RouteNotFoundFactory.h"
#include "Application/Configuration/WebCORSConfiguration.h"

namespace Application {
namespace Resource {
namespace Factory {


    Poco::Net::HTTPRequestHandler * RouteNotFoundFactory::createResource()
    {
        auto resource = new Application::Resource::RouteNotFound();
        resource->setCORSConfiguration(new Configuration::WebCORSConfiguration());
        return resource;
    }


} } }
