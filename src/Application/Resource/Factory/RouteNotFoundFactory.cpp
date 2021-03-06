#include "Application/Resource/RouteNotFound.h"
#include "Application/Configuration/WebCORSConfiguration.h"
#include "Application/Resource/Factory/RouteNotFoundFactory.h"

#include <memory>

namespace Application {
namespace Resource {
namespace Factory {


    Poco::Net::HTTPRequestHandler * RouteNotFoundFactory::createResource()
    {

        auto resource = new Resource::RouteNotFound();

        auto corsConfiguration = std::make_shared<Configuration::WebCORSConfiguration>();
        resource->setCORSConfiguration(corsConfiguration);

        return resource;

    }


} } }
