cmake_minimum_required(VERSION 3.9)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(verembalses)

set(QT_MIN_VERSION "5.9.0")
set(KF_MIN_VERSION "5.37.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMInstallIcons)
include(ECMQtDeclareLoggingCategory)
include(FeatureSummary)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Core Gui Widgets Charts PrintSupport)

find_package(KF5 ${KF_MIN_VERSION} REQUIRED COMPONENTS
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

find_package(spdlog REQUIRED)
find_package(NumCpp REQUIRED)
find_package(DataFrame REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(fmt REQUIRED)

find_package(mongocxx REQUIRED)

find_package(bsoncxx REQUIRED)

add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(icons)

# Make it possible to use the po files fetched by the fetch-translations step
ki18n_install(po)
kdoctools_install(po)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
