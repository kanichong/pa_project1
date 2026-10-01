// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tracking_interfaces:action/Search.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tracking_interfaces/action/search.hpp"


#ifndef TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__BUILDER_HPP_
#define TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tracking_interfaces/action/detail/search__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_Goal_timeout
{
public:
  explicit Init_Search_Goal_timeout(::tracking_interfaces::action::Search_Goal & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_Goal timeout(::tracking_interfaces::action::Search_Goal::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Goal msg_;
};

class Init_Search_Goal_speed
{
public:
  explicit Init_Search_Goal_speed(::tracking_interfaces::action::Search_Goal & msg)
  : msg_(msg)
  {}
  Init_Search_Goal_timeout speed(::tracking_interfaces::action::Search_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Search_Goal_timeout(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Goal msg_;
};

class Init_Search_Goal_direction
{
public:
  Init_Search_Goal_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_Goal_speed direction(::tracking_interfaces::action::Search_Goal::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Search_Goal_speed(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_Goal>()
{
  return tracking_interfaces::action::builder::Init_Search_Goal_direction();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_Result_elapsed
{
public:
  explicit Init_Search_Result_elapsed(::tracking_interfaces::action::Search_Result & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_Result elapsed(::tracking_interfaces::action::Search_Result::_elapsed_type arg)
  {
    msg_.elapsed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Result msg_;
};

class Init_Search_Result_reason
{
public:
  explicit Init_Search_Result_reason(::tracking_interfaces::action::Search_Result & msg)
  : msg_(msg)
  {}
  Init_Search_Result_elapsed reason(::tracking_interfaces::action::Search_Result::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_Search_Result_elapsed(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Result msg_;
};

class Init_Search_Result_found
{
public:
  Init_Search_Result_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_Result_reason found(::tracking_interfaces::action::Search_Result::_found_type arg)
  {
    msg_.found = std::move(arg);
    return Init_Search_Result_reason(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_Result>()
{
  return tracking_interfaces::action::builder::Init_Search_Result_found();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_Feedback_state
{
public:
  explicit Init_Search_Feedback_state(::tracking_interfaces::action::Search_Feedback & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_Feedback state(::tracking_interfaces::action::Search_Feedback::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Feedback msg_;
};

class Init_Search_Feedback_angular_z
{
public:
  explicit Init_Search_Feedback_angular_z(::tracking_interfaces::action::Search_Feedback & msg)
  : msg_(msg)
  {}
  Init_Search_Feedback_state angular_z(::tracking_interfaces::action::Search_Feedback::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return Init_Search_Feedback_state(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Feedback msg_;
};

class Init_Search_Feedback_elapsed
{
public:
  Init_Search_Feedback_elapsed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_Feedback_angular_z elapsed(::tracking_interfaces::action::Search_Feedback::_elapsed_type arg)
  {
    msg_.elapsed = std::move(arg);
    return Init_Search_Feedback_angular_z(msg_);
  }

private:
  ::tracking_interfaces::action::Search_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_Feedback>()
{
  return tracking_interfaces::action::builder::Init_Search_Feedback_elapsed();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_SendGoal_Request_goal
{
public:
  explicit Init_Search_SendGoal_Request_goal(::tracking_interfaces::action::Search_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_SendGoal_Request goal(::tracking_interfaces::action::Search_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Request msg_;
};

class Init_Search_SendGoal_Request_goal_id
{
public:
  Init_Search_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_SendGoal_Request_goal goal_id(::tracking_interfaces::action::Search_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Search_SendGoal_Request_goal(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_SendGoal_Request>()
{
  return tracking_interfaces::action::builder::Init_Search_SendGoal_Request_goal_id();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_SendGoal_Response_stamp
{
public:
  explicit Init_Search_SendGoal_Response_stamp(::tracking_interfaces::action::Search_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_SendGoal_Response stamp(::tracking_interfaces::action::Search_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Response msg_;
};

class Init_Search_SendGoal_Response_accepted
{
public:
  Init_Search_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_SendGoal_Response_stamp accepted(::tracking_interfaces::action::Search_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Search_SendGoal_Response_stamp(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_SendGoal_Response>()
{
  return tracking_interfaces::action::builder::Init_Search_SendGoal_Response_accepted();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_SendGoal_Event_response
{
public:
  explicit Init_Search_SendGoal_Event_response(::tracking_interfaces::action::Search_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_SendGoal_Event response(::tracking_interfaces::action::Search_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Event msg_;
};

class Init_Search_SendGoal_Event_request
{
public:
  explicit Init_Search_SendGoal_Event_request(::tracking_interfaces::action::Search_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Search_SendGoal_Event_response request(::tracking_interfaces::action::Search_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Search_SendGoal_Event_response(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Event msg_;
};

class Init_Search_SendGoal_Event_info
{
public:
  Init_Search_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_SendGoal_Event_request info(::tracking_interfaces::action::Search_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Search_SendGoal_Event_request(msg_);
  }

private:
  ::tracking_interfaces::action::Search_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_SendGoal_Event>()
{
  return tracking_interfaces::action::builder::Init_Search_SendGoal_Event_info();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_GetResult_Request_goal_id
{
public:
  Init_Search_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tracking_interfaces::action::Search_GetResult_Request goal_id(::tracking_interfaces::action::Search_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_GetResult_Request>()
{
  return tracking_interfaces::action::builder::Init_Search_GetResult_Request_goal_id();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_GetResult_Response_result
{
public:
  explicit Init_Search_GetResult_Response_result(::tracking_interfaces::action::Search_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_GetResult_Response result(::tracking_interfaces::action::Search_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Response msg_;
};

class Init_Search_GetResult_Response_status
{
public:
  Init_Search_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_GetResult_Response_result status(::tracking_interfaces::action::Search_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Search_GetResult_Response_result(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_GetResult_Response>()
{
  return tracking_interfaces::action::builder::Init_Search_GetResult_Response_status();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_GetResult_Event_response
{
public:
  explicit Init_Search_GetResult_Event_response(::tracking_interfaces::action::Search_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_GetResult_Event response(::tracking_interfaces::action::Search_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Event msg_;
};

class Init_Search_GetResult_Event_request
{
public:
  explicit Init_Search_GetResult_Event_request(::tracking_interfaces::action::Search_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Search_GetResult_Event_response request(::tracking_interfaces::action::Search_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Search_GetResult_Event_response(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Event msg_;
};

class Init_Search_GetResult_Event_info
{
public:
  Init_Search_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_GetResult_Event_request info(::tracking_interfaces::action::Search_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Search_GetResult_Event_request(msg_);
  }

private:
  ::tracking_interfaces::action::Search_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_GetResult_Event>()
{
  return tracking_interfaces::action::builder::Init_Search_GetResult_Event_info();
}

}  // namespace tracking_interfaces


namespace tracking_interfaces
{

namespace action
{

namespace builder
{

class Init_Search_FeedbackMessage_feedback
{
public:
  explicit Init_Search_FeedbackMessage_feedback(::tracking_interfaces::action::Search_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tracking_interfaces::action::Search_FeedbackMessage feedback(::tracking_interfaces::action::Search_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracking_interfaces::action::Search_FeedbackMessage msg_;
};

class Init_Search_FeedbackMessage_goal_id
{
public:
  Init_Search_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Search_FeedbackMessage_feedback goal_id(::tracking_interfaces::action::Search_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Search_FeedbackMessage_feedback(msg_);
  }

private:
  ::tracking_interfaces::action::Search_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracking_interfaces::action::Search_FeedbackMessage>()
{
  return tracking_interfaces::action::builder::Init_Search_FeedbackMessage_goal_id();
}

}  // namespace tracking_interfaces

#endif  // TRACKING_INTERFACES__ACTION__DETAIL__SEARCH__BUILDER_HPP_
