using System;
using System.Runtime.InteropServices;

namespace Qt
{
	public class Event
	{
		public EventType Type { get; set; }
	}

	public class MouseEvent
	{
	}

	public class InputEvent : Qt.Event
	{
		public KeyboardModifier Modifiers { get; set; }
	}

	public class KeyEvent : InputEvent
	{
		public KeyEvent()
		{
		}

		public KeyEvent(EventType type, int key, KeyboardModifier modifiers, string text = "", bool autorep = false, ushort count = 1)
		{
			Type = type;
			Key = key;
			Modifiers = modifiers;
			Text = text;
			AutoRepeat = autorep;
			Count = count;
		}

		public int Key
		{
			get;
			set;
		}

		public string Text {
			get;
			set;
		}

		public bool AutoRepeat {
			get;
			set;
		}

		public ushort Count {
			get;
			set;
		}
	}
}
