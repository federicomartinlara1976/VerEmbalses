cmake_minimum_required(VERSION 3.9)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 20)
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

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Core Gui Widgets Charts PrintSupport LinguistTools)

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

find_package(chronoslibs-common REQUIRED)
find_package(chronoslibs-configuration REQUIRED)
find_package(chronoslibs-kdetools REQUIRED)
find_package(chronoslibs-mongo REQUIRED)
find_package(spdlog REQUIRED)
find_package(NumCpp REQUIRED)
find_package(DataFrame REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(fmt REQUIRED)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

qt5_add_resources(RESOURCES ${CMAKE_SOURCE_DIR}/translations.qrc)

add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(icons)

include(GNUInstallDirs)
set(MO_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LOCALEDIR}")

# 2. Lista de idiomas soportados
#set(SUPPORTED_LANGUAGES es_ES.UTF-8)  # ca_ES -> ca, es_ES -> es

# 3. Procesar cada traducción
#foreach(LANG ${SUPPORTED_LANGUAGES})
    # Ruta del archivo .po (ajusta si usas ca_ES.po -> cambia a ${LANG}_ES.po)
#    set(PO_FILE "${CMAKE_CURRENT_SOURCE_DIR}/po/${LANG}.po")
    
    # Ruta de salida del .mo (TEMPORAL en build/)
#    set(MO_FILE "${CMAKE_CURRENT_BINARY_DIR}/${LANG}.mo")
    
    # Comando para generar .mo
#    add_custom_command(
#        OUTPUT ${MO_FILE}
#        COMMAND msgfmt ${PO_FILE} -o ${MO_FILE}
#        DEPENDS ${PO_FILE}
#        COMMENT "Generando .mo para ${LANG}"
#    )
    
    # Instalación en /usr/share/locale/<lang>/LC_MESSAGES/verembalses.mo
#    install(
#        FILES ${MO_FILE}
#        DESTINATION "${MO_INSTALL_DIR}/${LANG}/LC_MESSAGES"
#        RENAME "verembalses.mo"  # ¡NOMBRE CLAVE!
#    )
    
    # Añade el .mo a la lista de archivos generados
#    list(APPEND GENERATED_MO_FILES ${MO_FILE})
#endforeach()

# 4. Asegura que las traducciones se compilan ANTES de instalar
#add_custom_target(compile_translations ALL DEPENDS ${GENERATED_MO_FILES})

#kdoctools_install(po)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
