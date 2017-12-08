using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class VBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_vboxlayout_new (VBoxLayout thisObject, IntPtr parent);

		private VBoxLayout (IntPtr parent) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(VBoxLayout))
				return;
			Raw = qt_vboxlayout_new (this, parent);
		}

		public VBoxLayout (Widget parent = null) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(VBoxLayout))
				return;
			Raw = qt_vboxlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

