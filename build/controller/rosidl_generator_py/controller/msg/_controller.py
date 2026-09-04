# generated from rosidl_generator_py/resource/_idl.py.em
# with input from controller:msg/Controller.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Controller(type):
    """Metaclass of message 'Controller'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'controller.msg.Controller')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__controller
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__controller
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__controller
            cls._TYPE_SUPPORT = module.type_support_msg__msg__controller
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__controller

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Controller(metaclass=Metaclass_Controller):
    """Message class 'Controller'."""

    __slots__ = [
        '_x',
        '_y',
        '_theta',
        '_hata_turn_x',
        '_hata_turn_y',
        '_hata_turn_theta',
        '_baketu_turn_x',
        '_baketu_turn_y',
        '_baketu_turn_theta',
        '_hoju_turn_x',
        '_hoju_turn_y',
        '_hoju_turn_theta',
        '_hata_speed',
        '_baketu_speed',
        '_fieldcolor',
        '_dengen',
        '_mode',
        '_column1',
        '_column2',
        '_column3',
        '_execute',
        '_refill',
        '_reload1',
        '_reload2',
        '_reload3',
        '_firehata',
        '_firebaketu',
        '_hojuposition',
        '_left',
        '_right',
        '_up',
        '_down',
        '_circle',
        '_triangle',
        '_square',
        '_cross',
        '_l1',
        '_l2',
        '_r1',
        '_r2',
    ]

    _fields_and_field_types = {
        'x': 'float',
        'y': 'float',
        'theta': 'float',
        'hata_turn_x': 'float',
        'hata_turn_y': 'float',
        'hata_turn_theta': 'float',
        'baketu_turn_x': 'float',
        'baketu_turn_y': 'float',
        'baketu_turn_theta': 'float',
        'hoju_turn_x': 'float',
        'hoju_turn_y': 'float',
        'hoju_turn_theta': 'float',
        'hata_speed': 'float',
        'baketu_speed': 'float',
        'fieldcolor': 'string',
        'dengen': 'boolean',
        'mode': 'string',
        'column1': 'string',
        'column2': 'string',
        'column3': 'string',
        'execute': 'boolean',
        'refill': 'boolean',
        'reload1': 'boolean',
        'reload2': 'boolean',
        'reload3': 'boolean',
        'firehata': 'boolean',
        'firebaketu': 'boolean',
        'hojuposition': 'boolean',
        'left': 'boolean',
        'right': 'boolean',
        'up': 'boolean',
        'down': 'boolean',
        'circle': 'boolean',
        'triangle': 'boolean',
        'square': 'boolean',
        'cross': 'boolean',
        'l1': 'boolean',
        'l2': 'boolean',
        'r1': 'boolean',
        'r2': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.theta = kwargs.get('theta', float())
        self.hata_turn_x = kwargs.get('hata_turn_x', float())
        self.hata_turn_y = kwargs.get('hata_turn_y', float())
        self.hata_turn_theta = kwargs.get('hata_turn_theta', float())
        self.baketu_turn_x = kwargs.get('baketu_turn_x', float())
        self.baketu_turn_y = kwargs.get('baketu_turn_y', float())
        self.baketu_turn_theta = kwargs.get('baketu_turn_theta', float())
        self.hoju_turn_x = kwargs.get('hoju_turn_x', float())
        self.hoju_turn_y = kwargs.get('hoju_turn_y', float())
        self.hoju_turn_theta = kwargs.get('hoju_turn_theta', float())
        self.hata_speed = kwargs.get('hata_speed', float())
        self.baketu_speed = kwargs.get('baketu_speed', float())
        self.fieldcolor = kwargs.get('fieldcolor', str())
        self.dengen = kwargs.get('dengen', bool())
        self.mode = kwargs.get('mode', str())
        self.column1 = kwargs.get('column1', str())
        self.column2 = kwargs.get('column2', str())
        self.column3 = kwargs.get('column3', str())
        self.execute = kwargs.get('execute', bool())
        self.refill = kwargs.get('refill', bool())
        self.reload1 = kwargs.get('reload1', bool())
        self.reload2 = kwargs.get('reload2', bool())
        self.reload3 = kwargs.get('reload3', bool())
        self.firehata = kwargs.get('firehata', bool())
        self.firebaketu = kwargs.get('firebaketu', bool())
        self.hojuposition = kwargs.get('hojuposition', bool())
        self.left = kwargs.get('left', bool())
        self.right = kwargs.get('right', bool())
        self.up = kwargs.get('up', bool())
        self.down = kwargs.get('down', bool())
        self.circle = kwargs.get('circle', bool())
        self.triangle = kwargs.get('triangle', bool())
        self.square = kwargs.get('square', bool())
        self.cross = kwargs.get('cross', bool())
        self.l1 = kwargs.get('l1', bool())
        self.l2 = kwargs.get('l2', bool())
        self.r1 = kwargs.get('r1', bool())
        self.r2 = kwargs.get('r2', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.theta != other.theta:
            return False
        if self.hata_turn_x != other.hata_turn_x:
            return False
        if self.hata_turn_y != other.hata_turn_y:
            return False
        if self.hata_turn_theta != other.hata_turn_theta:
            return False
        if self.baketu_turn_x != other.baketu_turn_x:
            return False
        if self.baketu_turn_y != other.baketu_turn_y:
            return False
        if self.baketu_turn_theta != other.baketu_turn_theta:
            return False
        if self.hoju_turn_x != other.hoju_turn_x:
            return False
        if self.hoju_turn_y != other.hoju_turn_y:
            return False
        if self.hoju_turn_theta != other.hoju_turn_theta:
            return False
        if self.hata_speed != other.hata_speed:
            return False
        if self.baketu_speed != other.baketu_speed:
            return False
        if self.fieldcolor != other.fieldcolor:
            return False
        if self.dengen != other.dengen:
            return False
        if self.mode != other.mode:
            return False
        if self.column1 != other.column1:
            return False
        if self.column2 != other.column2:
            return False
        if self.column3 != other.column3:
            return False
        if self.execute != other.execute:
            return False
        if self.refill != other.refill:
            return False
        if self.reload1 != other.reload1:
            return False
        if self.reload2 != other.reload2:
            return False
        if self.reload3 != other.reload3:
            return False
        if self.firehata != other.firehata:
            return False
        if self.firebaketu != other.firebaketu:
            return False
        if self.hojuposition != other.hojuposition:
            return False
        if self.left != other.left:
            return False
        if self.right != other.right:
            return False
        if self.up != other.up:
            return False
        if self.down != other.down:
            return False
        if self.circle != other.circle:
            return False
        if self.triangle != other.triangle:
            return False
        if self.square != other.square:
            return False
        if self.cross != other.cross:
            return False
        if self.l1 != other.l1:
            return False
        if self.l2 != other.l2:
            return False
        if self.r1 != other.r1:
            return False
        if self.r2 != other.r2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def theta(self):
        """Message field 'theta'."""
        return self._theta

    @theta.setter
    def theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'theta' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'theta' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._theta = value

    @builtins.property
    def hata_turn_x(self):
        """Message field 'hata_turn_x'."""
        return self._hata_turn_x

    @hata_turn_x.setter
    def hata_turn_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hata_turn_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hata_turn_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hata_turn_x = value

    @builtins.property
    def hata_turn_y(self):
        """Message field 'hata_turn_y'."""
        return self._hata_turn_y

    @hata_turn_y.setter
    def hata_turn_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hata_turn_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hata_turn_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hata_turn_y = value

    @builtins.property
    def hata_turn_theta(self):
        """Message field 'hata_turn_theta'."""
        return self._hata_turn_theta

    @hata_turn_theta.setter
    def hata_turn_theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hata_turn_theta' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hata_turn_theta' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hata_turn_theta = value

    @builtins.property
    def baketu_turn_x(self):
        """Message field 'baketu_turn_x'."""
        return self._baketu_turn_x

    @baketu_turn_x.setter
    def baketu_turn_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'baketu_turn_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'baketu_turn_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._baketu_turn_x = value

    @builtins.property
    def baketu_turn_y(self):
        """Message field 'baketu_turn_y'."""
        return self._baketu_turn_y

    @baketu_turn_y.setter
    def baketu_turn_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'baketu_turn_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'baketu_turn_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._baketu_turn_y = value

    @builtins.property
    def baketu_turn_theta(self):
        """Message field 'baketu_turn_theta'."""
        return self._baketu_turn_theta

    @baketu_turn_theta.setter
    def baketu_turn_theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'baketu_turn_theta' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'baketu_turn_theta' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._baketu_turn_theta = value

    @builtins.property
    def hoju_turn_x(self):
        """Message field 'hoju_turn_x'."""
        return self._hoju_turn_x

    @hoju_turn_x.setter
    def hoju_turn_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hoju_turn_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hoju_turn_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hoju_turn_x = value

    @builtins.property
    def hoju_turn_y(self):
        """Message field 'hoju_turn_y'."""
        return self._hoju_turn_y

    @hoju_turn_y.setter
    def hoju_turn_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hoju_turn_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hoju_turn_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hoju_turn_y = value

    @builtins.property
    def hoju_turn_theta(self):
        """Message field 'hoju_turn_theta'."""
        return self._hoju_turn_theta

    @hoju_turn_theta.setter
    def hoju_turn_theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hoju_turn_theta' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hoju_turn_theta' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hoju_turn_theta = value

    @builtins.property
    def hata_speed(self):
        """Message field 'hata_speed'."""
        return self._hata_speed

    @hata_speed.setter
    def hata_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hata_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hata_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hata_speed = value

    @builtins.property
    def baketu_speed(self):
        """Message field 'baketu_speed'."""
        return self._baketu_speed

    @baketu_speed.setter
    def baketu_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'baketu_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'baketu_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._baketu_speed = value

    @builtins.property
    def fieldcolor(self):
        """Message field 'fieldcolor'."""
        return self._fieldcolor

    @fieldcolor.setter
    def fieldcolor(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fieldcolor' field must be of type 'str'"
        self._fieldcolor = value

    @builtins.property
    def dengen(self):
        """Message field 'dengen'."""
        return self._dengen

    @dengen.setter
    def dengen(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dengen' field must be of type 'bool'"
        self._dengen = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mode' field must be of type 'str'"
        self._mode = value

    @builtins.property
    def column1(self):
        """Message field 'column1'."""
        return self._column1

    @column1.setter
    def column1(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'column1' field must be of type 'str'"
        self._column1 = value

    @builtins.property
    def column2(self):
        """Message field 'column2'."""
        return self._column2

    @column2.setter
    def column2(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'column2' field must be of type 'str'"
        self._column2 = value

    @builtins.property
    def column3(self):
        """Message field 'column3'."""
        return self._column3

    @column3.setter
    def column3(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'column3' field must be of type 'str'"
        self._column3 = value

    @builtins.property
    def execute(self):
        """Message field 'execute'."""
        return self._execute

    @execute.setter
    def execute(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'execute' field must be of type 'bool'"
        self._execute = value

    @builtins.property
    def refill(self):
        """Message field 'refill'."""
        return self._refill

    @refill.setter
    def refill(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'refill' field must be of type 'bool'"
        self._refill = value

    @builtins.property
    def reload1(self):
        """Message field 'reload1'."""
        return self._reload1

    @reload1.setter
    def reload1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reload1' field must be of type 'bool'"
        self._reload1 = value

    @builtins.property
    def reload2(self):
        """Message field 'reload2'."""
        return self._reload2

    @reload2.setter
    def reload2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reload2' field must be of type 'bool'"
        self._reload2 = value

    @builtins.property
    def reload3(self):
        """Message field 'reload3'."""
        return self._reload3

    @reload3.setter
    def reload3(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reload3' field must be of type 'bool'"
        self._reload3 = value

    @builtins.property
    def firehata(self):
        """Message field 'firehata'."""
        return self._firehata

    @firehata.setter
    def firehata(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'firehata' field must be of type 'bool'"
        self._firehata = value

    @builtins.property
    def firebaketu(self):
        """Message field 'firebaketu'."""
        return self._firebaketu

    @firebaketu.setter
    def firebaketu(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'firebaketu' field must be of type 'bool'"
        self._firebaketu = value

    @builtins.property
    def hojuposition(self):
        """Message field 'hojuposition'."""
        return self._hojuposition

    @hojuposition.setter
    def hojuposition(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hojuposition' field must be of type 'bool'"
        self._hojuposition = value

    @builtins.property
    def left(self):
        """Message field 'left'."""
        return self._left

    @left.setter
    def left(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left' field must be of type 'bool'"
        self._left = value

    @builtins.property
    def right(self):
        """Message field 'right'."""
        return self._right

    @right.setter
    def right(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right' field must be of type 'bool'"
        self._right = value

    @builtins.property
    def up(self):
        """Message field 'up'."""
        return self._up

    @up.setter
    def up(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'up' field must be of type 'bool'"
        self._up = value

    @builtins.property
    def down(self):
        """Message field 'down'."""
        return self._down

    @down.setter
    def down(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'down' field must be of type 'bool'"
        self._down = value

    @builtins.property
    def circle(self):
        """Message field 'circle'."""
        return self._circle

    @circle.setter
    def circle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'circle' field must be of type 'bool'"
        self._circle = value

    @builtins.property
    def triangle(self):
        """Message field 'triangle'."""
        return self._triangle

    @triangle.setter
    def triangle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'triangle' field must be of type 'bool'"
        self._triangle = value

    @builtins.property
    def square(self):
        """Message field 'square'."""
        return self._square

    @square.setter
    def square(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'square' field must be of type 'bool'"
        self._square = value

    @builtins.property
    def cross(self):
        """Message field 'cross'."""
        return self._cross

    @cross.setter
    def cross(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cross' field must be of type 'bool'"
        self._cross = value

    @builtins.property
    def l1(self):
        """Message field 'l1'."""
        return self._l1

    @l1.setter
    def l1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'l1' field must be of type 'bool'"
        self._l1 = value

    @builtins.property
    def l2(self):
        """Message field 'l2'."""
        return self._l2

    @l2.setter
    def l2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'l2' field must be of type 'bool'"
        self._l2 = value

    @builtins.property
    def r1(self):
        """Message field 'r1'."""
        return self._r1

    @r1.setter
    def r1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'r1' field must be of type 'bool'"
        self._r1 = value

    @builtins.property
    def r2(self):
        """Message field 'r2'."""
        return self._r2

    @r2.setter
    def r2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'r2' field must be of type 'bool'"
        self._r2 = value
