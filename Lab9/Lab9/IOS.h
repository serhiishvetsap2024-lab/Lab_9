#ifndef IOS_H
#define IOS_H

#include "MobileOS.h"
#include <string>

class IOS : public MobileOS {
public:
    struct IOSSpecific {
        bool isEnterpriseSigned;
        std::string deviceFamily; 
    };

    IOS();
    virtual ~IOS();

    void input() override;
    void print() const override;
    double computeMetric() const override;

private:
    IOSSpecific ios_;
};

#endif 
