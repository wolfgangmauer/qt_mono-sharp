using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class PushButton : AbstractButton
	{
		public PushButton (IntPtr raw) : base(raw) {}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_pushbutton_new_with_text (PushButton thisObject, string text, IntPtr parent);
		public PushButton (string text, Widget parent=null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_pushbutton_new_with_text (this, text, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_pushbutton_new (PushButton thisObject, IntPtr parent);
		public PushButton (Widget parent)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_pushbutton_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_pushbutton_sizehint_get (IntPtr raw);
		public new Size SizeHint
		{
			get{ return new Size(qt_pushbutton_sizehint_get(Handle));}
		}
	}
}

