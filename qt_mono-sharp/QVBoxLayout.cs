using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class VBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_vboxlayout_new (VBoxLayout thisObject, IntPtr parent);

		protected VBoxLayout () {}

		protected VBoxLayout (IntPtr raw) : base(raw) {}

		public VBoxLayout (Widget parent = null)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_vboxlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

