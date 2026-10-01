// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from tracking_interfaces:action/Search.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "tracking_interfaces/action/detail/search__functions.h"
#include "tracking_interfaces/action/detail/search__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_Goal_type_support_ids_t;

static const _Search_Goal_type_support_ids_t _Search_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_Goal_type_support_symbol_names_t _Search_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_Goal)),
  }
};

typedef struct _Search_Goal_type_support_data_t
{
  void * data[2];
} _Search_Goal_type_support_data_t;

static _Search_Goal_type_support_data_t _Search_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_Goal_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Search_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Search_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Goal__get_type_hash,
  &tracking_interfaces__action__Search_Goal__get_type_description,
  &tracking_interfaces__action__Search_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_Goal>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_Goal)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_Result_type_support_ids_t;

static const _Search_Result_type_support_ids_t _Search_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_Result_type_support_symbol_names_t _Search_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_Result)),
  }
};

typedef struct _Search_Result_type_support_data_t
{
  void * data[2];
} _Search_Result_type_support_data_t;

static _Search_Result_type_support_data_t _Search_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_Result_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Search_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Search_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Result__get_type_hash,
  &tracking_interfaces__action__Search_Result__get_type_description,
  &tracking_interfaces__action__Search_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_Result>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_Result)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_Feedback_type_support_ids_t;

static const _Search_Feedback_type_support_ids_t _Search_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_Feedback_type_support_symbol_names_t _Search_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_Feedback)),
  }
};

typedef struct _Search_Feedback_type_support_data_t
{
  void * data[2];
} _Search_Feedback_type_support_data_t;

static _Search_Feedback_type_support_data_t _Search_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_Feedback_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Search_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Search_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_Feedback__get_type_hash,
  &tracking_interfaces__action__Search_Feedback__get_type_description,
  &tracking_interfaces__action__Search_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_Feedback>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_Feedback)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_SendGoal_Request_type_support_ids_t;

static const _Search_SendGoal_Request_type_support_ids_t _Search_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_SendGoal_Request_type_support_symbol_names_t _Search_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_SendGoal_Request)),
  }
};

typedef struct _Search_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Search_SendGoal_Request_type_support_data_t;

static _Search_SendGoal_Request_type_support_data_t _Search_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_SendGoal_Request_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Search_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Search_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Request>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_SendGoal_Request)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_SendGoal_Response_type_support_ids_t;

static const _Search_SendGoal_Response_type_support_ids_t _Search_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_SendGoal_Response_type_support_symbol_names_t _Search_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_SendGoal_Response)),
  }
};

typedef struct _Search_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Search_SendGoal_Response_type_support_data_t;

static _Search_SendGoal_Response_type_support_data_t _Search_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_SendGoal_Response_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Search_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Search_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Response>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_SendGoal_Response)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_SendGoal_Event_type_support_ids_t;

static const _Search_SendGoal_Event_type_support_ids_t _Search_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_SendGoal_Event_type_support_symbol_names_t _Search_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_SendGoal_Event)),
  }
};

typedef struct _Search_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Search_SendGoal_Event_type_support_data_t;

static _Search_SendGoal_Event_type_support_data_t _Search_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_SendGoal_Event_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Search_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Search_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_description,
  &tracking_interfaces__action__Search_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Event>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_SendGoal_Event)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_SendGoal_type_support_ids_t;

static const _Search_SendGoal_type_support_ids_t _Search_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_SendGoal_type_support_symbol_names_t _Search_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_SendGoal)),
  }
};

typedef struct _Search_SendGoal_type_support_data_t
{
  void * data[2];
} _Search_SendGoal_type_support_data_t;

static _Search_SendGoal_type_support_data_t _Search_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_SendGoal_service_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Search_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Search_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Search_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tracking_interfaces::action::Search_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tracking_interfaces::action::Search_SendGoal>,
  &tracking_interfaces__action__Search_SendGoal__get_type_hash,
  &tracking_interfaces__action__Search_SendGoal__get_type_description,
  &tracking_interfaces__action__Search_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tracking_interfaces::action::Search_SendGoal>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<tracking_interfaces::action::Search_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_GetResult_Request_type_support_ids_t;

