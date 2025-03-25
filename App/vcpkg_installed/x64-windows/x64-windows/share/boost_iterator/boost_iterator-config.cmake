# Generated by BoostInstall.cmake for boost_iterator-1.87.0

if(Boost_VERBOSE OR Boost_DEBUG)
  message(STATUS "Found boost_iterator ${boost_iterator_VERSION} at ${boost_iterator_DIR}")
endif()

include(CMakeFindDependencyMacro)

if(NOT boost_assert_FOUND)
  find_dependency(boost_assert 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_concept_check_FOUND)
  find_dependency(boost_concept_check 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_config_FOUND)
  find_dependency(boost_config 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_core_FOUND)
  find_dependency(boost_core 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_detail_FOUND)
  find_dependency(boost_detail 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_function_types_FOUND)
  find_dependency(boost_function_types 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_fusion_FOUND)
  find_dependency(boost_fusion 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_mpl_FOUND)
  find_dependency(boost_mpl 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_optional_FOUND)
  find_dependency(boost_optional 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_smart_ptr_FOUND)
  find_dependency(boost_smart_ptr 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_static_assert_FOUND)
  find_dependency(boost_static_assert 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_type_traits_FOUND)
  find_dependency(boost_type_traits 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()
if(NOT boost_utility_FOUND)
  find_dependency(boost_utility 1.87.0 EXACT HINTS "${CMAKE_CURRENT_LIST_DIR}/..")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/boost_iterator-targets.cmake")
