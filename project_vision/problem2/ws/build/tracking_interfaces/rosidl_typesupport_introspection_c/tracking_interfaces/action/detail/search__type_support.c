// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tracking_interfaces:action/Search.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
#include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tracking_interfaces/action/detail/search__functions.h"
#include "tracking_interfaces/action/detail/search__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_Goal__init(message_memory);
}

void tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_member_array[3] = {
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Goal, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Goal, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "timeout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Goal, timeout),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_Goal",  // message name
  3,  // number of fields
  sizeof(tracking_interfaces__action__Search_Goal),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_member_array,  // message members
  tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Goal__get_type_hash,
  &tracking_interfaces__action__Search_Goal__get_type_description,
  &tracking_interfaces__action__Search_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Goal)() {
  if (!tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_Goal__rosidl_typesupport_introspection_c__Search_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_Result__init(message_memory);
}

void tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_member_array[3] = {
  {
    "found",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Result, found),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Result, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "elapsed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Result, elapsed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_Result",  // message name
  3,  // number of fields
  sizeof(tracking_interfaces__action__Search_Result),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_member_array,  // message members
  tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Result__get_type_hash,
  &tracking_interfaces__action__Search_Result__get_type_description,
  &tracking_interfaces__action__Search_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Result)() {
  if (!tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_Result__rosidl_typesupport_introspection_c__Search_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `state`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_Feedback__init(message_memory);
}

void tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_member_array[3] = {
  {
    "elapsed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Feedback, elapsed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "angular_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Feedback, angular_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_Feedback, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_Feedback",  // message name
  3,  // number of fields
  sizeof(tracking_interfaces__action__Search_Feedback),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_member_array,  // message members
  tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Feedback__get_type_hash,
  &tracking_interfaces__action__Search_Feedback__get_type_description,
  &tracking_interfaces__action__Search_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Feedback)() {
  if (!tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_Feedback__rosidl_typesupport_introspection_c__Search_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "tracking_interfaces/action/search.h"
// Member `goal`
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_SendGoal_Request__init(message_memory);
}

void tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(tracking_interfaces__action__Search_SendGoal_Request),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_member_array,  // message members
  tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Request)() {
  tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Goal)();
  if (!tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_SendGoal_Response__init(message_memory);
}

void tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(tracking_interfaces__action__Search_SendGoal_Response),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_member_array,  // message members
  tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Response)() {
  tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "tracking_interfaces/action/search.h"
// Member `request`
// Member `response`
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_SendGoal_Event__init(message_memory);
}

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_SendGoal_Event__fini(message_memory);
}

size_t tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__Search_SendGoal_Event__request(
  const void * untyped_member)
{
  const tracking_interfaces__action__Search_SendGoal_Request__Sequence * member =
    (const tracking_interfaces__action__Search_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const tracking_interfaces__action__Search_SendGoal_Request__Sequence * member =
    (const tracking_interfaces__action__Search_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  tracking_interfaces__action__Search_SendGoal_Request__Sequence * member =
    (tracking_interfaces__action__Search_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__Search_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tracking_interfaces__action__Search_SendGoal_Request * item =
    ((const tracking_interfaces__action__Search_SendGoal_Request *)
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__request(untyped_member, index));
  tracking_interfaces__action__Search_SendGoal_Request * value =
    (tracking_interfaces__action__Search_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__Search_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tracking_interfaces__action__Search_SendGoal_Request * item =
    ((tracking_interfaces__action__Search_SendGoal_Request *)
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__request(untyped_member, index));
  const tracking_interfaces__action__Search_SendGoal_Request * value =
    (const tracking_interfaces__action__Search_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__Search_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  tracking_interfaces__action__Search_SendGoal_Request__Sequence * member =
    (tracking_interfaces__action__Search_SendGoal_Request__Sequence *)(untyped_member);
  tracking_interfaces__action__Search_SendGoal_Request__Sequence__fini(member);
  return tracking_interfaces__action__Search_SendGoal_Request__Sequence__init(member, size);
}

size_t tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__Search_SendGoal_Event__response(
  const void * untyped_member)
{
  const tracking_interfaces__action__Search_SendGoal_Response__Sequence * member =
    (const tracking_interfaces__action__Search_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const tracking_interfaces__action__Search_SendGoal_Response__Sequence * member =
    (const tracking_interfaces__action__Search_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  tracking_interfaces__action__Search_SendGoal_Response__Sequence * member =
    (tracking_interfaces__action__Search_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__Search_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tracking_interfaces__action__Search_SendGoal_Response * item =
    ((const tracking_interfaces__action__Search_SendGoal_Response *)
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__response(untyped_member, index));
  tracking_interfaces__action__Search_SendGoal_Response * value =
    (tracking_interfaces__action__Search_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__Search_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tracking_interfaces__action__Search_SendGoal_Response * item =
    ((tracking_interfaces__action__Search_SendGoal_Response *)
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__response(untyped_member, index));
  const tracking_interfaces__action__Search_SendGoal_Response * value =
    (const tracking_interfaces__action__Search_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__Search_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  tracking_interfaces__action__Search_SendGoal_Response__Sequence * member =
    (tracking_interfaces__action__Search_SendGoal_Response__Sequence *)(untyped_member);
  tracking_interfaces__action__Search_SendGoal_Response__Sequence__fini(member);
  return tracking_interfaces__action__Search_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__Search_SendGoal_Event__request,  // size() function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__request,  // get_const(index) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__request,  // get(index) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__Search_SendGoal_Event__request,  // fetch(index, &value) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__Search_SendGoal_Event__request,  // assign(index, value) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__Search_SendGoal_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tracking_interfaces__action__Search_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__Search_SendGoal_Event__response,  // size() function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__Search_SendGoal_Event__response,  // get_const(index) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__Search_SendGoal_Event__response,  // get(index) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__Search_SendGoal_Event__response,  // fetch(index, &value) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__Search_SendGoal_Event__response,  // assign(index, value) function pointer
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__Search_SendGoal_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(tracking_interfaces__action__Search_SendGoal_Event),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_member_array,  // message members
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Event)() {
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Request)();
  tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Response)();
  if (!tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_members = {
  "tracking_interfaces__action",  // service namespace
  "Search_SendGoal",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_type_support_handle = {
  0,
  &tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Request__rosidl_typesupport_introspection_c__Search_SendGoal_Request_message_type_support_handle,
  &tracking_interfaces__action__Search_SendGoal_Response__rosidl_typesupport_introspection_c__Search_SendGoal_Response_message_type_support_handle,
  &tracking_interfaces__action__Search_SendGoal_Event__rosidl_typesupport_introspection_c__Search_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tracking_interfaces,
    action,
    Search_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tracking_interfaces,
    action,
    Search_SendGoal
  ),
  &tracking_interfaces__action__Search_SendGoal__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal__get_type_description,
  &tracking_interfaces__action__Search_SendGoal__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal)(void) {
  if (!tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_SendGoal_Event)()->data;
  }

  return &tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_GetResult_Request__init(message_memory);
}

void tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(tracking_interfaces__action__Search_GetResult_Request),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_member_array,  // message members
  tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Request)() {
  tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "tracking_interfaces/action/search.h"
// Member `result`
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_GetResult_Response__init(message_memory);
}

void tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(tracking_interfaces__action__Search_GetResult_Response),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_member_array,  // message members
  tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Response)() {
  tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Result)();
  if (!tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "tracking_interfaces/action/search.h"
// Member `request`
// Member `response`
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_GetResult_Event__init(message_memory);
}

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_GetResult_Event__fini(message_memory);
}

size_t tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__size_function__Search_GetResult_Event__request(
  const void * untyped_member)
{
  const tracking_interfaces__action__Search_GetResult_Request__Sequence * member =
    (const tracking_interfaces__action__Search_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const tracking_interfaces__action__Search_GetResult_Request__Sequence * member =
    (const tracking_interfaces__action__Search_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  tracking_interfaces__action__Search_GetResult_Request__Sequence * member =
    (tracking_interfaces__action__Search_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__Search_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tracking_interfaces__action__Search_GetResult_Request * item =
    ((const tracking_interfaces__action__Search_GetResult_Request *)
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__request(untyped_member, index));
  tracking_interfaces__action__Search_GetResult_Request * value =
    (tracking_interfaces__action__Search_GetResult_Request *)(untyped_value);
  *value = *item;
}

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__Search_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tracking_interfaces__action__Search_GetResult_Request * item =
    ((tracking_interfaces__action__Search_GetResult_Request *)
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__request(untyped_member, index));
  const tracking_interfaces__action__Search_GetResult_Request * value =
    (const tracking_interfaces__action__Search_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__Search_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  tracking_interfaces__action__Search_GetResult_Request__Sequence * member =
    (tracking_interfaces__action__Search_GetResult_Request__Sequence *)(untyped_member);
  tracking_interfaces__action__Search_GetResult_Request__Sequence__fini(member);
  return tracking_interfaces__action__Search_GetResult_Request__Sequence__init(member, size);
}

size_t tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__size_function__Search_GetResult_Event__response(
  const void * untyped_member)
{
  const tracking_interfaces__action__Search_GetResult_Response__Sequence * member =
    (const tracking_interfaces__action__Search_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const tracking_interfaces__action__Search_GetResult_Response__Sequence * member =
    (const tracking_interfaces__action__Search_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  tracking_interfaces__action__Search_GetResult_Response__Sequence * member =
    (tracking_interfaces__action__Search_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__Search_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tracking_interfaces__action__Search_GetResult_Response * item =
    ((const tracking_interfaces__action__Search_GetResult_Response *)
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__response(untyped_member, index));
  tracking_interfaces__action__Search_GetResult_Response * value =
    (tracking_interfaces__action__Search_GetResult_Response *)(untyped_value);
  *value = *item;
}

void tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__Search_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tracking_interfaces__action__Search_GetResult_Response * item =
    ((tracking_interfaces__action__Search_GetResult_Response *)
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__response(untyped_member, index));
  const tracking_interfaces__action__Search_GetResult_Response * value =
    (const tracking_interfaces__action__Search_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__Search_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  tracking_interfaces__action__Search_GetResult_Response__Sequence * member =
    (tracking_interfaces__action__Search_GetResult_Response__Sequence *)(untyped_member);
  tracking_interfaces__action__Search_GetResult_Response__Sequence__fini(member);
  return tracking_interfaces__action__Search_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__size_function__Search_GetResult_Event__request,  // size() function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__request,  // get_const(index) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__request,  // get(index) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__Search_GetResult_Event__request,  // fetch(index, &value) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__Search_GetResult_Event__request,  // assign(index, value) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__Search_GetResult_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tracking_interfaces__action__Search_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__size_function__Search_GetResult_Event__response,  // size() function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__Search_GetResult_Event__response,  // get_const(index) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__get_function__Search_GetResult_Event__response,  // get(index) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__Search_GetResult_Event__response,  // fetch(index, &value) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__Search_GetResult_Event__response,  // assign(index, value) function pointer
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__Search_GetResult_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(tracking_interfaces__action__Search_GetResult_Event),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_member_array,  // message members
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Event)() {
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Request)();
  tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Response)();
  if (!tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_members = {
  "tracking_interfaces__action",  // service namespace
  "Search_GetResult",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_type_support_handle = {
  0,
  &tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_members,
  get_service_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Request__rosidl_typesupport_introspection_c__Search_GetResult_Request_message_type_support_handle,
  &tracking_interfaces__action__Search_GetResult_Response__rosidl_typesupport_introspection_c__Search_GetResult_Response_message_type_support_handle,
  &tracking_interfaces__action__Search_GetResult_Event__rosidl_typesupport_introspection_c__Search_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tracking_interfaces,
    action,
    Search_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tracking_interfaces,
    action,
    Search_GetResult
  ),
  &tracking_interfaces__action__Search_GetResult__get_type_hash,
  &tracking_interfaces__action__Search_GetResult__get_type_description,
  &tracking_interfaces__action__Search_GetResult__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult)(void) {
  if (!tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_GetResult_Event)()->data;
  }

  return &tracking_interfaces__action__detail__search__rosidl_typesupport_introspection_c__Search_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tracking_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "tracking_interfaces/action/search.h"
// Member `feedback`
// already included above
// #include "tracking_interfaces/action/detail/search__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracking_interfaces__action__Search_FeedbackMessage__init(message_memory);
}

void tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_fini_function(void * message_memory)
{
  tracking_interfaces__action__Search_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracking_interfaces__action__Search_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_members = {
  "tracking_interfaces__action",  // message namespace
  "Search_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(tracking_interfaces__action__Search_FeedbackMessage),
  false,  // has_any_key_member_
  tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_member_array,  // message members
  tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_type_support_handle = {
  0,
  &tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_hash,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_description,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracking_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_FeedbackMessage)() {
  tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracking_interfaces, action, Search_Feedback)();
  if (!tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracking_interfaces__action__Search_FeedbackMessage__rosidl_typesupport_introspection_c__Search_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
