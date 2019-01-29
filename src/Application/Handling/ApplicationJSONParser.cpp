#include "Poco/JSON/Object.h"
#include "Application/Handling/ApplicationJSONParser.h"

namespace Application {
namespace Handling {


    ApplicationJSONParser::ApplicationJSONParser()
        : baseUrl("localhost:8080")
    {}

    ApplicationJSONParser::ApplicationJSONParser(const std::string & url)
        : baseUrl(url)
    {}

    std::string ApplicationJSONParser::getUrl(const std::string & path) const
    {
        return "http://" + baseUrl + path;
    }

    std::string ApplicationJSONParser::toJson(const std::string & version) const
    {

        Poco::JSON::Object::Ptr root  = new Poco::JSON::Object();

        Poco::JSON::Object::Ptr links = new Poco::JSON::Object();
        links->set("self", getUrl("/"));

        root->set("links", links);

        Poco::JSON::Object::Ptr meta = new Poco::JSON::Object();
        meta->set("version", version);

        Poco::JSON::Array::Ptr lang  = new Poco::JSON::Array();

        lang->set(0, "en-US");

        meta->set("lang", lang);
        root->set("meta", meta);

        std::stringstream stream;
        root->stringify(stream);
        return stream.str();

    }


} }
