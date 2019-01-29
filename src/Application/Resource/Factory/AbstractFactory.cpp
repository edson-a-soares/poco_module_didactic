#include "Application/Resource/Factory/AbstractFactory.h"
#include "Application/Resource/Factory/ApplicationFactory.h"
#include "Application/Resource/Factory/RouteNotFoundFactory.h"

namespace Application {
namespace Resource {
namespace Factory {


    FactoryInterface * AbstractFactory::createResourceFactory(const std::string & resourceName)
    {

        FactoryInterface * factory = nullptr;
        if ( resourceName == "Application::Resource::AbstractFactory::ApplicationFactory" )
            factory = new ApplicationFactory();

        if ( factory == nullptr )
            factory = new RouteNotFoundFactory();

        return factory;

    }


} } }
