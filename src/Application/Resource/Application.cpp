#include "Application/Resource/Application.h"
#include "Application/Handling/ApplicationJSONParser.h"

namespace Application {
namespace Resource {


    Application::Application()
        : AbstractResource()
    {}

    void Application::handle_get(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response)
    {

        std::ostream & outputStream = response.send();
        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);

        Handling::ApplicationJSONParser parser = Handling::ApplicationJSONParser(request.getHost());
        outputStream << parser.toJson("1.0");
        outputStream.flush();

    }


} }
