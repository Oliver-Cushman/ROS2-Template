// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Example.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__EXAMPLE__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__EXAMPLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/example__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Example_Request_input
{
public:
  Init_Example_Request_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Example_Request input(::interfaces::srv::Example_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Example_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Example_Request>()
{
  return interfaces::srv::builder::Init_Example_Request_input();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Example_Response_output
{
public:
  Init_Example_Response_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Example_Response output(::interfaces::srv::Example_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Example_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Example_Response>()
{
  return interfaces::srv::builder::Init_Example_Response_output();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__EXAMPLE__BUILDER_HPP_
