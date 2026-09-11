#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__msg__CanPacket() -> *const std::ffi::c_void;
}

#[link(name = "custom_msgs__rosidl_generator_c")]
extern "C" {
    fn custom_msgs__msg__CanPacket__init(msg: *mut CanPacket) -> bool;
    fn custom_msgs__msg__CanPacket__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CanPacket>, size: usize) -> bool;
    fn custom_msgs__msg__CanPacket__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CanPacket>);
    fn custom_msgs__msg__CanPacket__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CanPacket>, out_seq: *mut rosidl_runtime_rs::Sequence<CanPacket>) -> bool;
}

// Corresponds to custom_msgs__msg__CanPacket
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CanPacket {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: [u8; 32],

}



impl Default for CanPacket {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_msgs__msg__CanPacket__init(&mut msg as *mut _) {
        panic!("Call to custom_msgs__msg__CanPacket__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CanPacket {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__msg__CanPacket__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__msg__CanPacket__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_msgs__msg__CanPacket__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CanPacket {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CanPacket where Self: Sized {
  const TYPE_NAME: &'static str = "custom_msgs/msg/CanPacket";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_msgs__msg__CanPacket() }
  }
}


