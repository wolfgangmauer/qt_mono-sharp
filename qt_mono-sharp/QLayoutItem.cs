using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class LayoutItem : Layout
    {
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern IntPtr qt_layoutitem_new(LayoutItem thisObject, IntPtr parent);

		protected LayoutItem(IntPtr raw) : base(raw) { }

        public LayoutItem(Widget parent = null) : base(IntPtr.Zero)
        {
			Raw = qt_layoutitem_new(this, parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
