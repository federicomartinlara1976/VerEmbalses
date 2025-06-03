#ifndef _VER_EMBALSES_APP_HELPER_HPP_
#define _VER_EMBALSES_APP_HELPER_HPP_

#include <iostream>
#include <tuple>

#include <QComboBox>
#include <QLabel>
#include <DataFrame/DataFrame.h>

#include <qttools/qthelper.hpp>

using namespace std;
using namespace hmdf;

class VerEmbalsesAppHelper {
private:
    QtHelper qtHelper;
    
public:
    tuple<String64, std::size_t, std::type_index> getColumn(const StdDataFrame<ulong>& dataframe, int index) const;
    
    void setLabelStyleValue(QLabel *lbl, float value);
};

#endif
