#include "Application/Resource/Application.h"
#include "Application/Configuration/WebCORSConfiguration.h"
#include "Application/Resource/Factory/ApplicationFactory.h"

#include <memory>

namespace Application {
namespace Resource {
namespace Factory {


    Poco::Net::HTTPRequestHandler * ApplicationFactory::createResource()
    {

        auto resource = new Resource::Application();

        auto corsConfiguration = std::make_shared<Configuration::WebCORSConfiguration>();
        resource->setCORSConfiguration(corsConfiguration.get());
        return resource;

    }


} } }
