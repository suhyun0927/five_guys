# Generated by BoostInstall.cmake for boost_date_time-1.87.0

if(Boost_VERBOSE OR Boost_DEBUG)
  message(STATUS "Found boost_date_time ${boost_date_time_VERSION} at ${boost_date_time_DIR}")
endif()

include(CMakeFindDependencyMacro)

if(NOT boost_algorithm_FOUND)
  find_dependency(boost_algorithm 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_assert_FOUND)
  find_dependency(boost_assert 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_config_FOUND)
  find_dependency(boost_config 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_core_FOUND)
  find_dependency(boost_core 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_io_FOUND)
  find_dependency(boost_io 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_lexical_cast_FOUND)
  find_dependency(boost_lexical_cast 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_numeric_conversion_FOUND)
  find_dependency(boost_numeric_conversion 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_range_FOUND)
  find_dependency(boost_range 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_smart_ptr_FOUND)
  find_dependency(boost_smart_ptr 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_static_assert_FOUND)
  find_dependency(boost_static_assert 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_throw_exception_FOUND)
  find_dependency(boost_throw_exception 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_tokenizer_FOUND)
  find_dependency(boost_tokenizer 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_type_traits_FOUND)
  find_dependency(boost_type_traits 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_utility_FOUND)
  find_dependency(boost_utility 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_winapi_FOUND)
  find_dependency(boost_winapi 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/boost_date_time-targets.cmake")
