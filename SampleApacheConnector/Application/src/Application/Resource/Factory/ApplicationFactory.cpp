#include "Application/Resource/Application.h"
#include "Application/Resource/Factory/ApplicationFactory.h"

namespace Application {
namespace Resource {
namespace Factory {


    Poco::Net::HTTPRequestHandler * ApplicationFactory::createResource()
    {
        return new Resource::Application();
    }


} } }
