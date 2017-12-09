using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class GridLayout : Layout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_gridlayout_new (GridLayout thisObject, IntPtr parent);

		protected GridLayout () {}

		protected GridLayout (IntPtr raw) : base(raw) {}

		public GridLayout (Object parent)
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
		protected static extern void qt_gridlayout_widget_alignment_add (IntPtr raw, IntPtr widget, int row, int column, Alignment alignment);
		public void AddWidget(Widget widget, int row, int column, Alignment alignment = (Alignment)0)
		{
			qt_gridlayout_widget_alignment_add (Handle, widget.Handle, row, column, alignment);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_gridlayout_widget_span_add (IntPtr raw, IntPtr widget, int row, int column, int rowSpan, int columnSpan, Alignment alignment);
		public void AddWidget(Widget widget, int row, int column, int rowSpan, int columnSpan, Alignment alignment = (Alignment)0)
		{
			qt_gridlayout_widget_span_add (Handle, widget.Handle, row, column, rowSpan, columnSpan, alignment);
		}
	}
}
