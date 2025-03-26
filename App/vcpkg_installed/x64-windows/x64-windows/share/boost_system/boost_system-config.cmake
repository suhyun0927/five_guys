# Generated by BoostInstall.cmake for boost_system-1.87.0

if(Boost_VERBOSE OR Boost_DEBUG)
  message(STATUS "Found boost_system ${boost_system_VERSION} at ${boost_system_DIR}")
endif()

include(CMakeFindDependencyMacro)

if(NOT boost_assert_FOUND)
  find_dependency(boost_assert 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_config_FOUND)
  find_dependency(boost_config 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_throw_exception_FOUND)
  find_dependency(boost_throw_exception 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_variant2_FOUND)
  find_dependency(boost_variant2 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_winapi_FOUND)
  find_dependency(boost_winapi 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/boost_system-targets.cmake")
