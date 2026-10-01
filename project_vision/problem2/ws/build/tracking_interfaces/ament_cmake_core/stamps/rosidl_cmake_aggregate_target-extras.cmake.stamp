# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target tracking_interfaces::tracking_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${tracking_interfaces_TARGETS}.
if(tracking_interfaces_TARGETS AND NOT TARGET tracking_interfaces::tracking_interfaces)
  add_library(tracking_interfaces::tracking_interfaces INTERFACE IMPORTED)
  set_target_properties(tracking_interfaces::tracking_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${tracking_interfaces_TARGETS}")
endif()
