#include "Application/Resource/Application.h"
#include "Application/Resource/Factory/ApplicationFactory.h"
#include "Application/Configuration/WebCORSConfiguration.h"

namespace Application {
namespace Resource {
namespace Factory {


    Poco::Net::HTTPRequestHandler * ApplicationFactory::createResource()
    {
        auto resource = new Resource::Application();
        resource->setCORSConfiguration(new Configuration::WebCORSConfiguration());
        return resource;
    }


} } }