static const _Search_GetResult_Request_type_support_ids_t _Search_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_GetResult_Request_type_support_symbol_names_t _Search_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_GetResult_Request)),
  }
};

typedef struct _Search_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Search_GetResult_Request_type_support_data_t;

static _Search_GetResult_Request_type_support_data_t _Search_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_GetResult_Request_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Search_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Search_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Request>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_GetResult_Request)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_GetResult_Response_type_support_ids_t;

static const _Search_GetResult_Response_type_support_ids_t _Search_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_GetResult_Response_type_support_symbol_names_t _Search_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_GetResult_Response)),
  }
};

typedef struct _Search_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Search_GetResult_Response_type_support_data_t;

static _Search_GetResult_Response_type_support_data_t _Search_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_GetResult_Response_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Search_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Search_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Response>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_GetResult_Response)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_GetResult_Event_type_support_ids_t;

static const _Search_GetResult_Event_type_support_ids_t _Search_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_GetResult_Event_type_support_symbol_names_t _Search_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_GetResult_Event)),
  }
};

typedef struct _Search_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Search_GetResult_Event_type_support_data_t;

static _Search_GetResult_Event_type_support_data_t _Search_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_GetResult_Event_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Search_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Search_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_hash,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_description,
  &tracking_interfaces__action__Search_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Event>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_GetResult_Event)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_GetResult_type_support_ids_t;

static const _Search_GetResult_type_support_ids_t _Search_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_GetResult_type_support_symbol_names_t _Search_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_GetResult)),
  }
};

typedef struct _Search_GetResult_type_support_data_t
{
  void * data[2];
} _Search_GetResult_type_support_data_t;

static _Search_GetResult_type_support_data_t _Search_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_GetResult_service_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Search_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Search_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Search_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tracking_interfaces::action::Search_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tracking_interfaces::action::Search_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tracking_interfaces::action::Search_GetResult>,
  &tracking_interfaces__action__Search_GetResult__get_type_hash,
  &tracking_interfaces__action__Search_GetResult__get_type_description,
  &tracking_interfaces__action__Search_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tracking_interfaces::action::Search_GetResult>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<tracking_interfaces::action::Search_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tracking_interfaces/action/detail/search__functions.h"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Search_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Search_FeedbackMessage_type_support_ids_t;

static const _Search_FeedbackMessage_type_support_ids_t _Search_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Search_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Search_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Search_FeedbackMessage_type_support_symbol_names_t _Search_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tracking_interfaces, action, Search_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracking_interfaces, action, Search_FeedbackMessage)),
  }
};

typedef struct _Search_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Search_FeedbackMessage_type_support_data_t;

static _Search_FeedbackMessage_type_support_data_t _Search_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Search_FeedbackMessage_message_typesupport_map = {
  2,
  "tracking_interfaces",
  &_Search_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Search_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Search_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Search_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Search_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_hash,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_description,
  &tracking_interfaces__action__Search_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracking_interfaces::action::Search_FeedbackMessage>()
{
  return &::tracking_interfaces::action::rosidl_typesupport_cpp::Search_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search_FeedbackMessage)() {
  return get_message_type_support_handle<tracking_interfaces::action::Search_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "tracking_interfaces/action/detail/search__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace tracking_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Search_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &tracking_interfaces__action__Search__get_type_hash,
  &tracking_interfaces__action__Search__get_type_description,
  &tracking_interfaces__action__Search__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tracking_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<tracking_interfaces::action::Search>()
{
  using ::tracking_interfaces::action::rosidl_typesupport_cpp::Search_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Search_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::tracking_interfaces::action::Search::Impl::SendGoalService>();
  Search_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::tracking_interfaces::action::Search::Impl::GetResultService>();
  Search_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::tracking_interfaces::action::Search::Impl::CancelGoalService>();
  Search_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::tracking_interfaces::action::Search::Impl::FeedbackMessage>();
  Search_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::tracking_interfaces::action::Search::Impl::GoalStatusMessage>();
  return &Search_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, tracking_interfaces, action, Search)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<tracking_interfaces::action::Search>();
}

#ifdef __cplusplus
}
#endif
