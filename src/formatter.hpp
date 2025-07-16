#ifndef __FORMATTER_HPP__
#define __FORMATTER_HPP__

#include "configuracion.hpp"

class Formatter {
private:
    string _numberFormat;
    
public:
    Formatter();
    
    string numberFormat() {  return _numberFormat; }
    string formatNumber(double& number) const;
    string formatNumber(float& number) const;
};

#endif
