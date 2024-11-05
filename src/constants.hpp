#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include <iostream>

namespace Constants {
    using namespace std;
    
    static constexpr const string APP_NAME = "verembalses";
    
    static constexpr const string DATE_FORMAT = "yyyy-MM-dd";
    static constexpr const string NUMBER_FORMAT = "{:.3f}";
    static constexpr const string PERCENT_FORMAT = "{:.2f}";
    static constexpr const string CSV_FIELD_SEPARATOR = ",";
    static constexpr const char* CSV_FILE_TYPE = "Hojas de cálculo (*.csv)";
    
    static constexpr const string RED = "#ffb3b3";
    static constexpr const string GREEN = "#bfff80";
    static constexpr const string YELLOW = "#ffff80";

    enum TableType {
        EMBALSE,
        ZONA,
        EMBALSES
    };
}

#endif
