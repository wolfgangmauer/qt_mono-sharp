﻿using System;
using System.Xml.Serialization;

namespace Qt
{
	public enum FocusReason : uint
	{
		MouseFocusReason,
		TabFocusReason,
		BacktabFocusReason,
		ActiveWindowFocusReason,
		PopupFocusReason,
		ShortcutFocusReason,
		MenuBarFocusReason,
		OtherFocusReason,
		NoFocusReason
	}

	[Flags]
	public enum DropActions : uint
	{
		CopyAction = 0x1,
		MoveAction = 0x2,
		LinkAction = 0x4,
		ActionMask = 0xff,
		TargetMoveAction = 0x8002,
		IgnoreAction = 0x0
	}

	[Flags]
	public enum KeyboardModifier : uint
	{
		NoModifier = 0x00000000,
		ShiftModifier = 0x02000000,
		ControlModifier = 0x04000000,
		AltModifier = 0x08000000,
		MetaModifier = 0x10000000,
		KeypadModifier = 0x20000000,
		GroupSwitchModifier = 0x40000000,
		// Do not extend the mask to include 0x01000000
		KeyboardModifierMask = 0xfe000000
	}

	[Flags]
	public enum MouseButton : uint
	{
		NoButton = 0x00000000,
		LeftButton = 0x00000001,
		RightButton = 0x00000002,
		MidButton = 0x00000004,
		// ### Qt 6: remove me
		MiddleButton = MidButton,
		BackButton = 0x00000008,
		XButton1 = BackButton,
		ExtraButton1 = XButton1,
		ForwardButton = 0x00000010,
		XButton2 = ForwardButton,
		ExtraButton2 = ForwardButton,
		TaskButton = 0x00000020,
		ExtraButton3 = TaskButton,
		ExtraButton4 = 0x00000040,
		ExtraButton5 = 0x00000080,
		ExtraButton6 = 0x00000100,
		ExtraButton7 = 0x00000200,
		ExtraButton8 = 0x00000400,
		ExtraButton9 = 0x00000800,
		ExtraButton10 = 0x00001000,
		ExtraButton11 = 0x00002000,
		ExtraButton12 = 0x00004000,
		ExtraButton13 = 0x00008000,
		ExtraButton14 = 0x00010000,
		ExtraButton15 = 0x00020000,
		ExtraButton16 = 0x00040000,
		ExtraButton17 = 0x00080000,
		ExtraButton18 = 0x00100000,
		ExtraButton19 = 0x00200000,
		ExtraButton20 = 0x00400000,
		ExtraButton21 = 0x00800000,
		ExtraButton22 = 0x01000000,
		ExtraButton23 = 0x02000000,
		ExtraButton24 = 0x04000000,
		AllButtons = 0x07ffffff,
		MaxMouseButton = ExtraButton24,
		// 4 high-order bits remain available for future use (0x08000000 through 0x40000000).
		MouseButtonMask = 0xffffffff
	}

	public enum ScrollPhase : uint
	{
		NoScrollPhase = 0,
		ScrollBegin,
		ScrollUpdate,
		ScrollEnd
	}

	public enum MouseEventSource : uint
	{
		MouseEventNotSynthesized,
		MouseEventSynthesizedBySystem,
		MouseEventSynthesizedByQt,
		MouseEventSynthesizedByApplication
	}

	[Flags]
	public enum MouseEventFlag : uint
	{
		MouseEventCreatedDoubleClick = 0x01,
		MouseEventFlagMask = 0xFF
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

	public enum Orientation : uint
	{
		[XmlEnum ("Qt::Horizontal")]
		Horizontal = 0x1,
		[XmlEnum ("Qt::Vertical")]
		Vertical = 0x2
	}

	public enum TextInteractionFlags : uint
	{
		[XmlEnum ("Qt::NoTextInteraction")]
		NoTextInteraction = 0,
		[XmlEnum ("Qt::TextSelectableByMouse")]
		TextSelectableByMouse = 1,
		[XmlEnum ("Qt::TextSelectableByKeyboard")]
		TextSelectableByKeyboard = 2,
		[XmlEnum ("Qt::LinksAccessibleByMouse")]
		LinksAccessibleByMouse = 4,
		[XmlEnum ("Qt::LinksAccessibleByKeyboard")]
		LinksAccessibleByKeyboard = 8,
		[XmlEnum ("Qt::TextEditable")]
		TextEditable = 16,
		[XmlEnum ("Qt::TextEditorInteraction")]
		TextEditorInteraction = TextSelectableByMouse | TextSelectableByKeyboard | TextEditable,
		[XmlEnum ("Qt::TextBrowserInteraction")]
		TextBrowserInteraction = TextSelectableByMouse | LinksAccessibleByMouse | LinksAccessibleByKeyboard
	}

