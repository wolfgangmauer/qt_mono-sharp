using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class HBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_hboxlayout_new (IntPtr parent);

		protected HBoxLayout (IntPtr raw) : base(raw) {}

		public HBoxLayout (Widget parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_hboxlayout_new (parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

