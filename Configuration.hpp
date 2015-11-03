#pragma once

#include <string>
#include <stdexcept>

#include <boost/noncopyable.hpp>

namespace config {

    class ConfigException : public std::runtime_error {
    public:
        ConfigException(const std::string &message)
                : std::runtime_error(message) {
        }
    };

    struct ConfigurationImpl;

    class Configuration : boost::noncopyable {
    public:
        Configuration(const std::string fileName);

        Configuration(const std::vector<std::string> fileNames);

        ~Configuration();

        int getInt(const std::string &property);

        bool getBool(const std::string &property);

        std::string getString(const std::string &property);

    private:
        ConfigurationImpl *impl;
    };
}
