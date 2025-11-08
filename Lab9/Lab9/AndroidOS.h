#ifndef ANDROIDOS_H
#define ANDROIDOS_H

#include "MobileOS.h"
#include <string>

class AndroidOS : public MobileOS {
public:
    struct AndroidSpecific {
        std::string vendor; 
        int majorAPILevel;
    };

    AndroidOS();
    virtual ~AndroidOS();

    void input() override;
    void print() const override;
    double computeMetric() const override;

private:
    AndroidSpecific android_;
};

#endif 
