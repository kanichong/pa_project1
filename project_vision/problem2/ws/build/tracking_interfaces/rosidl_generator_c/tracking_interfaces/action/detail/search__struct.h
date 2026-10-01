// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tracking_interfaces:action/Search.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tracking_interfaces/action/search.h"


#ifndef TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__STRUCT_H_
#define TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_Goal
{
  /// +1 = 왼쪽(반시계, REP-103 angular.z +), -1 = 오른쪽
  double direction;
  /// 회전 속도 크기, > 0
  double speed;
  /// 탐색 제한 시간, > 0
  double timeout;
} tracking_interfaces__action__Search_Goal;

// Struct for a sequence of tracking_interfaces__action__Search_Goal.
typedef struct tracking_interfaces__action__Search_Goal__Sequence
{
  tracking_interfaces__action__Search_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_Result
{
  bool found;
  /// FOUND | TIMEOUT | CANCELED | NO_INPUT | INVALID_GOAL
  rosidl_runtime_c__String reason;
  double elapsed;
} tracking_interfaces__action__Search_Result;

// Struct for a sequence of tracking_interfaces__action__Search_Result.
typedef struct tracking_interfaces__action__Search_Result__Sequence
{
  tracking_interfaces__action__Search_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'state'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_Feedback
{
  double elapsed;
  /// 현재 회전 명령
  double angular_z;
  /// SEARCHING
  rosidl_runtime_c__String state;
} tracking_interfaces__action__Search_Feedback;

// Struct for a sequence of tracking_interfaces__action__Search_Feedback.
typedef struct tracking_interfaces__action__Search_Feedback__Sequence
{
  tracking_interfaces__action__Search_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "tracking_interfaces/action/detail/search__struct.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  tracking_interfaces__action__Search_Goal goal;
} tracking_interfaces__action__Search_SendGoal_Request;

// Struct for a sequence of tracking_interfaces__action__Search_SendGoal_Request.
typedef struct tracking_interfaces__action__Search_SendGoal_Request__Sequence
{
  tracking_interfaces__action__Search_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} tracking_interfaces__action__Search_SendGoal_Response;

// Struct for a sequence of tracking_interfaces__action__Search_SendGoal_Response.
typedef struct tracking_interfaces__action__Search_SendGoal_Response__Sequence
{
  tracking_interfaces__action__Search_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tracking_interfaces__action__Search_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tracking_interfaces__action__Search_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tracking_interfaces__action__Search_SendGoal_Request__Sequence request;
  tracking_interfaces__action__Search_SendGoal_Response__Sequence response;
} tracking_interfaces__action__Search_SendGoal_Event;

// Struct for a sequence of tracking_interfaces__action__Search_SendGoal_Event.
typedef struct tracking_interfaces__action__Search_SendGoal_Event__Sequence
{
  tracking_interfaces__action__Search_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} tracking_interfaces__action__Search_GetResult_Request;

// Struct for a sequence of tracking_interfaces__action__Search_GetResult_Request.
typedef struct tracking_interfaces__action__Search_GetResult_Request__Sequence
{
  tracking_interfaces__action__Search_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_GetResult_Response
{
  int8_t status;
  tracking_interfaces__action__Search_Result result;
} tracking_interfaces__action__Search_GetResult_Response;

// Struct for a sequence of tracking_interfaces__action__Search_GetResult_Response.
typedef struct tracking_interfaces__action__Search_GetResult_Response__Sequence
{
  tracking_interfaces__action__Search_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tracking_interfaces__action__Search_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tracking_interfaces__action__Search_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tracking_interfaces__action__Search_GetResult_Request__Sequence request;
  tracking_interfaces__action__Search_GetResult_Response__Sequence response;
} tracking_interfaces__action__Search_GetResult_Event;

// Struct for a sequence of tracking_interfaces__action__Search_GetResult_Event.
typedef struct tracking_interfaces__action__Search_GetResult_Event__Sequence
{
  tracking_interfaces__action__Search_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "tracking_interfaces/action/detail/search__struct.h"

/// Struct defined in action/Search in the package tracking_interfaces.
typedef struct tracking_interfaces__action__Search_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  tracking_interfaces__action__Search_Feedback feedback;
} tracking_interfaces__action__Search_FeedbackMessage;

// Struct for a sequence of tracking_interfaces__action__Search_FeedbackMessage.
typedef struct tracking_interfaces__action__Search_FeedbackMessage__Sequence
{
  tracking_interfaces__action__Search_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracking_interfaces__action__Search_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__STRUCT_H_
