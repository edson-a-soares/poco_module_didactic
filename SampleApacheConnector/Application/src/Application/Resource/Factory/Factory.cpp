#include "Application/Resource/Factory/Factory.h"
#include "Application/Resource/Factory/ApplicationFactory.h"
#include "Application/Resource/Factory/RouteNotFoundFactory.h"

namespace Application {
namespace Resource {
namespace Factory {


        IFactory * Factory::createResourceFactory(const std::string & index)
        {

            IFactory * factory = nullptr;
            if ( index == "Application::Resource::Factory::ApplicationFactory" ) {
                factory = new ApplicationFactory();
            }

            if ( index == "Application::Resource::Factory::RouteNotFoundFactory" ) {
                factory = new RouteNotFoundFactory();
            }

            return factory;

        }


} } }
