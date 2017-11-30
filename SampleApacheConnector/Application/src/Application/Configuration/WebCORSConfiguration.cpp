#include "Application/Configuration/WebCORSConfiguration.h"

namespace Application {
namespace Configuration {


    WebCORSConfiguration::WebCORSConfiguration()
    { }

    std::map<std::string, std::string> WebCORSConfiguration::getCORSHeaders()
    {
        std::map<std::string, std::string> corsHeaders;

        corsHeaders["Access-Control-Allow-Origin"]      = "*";
        corsHeaders["Access-Control-Max-Age"]           = "86400";
        corsHeaders["Access-Control-Request-Method"]    = "POST, GET, PUT, DELETE, OPTIONS";
        corsHeaders["Access-Control-Request-Headers"]   = "Accept, Content-Type, Content-Language, Authorization, X-Authorization";

        return corsHeaders;
    }


} }
