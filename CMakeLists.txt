cmake_minimum_required(VERSION 3.16)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_COMPILER "/usr/bin/c++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(verembalses)

set(QT_MIN_VERSION "6.5.0")
set(KF_MIN_VERSION "6.0.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

set(QT_MAJOR_VERSION 6 CACHE STRING "Qt major version" FORCE)
include(KDEInstallDirs6)
include(ECMAddAppIcon)
include(ECMInstallIcons)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(ECMQtDeclareLoggingCategory)
include(ECMPoQmTools)
include(FeatureSummary)

find_package(Qt6 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core 
    Gui 
    Widgets 
    Charts 
    PrintSupport)

find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    ConfigWidgets
    CoreAddons
    Crash
    DBusAddons
    DocTools
    I18n
    XmlGui
    Plotting
    Config
    ThreadWeaver
)

find_package(chronoslibs-common REQUIRED)
find_package(chronoslibs-configuration REQUIRED)
find_package(chronoslibs-kdetools REQUIRED)
find_package(chronoslibs-mongo REQUIRED)
find_package(NumCpp REQUIRED)
find_package(DataFrame REQUIRED)
find_package(fmt REQUIRED)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_subdirectory(src)
add_subdirectory(icons)

# Make it possible to use the po files fetched by the fetch-translations step
ki18n_install(po)
kdoctools_install(po)
