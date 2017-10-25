#include "Application/Resource/Factory/Factory.h"
#include "Application/Resource/Factory/ApplicationFactory.h"

namespace Application {
namespace Resource {
namespace Factory {


        IFactory * Factory::createResourceFactory(std::string & index)
        {

            IFactory * factory = nullptr;
            if ( index == "Application::Resource::Factory::ApplicationFactory" ) {
                factory = new ApplicationFactory();
            }

            return factory;
        }


} } }
