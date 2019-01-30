#include "Application/Resource/AbstractResource.h"

namespace Application {
namespace Resource {


    AbstractResource::AbstractResource()
        : corsConfiguration (nullptr)
    {}

    AbstractResource::~AbstractResource()
    {
        delete corsConfiguration;
    }

    void AbstractResource::handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response)
    {

        configureCORS(response);
        response.setContentType("application/json; charset=utf-8");

        if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET )
            this->handle_get(request, response);

        if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST )
            this->handle_post(request, response);

        if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT )
            this->handle_put(request, response);

        if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE )
            this->handle_delete(request, response);

        if ( request.getMethod() == Poco::Net::HTTPRequest::HTTP_OPTIONS )
            this->handle_options(request, response);

    }

    void AbstractResource::setCORSConfiguration(Configuration::CORSConfigurationInterface * configuration)
    {
        corsConfiguration = configuration;
    }

    void AbstractResource::configureCORS(Poco::Net::HTTPServerResponse & response)
    {

        std::map<std::string, std::string> headerSet = corsConfiguration->getCORSHeaders();
        for ( auto & header : headerSet )
            response.set(header.first, header.second);

    }

    void AbstractResource::handle_get(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED);

        std::ostream & outputStream = response.send();
        outputStream.flush();

    }

    void AbstractResource::handle_put(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED);

        std::ostream & outputStream = response.send();
        outputStream.flush();

    }

    void AbstractResource::handle_post(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED);

        std::ostream & outputStream = response.send();
        outputStream.flush();

    }

    void AbstractResource::handle_delete(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED);

        std::ostream & outputStream = response.send();
        outputStream.flush();

    }

    void AbstractResource::handle_options(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse & response)
    {

        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED);

        std::ostream & outputStream = response.send();
        outputStream.flush();

    }


} }
