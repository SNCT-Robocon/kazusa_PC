#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to controller__msg__Controller

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub fieldcolor: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dengen: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column1: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column2: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub column3: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Controller::default())
  }
}

impl rosidl_runtime_rs::Message for Controller {
  type RmwMsg = super::msg::rmw::Controller;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
        hata_turn_x: msg.hata_turn_x,
        hata_turn_y: msg.hata_turn_y,
        hata_turn_theta: msg.hata_turn_theta,
        baketu_turn_x: msg.baketu_turn_x,
        baketu_turn_y: msg.baketu_turn_y,
        baketu_turn_theta: msg.baketu_turn_theta,
        hoju_turn_x: msg.hoju_turn_x,
        hoju_turn_y: msg.hoju_turn_y,
        hoju_turn_theta: msg.hoju_turn_theta,
        hata_speed: msg.hata_speed,
        baketu_speed: msg.baketu_speed,
        fieldcolor: msg.fieldcolor.as_str().into(),
        dengen: msg.dengen,
        mode: msg.mode.as_str().into(),
        column1: msg.column1.as_str().into(),
        column2: msg.column2.as_str().into(),
        column3: msg.column3.as_str().into(),
        execute: msg.execute,
        refill: msg.refill,
        reload1: msg.reload1,
        reload2: msg.reload2,
        reload3: msg.reload3,
        firehata: msg.firehata,
        firebaketu: msg.firebaketu,
        hojuposition: msg.hojuposition,
        left: msg.left,
        right: msg.right,
        up: msg.up,
        down: msg.down,
        circle: msg.circle,
        triangle: msg.triangle,
        square: msg.square,
        cross: msg.cross,
        l1: msg.l1,
        l2: msg.l2,
        r1: msg.r1,
        r2: msg.r2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      hata_turn_x: msg.hata_turn_x,
      hata_turn_y: msg.hata_turn_y,
      hata_turn_theta: msg.hata_turn_theta,
      baketu_turn_x: msg.baketu_turn_x,
      baketu_turn_y: msg.baketu_turn_y,
      baketu_turn_theta: msg.baketu_turn_theta,
      hoju_turn_x: msg.hoju_turn_x,
      hoju_turn_y: msg.hoju_turn_y,
      hoju_turn_theta: msg.hoju_turn_theta,
      hata_speed: msg.hata_speed,
      baketu_speed: msg.baketu_speed,
        fieldcolor: msg.fieldcolor.as_str().into(),
      dengen: msg.dengen,
        mode: msg.mode.as_str().into(),
        column1: msg.column1.as_str().into(),
        column2: msg.column2.as_str().into(),
        column3: msg.column3.as_str().into(),
      execute: msg.execute,
      refill: msg.refill,
      reload1: msg.reload1,
      reload2: msg.reload2,
      reload3: msg.reload3,
      firehata: msg.firehata,
      firebaketu: msg.firebaketu,
      hojuposition: msg.hojuposition,
      left: msg.left,
      right: msg.right,
      up: msg.up,
      down: msg.down,
      circle: msg.circle,
      triangle: msg.triangle,
      square: msg.square,
      cross: msg.cross,
      l1: msg.l1,
      l2: msg.l2,
      r1: msg.r1,
      r2: msg.r2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      hata_turn_x: msg.hata_turn_x,
      hata_turn_y: msg.hata_turn_y,
      hata_turn_theta: msg.hata_turn_theta,
      baketu_turn_x: msg.baketu_turn_x,
      baketu_turn_y: msg.baketu_turn_y,
      baketu_turn_theta: msg.baketu_turn_theta,
      hoju_turn_x: msg.hoju_turn_x,
      hoju_turn_y: msg.hoju_turn_y,
      hoju_turn_theta: msg.hoju_turn_theta,
      hata_speed: msg.hata_speed,
      baketu_speed: msg.baketu_speed,
      fieldcolor: msg.fieldcolor.to_string(),
      dengen: msg.dengen,
      mode: msg.mode.to_string(),
      column1: msg.column1.to_string(),
      column2: msg.column2.to_string(),
      column3: msg.column3.to_string(),
      execute: msg.execute,
      refill: msg.refill,
      reload1: msg.reload1,
      reload2: msg.reload2,
      reload3: msg.reload3,
      firehata: msg.firehata,
      firebaketu: msg.firebaketu,
      hojuposition: msg.hojuposition,
      left: msg.left,
      right: msg.right,
      up: msg.up,
      down: msg.down,
      circle: msg.circle,
      triangle: msg.triangle,
      square: msg.square,
      cross: msg.cross,
      l1: msg.l1,
      l2: msg.l2,
      r1: msg.r1,
      r2: msg.r2,
    }
  }
}


