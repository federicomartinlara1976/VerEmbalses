#include "graphic.hpp"

#include "verembalsesdebug.h"

using namespace std;

QChart* GraphicContext::getGraphic() const {
    if (strategy_) {
        return strategy_->getGraphic();
    } else {
        QString errorMessage = "Context: Strategy isn't set";
        qCCritical(VEREMBALSES) << errorMessage;
        throw runtime_error(errorMessage.toStdString());
    }
}
