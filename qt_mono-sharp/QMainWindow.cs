using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class MainWindow : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mainwindow_new (MainWindow thisObject, IntPtr parent, WindowType f);

		protected MainWindow () { }

		protected MainWindow (IntPtr raw) : base(raw) { }

		public MainWindow (Widget parent) : this(parent, 0) {}

		public MainWindow (Widget parent, WindowType f)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_mainwindow_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		public MainWindow (Widget parent, string uiFile, WindowType f = 0)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_mainwindow_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
			new UiLoader ().Load (this, uiFile);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_mainwindow_menubar_get (IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_mainwindow_menubar_set (IntPtr raw, IntPtr menubar);
        public MenuBar MenuBar
		{
			get
			{
				var ptr = qt_mainwindow_menubar_get (Handle);
				return ptr == IntPtr.Zero ? null : new MenuBar (ptr);
			}
			set
			{
				qt_mainwindow_menubar_set (Handle, value.Handle);
			}
		}
	}
}

