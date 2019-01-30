#include <fstream>
#include <sstream>

#include "Poco/File.h"
#include "Poco/JSON/Parser.h"
#include "Application/Configuration/JSONFileCORSConfiguration.h"

namespace Application {
namespace Configuration  {


	JSONFileCORSConfiguration::JSONFileCORSConfiguration(const std::string & filePath)
    {

	    try {

		    Poco::File configurationFile = Poco::File(filePath);
		    if ( !configurationFile.isFile() || !configurationFile.exists() )
			    throw Poco::FileNotFoundException("File Not Found", " Configuration file " + filePath + " does not exists.", 500);

		    if ( !configurationFile.canRead() )
			    throw Poco::FileAccessDeniedException("File Not Readable", "Configuration file " + filePath + " is not a readable file.", 500);

		    std::stringstream buffer;
		    std::ifstream fileStream(configurationFile.path().c_str());

		    buffer << fileStream.rdbuf();
		    std::string fileContent = buffer.str();
			setConfigurationProperties(fileContent);

	    } catch (Poco::Exception & exception) {
	    	throw;
	    }

    }

	void JSONFileCORSConfiguration::setConfigurationProperties(const std::string & jsonData)
	{

		Poco::JSON::Parser jsonParser;
		Poco::Dynamic::Var parserResult     = jsonParser.parse(jsonData);
		Poco::JSON::Object::Ptr jsonObject  = parserResult.extract<Poco::JSON::Object::Ptr>();

		auto originsList      = jsonObject->getArray("allow_origins");
		auto originsAllowed   = processNodeList(originsList);
		corsHeaders["Access-Control-Allow-Origin"] = originsAllowed;

		auto httpMethodsList = jsonObject->getArray("allow_http_methods");
		auto methodsAllowed  = processNodeList(httpMethodsList);
		corsHeaders["Access-Control-Request-Method"] = methodsAllowed;

		auto httpHeadersList = jsonObject->getArray("allow_http_headers");
		auto headersAllowed  = processNodeList(httpHeadersList);
		corsHeaders["Access-Control-Request-Headers"] = headersAllowed;

		auto allowCredentials = jsonObject->getValue<std::string>("allow_credentials");
		corsHeaders["Access-Control-Allow-Credentials"] = allowCredentials;

	}

	std::string JSONFileCORSConfiguration::processNodeList(Poco::JSON::Array::Ptr & list)
	{

		std::string nodeList;
		std::size_t originalListSize = list->size() - 1;

		for ( unsigned int counter = 0; counter < originalListSize; counter++ )
			nodeList += list->get(counter).toString() + ", ";

		nodeList += list->get(static_cast<int>(originalListSize)).toString();
		return nodeList;

	}

    std::map<std::string, std::string> JSONFileCORSConfiguration::getCORSHeaders()
    {
        return corsHeaders;
    }


} }
