using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class HBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_hboxlayout_new (HBoxLayout thisObject, IntPtr parent);

		protected HBoxLayout () {}

		protected HBoxLayout (IntPtr raw) : base(raw) {}

		public HBoxLayout (Widget parent) : base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_hboxlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

