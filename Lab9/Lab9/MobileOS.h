#ifndef MOBILEOS_H
#define MOBILEOS_H

#include <string>
#include <iostream>

class MobileOS {
public:
    struct Info {
        std::string name;
        std::string version;
        int releaseYear;
        double userBaseMillions;
    };

    MobileOS();
    MobileOS(const Info& info);
    virtual ~MobileOS();

    
    virtual void input();   
    virtual void print() const;  

    
    virtual double computeMetric() const;

protected:
    Info info_;
};

#endif 
