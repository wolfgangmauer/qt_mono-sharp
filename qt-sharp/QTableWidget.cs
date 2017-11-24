using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class TableWidget : TableView
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_tablewidget_new(IntPtr parent);

        protected TableWidget(IntPtr raw) : base(raw) { }

		public TableWidget() : this(null) {}

		public TableWidget(Object parent) : base(IntPtr.Zero)
        {
			Raw = qt_tablewidget_new(parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
