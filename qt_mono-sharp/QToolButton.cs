using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ToolButton : AbstractButton
	{
		public ToolButton (IntPtr raw) : base(raw) {}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_toolbutton_new (ToolButton thisObject, IntPtr parent);
		public ToolButton (Widget parent)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_toolbutton_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_toolbutton_sizehint_get (IntPtr raw);
		public new Size SizeHint
		{
			get{ return new Size(qt_toolbutton_sizehint_get(Handle));}
		}
	}
}

