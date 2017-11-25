using System;
using System.Runtime.InteropServices;

namespace Qt
{
	public class EventArgs
	{
		public EventType Type { get; set; }
	}

	[StructLayout(LayoutKind.Sequential, CharSet=CharSet.Ansi)]
	public class InputEventArgs : Qt.EventArgs
	{
		public KeyboardModifier Modifiers { get; set; }
	}

	[StructLayout(LayoutKind.Sequential, CharSet=CharSet.Ansi)]
	public class KeyEventArgs : InputEventArgs
	{
		public KeyEventArgs()
		{
		}

		public KeyEventArgs(EventType type, int key, KeyboardModifier modifiers, string text = "", bool autorep = false, ushort count = 1)
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

