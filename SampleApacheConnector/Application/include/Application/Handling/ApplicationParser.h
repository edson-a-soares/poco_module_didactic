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

#ifndef Sample_Apache_Connector_Application_Handling_Application_Parser_INCLUDED
#define Sample_Apache_Connector_Application_Handling_Application_Parser_INCLUDED

#include <string>

namespace Application {
namespace Handling {


    class ApplicationParser
    {
    public:
        ApplicationParser();
        ApplicationParser(const std::string &);

        std::string toJson(const std::string &) const;
        std::string getUrl(const std::string &) const;

    private:
        std::string baseUrl;

    };


} }

#endif