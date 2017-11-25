using System;
using System.Xml.Serialization;

namespace Qt
{
	[Flags]
	public enum KeyboardModifier : uint
	{
		NoModifier           = 0x00000000,
		ShiftModifier        = 0x02000000,
		ControlModifier      = 0x04000000,
		AltModifier          = 0x08000000,
		MetaModifier         = 0x10000000,
		KeypadModifier       = 0x20000000,
		GroupSwitchModifier  = 0x40000000,
		// Do not extend the mask to include 0x01000000
		KeyboardModifierMask = 0xfe000000
	}

    [Flags]
	public enum TextInteraction : uint
    {
        NoTextInteraction = 0,
        TextSelectableByMouse = 1,
        TextSelectableByKeyboard = 2,
        LinksAccessibleByMouse = 4,
        LinksAccessibleByKeyboard = 8,
        TextEditable = 16,
        TextEditorInteraction = TextSelectableByMouse | TextSelectableByKeyboard | TextEditable,
        TextBrowserInteraction = TextSelectableByMouse | LinksAccessibleByMouse | LinksAccessibleByKeyboard
    }

	public enum Orientation
	{
		[XmlEnum("Qt::Horizontal")]
		Horizontal = 0x1,
		[XmlEnum("Qt::Vertical")]
		Vertical = 0x2
	}

	public enum TextInteractionFlags 
	{
		[XmlEnum("Qt::NoTextInteraction")]
		NoTextInteraction         = 0,
		[XmlEnum("Qt::TextSelectableByMouse")]
		TextSelectableByMouse     = 1,
		[XmlEnum("Qt::TextSelectableByKeyboard")]
		TextSelectableByKeyboard  = 2,
		[XmlEnum("Qt::LinksAccessibleByMouse")]
		LinksAccessibleByMouse    = 4,
		[XmlEnum("Qt::LinksAccessibleByKeyboard")]
		LinksAccessibleByKeyboard = 8,
		[XmlEnum("Qt::TextEditable")]
		TextEditable              = 16,
		[XmlEnum("Qt::TextEditorInteraction")]
		TextEditorInteraction     = TextSelectableByMouse | TextSelectableByKeyboard | TextEditable,
		[XmlEnum("Qt::TextBrowserInteraction")]
		TextBrowserInteraction    = TextSelectableByMouse | LinksAccessibleByMouse | LinksAccessibleByKeyboard
	}

    [Flags]
	public enum Alignment
    {
		[XmlEnum("Qt::AlignLeft")]
        AlignLeft = 0x0001,
		[XmlEnum("Qt::AlignLeading")]
        AlignLeading = AlignLeft,
        AlignRight = 0x0002,
        AlignTrailing = AlignRight,
        AlignHCenter = 0x0004,
        AlignJustify = 0x0008,
        AlignAbsolute = 0x0010,
        AlignHorizontal_Mask = AlignLeft | AlignRight | AlignHCenter | AlignJustify | AlignAbsolute,

		[XmlEnum("Qt::AlignTop")]
        AlignTop = 0x0020,
        AlignBottom = 0x0040,
        AlignVCenter = 0x0080,
        AlignBaseline = 0x0100,
        // Note that 0x100 will clash with Qt::TextSingleLine = 0x100 due to what the comment above
        // this enum declaration states. However, since Qt::AlignBaseline is only used by layouts,
        // it doesn't make sense to pass Qt::AlignBaseline to QPainter::drawText(), so there
        // shouldn't really be any ambiguity between the two overlapping enum values.
        AlignVertical_Mask = AlignTop | AlignBottom | AlignVCenter | AlignBaseline,

		[XmlEnum("Qt::AlignCenter")]
        AlignCenter = AlignVCenter | AlignHCenter
    }

	public enum ContextMenuPolicy : uint
    {
		[XmlEnum("Qt::NoContextMenu")]
        NoContextMenu,
		[XmlEnum("Qt::DefaultContextMenu")]
        DefaultContextMenu,
		[XmlEnum("Qt::ActionsContextMenu")]
        ActionsContextMenu,
		[XmlEnum("Qt::CustomContextMenu")]
        CustomContextMenu,
		[XmlEnum("Qt::PreventContextMenu")]
        PreventContextMenu
    }

	public enum Direction
	{
		LeftToRight,
		RightToLeft,
		TopToBottom,
		BottomToTop,
		Down = TopToBottom,
		Up = BottomToTop
	};

	public enum TextFormat
	{
		[XmlEnum("Qt::PlainText")]
		PlainText,
		[XmlEnum("Qt::RichText")]
		RichText,
		[XmlEnum("Qt::AutoText")]
		AutoText,
		[XmlEnum("Qt::LogText")]
		LogText
	}

