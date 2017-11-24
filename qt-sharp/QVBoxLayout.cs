using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class VBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_vboxlayout_new (Object thisObject, IntPtr parent);

		protected VBoxLayout (IntPtr raw) : base(raw) {}

		public VBoxLayout (Widget parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_vboxlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

