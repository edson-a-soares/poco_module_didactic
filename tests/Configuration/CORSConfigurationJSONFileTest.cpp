#include <memory>
#include <gtest/gtest.h>

#include "Poco/Path.h"
#include "Poco/Exception.h"
#include "Application/Configuration/JSONFileCORSConfiguration.h"

class CORSConfigurationJSONFileTest : public ::testing::Test
{
protected:

    void SetUp() override
    {

	    dependenciesPath.append("data/settings/cors.json");
        corsConfiguration = std::make_shared<Application::Configuration::JSONFileCORSConfiguration>(dependenciesPath);

    }

	std::string dependenciesPath = TESTS_RESOURCES_PATH;
    std::shared_ptr<Application::Configuration::CORSConfigurationInterface> corsConfiguration = nullptr;

};

TEST_F(CORSConfigurationJSONFileTest, FileNotFoundException) {

	ASSERT_THROW(
		Application::Configuration::JSONFileCORSConfiguration("/incorrect/path/file.json"),
		Poco::FileNotFoundException
	);

}

TEST_F(CORSConfigurationJSONFileTest, ReturnAllowedCredentials) {

    ASSERT_FALSE(corsConfiguration->getCORSHeaders().at("Access-Control-Allow-Credentials").empty());

}

TEST_F(CORSConfigurationJSONFileTest, ReturnAllowedOrigins) {

    ASSERT_EQ(
        "localhost:8080, 127.0.0.1:8080",
        corsConfiguration->getCORSHeaders().at("Access-Control-Allow-Origin")
    );

}

TEST_F(CORSConfigurationJSONFileTest, ReturnAllowedHttpMethods) {

    ASSERT_EQ(
        "GET, PUT, PATH, POST, DELETE, OPTIONS",
        corsConfiguration->getCORSHeaders().at("Access-Control-Request-Method")
    );

}

TEST_F(CORSConfigurationJSONFileTest, ReturnAllowedHttpHeaders) {

    ASSERT_EQ(
        "Accept, Content-Type, Accept-Language",
        corsConfiguration->getCORSHeaders().at("Access-Control-Request-Headers")
    );

}
