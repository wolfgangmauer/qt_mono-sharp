using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ToolBar : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_toolbar_new (ToolBar thisObject, IntPtr parent);
		public ToolBar (Widget parent = null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_toolbar_new (this, parent?.Handle ?? IntPtr.Zero);
		}
	}
}