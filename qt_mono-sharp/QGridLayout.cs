using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class GridLayout : Layout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_gridlayout_new (GridLayout thisObject, IntPtr parent);

		public GridLayout (IntPtr raw) : base(raw) {}

		public GridLayout (Widget parent = null)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_gridlayout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_gridlayout_widget_add (IntPtr raw, IntPtr widget);
		public new void AddWidget(Widget widget)
		{
			qt_gridlayout_widget_add (Handle, widget.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_gridlayout_widget_alignment_add (IntPtr raw, IntPtr widget, int row, int col, Alignment alignment);
		public void AddWidget(Widget widget, int row, int col, Alignment alignment = (Alignment)0)
		{
			qt_gridlayout_widget_alignment_add (Handle, widget.Handle, row, col, alignment);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_gridlayout_widget_span_add (IntPtr raw, IntPtr widget, int row, int col, int rowSpan, int colSpan, Alignment alignment);
		public void AddWidget(Widget widget, int row, int col, int rowSpan, int colSpan, Alignment alignment = (Alignment)0)
		{
			qt_gridlayout_widget_span_add (Handle, widget.Handle, row, col, rowSpan, colSpan, alignment);
		}
	}
}
