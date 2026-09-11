
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Goal() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_Goal__init(msg: *mut FollowPath_Goal) -> bool;
    fn custom_msgs__action__FollowPath_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Goal>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Goal>);
    fn custom_msgs__action__FollowPath_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Goal>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub path_name: rosidl_runtime_rs::String,

}



impl Default for FollowPath_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_Goal__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Goal() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Result() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_Result__init(msg: *mut FollowPath_Result) -> bool;
    fn custom_msgs__action__FollowPath_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Result>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Result>);
    fn custom_msgs__action__FollowPath_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Result>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for FollowPath_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_Result__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_Result where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Result() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_Feedback__init(msg: *mut FollowPath_Feedback) -> bool;
    fn custom_msgs__action__FollowPath_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Feedback>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Feedback>);
    fn custom_msgs__action__FollowPath_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_Feedback>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub path_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub index: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ref_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ref_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ref_yaw: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub now_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub now_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub now_yaw: f32,

}



impl Default for FollowPath_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_Feedback__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_Feedback() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_FeedbackMessage__init(msg: *mut FollowPath_FeedbackMessage) -> bool;
    fn custom_msgs__action__FollowPath_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_FeedbackMessage>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_FeedbackMessage>);
    fn custom_msgs__action__FollowPath_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_FeedbackMessage>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::FollowPath_Feedback,

}



impl Default for FollowPath_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_FeedbackMessage() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Goal() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_Goal__init(msg: *mut Hoju_Goal) -> bool;
    fn custom_msgs__action__Hoju_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Goal>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Goal>);
    fn custom_msgs__action__Hoju_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_Goal>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub action_name: rosidl_runtime_rs::String,

}



impl Default for Hoju_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_Goal__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Goal() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Result() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_Result__init(msg: *mut Hoju_Result) -> bool;
    fn custom_msgs__action__Hoju_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Result>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Result>);
    fn custom_msgs__action__Hoju_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_Result>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_Result {
    /// Result
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub arm_mode: u8,

}



impl Default for Hoju_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_Result__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_Result where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Result() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_Feedback__init(msg: *mut Hoju_Feedback) -> bool;
    fn custom_msgs__action__Hoju_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Feedback>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_Feedback>);
    fn custom_msgs__action__Hoju_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_Feedback>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_Feedback {
    /// Feedback
    pub z: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hand: [bool; 9],

}



impl Default for Hoju_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_Feedback__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_Feedback() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_FeedbackMessage__init(msg: *mut Hoju_FeedbackMessage) -> bool;
    fn custom_msgs__action__Hoju_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_FeedbackMessage>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_FeedbackMessage>);
    fn custom_msgs__action__Hoju_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_FeedbackMessage>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Hoju_Feedback,

}



impl Default for Hoju_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_FeedbackMessage() }
  }
}




#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_SendGoal_Request__init(msg: *mut FollowPath_SendGoal_Request) -> bool;
    fn custom_msgs__action__FollowPath_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Request>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Request>);
    fn custom_msgs__action__FollowPath_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Request>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::FollowPath_Goal,

}



impl Default for FollowPath_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_SendGoal_Request() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_SendGoal_Response__init(msg: *mut FollowPath_SendGoal_Response) -> bool;
    fn custom_msgs__action__FollowPath_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Response>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Response>);
    fn custom_msgs__action__FollowPath_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_SendGoal_Response>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for FollowPath_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_SendGoal_Response() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_GetResult_Request__init(msg: *mut FollowPath_GetResult_Request) -> bool;
    fn custom_msgs__action__FollowPath_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Request>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Request>);
    fn custom_msgs__action__FollowPath_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Request>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for FollowPath_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_GetResult_Request() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__FollowPath_GetResult_Response__init(msg: *mut FollowPath_GetResult_Response) -> bool;
    fn custom_msgs__action__FollowPath_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Response>, size: usize) -> bool;
    fn custom_msgs__action__FollowPath_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Response>);
    fn custom_msgs__action__FollowPath_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FollowPath_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FollowPath_GetResult_Response>) -> bool;
}

// Corresponds to custom_msgs__action__FollowPath_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FollowPath_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::FollowPath_Result,

}



impl Default for FollowPath_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__FollowPath_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__FollowPath_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FollowPath_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__FollowPath_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FollowPath_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FollowPath_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/FollowPath_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__FollowPath_GetResult_Response() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_SendGoal_Request__init(msg: *mut Hoju_SendGoal_Request) -> bool;
    fn custom_msgs__action__Hoju_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Request>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Request>);
    fn custom_msgs__action__Hoju_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Request>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Hoju_Goal,

}



impl Default for Hoju_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_SendGoal_Request() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_SendGoal_Response__init(msg: *mut Hoju_SendGoal_Response) -> bool;
    fn custom_msgs__action__Hoju_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Response>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Response>);
    fn custom_msgs__action__Hoju_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_SendGoal_Response>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Hoju_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_SendGoal_Response() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_GetResult_Request__init(msg: *mut Hoju_GetResult_Request) -> bool;
    fn custom_msgs__action__Hoju_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Request>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Request>);
    fn custom_msgs__action__Hoju_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Request>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Hoju_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_GetResult_Request() }
  }
}


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__action__Hoju_GetResult_Response__init(msg: *mut Hoju_GetResult_Response) -> bool;
    fn custom_msgs__action__Hoju_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Response>, size: usize) -> bool;
    fn custom_msgs__action__Hoju_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Response>);
    fn custom_msgs__action__Hoju_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hoju_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Hoju_GetResult_Response>) -> bool;
}

// Corresponds to custom_msgs__action__Hoju_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hoju_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Hoju_Result,

}



impl Default for Hoju_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__action__Hoju_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__action__Hoju_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hoju_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__action__Hoju_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hoju_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hoju_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/action/Hoju_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__action__Hoju_GetResult_Response() }
  }
}






#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__FollowPath_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to custom_msgs__action__FollowPath_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct FollowPath_SendGoal;

impl rosidl_runtime_rs::Service for FollowPath_SendGoal {
    type Request = FollowPath_SendGoal_Request;
    type Response = FollowPath_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__FollowPath_SendGoal() }
    }
}




#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__FollowPath_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to custom_msgs__action__FollowPath_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct FollowPath_GetResult;

impl rosidl_runtime_rs::Service for FollowPath_GetResult {
    type Request = FollowPath_GetResult_Request;
    type Response = FollowPath_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__FollowPath_GetResult() }
    }
}




#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__Hoju_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to custom_msgs__action__Hoju_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Hoju_SendGoal;

impl rosidl_runtime_rs::Service for Hoju_SendGoal {
    type Request = Hoju_SendGoal_Request;
    type Response = Hoju_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__Hoju_SendGoal() }
    }
}




#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__Hoju_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to custom_msgs__action__Hoju_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Hoju_GetResult;

impl rosidl_runtime_rs::Service for Hoju_GetResult {
    type Request = Hoju_GetResult_Request;
    type Response = Hoju_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__custom_msgs__action__Hoju_GetResult() }
    }
}


