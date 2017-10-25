#include "Application/Exception.h"
#include "Application/Resource/Application.h"
#include "Application/Handling/ErrorParser.h"
#include "Application/Handling/ApplicationParser.h"

namespace Application {
namespace Resource {


        Application::Application()
        { }

        void Application::handleRequest(Poco::Net::HTTPServerRequest & request,
                                        Poco::Net::HTTPServerResponse & response) {

            if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET ) {
                this->handle_get(request, response);
            }

        }

        void Application::handle_get(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response)
        {

            std::ostream & outputStream = response.send();
            response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
            Handling::ApplicationParser parser = Handling::ApplicationParser(request.getHost());

            outputStream << parser.toJson("1.0");
            outputStream.flush();

        }


} }
