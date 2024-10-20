#include "VerEmbalsesAppHelper.hpp"
#include "constants.hpp"

#include <spdlog/spdlog.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;
using namespace hmdf;

tuple<String64, std::size_t, std::type_index> VerEmbalsesAppHelper::getColumn(const StdDataFrame<string>& dataframe, int index) const {
    auto columnsInfo = dataframe.get_columns_info<int, double, std::string>();
    
    int i = 0;
    for (auto citer: columnsInfo)  {
        if (i == index) {
            return citer;
        }
        
        i++;
    }
    
    String64 str = "Not found";
    return make_tuple(str, 0, std::type_index(typeid(int)));
}

void VerEmbalsesAppHelper::setLabelStyleValue(QLabel *lbl, float value) {
    string color = {};
    if (value < 30.0) {
        color = Constants::RED;
    }
    else if(value >= 30.0 && value <= 65.0) {
        color = Constants::YELLOW;
    }
    else {
        color = Constants::GREEN;
    }
    
    string style = "QLabel { background-color : " + color + "; border: 1px solid black; }";
    lbl->setStyleSheet(asQString(style, false));
}
