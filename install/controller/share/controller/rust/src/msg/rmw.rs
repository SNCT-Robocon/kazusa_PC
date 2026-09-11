#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "controller__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__controller__msg__Controller() -> *const std::ffi::c_void;
}

#[link(name = "controller__rosidl_generator_c")]
extern "C" {
    fn controller__msg__Controller__init(msg: *mut Controller) -> bool;
    fn controller__msg__Controller__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Controller>, size: usize) -> bool;
    fn controller__msg__Controller__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Controller>);
    fn controller__msg__Controller__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Controller>, out_seq: *mut rosidl_runtime_rs::Sequence<Controller>) -> bool;
}

// Corresponds to controller__msg__Controller
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Controller {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hata_turn_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hata_turn_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hata_turn_theta: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub baketu_turn_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub baketu_turn_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub baketu_turn_theta: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hoju_turn_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hoju_turn_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hoju_turn_theta: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hata_speed: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub baketu_speed: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fieldcolor: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dengen: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column1: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column2: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column3: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub execute: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub refill: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reload1: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reload2: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reload3: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub firehata: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub firebaketu: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hojuposition: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub up: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub down: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub circle: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub triangle: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub square: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cross: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub l1: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub l2: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub r1: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub r2: bool,

}



impl Default for Controller {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !controller__msg__Controller__init(&mut msg as *mut _) {
        panic!("Call to controller__msg__Controller__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Controller {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { controller__msg__Controller__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { controller__msg__Controller__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { controller__msg__Controller__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Controller {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Controller where Self: Sized {
  const TYPE_NAME: &'static str = "controller/msg/Controller";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__controller__msg__Controller() }
  }
}


