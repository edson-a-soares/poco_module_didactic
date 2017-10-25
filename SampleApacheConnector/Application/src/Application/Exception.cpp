#include "Application/Exception.h"

namespace Application {


    Exception::Exception()
        : type(""),
          number("0"),
          message("")
    { }

    Exception::Exception(const std::string & _type, const std::string & _number, const std::string & _message)
        : type(_type),
          number(_number),
          message(_message)
    { }

    std::string Exception::getType() const
    {
        return type;
    }

    std::string Exception::getNumber() const
    {
        return number;
    }

    std::string Exception::getMessage() const
    {
        return message;
    }


}
