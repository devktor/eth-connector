#pragma once 

#ifdef __ABI_ENABLED__

#include <string>

#include "abi/Contract.hpp"
#include "Provider.hpp"
#include "GasEstimator.hpp"

#include "detail/TransactionParamsFactory.hpp"


namespace Ethereum{namespace Connector{


class ContractInvoker
{
    public:
        ContractInvoker(Provider &);

        std::string call(const std::string &, const std::string &);
        std::string execute(const std::string &, const std::string &);

        std::string call(const std::string &, const std::string &, const std::string &);
        std::string execute(const std::string &, const std::string &, const std::string &);

        void setSenderAddress(const std::string &);

    private:
        std::string getDefaultAddress();

    private:
        Provider &_provider;
        std::string _sender;
};


typedef Ethereum::ABI::Result ContractResult;
typedef Ethereum::ABI::Arguments ContractArguments;


class Contract : public Ethereum::ABI::Contract<ContractInvoker>
{
    public:
        typedef Ethereum::ABI::Contract<ContractInvoker> Base;

    public:
        Contract(Provider &, const std::string &address);
        void setSenderAddress(const std::string &address);

        using Base::call;
        using Base::execute;

};


}}

#endif