	public enum SizeConstraint
	{
		[XmlEnum("QLayout::SetDefaultConstraint")]
		SetDefaultConstraint,
		[XmlEnum("QLayout::SetNoConstraint")]
		SetNoConstraint,
		[XmlEnum("QLayout::SetMinimumSize")]
		SetMinimumSize,
		[XmlEnum("QLayout::SetFixedSize")]
		SetFixedSize,
		[XmlEnum("QLayout::SetMaximumSize")]
		SetMaximumSize,
		[XmlEnum("QLayout::SetMinAndMaxSize")]
		SetMinAndMaxSize
	}

	public enum FocusPolicy : uint
    {
		[XmlEnum("Qt::NoFocus")]
        NoFocus = 0,
		[XmlEnum("Qt::TabFocus")]
        TabFocus = 0x1,
		[XmlEnum("Qt::ClickFocus")]
        ClickFocus = 0x2,
		[XmlEnum("Qt::StrongFocus")]
        StrongFocus = TabFocus | ClickFocus | 0x8,
		[XmlEnum("Qt::WheelFocus")]
        WheelFocus = StrongFocus | 0x4
    }

    [Flags]
	public enum ItemFlags : uint
	{
		NoItemFlags = 0,
		ItemIsSelectable = 1,
		ItemIsEditable = 2,
		ItemIsDragEnabled = 4,
		ItemIsDropEnabled = 8,
		ItemIsUserCheckable = 16,
		ItemIsEnabled = 32,
		ItemIsAutoTristate = 64,
		ItemNeverHasChildren = 128,
		ItemIsUserTristate = 256
	}

	public enum Key : uint
	{
		Key_AX51_1 = 49,
		Key_AX51_2 = 50,
		Key_AX51_3 = 51,
		Key_AX51_4 = 52,
		Key_AX51_5 = 53,
		Key_AX51_6 = 54,
		Key_AX51_7 = 55,
		Key_AX51_8 = 56,
		Key_AX51_9 = 57,
		Key_AX51_0 = 48,
		Key_AX51_Menu = 139,
		Key_AX51_Sleep = 142,
		Key_AX51_TV = 377,
		Key_AX51_Radio = 385,
		Key_AX51_Audio = 392,
		Key_AX51_Subtitle = 370,
		Key_AX51_Teletext = 388,
		Key_AX51_Help = 138,
		Key_AX51_Info = 16777499,
		Key_AX51_Red = 16777492,
		Key_AX51_Green = 16777493,
		Key_AX51_Yellow = 16777494,
		Key_AX51_Blue = 16777495,
		Key_AX51_PAD_Up = 16777235,
		Key_AX51_PAD_Left = 16777234,
		Key_AX51_PAD_Ok = 352,
		Key_AX51_PAD_Right = 16777236,
		Key_AX51_PAD_Down = 16777237,
		Key_AX51_Exit = 16908298,
		Key_AX51_Epg = 365,
		Key_AX51_Right = 407,
		Key_AX51_Left = 412,
		Key_AX51_Volume_Up = 16777330,
		Key_AX51_Volume_Down = 16777328,
		Key_AX51_Channel_Up = 16777496,
		Key_AX51_Channel_Down = 16777497,
		Key_AX51_Context = 156,
		Key_AX51_List = 393,
		Key_AX51_Skip_Rewind = 165,
		Key_AX51_Skip_Forward = 163,
		Key_AX51_Fast_Rewind = 16777413,
		Key_AX51_Fast_Forward = 16777474,
		Key_AX51_Stop = 16777315,
		Key_AX51_TogglePlay = 16777350,
		Key_AX51_Record = 16777348,
		Key_AX51_Timer = 16777498,
		Key_AX51_Mute = 16777329,
		Key_AX51_Power = 16777399
	}

	public enum EventType : uint
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

	public enum ApplicationAttribute : uint
	{
		AA_DontShowIconsInMenus = 2,
		AA_NativeWindows,
		AA_DontCreateNativeWidgetSiblings,
		AA_PluginApplication,
		AA_DontUseNativeMenuBar,
		AA_UseOpenGLES = 16,
		AA_EnableHighDpiScaling = 20
	}

	public enum WidgetAttribute : uint
	{
		WA_TranslucentBackground = 120,
	}

	public enum WindowModality : uint
    {
		[XmlEnum("Qt::NonModal")]
        NonModal,
		[XmlEnum("Qt::WindowModal")]
        WindowModal,
		[XmlEnum("Qt::ApplicationModal")]
        ApplicationModal
    }

	public enum WindowType : uint
	{
		Window = 0x00000001,
		Dialog = 0x00000002 | Window,
		Popup = 0x00000008 | Window,
		Tool = Popup | Dialog,
		FramelessWindowHint = 0x00000800,
		WindowStaysOnTopHint = 0x00040000
	}
}