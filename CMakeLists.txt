cmake_minimum_required(VERSION 3.26)

project(
    message_source
    VERSION 1.0.0
    LANGUAGES CXX)

file(GLOB SRC_FILES src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
                           PUBLIC $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

find_package(diff REQUIRED)
find_package(iprocessable REQUIRED)
find_package(ilink REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_LOCAL_INTERFACE:diff::diff> $<BUILD_LOCAL_INTERFACE:iprocessable::iprocessable>
           $<BUILD_LOCAL_INTERFACE:ilink::ilink>)

add_subdirectory(test)

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(
    EXPORT ${PROJECT_NAME}-targets
    DESTINATION ${INSTALL_CONFIGDIR}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}.cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)
configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIGDIR})

export(
    EXPORT ${PROJECT_NAME}-targets
    NAMESPACE ${PROJECT_NAME}::
    FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake)
export(PACKAGE ${PROJECT_NAME})
