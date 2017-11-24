using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class AbstractItemView : AbstractScrollArea
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_abstractitemview_new(IntPtr parent);

		protected AbstractItemView(IntPtr raw) : base(raw) { }

		protected AbstractItemView(Widget parent) : base(IntPtr.Zero)
        {
			Raw = qt_abstractitemview_new(parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
