using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class TableView : AbstractItemView
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_tableview_new(IntPtr parent);

		protected TableView(IntPtr raw) : base(raw) { }

		public TableView () : this(null) {}

        public TableView(Widget parent) : base(IntPtr.Zero)
        {
			Raw = qt_tableview_new(parent != null ? parent.Handle : IntPtr.Zero);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_widget_horizontalheader_get(IntPtr raw);
        public HeaderView HorizontalHeader
        {
            get
            {
				return new HeaderView(qt_widget_horizontalheader_get(Handle));
            }
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_widget_verticalheader_get(IntPtr raw);
        public HeaderView VerticalHeader
        {
            get
            {
				return new HeaderView(qt_widget_verticalheader_get(Handle));
            }
        }
    }
}
