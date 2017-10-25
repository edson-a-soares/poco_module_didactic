#include "Application/Container.h"
#include "Application/Router.h"

int main (int argc, char * argv[]) {

    Application::Container container;

    container.setPort(9000);
    container.setRouter(new Application::Router());
    return container.run(argc, argv);

}
