#ifndef __GRAPHIC_HPP__
#define __GRAPHIC_HPP__

#include <memory>
#include <QtCharts/QChartView>

using namespace std;
using namespace QtCharts;

class Grafico {
protected:
    QChart *graphic;

public:
    QChart* getGraphic() { return graphic; }
};

class GraphicStrategy {
public:
    virtual ~GraphicStrategy() = default;
    virtual QChart* getGraphic() const = 0;
};

class GraphicContext {
private:
    std::unique_ptr<GraphicStrategy> strategy_;

public:
    explicit GraphicContext() {
    }

    explicit GraphicContext(std::unique_ptr<GraphicStrategy> &&strategy = {}) : strategy_(std::move(strategy)) {
    }

    void set_strategy(std::unique_ptr<GraphicStrategy> &&strategy) {
        strategy_ = std::move(strategy);
    }
    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing +multiple versions of the algorithm on its own.
     */
    QChart* getGraphic() const;
};

#endif
