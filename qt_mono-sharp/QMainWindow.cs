using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class MainWindow : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mainwindow_new (MainWindow thisObject, IntPtr parent, WindowType f);

		protected MainWindow (IntPtr parent) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(MainWindow))
				return;
			Raw = qt_mainwindow_new (this, parent, 0);
		}

		public MainWindow (Widget parent, string uiFile)
			: base(IntPtr.Zero)
		{
			Raw = qt_mainwindow_new (this, parent != null ? parent.Handle : IntPtr.Zero, 0);
			new UiLoader (this).Load (uiFile);
		}

		public MainWindow () : this(null, 0) {}

		public MainWindow (Widget parent, WindowType f = 0) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(MainWindow))
				return;
			Raw = qt_mainwindow_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}
	}
}

