using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class HBoxLayout : BoxLayout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_hboxlayout_new (HBoxLayout thisObject, IntPtr parent);

		private HBoxLayout (IntPtr parent) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(HBoxLayout))
				return;
			Raw = qt_hboxlayout_new (this, parent);
		}

		public HBoxLayout (Widget parent = null) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(HBoxLayout))
				return;
			Raw = qt_hboxlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}
	}
}

