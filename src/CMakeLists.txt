set(verembalses_SRCS
    main.cpp verembalseswindow.cpp verembalsesview.cpp selectfecha.cpp
    selecttipografico.cpp showlinegraphic.cpp
    showpiegraphic.cpp showscattergraphic.cpp showtable.cpp
    funciones_ui.cpp VerEmbalsesAppHelper.cpp tablemodel.cpp
    tablemodelembalse.cpp tablemodelzona.cpp tablemodelembalses.cpp
    tablemodelregistrospluviometricos.cpp
    progreso.cpp qtdialogwindow.cpp window.cpp view.cpp observer.cpp
    configuracion.cpp
    signalmanager.cpp qloadjob.cpp graphic.cpp
    linegraphic.cpp sectorgraphic.cpp scattergraphic.cpp
    stackedbargraphic.cpp
)

ecm_qt_declare_logging_category(verembalses_SRCS
    HEADER verembalsesdebug.h
    IDENTIFIER VEREMBALSES
    CATEGORY_NAME "verembalses"
)
kconfig_add_kcfg_files(verembalses_SRCS VerEmbalsesSettings.kcfgc)
ki18n_wrap_ui(verembalses_SRCS
    settings.ui
)

add_executable(verembalses ${verembalses_SRCS})

target_include_directories (verembalses PRIVATE 
    "/usr/local/include"
    "/usr/local/include/bsoncxx/v_noabi"
    "/usr/local/include/mongocxx/v_noabi" 
    "/usr/local/include/chronoslibs/common"
    "/usr/local/include/chronoslibs/mongo"
    "/usr/local/include/chronoslibs/common"
    "/usr/local/include/chronoslibs/configuration"
    "/usr/local/include/chronoslibs/kdetools")
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
    Qt5::PrintSupport
    spdlog::spdlog
    NumCpp::NumCpp
    DataFrame::DataFrame
    yaml-cpp::yaml-cpp
    fmt::fmt
    "common"
    "mongocxx"
    "bsoncxx"
    "kdetools"
    "mongo"
    "configuration"
)

install(TARGETS verembalses ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS net.bounceme.chronos.verembalses.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES net.bounceme.chronos.verembalses.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
install(FILES verembalsesui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/verembalses)
