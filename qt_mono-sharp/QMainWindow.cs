using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class MainWindow : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mainwindow_new (MainWindow thisObject, IntPtr parent, WindowType f);

		protected MainWindow (IntPtr raw) : base(raw) {}

		public MainWindow () : this(null, 0) {}

		public MainWindow (Widget parent) : this(parent, 0) {}

		public MainWindow (Widget parent, WindowType f) : base(IntPtr.Zero)
		{
			Raw = qt_mainwindow_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}
	}
}

