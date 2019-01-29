#include "Application/Resource/RouteNotFound.h"
#include "Application/Handling/ErrorJSONParser.h"

namespace Application {
namespace Resource {

    RouteNotFound::RouteNotFound()
        : AbstractResource()
    {}

    void RouteNotFound::handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND);

        configureCORS(response);
        response.setContentType("application/json; charset=utf-8");
        Handling::ErrorJSONParser error = Handling::ErrorJSONParser(request.getHost());

        std::ostream & outputStream = response.send();
        outputStream << error.toJson("404", request.getURI(),
            Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND, "This route does not exist.");

        outputStream.flush();

    }


} }
