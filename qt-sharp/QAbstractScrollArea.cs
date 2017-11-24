using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class AbstractScrollArea : Frame
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_abstractscrollarea_new(IntPtr parent);
        
		protected AbstractScrollArea(IntPtr raw) : base(raw) { }

		protected AbstractScrollArea(Widget parent) : base(IntPtr.Zero)
        {
			Raw = qt_abstractscrollarea_new(parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
