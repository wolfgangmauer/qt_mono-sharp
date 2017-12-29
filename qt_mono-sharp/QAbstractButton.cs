using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public abstract class AbstractButton : Widget
	{
		public event EventHandler PressedEvent;
		public event EventHandler ReleasedEvent;
		public event EventHandler<bool> ClickedEvent;
		public event EventHandler<bool> ToggledEvent;

		protected AbstractButton (IntPtr raw) : base (raw) { }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_abstractbutton_text_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_abstractbutton_text_set(IntPtr raw, string text);
		public string Text
		{
			get
			{
				return qt_abstractbutton_text_get(Handle);
			}
			set
			{
				qt_abstractbutton_text_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_abstractbutton_icon_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_abstractbutton_icon_set(IntPtr raw, IntPtr icon);
		public Icon Icon
		{
			get
			{
				return new Icon(qt_abstractbutton_icon_get(Handle));
			}
			set
			{
				qt_abstractbutton_icon_set(Handle, value.Handle);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_abstractbutton_iconsize_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_abstractbutton_iconsize_set(IntPtr raw, IntPtr iconsize);
		public Size IconSize
		{
			get
			{
				return new Size(qt_abstractbutton_iconsize_get(Handle));
			}
			set
			{
				qt_abstractbutton_iconsize_set(Handle, value.Handle);
			}
		}

		private void OnPressed()
		{
			var tmp = PressedEvent;
			tmp?.Invoke (this, EventArgs.Empty);
		}

		private void OnReleased()
		{
			var tmp = ReleasedEvent;
			tmp?.Invoke (this, EventArgs.Empty);
		}

		private void OnClicked(bool _checked)
		{
			var tmp = ClickedEvent;
			tmp?.Invoke (this, _checked);
		}

		private void OnToggled(bool _checked)
		{
			var tmp = ToggledEvent;
			tmp?.Invoke (this, _checked);
		}
	}
}