	[Flags]
	public enum Alignment : uint
	{
		[XmlEnum ("Qt::AlignLeft")]
		AlignLeft = 0x0001,
		[XmlEnum ("Qt::AlignLeading")]
		AlignLeading = AlignLeft,
		AlignRight = 0x0002,
		AlignTrailing = AlignRight,
		AlignHCenter = 0x0004,
		AlignJustify = 0x0008,
		AlignAbsolute = 0x0010,
		AlignHorizontal_Mask = AlignLeft | AlignRight | AlignHCenter | AlignJustify | AlignAbsolute,

		[XmlEnum ("Qt::AlignTop")]
		AlignTop = 0x0020,
		AlignBottom = 0x0040,
		AlignVCenter = 0x0080,
		AlignBaseline = 0x0100,
		// Note that 0x100 will clash with Qt::TextSingleLine = 0x100 due to what the comment above
		// this enum declaration states. However, since Qt::AlignBaseline is only used by layouts,
		// it doesn't make sense to pass Qt::AlignBaseline to QPainter::drawText(), so there
		// shouldn't really be any ambiguity between the two overlapping enum values.
		AlignVertical_Mask = AlignTop | AlignBottom | AlignVCenter | AlignBaseline,

		[XmlEnum ("Qt::AlignCenter")]
		AlignCenter = AlignVCenter | AlignHCenter
	}

	public enum ContextMenuPolicy : uint
	{
		[XmlEnum ("Qt::NoContextMenu")]
		NoContextMenu,
		[XmlEnum ("Qt::DefaultContextMenu")]
		DefaultContextMenu,
		[XmlEnum ("Qt::ActionsContextMenu")]
		ActionsContextMenu,
		[XmlEnum ("Qt::CustomContextMenu")]
		CustomContextMenu,
		[XmlEnum ("Qt::PreventContextMenu")]
		PreventContextMenu
	}

	public enum Direction : uint
	{
		LeftToRight,
		RightToLeft,
		TopToBottom,
		BottomToTop,
		Down = TopToBottom,
		Up = BottomToTop}

	;

	public enum TextFormat : uint
	{
		[XmlEnum ("Qt::PlainText")]
		PlainText,
		[XmlEnum ("Qt::RichText")]
		RichText,
		[XmlEnum ("Qt::AutoText")]
		AutoText,
		[XmlEnum ("Qt::LogText")]
		LogText
	}

	public enum SizeConstraint : uint
	{
		[XmlEnum ("QLayout::SetDefaultConstraint")]
		SetDefaultConstraint,
		[XmlEnum ("QLayout::SetNoConstraint")]
		SetNoConstraint,
		[XmlEnum ("QLayout::SetMinimumSize")]
		SetMinimumSize,
		[XmlEnum ("QLayout::SetFixedSize")]
		SetFixedSize,
		[XmlEnum ("QLayout::SetMaximumSize")]
		SetMaximumSize,
		[XmlEnum ("QLayout::SetMinAndMaxSize")]
		SetMinAndMaxSize
	}

	public enum FocusPolicy : uint
	{
		[XmlEnum ("Qt::NoFocus")]
		NoFocus = 0,
		[XmlEnum ("Qt::TabFocus")]
		TabFocus = 0x1,
		[XmlEnum ("Qt::ClickFocus")]
		ClickFocus = 0x2,
		[XmlEnum ("Qt::StrongFocus")]
		StrongFocus = TabFocus | ClickFocus | 0x8,
		[XmlEnum ("Qt::WheelFocus")]
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
		[XmlEnum ("Qt::NonModal")]
		NonModal,
		[XmlEnum ("Qt::WindowModal")]
		WindowModal,
		[XmlEnum ("Qt::ApplicationModal")]
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