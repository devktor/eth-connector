#pragma once

#include <json/value.h>
#include <stdint.h>
#include <cstdlib>

namespace Eth{


class FilterLog
{
    public:

        FilterLog(const Json::Value &data);
        std::string getType() const;
        uint64_t getTransactionIndex() const;
        std::string getTransactionHash() const;
        std::string getAddress() const;
        std::string getBlockHash() const;
        uint64_t getBlockIndex() const;

    private:
        Json::Value _data;
};



}
