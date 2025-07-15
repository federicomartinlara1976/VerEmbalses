set(SOURCE_DIR
    ${CMAKE_SOURCE_DIR}/src
)

set(verembalses_SRCS
    ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/verembalseswindow.cpp ${SOURCE_DIR}/verembalsesview.cpp ${SOURCE_DIR}/selectfecha.cpp
    ${SOURCE_DIR}/selecttipografico.cpp ${SOURCE_DIR}/showlinegraphic.cpp
    ${SOURCE_DIR}/showpiegraphic.cpp ${SOURCE_DIR}/showscattergraphic.cpp ${SOURCE_DIR}/showtable.cpp
    ${SOURCE_DIR}/funciones_ui.cpp ${SOURCE_DIR}/VerEmbalsesAppHelper.cpp ${SOURCE_DIR}/tablemodel.cpp
    ${SOURCE_DIR}/tablemodelembalse.cpp ${SOURCE_DIR}/tablemodelzona.cpp ${SOURCE_DIR}/tablemodelembalses.cpp
    ${SOURCE_DIR}/tablemodelregistrospluviometricos.cpp
    ${SOURCE_DIR}/progreso.cpp ${SOURCE_DIR}/qtdialogwindow.cpp ${SOURCE_DIR}/window.cpp ${SOURCE_DIR}/view.cpp ${SOURCE_DIR}/observer.cpp
    ${SOURCE_DIR}/configuracion.cpp ${SOURCE_DIR}/formatter.cpp
    ${SOURCE_DIR}/signalmanager.cpp ${SOURCE_DIR}/qloadjob.cpp ${SOURCE_DIR}/graphic.cpp
    ${SOURCE_DIR}/linegraphic.cpp ${SOURCE_DIR}/sectorgraphic.cpp ${SOURCE_DIR}/scattergraphic.cpp
    ${SOURCE_DIR}/stackedbargraphic.cpp
)

ecm_qt_declare_logging_category(verembalses_SRCS
    HEADER verembalsesdebug.h
    IDENTIFIER VEREMBALSES
    CATEGORY_NAME "verembalses"
)

# Antes de qt5_add_translation
set(TS_FILES
    ${CMAKE_SOURCE_DIR}/translations/verembalses_es.ts
    ${CMAKE_SOURCE_DIR}/translations/verembalses_en.ts
    ${CMAKE_SOURCE_DIR}/translations/verembalses_ca_ES.ts
)

set(QM_FILES
    ${CMAKE_SOURCE_DIR}/translations/verembalses_es.qm
    ${CMAKE_SOURCE_DIR}/translations/verembalses_en.qm
    ${CMAKE_SOURCE_DIR}/translations/verembalses_ca_ES.qm
)

set(UI_FILES
    ${SOURCE_DIR}/dlg-select-fecha.ui
    ${SOURCE_DIR}/dlg-show-embalses-graphic.ui
    ${SOURCE_DIR}/dlg-show-line-graphic.ui
    ${SOURCE_DIR}/dlg-show-simple-graphic.ui
    ${SOURCE_DIR}/dlg-show-table.ui
    ${SOURCE_DIR}/dlg_progreso.ui
    ${SOURCE_DIR}/dlg_select-tipo-grafico.ui
    ${SOURCE_DIR}/settings.ui
    ${SOURCE_DIR}/ver_embalses.ui
)

# 1. Actualizar traducciones
add_custom_target(update_translations
    COMMAND Qt5::lupdate ${verembalses_SRCS} ${UI_FILES} -ts ${TS_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# 2. Compilar traducciones
add_custom_target(build_translations
    COMMAND Qt5::lrelease ${TS_FILES}
    DEPENDS update_translations
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# 3. Target unificado
add_custom_target(translations
    DEPENDS build_translations
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

message(STATUS "Instalar verembalses en: ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}")
install(TARGETS verembalses ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

message(STATUS "Instalar net.bounceme.chronos.verembalses.desktop en: ${KDE_INSTALL_APPDIR}")
install(PROGRAMS net.bounceme.chronos.verembalses.desktop  DESTINATION ${KDE_INSTALL_APPDIR})

message(STATUS "Instalar net.bounceme.chronos.verembalses.appdata.xml en: ${KDE_INSTALL_METAINFODIR}")
install(FILES net.bounceme.chronos.verembalses.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})

message(STATUS "Instalar verembalsesui.rc en: ${KDE_INSTALL_KXMLGUI5DIR}/verembalses")
install(FILES verembalsesui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/verembalses)

# Instalar traducciones en sistemas Unix/Linux
message(STATUS "Instalar traducciones de ${CMAKE_BINARY_DIR}/i18n/ en: ${KDE_INSTALL_DATADIR}/verembalses/translations")
install(FILES ${QM_FILES}
    DESTINATION ${KDE_INSTALL_DATADIR}/verembalses/translations
)

