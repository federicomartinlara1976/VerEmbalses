#include "graphic.hpp"

#include <spdlog/spdlog.h>

using namespace std;

QChart* GraphicContext::getGraphic() const {
    if (strategy_) {
        return strategy_->getGraphic();
    } else {
        string errorMessage = string("Context: Strategy isn't set");
        spdlog::error(errorMessage);
        throw runtime_error(errorMessage);
    }
}
