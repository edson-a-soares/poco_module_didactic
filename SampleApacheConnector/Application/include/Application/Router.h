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

#ifndef Sample_Apache_Connector_Application_Router_INCLUDED
#define Sample_Apache_Connector_Application_Router_INCLUDED

#include <map>
#include <string>

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Application/Resource/Factory/IFactory.h"

namespace Application {


    class Router : public Poco::Net::HTTPRequestHandlerFactory
    {
    public:
        Router();

        void addRoute(const std::string &, const std::string &);
        Poco::Net::HTTPRequestHandler * createRequestHandler (const Poco::Net::HTTPServerRequest & request);

    private:
        void init();
        Poco::Net::HTTPRequestHandler * getResource(const std::string &);

        std::map<std::string, std::string> routingTable;

    };


}

#endif