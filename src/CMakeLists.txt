add_executable(verembalses)

target_sources(verembalses PRIVATE
    main.cpp
    verembalses.cpp
    selectfecha.cpp
    selectmes.cpp
    showlinegraphic.cpp
    showpiegraphic.cpp
    showtable.cpp
    funciones_ui.cpp
    VerEmbalsesAppHelper.cpp
    tablemodel.cpp
    tablemodelembalse.cpp
    tablemodelzona.cpp
    tablemodelembalses.cpp
    progreso.cpp
    qtdialogwindow.cpp
    qtwindow.cpp
    signalmanager.cpp
    qloadjob.cpp
    graphic.cpp
    linegraphic.cpp
    sectorgraphic.cpp
)

ecm_qt_declare_logging_category(verembalses
    HEADER verembalsesdebug.h
    IDENTIFIER VEREMBALSES
    CATEGORY_NAME "verembalses"
)

target_include_directories (verembalses PRIVATE 
    "/usr/local/include"
    "/usr/local/include/bsoncxx/v_noabi"
    "/usr/local/include/mongocxx/v_noabi" 
    "/usr/local/include/chronoslibs"
    "/usr/local/include/chronoslibs/data/nosql")
target_compile_options(verembalses PRIVATE -fexceptions -Woverloaded-virtual)

target_link_directories(verembalses PRIVATE "/usr/local/lib/chronoslibs")

target_link_libraries(verembalses
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
    KF5::DBusAddons
    KF5::Crash
    KF5::Plotting
    KF5::ThreadWeaver
    Qt5::Widgets
    Qt5::Charts
    spdlog::spdlog
    NumCpp::NumCpp
    DataFrame::DataFrame
    yaml-cpp::yaml-cpp
    "fmt"
    "common"
    "mongocxx"
    "bsoncxx"
    "qttools"
    "mongo"
)

install(TARGETS verembalses ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS net.bounceme.chronos.verembalses.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES net.bounceme.chronos.verembalses.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
