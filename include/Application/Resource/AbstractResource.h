/*
 * (C) Copyright 2017 Edson (http://edsonaraujosoares.com) and others.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 *     Edson Araújo Soares
 */

#ifndef Application_Resource_Abstract_Resource_INCLUDED
#define Application_Resource_Abstract_Resource_INCLUDED

#include <memory>

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Application/Configuration/CORSConfigurationInterface.h"

namespace Application {
namespace Resource {


    class AbstractResource : public Poco::Net::HTTPRequestHandler
    {
    public:
        AbstractResource();

        void setCORSConfiguration(std::shared_ptr<Configuration::CORSConfigurationInterface>);
        virtual void handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

    protected:
        void configureCORS(Poco::Net::HTTPServerResponse &);

        virtual void handle_get(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_put(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_post(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
	    virtual void handle_head(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_trace(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_patch(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_delete(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
	    virtual void handle_connect(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
        virtual void handle_options(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

    private:
	    std::shared_ptr<Configuration::CORSConfigurationInterface> corsConfiguration;

    };


} }

#endif
