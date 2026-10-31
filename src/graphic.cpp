#include "graphic.hpp"

#include "verembalsesdebug.h"

#include <KLocalizedString>

using namespace std;

QChart* GraphicContext::getGraphic() const {
    if (strategy_) {
        return strategy_->getGraphic();
    } else {
        QString errorMessage = i18n("Context: Strategy isn't set");
        qCCritical(VEREMBALSES) << errorMessage;
        throw runtime_error(errorMessage.toStdString());
    }
}
