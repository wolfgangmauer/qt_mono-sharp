using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Event
	{
		public enum EventType
		{
			/*
		          If you get a strange compiler error on the line with None,
		          it's probably because you're also including X11 headers,
		          which #define the symbol None. Put the X11 includes after
		          the Qt includes to solve this problem.
		        */
			None = 0,
			// invalid event
			Timer = 1,
			// timer event
			MouseButtonPress = 2,
			// mouse button pressed
			MouseButtonRelease = 3,
			// mouse button released
			MouseButtonDblClick = 4,
			// mouse button double click
			MouseMove = 5,
			// mouse move
			KeyPress = 6,
			// key pressed
			KeyRelease = 7,
			// key released
			FocusIn = 8,
			// keyboard focus received
			FocusOut = 9,
			// keyboard focus lost
			FocusAboutToChange = 23,
			// keyboard focus is about to be lost
			Enter = 10,
			// mouse enters widget
			Leave = 11,
			// mouse leaves widget
			Paint = 12,
			// paint widget
			Move = 13,
			// move widget
			Resize = 14,
			// resize widget
			Create = 15,
			// after widget creation
			Destroy = 16,
			// during widget destruction
			Show = 17,
			// widget is shown
			Hide = 18,
			// widget is hidden
			Close = 19,
			// request to close widget
			Quit = 20,
			// request to quit application
			ParentChange = 21,
			// widget has been reparented
			ParentAboutToChange = 131,
			// sent just before the parent change is done
			ThreadChange = 22,
			// object has changed threads
			WindowActivate = 24,
			// window was activated
			WindowDeactivate = 25,
			// window was deactivated
			ShowToParent = 26,
			// widget is shown to parent
			HideToParent = 27,
			// widget is hidden to parent
			Wheel = 31,
			// wheel event
			WindowTitleChange = 33,
			// window title changed
			WindowIconChange = 34,
			// icon changed
			ApplicationWindowIconChange = 35,
			// application icon changed
			ApplicationFontChange = 36,
			// application font changed
			ApplicationLayoutDirectionChange = 37,
			// application layout direction changed
			ApplicationPaletteChange = 38,
			// application palette changed
			PaletteChange = 39,
			// widget palette changed
			Clipboard = 40,
			// internal clipboard event
			Speech = 42,
			// reserved for speech input
			MetaCall = 43,
			// meta call event
			SockAct = 50,
			// socket activation
			WinEventAct = 132,
			// win event activation
			DeferredDelete = 52,
			// deferred delete event
			DragEnter = 60,
			// drag moves into widget
			DragMove = 61,
			// drag moves in widget
			DragLeave = 62,
			// drag leaves or is cancelled
			Drop = 63,
			// actual drop
			DragResponse = 64,
			// drag accepted/rejected
			ChildAdded = 68,
			// new child widget
			ChildPolished = 69,
			// polished child widget
			ChildRemoved = 71,
			// deleted child widget
			ShowWindowRequest = 73,
			// widget's window should be mapped
			PolishRequest = 74,
			// widget should be polished
			Polish = 75,
			// widget is polished
			LayoutRequest = 76,
			// widget should be relayouted
			UpdateRequest = 77,
			// widget should be repainted
			UpdateLater = 78,
			// request update() later

			EmbeddingControl = 79,
			// ActiveX embedding
			ActivateControl = 80,
			// ActiveX activation
			DeactivateControl = 81,
			// ActiveX deactivation
			ContextMenu = 82,
			// context popup menu
			InputMethod = 83,
			// input method
			TabletMove = 87,
			// Wacom tablet event
			LocaleChange = 88,
			// the system locale changed
			LanguageChange = 89,
			// the application language changed
			LayoutDirectionChange = 90,
			// the layout direction changed
			Style = 91,
			// internal style event
			TabletPress = 92,
			// tablet press
			TabletRelease = 93,
			// tablet release
			OkRequest = 94,
			// CE (Ok) button pressed
			HelpRequest = 95,
			// CE (?)  button pressed

			IconDrag = 96,
			// proxy icon dragged

			FontChange = 97,
			// font has changed
			EnabledChange = 98,
			// enabled state has changed
			ActivationChange = 99,
			// window activation has changed
			StyleChange = 100,
			// style has changed
			IconTextChange = 101,
			// icon text has changed.  Deprecated.
			ModifiedChange = 102,
			// modified state has changed
			MouseTrackingChange = 109,
			// mouse tracking state has changed

			WindowBlocked = 103,
			// window is about to be blocked modally
			WindowUnblocked = 104,
			// windows modal blocking has ended
			WindowStateChange = 105,

			ReadOnlyChange = 106,
			// readonly state has changed

			ToolTip = 110,
			WhatsThis = 111,
			StatusTip = 112,

			ActionChanged = 113,
			ActionAdded = 114,
			ActionRemoved = 115,

			FileOpen = 116,
			// file open request

			Shortcut = 117,
			// shortcut triggered
			ShortcutOverride = 51,
			// shortcut override request

			WhatsThisClicked = 118,

			ToolBarChange = 120,
			// toolbar visibility toggled

			ApplicationActivate = 121,
			// deprecated. Use ApplicationStateChange instead.
			ApplicationActivated = ApplicationActivate,
			// deprecated
			ApplicationDeactivate = 122,
			// deprecated. Use ApplicationStateChange instead.
			ApplicationDeactivated = ApplicationDeactivate,
			// deprecated

			QueryWhatsThis = 123,
			// query what's this widget help
			EnterWhatsThisMode = 124,
			LeaveWhatsThisMode = 125,

			ZOrderChange = 126,
			// child widget has had its z-order changed

			HoverEnter = 127,
			// mouse cursor enters a hover widget
			HoverLeave = 128,
			// mouse cursor leaves a hover widget
			HoverMove = 129,
			// mouse cursor move inside a hover widget

			// last event id used = 132

			EnterEditFocus = 150,
			// enter edit mode in keypad navigation
			LeaveEditFocus = 151,
			// enter edit mode in keypad navigation
			AcceptDropsChange = 152,

			ZeroTimerEvent = 154,
			// Used for Windows Zero timer events

			GraphicsSceneMouseMove = 155,
			// GraphicsView
			GraphicsSceneMousePress = 156,
			GraphicsSceneMouseRelease = 157,
			GraphicsSceneMouseDoubleClick = 158,
			GraphicsSceneContextMenu = 159,
			GraphicsSceneHoverEnter = 160,
			GraphicsSceneHoverMove = 161,
			GraphicsSceneHoverLeave = 162,
			GraphicsSceneHelp = 163,
			GraphicsSceneDragEnter = 164,
			GraphicsSceneDragMove = 165,
			GraphicsSceneDragLeave = 166,
			GraphicsSceneDrop = 167,
			GraphicsSceneWheel = 168,

			KeyboardLayoutChange = 169,
			// keyboard layout changed

			DynamicPropertyChange = 170,
			// A dynamic property was changed through setProperty/property

			TabletEnterProximity = 171,
			TabletLeaveProximity = 172,

			NonClientAreaMouseMove = 173,
			NonClientAreaMouseButtonPress = 174,
			NonClientAreaMouseButtonRelease = 175,
			NonClientAreaMouseButtonDblClick = 176,

			MacSizeChange = 177,
			// when the Qt::WA_Mac{Normal,Small,Mini}Size changes

			ContentsRectChange = 178,
			// sent by QWidget::setContentsMargins (internal)

			MacGLWindowChange = 179,
			// Internal! the window of the GLWidget has changed

			FutureCallOut = 180,

			GraphicsSceneResize = 181,
			GraphicsSceneMove = 182,

			CursorChange = 183,
			ToolTipChange = 184,

			NetworkReplyUpdated = 185,
			// Internal for QNetworkReply

			GrabMouse = 186,
			UngrabMouse = 187,
			GrabKeyboard = 188,
			UngrabKeyboard = 189,
			MacGLClearDrawable = 191,
			// Internal Cocoa, the window has changed, so we must clear

			StateMachineSignal = 192,
			StateMachineWrapped = 193,

			TouchBegin = 194,
			TouchUpdate = 195,
			TouchEnd = 196,

			NativeGesture = 197,
			// QtGui native gesture

			RequestSoftwareInputPanel = 199,
			CloseSoftwareInputPanel = 200,

			WinIdChange = 203,
			Gesture = 198,
			GestureOverride = 202,
			ScrollPrepare = 204,
			Scroll = 205,

			Expose = 206,

			InputMethodQuery = 207,
			OrientationChange = 208,
			// Screen orientation has changed

			TouchCancel = 209,

			ThemeChange = 210,

			SockClose = 211,
			// socket closed

			PlatformPanel = 212,

			StyleAnimationUpdate = 213,
			// style animation target should be updated
			ApplicationStateChange = 214,

			WindowChangeInternal = 215,
			// internal for QQuickWidget
			ScreenChangeInternal = 216,

			PlatformSurface = 217,
			// Platform surface created or about to be destroyed

			Pointer = 218,
			// QQuickPointerEvent; ### Qt 6: QPointerEvent

			// 512 reserved for Qt Jambi's MetaCall event
			// 513 reserved for Qt Jambi's DeleteOnMainThread event

			User = 1000,
			// first user event id
			MaxUser = 65535
			// last user event id
		}

		public IntPtr Handle { get; protected set;}

		protected Event (IntPtr raw)
		{
			Handle = raw;
		}

		public void Accept ()
		{
			Accepted = true;
		}

		public void Ignore ()
		{
			Accepted = false;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern EventType qt_event_type_get(IntPtr raw);
		public EventType Type
		{
			get{ return qt_event_type_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern bool qt_event_spontaneous_get(IntPtr raw);
		public bool Spontaneous
		{
			get { return qt_event_spontaneous_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern bool qt_event_accepted_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_event_accepted_set(IntPtr raw, bool accepted);
		public bool Accepted
		{
			get { return qt_event_accepted_get (Handle); }
			set { qt_event_accepted_set (Handle, value); }
		}
	}

	public class CloseEvent : Event
	{
		protected CloseEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class ShowEvent : Event
	{
		protected ShowEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class HideEvent : Event
	{
		protected HideEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class DropEvent : Event
	{
		protected DropEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class DragMoveEvent : DropEvent
	{
		protected DragMoveEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class DragEnterEvent : DragMoveEvent
	{
		protected DragEnterEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class InputEvent : Event
	{
		protected InputEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern UInt64 qt_inputevent_timestamp_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_inputevent_timestamp_set(IntPtr raw, UInt64 timestamp);
		public UInt64 Timestamp
		{
			get { return qt_inputevent_timestamp_get (Handle); }
			set { qt_inputevent_timestamp_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern KeyboardModifier qt_inputevent_modifiers_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_inputevent_modifiers_set(IntPtr raw, KeyboardModifier modifier);
		public KeyboardModifier Modifiers
		{
			get { return qt_inputevent_modifiers_get (Handle); }
			set { qt_inputevent_modifiers_set (Handle, value); }
		}
	}

	public class TabletEvent : InputEvent
	{
		protected TabletEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class ActionEvent : Event
	{
		protected ActionEvent (IntPtr raw) : base (raw)
		{
		}
	}

	public class ContextMenuEvent : InputEvent
	{
		public enum ReasonEnum
		{
			Mouse,
			Keyboard,
			Other
		}
		protected ContextMenuEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern ReasonEnum qt_contextmenuevent_reason_get(IntPtr raw);
		public ReasonEnum Reason
		{
			get{ return qt_contextmenuevent_reason_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_contextmenuevent_pos_get(IntPtr raw);
		public Point Pos
		{
			get{ return new Point(qt_contextmenuevent_pos_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_contextmenuevent_globalpos_get(IntPtr raw);
		public Point GlobalPos
		{
			get{ return new Point(qt_contextmenuevent_globalpos_get (Handle)); }
		}
	}

	public class ResizeEvent : Event
	{
		protected ResizeEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_resizeevent_size_get(IntPtr raw);
		public Size Size 
		{
			get{ return new Size(qt_resizeevent_size_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_resizeevent_oldsize_get(IntPtr raw);
		public Size OldSize 
		{
			get{ return new Size(qt_resizeevent_oldsize_get (Handle)); }
		}
	}

	public class MoveEvent : Event
	{
		protected MoveEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_moveevent_pos_get(IntPtr raw);
		public Point Pos 
		{
			get{ return new Point(qt_moveevent_pos_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_moveevent_oldpos_get(IntPtr raw);
		public Point OldPos
		{
			get{ return new Point(qt_moveevent_oldpos_get (Handle)); }
		}
	}

	public class PaintEvent : Event
	{
		protected PaintEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_paintevent_rect_get(IntPtr raw);
		public Rectangle Rect
		{
			get{ return new Rectangle(qt_paintevent_rect_get (Handle)); }
		}
	}

	public class FocusEvent : Event
	{
		protected FocusEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern FocusReason qt_focusevent_reason_get(IntPtr raw);
		public FocusReason Reason
		{
			get{ return qt_focusevent_reason_get (Handle); }
		}
	}

	public class WheelEvent : InputEvent
	{
		protected WheelEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern bool qt_wheelevent_inverted_get(IntPtr raw);
		public bool Inverted
		{
			get{ return qt_wheelevent_inverted_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern ScrollPhase qt_wheelevent_phase_get(IntPtr raw);
		public ScrollPhase Phase
		{
			get{ return qt_wheelevent_phase_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_wheelevent_delta_get(IntPtr raw);
		public int Delta
		{
			get{ return qt_wheelevent_delta_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Orientation qt_wheelevent_orientation_get(IntPtr raw);
		public Orientation Orientation
		{
			get{ return qt_wheelevent_orientation_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseEventSource qt_wheelevent_source_get(IntPtr raw);
		public MouseEventSource Source
		{
			get{ return qt_wheelevent_source_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_wheelevent_pixeldelta_get(IntPtr raw);
		public PointF PixelDelta
		{
			get{ return new PointF(qt_wheelevent_pixeldelta_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_wheelevent_angledelta_get(IntPtr raw);
		public PointF AngleDelta
		{
			get{ return new PointF(qt_wheelevent_angledelta_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_wheelevent_posf_get(IntPtr raw);
		public PointF PosF
		{
			get{ return new PointF(qt_wheelevent_posf_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_wheelevent_globalposf_get(IntPtr raw);
		public PointF GlobalPosF
		{
			get{ return new PointF(qt_wheelevent_globalposf_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseButton qt_wheelevent_buttons_get(IntPtr raw);
		public MouseButton Buttons
		{
			get{ return qt_wheelevent_buttons_get (Handle); }
		}
	}

	public class MouseEvent : InputEvent
	{
		protected MouseEvent (IntPtr raw) : base (raw)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseEventSource qt_mouseevent_source_get(IntPtr raw);
		public MouseEventSource Source
		{
			get{ return qt_mouseevent_source_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseEventFlag qt_mouseevent_flags_get(IntPtr raw);
		public MouseEventFlag Flags
		{
			get{ return qt_mouseevent_flags_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseButton qt_mouseevent_button_get(IntPtr raw);
		public MouseButton Button
		{
			get{ return qt_mouseevent_button_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern MouseButton qt_mouseevent_buttons_get(IntPtr raw);
		public MouseButton Buttons
		{
			get{ return qt_mouseevent_buttons_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mouseevent_localpos_get(IntPtr raw);
		public PointF LocalPos
		{
			get{ return new PointF(qt_mouseevent_localpos_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mouseevent_windowpos_get(IntPtr raw);
		public PointF WindowPos
		{
			get{ return new PointF(qt_mouseevent_windowpos_get (Handle)); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mouseevent_screenpos_get(IntPtr raw);
		public PointF ScreenPos
		{
			get{ return new PointF(qt_mouseevent_screenpos_get (Handle)); }
		}
	}

	public class KeyEvent : InputEvent
	{
		protected KeyEvent (IntPtr raw) : base (raw)
		{
		}


		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_keyevent_new(EventType type, int key, KeyboardModifier modifiers, string text, bool autorep, ushort count);
		public KeyEvent(EventType type, int key, KeyboardModifier modifiers, string text = "", bool autorep = false, ushort count = 1)
			: base(IntPtr.Zero)
		{
			Handle = qt_keyevent_new (type, key, modifiers, text, autorep, count);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_keyevent_native_new(EventType type, int key, KeyboardModifier modifiers, UInt32 nativeScanCode, UInt32 nativeVirtualKey, UInt32 nativeModifiers, string text, bool autorep, ushort count);
		public KeyEvent (EventType type, int key, KeyboardModifier modifiers, UInt32 nativeScanCode, UInt32 nativeVirtualKey, UInt32 nativeModifiers, string text = "", bool autorep = false, ushort count = 1)
			: base(IntPtr.Zero)
		{
			Handle = qt_keyevent_native_new (type, key, modifiers, nativeScanCode, nativeVirtualKey, nativeModifiers, text, autorep, count);
		}
				
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern UInt32 qt_keyevent_nativescancode_get(IntPtr raw);
		public UInt32 NativeScanCode
		{
			get{ return qt_keyevent_nativescancode_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern UInt32 qt_keyevent_nativevirtualkey_get(IntPtr raw);
		public UInt32 NativeVirtualKey
		{ 
			get{ return qt_keyevent_nativevirtualkey_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern UInt32 qt_keyevent_nativemodifiers_get(IntPtr raw);
		public UInt32 NativeModifiers
		{ 
			get{ return qt_keyevent_nativemodifiers_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_keyevent_key_get(IntPtr raw);
		public int Key
		{ 
			get{ return qt_keyevent_key_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern string qt_keyevent_text_get(IntPtr raw);
		public string Text
		{
			get{ return qt_keyevent_text_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern bool qt_keyevent_autorepeat_get(IntPtr raw);
		public bool AutoRepeat
		{
			get{ return qt_keyevent_autorepeat_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_keyevent_count_get(IntPtr raw);
		public int Count
		{
			get{ return qt_keyevent_count_get (Handle); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern KeyboardModifier qt_keyevent_modifiers_get(IntPtr raw);
		public new KeyboardModifier Modifiers
		{
			get { return qt_keyevent_modifiers_get (Handle); }
		}
	}
}